USE MediCheckDB;
GO

/* ============================================================
   SCRIPT 1: ELIMINAR LOS EVENTOS FICTICIOS ACTUALES

   Este bloque solamente limpia LogEventos. No modifica pacientes,
   medicamentos, recetas ni horarios.
   ============================================================ */
BEGIN TRANSACTION;

DELETE FROM dbo.LogEventos;
DBCC CHECKIDENT ('dbo.LogEventos', RESEED, 0);

COMMIT TRANSACTION;
GO

/* ============================================================
   SCRIPT 2: CREAR EVENTOS FICTICIOS PARA LOS OCHO REPORTES

   Periodo utilizado: cuatro semanas completas.
   Desde: 11/05/2026
   Hasta: 07/06/2026

   Datos reales reutilizados:
   - Pacientes
   - Medicamentos
   - Recetas
   - HorariosReceta

   Datos ficticios generados:
   - Tomas correctas, retrasadas y omitidas
   - Autenticaciones exitosas y fallidas
   - Agua servida
   - Errores de hardware y alertas criticas
   ============================================================ */
SET NOCOUNT ON;
SET XACT_ABORT ON;

DECLARE @FechaInicio DATE = '2026-05-11';
DECLARE @FechaFin DATE = '2026-06-07';

IF NOT EXISTS (
    SELECT 1
    FROM dbo.Recetas r
    INNER JOIN dbo.HorariosReceta h ON h.idReceta = r.idReceta
)
BEGIN
    RAISERROR(
        'No existen recetas con horarios. Registre horarios antes de generar LogEventos.',
        16,
        1
    );
    RETURN;
END;

BEGIN TRY
    BEGIN TRANSACTION;

    DROP TABLE IF EXISTS #Dias;
    DROP TABLE IF EXISTS #TomasBase;
    DROP TABLE IF EXISTS #TomasClasificadas;
    DROP TABLE IF EXISTS #PacientesBase;
    DROP TABLE IF EXISTS #PacientesOrdenados;
    DROP TABLE IF EXISTS #Intentos;
    DROP TABLE IF EXISTS #Incidentes;

    /* --------------------------------------------------------
       1. Crear los 28 dias del periodo
       -------------------------------------------------------- */
    CREATE TABLE #Dias (
        fecha DATE NOT NULL PRIMARY KEY,
        numeroDia INT NOT NULL,
        numeroSemana INT NOT NULL
    );

    ;WITH Dias AS (
        SELECT
            @FechaInicio AS fecha,
            1 AS numeroDia
        UNION ALL
        SELECT
            DATEADD(DAY, 1, fecha),
            numeroDia + 1
        FROM Dias
        WHERE fecha < @FechaFin
    )
    INSERT INTO #Dias(fecha, numeroDia, numeroSemana)
    SELECT
        fecha,
        numeroDia,
        ((numeroDia - 1) / 7) + 1
    FROM Dias
    OPTION (MAXRECURSION 100);

    /* --------------------------------------------------------
       2. Construir cada toma programada usando datos reales
       -------------------------------------------------------- */
    SELECT
        d.fecha,
        d.numeroDia,
        d.numeroSemana,
        h.idHorario,
        r.idReceta,
        p.idPaciente,
        CONCAT(p.nombre, ' ', p.apellido) AS nombrePaciente,
        m.idMedicamento,
        m.nombre AS medicamento,
        DATEADD(
            SECOND,
            DATEDIFF(SECOND, CAST('00:00:00' AS TIME), h.horaProgramada),
            CAST(d.fecha AS DATETIME)
        ) AS fechaHoraProgramada,
        ABS(CHECKSUM(CONCAT(
            d.numeroDia, '-', h.idHorario, '-',
            p.idPaciente, '-', m.idMedicamento
        ))) % 100 AS valorResultado,
        ABS(CHECKSUM(CONCAT(
            'hora-', d.numeroDia, '-', h.idHorario, '-',
            p.idPaciente, '-', m.idMedicamento
        ))) % 100 AS valorHora,
        CASE d.numeroSemana
            WHEN 1 THEN 78
            WHEN 2 THEN 64
            WHEN 3 THEN 83
            ELSE 90
        END
        + CASE p.idPaciente % 4
            WHEN 0 THEN -8
            WHEN 1 THEN 5
            WHEN 2 THEN -3
            ELSE 1
          END
        + CASE m.idMedicamento % 3
            WHEN 0 THEN -4
            WHEN 1 THEN 3
            ELSE 0
          END AS limiteCumplimiento
    INTO #TomasBase
    FROM #Dias d
    CROSS JOIN dbo.HorariosReceta h
    INNER JOIN dbo.Recetas r ON r.idReceta = h.idReceta
    INNER JOIN dbo.Pacientes p ON p.idPaciente = r.idPaciente
    INNER JOIN dbo.Medicamentos m ON m.idMedicamento = r.idMedicamento;

    SELECT
        *,
        CASE
            WHEN valorResultado >= limiteCumplimiento THEN 'Omitida'
            WHEN valorHora < 30 THEN 'Retraso'
            ELSE 'Tomada'
        END AS estadoCalculado
    INTO #TomasClasificadas
    FROM #TomasBase;

    /* --------------------------------------------------------
       3. Insertar eventos de toma

       Semana 1: cumplimiento medio
       Semana 2: menor cumplimiento
       Semana 3: recuperacion
       Semana 4: mejor cumplimiento
       -------------------------------------------------------- */
    INSERT INTO dbo.LogEventos (
        idPaciente,
        nombrePaciente,
        idMedicamento,
        medicamento,
        tipoEvento,
        estado,
        origen,
        fechaHoraProgramada,
        fechaHoraReal,
        cantidad,
        detalle
    )
    SELECT
        idPaciente,
        nombrePaciente,
        idMedicamento,
        medicamento,
        'Toma',
        estadoCalculado,
        'Dispensador',
        fechaHoraProgramada,
        CASE estadoCalculado
            WHEN 'Omitida' THEN NULL
            WHEN 'Retraso' THEN DATEADD(
                MINUTE,
                12 + (valorHora % 45),
                fechaHoraProgramada
            )
            ELSE DATEADD(
                MINUTE,
                -8 + (valorHora % 18),
                fechaHoraProgramada
            )
        END,
        CASE WHEN estadoCalculado = 'Omitida' THEN 0 ELSE 1 END,
        CASE
            WHEN estadoCalculado = 'Tomada'
                THEN 'La dosis fue tomada dentro del horario esperado'
            WHEN estadoCalculado = 'Retraso'
                THEN 'La dosis fue tomada con retraso'
            WHEN valorHora % 3 = 0
                THEN 'Paciente dormida'
            WHEN valorHora % 3 = 1
                THEN 'Pastilla ignorada'
            ELSE 'Error de dispensador: pastilla no encontrada'
        END
    FROM #TomasClasificadas;

    /* --------------------------------------------------------
       4. Pacientes con un medicamento asociado

       Se utiliza para eventos del sistema que no pertenecen a una
       dosis especifica, evitando IDs inventados o valores NULL.
       -------------------------------------------------------- */
    ;WITH PrimeraReceta AS (
        SELECT
            r.idPaciente,
            r.idMedicamento,
            ROW_NUMBER() OVER (
                PARTITION BY r.idPaciente
                ORDER BY r.idReceta
            ) AS posicion
        FROM dbo.Recetas r
    )
    SELECT
        p.idPaciente,
        CONCAT(p.nombre, ' ', p.apellido) AS nombrePaciente,
        pr.idMedicamento,
        m.nombre AS medicamento
    INTO #PacientesBase
    FROM dbo.Pacientes p
    INNER JOIN PrimeraReceta pr
        ON pr.idPaciente = p.idPaciente
       AND pr.posicion = 1
    INNER JOIN dbo.Medicamentos m
        ON m.idMedicamento = pr.idMedicamento;

    SELECT
        ROW_NUMBER() OVER (ORDER BY idPaciente) AS numeroPaciente,
        idPaciente,
        nombrePaciente,
        idMedicamento,
        medicamento
    INTO #PacientesOrdenados
    FROM #PacientesBase;

    /* --------------------------------------------------------
       5. Autenticaciones por huella

       Se generan dos intentos diarios por paciente. Existen fallos
       distribuidos durante las cuatro semanas.
       -------------------------------------------------------- */
    CREATE TABLE #Intentos (
        intento INT NOT NULL PRIMARY KEY,
        hora TIME NOT NULL
    );

    INSERT INTO #Intentos(intento, hora)
    VALUES
        (1, '07:25:00'),
        (2, '19:20:00');

    INSERT INTO dbo.LogEventos (
        idPaciente,
        nombrePaciente,
        idMedicamento,
        medicamento,
        tipoEvento,
        estado,
        origen,
        fechaHoraProgramada,
        fechaHoraReal,
        cantidad,
        detalle
    )
    SELECT
        p.idPaciente,
        p.nombrePaciente,
        p.idMedicamento,
        p.medicamento,
        'Autenticacion',
        CASE
            WHEN (d.numeroDia + p.idPaciente + i.intento) % 11 = 0
              OR (d.numeroSemana = 2 AND (d.numeroDia + p.idPaciente + i.intento) % 7 = 0)
                THEN 'Fallida'
            ELSE 'Exitosa'
        END,
        'Sensor Huella',
        DATEADD(
            SECOND,
            DATEDIFF(SECOND, CAST('00:00:00' AS TIME), i.hora),
            CAST(d.fecha AS DATETIME)
        ),
        DATEADD(
            SECOND,
            15 + ((d.numeroDia + p.idPaciente + i.intento) % 45),
            DATEADD(
                SECOND,
                DATEDIFF(SECOND, CAST('00:00:00' AS TIME), i.hora),
                CAST(d.fecha AS DATETIME)
            )
        ),
        CASE
            WHEN (d.numeroDia + p.idPaciente + i.intento) % 11 = 0
              OR (d.numeroSemana = 2 AND (d.numeroDia + p.idPaciente + i.intento) % 7 = 0)
                THEN 0
            ELSE 1
        END,
        CASE
            WHEN (d.numeroDia + p.idPaciente + i.intento) % 11 = 0
              OR (d.numeroSemana = 2 AND (d.numeroDia + p.idPaciente + i.intento) % 7 = 0)
                THEN 'Huella no reconocida'
            ELSE 'Identidad verificada correctamente'
        END
    FROM #Dias d
    CROSS JOIN #PacientesBase p
    CROSS JOIN #Intentos i;

    /* --------------------------------------------------------
       6. Agua servida diariamente
       -------------------------------------------------------- */
    INSERT INTO dbo.LogEventos (
        idPaciente,
        nombrePaciente,
        idMedicamento,
        medicamento,
        tipoEvento,
        estado,
        origen,
        fechaHoraProgramada,
        fechaHoraReal,
        cantidad,
        detalle
    )
    SELECT
        p.idPaciente,
        p.nombrePaciente,
        p.idMedicamento,
        p.medicamento,
        'Agua Servida',
        'Servida',
        'Dispensador de Agua',
        DATEADD(MINUTE, 5, DATEADD(HOUR, 8, CAST(d.fecha AS DATETIME))),
        DATEADD(MINUTE, 5, DATEADD(HOUR, 8, CAST(d.fecha AS DATETIME))),
        180 + ((d.numeroDia * 37 + p.idPaciente * 29) % 241),
        'Agua servida junto con la toma programada'
    FROM #Dias d
    CROSS JOIN #PacientesBase p;

    /* --------------------------------------------------------
       7. Errores de hardware y alertas criticas
       -------------------------------------------------------- */
    CREATE TABLE #Incidentes (
        numero INT NOT NULL PRIMARY KEY,
        diasDesdeInicio INT NOT NULL,
        hora TIME NOT NULL,
        tipoEvento NVARCHAR(50) NOT NULL,
        estado NVARCHAR(30) NOT NULL,
        origen NVARCHAR(80) NOT NULL,
        detalle NVARCHAR(200) NOT NULL
    );

    INSERT INTO #Incidentes(
        numero, diasDesdeInicio, hora, tipoEvento,
        estado, origen, detalle
    )
    VALUES
        (1,  1,  '09:12:00', 'Error Hardware', 'Resuelta', 'Error Sensor',      'Fallo temporal en sensor de presencia'),
        (2,  3,  '20:15:00', 'Alerta Critica', 'Activa',   'Alarma Critica',   'Compartimento abierto fuera de horario'),
        (3,  6,  '08:40:00', 'Error Hardware', 'Resuelta', 'Error Conexion',   'Perdida de conexion durante cinco minutos'),
        (4,  8,  '13:05:00', 'Error Hardware', 'Activa',   'Error Motor',      'Motor del dispensador bloqueado'),
        (5,  10, '07:55:00', 'Error Hardware', 'Resuelta', 'Error Sensor',     'Lectura inestable del sensor de pastilla'),
        (6,  12, '19:42:00', 'Alerta Critica', 'Activa',   'Alarma Critica',   'Dispensacion no confirmada por el paciente'),
        (7,  14, '10:18:00', 'Error Hardware', 'Resuelta', 'Error Conexion',   'Reconexion automatica del dispositivo'),
        (8,  16, '21:10:00', 'Error Hardware', 'Activa',   'Error Motor',      'Atasco detectado en mecanismo de salida'),
        (9,  18, '08:25:00', 'Error Hardware', 'Resuelta', 'Error Sensor',     'Sensor de vaso sin respuesta'),
        (10, 20, '15:33:00', 'Alerta Critica', 'Activa',   'Alarma Critica',   'Tres intentos fallidos de autenticacion'),
        (11, 22, '18:47:00', 'Error Hardware', 'Resuelta', 'Error Conexion',   'Interrupcion breve de comunicacion'),
        (12, 24, '09:14:00', 'Error Hardware', 'Activa',   'Error Motor',      'Mecanismo requiere revision preventiva'),
        (13, 26, '07:38:00', 'Error Hardware', 'Resuelta', 'Error Sensor',     'Calibracion automatica completada'),
        (14, 27, '20:26:00', 'Alerta Critica', 'Activa',   'Alarma Critica',   'Dosis prioritaria sin confirmacion');

    DECLARE @CantidadPacientes INT = (
        SELECT COUNT(*) FROM #PacientesOrdenados
    );

    INSERT INTO dbo.LogEventos (
        idPaciente,
        nombrePaciente,
        idMedicamento,
        medicamento,
        tipoEvento,
        estado,
        origen,
        fechaHoraProgramada,
        fechaHoraReal,
        cantidad,
        detalle
    )
    SELECT
        p.idPaciente,
        p.nombrePaciente,
        p.idMedicamento,
        p.medicamento,
        i.tipoEvento,
        i.estado,
        i.origen,
        DATEADD(
            SECOND,
            DATEDIFF(SECOND, CAST('00:00:00' AS TIME), i.hora),
            CAST(DATEADD(DAY, i.diasDesdeInicio, @FechaInicio) AS DATETIME)
        ),
        DATEADD(
            SECOND,
            DATEDIFF(SECOND, CAST('00:00:00' AS TIME), i.hora),
            CAST(DATEADD(DAY, i.diasDesdeInicio, @FechaInicio) AS DATETIME)
        ),
        0,
        i.detalle
    FROM #Incidentes i
    INNER JOIN #PacientesOrdenados p
        ON p.numeroPaciente = ((i.numero - 1) % @CantidadPacientes) + 1;

    COMMIT TRANSACTION;
END TRY
BEGIN CATCH
    IF @@TRANCOUNT > 0
        ROLLBACK TRANSACTION;

    DECLARE @MensajeError NVARCHAR(4000) = ERROR_MESSAGE();
    RAISERROR(@MensajeError, 16, 1);
END CATCH;
GO

/* ============================================================
   VERIFICACION DE LOS DATOS GENERADOS
   ============================================================ */
SELECT
    tipoEvento,
    estado,
    COUNT(*) AS cantidadEventos
FROM dbo.LogEventos
GROUP BY tipoEvento, estado
ORDER BY tipoEvento, estado;

SELECT
    ((DATEDIFF(DAY, CAST('2026-05-11' AS DATE), fechaHoraProgramada) / 7) + 1) AS semana,
    COUNT(*) AS dosisProgramadas,
    SUM(CASE WHEN estado IN ('Tomada', 'Retraso') THEN 1 ELSE 0 END) AS dosisCumplidas,
    SUM(CASE WHEN estado = 'Omitida' THEN 1 ELSE 0 END) AS dosisOmitidas,
    CAST(
        100.0 * SUM(CASE WHEN estado IN ('Tomada', 'Retraso') THEN 1 ELSE 0 END)
        / NULLIF(COUNT(*), 0)
        AS DECIMAL(5, 2)
    ) AS porcentajeCumplimiento
FROM dbo.LogEventos
WHERE tipoEvento = 'Toma'
GROUP BY ((DATEDIFF(DAY, CAST('2026-05-11' AS DATE), fechaHoraProgramada) / 7) + 1)
ORDER BY semana;

SELECT
    idPaciente,
    nombrePaciente,
    medicamento,
    COUNT(*) AS dosisProgramadas,
    SUM(CASE WHEN estado IN ('Tomada', 'Retraso') THEN 1 ELSE 0 END) AS dosisCumplidas,
    SUM(CASE WHEN estado = 'Omitida' THEN 1 ELSE 0 END) AS dosisOmitidas,
    CAST(
        100.0 * SUM(CASE WHEN estado IN ('Tomada', 'Retraso') THEN 1 ELSE 0 END)
        / NULLIF(COUNT(*), 0)
        AS DECIMAL(5, 2)
    ) AS porcentajeAdherencia
FROM dbo.LogEventos
WHERE tipoEvento = 'Toma'
GROUP BY idPaciente, nombrePaciente, idMedicamento, medicamento
ORDER BY idPaciente, medicamento;
GO
