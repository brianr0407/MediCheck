#include "pch.h"
#include "RecetaController.h"
#include "ConexionBD.h"
#include "MedicamentoController.h"
#include "PacienteController.h"

namespace {
    System::TimeSpan NormalizarHora(System::TimeSpan hora) {
        return System::TimeSpan(hora.Hours, hora.Minutes, 0);
    }

    bool ContieneHorasDuplicadas(System::Collections::Generic::List<System::TimeSpan>^ horarios) {
        if (horarios == nullptr)
            return false;

        System::Collections::Generic::List<System::TimeSpan>^ normalizadas = gcnew System::Collections::Generic::List<System::TimeSpan>();
        for each (System::TimeSpan hora in horarios) {
            System::TimeSpan horaNormalizada = NormalizarHora(hora);
            if (normalizadas->Contains(horaNormalizada))
                return true;
            normalizadas->Add(horaNormalizada);
        }

        return false;
    }
}

namespace CONTROLLER {
    RecetaController::RecetaController() {
        this->listaRecetas = gcnew List<Receta^>();
        this->conexion = ConexionBD::CrearConexion();
    }

    RecetaController::RecetaController(List<Receta^>^ listaRecetas) {
        this->listaRecetas = listaRecetas;
        this->conexion = ConexionBD::CrearConexion();
    }

    void RecetaController::abrirConexion() {
        if (this->conexion == nullptr)
            this->conexion = ConexionBD::CrearConexion();
        if (this->conexion->State != System::Data::ConnectionState::Open)
            this->conexion->Open();
    }

    void RecetaController::cerrarConexion() {
        if (this->conexion != nullptr && this->conexion->State != System::Data::ConnectionState::Closed)
            this->conexion->Close();
    }

    void RecetaController::AgregarAlBackup(Receta^ receta) {
        // Respaldo delegado a la base de datos.
    }

    void RecetaController::ActualizarBackup(Receta^ receta) {
        // Respaldo delegado a la base de datos.
    }

    int RecetaController::ObtenerSiguienteId() {
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "SELECT ISNULL(MAX(idReceta), 0) + 1 FROM Recetas", this->conexion);
        int id = Convert::ToInt32(sentenciaSQL->ExecuteScalar());
        cerrarConexion();
        return id;
    }

    void RecetaController::EscribirArchivo(List<Receta^>^ listaRecetas) {
        abrirConexion();
        SqlCommand^ desactivar = gcnew SqlCommand("UPDATE Recetas SET Activo=0", this->conexion);
        desactivar->ExecuteNonQuery();

        for each (Receta ^ receta in listaRecetas) {
            SqlCommand^ actualizar = gcnew SqlCommand(
                "UPDATE Recetas SET idPaciente=@idPaciente,idMedicamento=@idMedicamento,"
                "dosisDiaria=@dosisDiaria,dosisTomada=@dosisTomada,Activo=1 WHERE idReceta=@idReceta",
                this->conexion);
            actualizar->Parameters->AddWithValue("@idPaciente", receta->getIdPaciente());
            actualizar->Parameters->AddWithValue("@idMedicamento", receta->getMedicamento()->getId());
            actualizar->Parameters->AddWithValue("@dosisDiaria", receta->getDosisDiaria());
            actualizar->Parameters->AddWithValue("@dosisTomada", receta->getDosisTomada());
            actualizar->Parameters->AddWithValue("@idReceta", receta->getIdReceta());

            if (actualizar->ExecuteNonQuery() <= 0) {
                SqlCommand^ insertar = gcnew SqlCommand(
                    "INSERT INTO Recetas(idReceta,idPaciente,idMedicamento,dosisDiaria,dosisTomada,Activo) "
                    "VALUES(@idReceta,@idPaciente,@idMedicamento,@dosisDiaria,@dosisTomada,1)",
                    this->conexion);
                insertar->Parameters->AddWithValue("@idReceta", receta->getIdReceta());
                insertar->Parameters->AddWithValue("@idPaciente", receta->getIdPaciente());
                insertar->Parameters->AddWithValue("@idMedicamento", receta->getMedicamento()->getId());
                insertar->Parameters->AddWithValue("@dosisDiaria", receta->getDosisDiaria());
                insertar->Parameters->AddWithValue("@dosisTomada", receta->getDosisTomada());
                insertar->ExecuteNonQuery();
            }
        }

        cerrarConexion();
    }

    bool RecetaController::ActualizarArchivo(Receta^ receta) {
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "UPDATE Recetas SET idPaciente=@idPaciente,idMedicamento=@idMedicamento,"
            "dosisDiaria=@dosisDiaria,dosisTomada=@dosisTomada WHERE idReceta=@idReceta AND Activo=1",
            this->conexion);
        sentenciaSQL->Parameters->AddWithValue("@idPaciente", receta->getIdPaciente());
        sentenciaSQL->Parameters->AddWithValue("@idMedicamento", receta->getMedicamento()->getId());
        sentenciaSQL->Parameters->AddWithValue("@dosisDiaria", receta->getDosisDiaria());
        sentenciaSQL->Parameters->AddWithValue("@dosisTomada", receta->getDosisTomada());
        sentenciaSQL->Parameters->AddWithValue("@idReceta", receta->getIdReceta());
        bool actualizado = sentenciaSQL->ExecuteNonQuery() > 0;
        cerrarConexion();
        return actualizado;
    }

    List<Receta^>^ RecetaController::ObtenerTodosRecetasTXT() {
        List<Receta^>^ lista = gcnew List<Receta^>();
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "SELECT r.idReceta, r.idPaciente, r.dosisDiaria, r.dosisTomada, "
            "m.idMedicamento, m.nombre, m.tamano "
            "FROM Recetas r "
            "INNER JOIN Medicamentos m ON m.idMedicamento = r.idMedicamento AND m.Activo = 1 "
            "WHERE r.Activo=1 ORDER BY r.idReceta",
            this->conexion);
        SqlDataReader^ data = sentenciaSQL->ExecuteReader();

        while (data->Read()) {
            Medicamento^ medicamento = gcnew Medicamento(
                Convert::ToInt32(data["idMedicamento"]),
                Convert::ToString(data["nombre"]),
                Convert::ToString(data["tamano"]));

            lista->Add(gcnew Receta(
                Convert::ToInt32(data["idReceta"]),
                Convert::ToInt32(data["idPaciente"]),
                medicamento,
                Convert::ToInt32(data["dosisDiaria"]),
                Convert::ToInt32(data["dosisTomada"])));
        }

        data->Close();
        cerrarConexion();
        return lista;
    }

    DataTable^ RecetaController::ObtenerRecetasParaGrillaTXT() {
        DataTable^ tabla = gcnew DataTable();
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "SELECT r.idReceta, "
            "m.nombre + ' (id: ' + CAST(m.idMedicamento AS VARCHAR(10)) + ')' AS medicamento, "
            "m.tamano, "
            "CASE "
            "WHEN p.idPaciente IS NULL THEN 'No Asignado' "
            "ELSE '(id: ' + CAST(r.idPaciente AS VARCHAR(10)) + ') ' + p.nombre + ' ' + p.apellido "
            "END AS pacienteAsignado, "
            "r.dosisDiaria, "
            "ISNULL("
            "STUFF(("
            "SELECT ', ' + LEFT(CONVERT(VARCHAR(8), CAST(h.horaProgramada AS time), 108), 5) "
            "FROM HorariosReceta h "
            "WHERE h.idReceta = r.idReceta "
            "ORDER BY h.horaProgramada "
            "FOR XML PATH(''), TYPE"
            ").value('.', 'NVARCHAR(MAX)'), 1, 2, ''), "
            "'Sin horario') AS horasProgramadas, "
            "m.nombre AS nombreMedicamento "
            "FROM Recetas r "
            "INNER JOIN Medicamentos m ON m.idMedicamento = r.idMedicamento AND m.Activo = 1 "
            "LEFT JOIN Pacientes p ON p.idPaciente = r.idPaciente AND p.Activo = 1 "
            "WHERE r.Activo = 1 "
            "ORDER BY r.idReceta",
            this->conexion);
        SqlDataAdapter^ adapter = gcnew SqlDataAdapter(sentenciaSQL);
        adapter->Fill(tabla);
        cerrarConexion();
        return tabla;
    }

    DataTable^ RecetaController::ObtenerRecetasInactivasTablaTXT() {
        DataTable^ tabla = gcnew DataTable();
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "SELECT r.idReceta, r.idPaciente, "
            "ISNULL(p.nombre + ' ' + p.apellido, 'Paciente no encontrado') AS paciente, "
            "CASE WHEN p.Activo = 1 THEN 'Activo' ELSE 'Inactivo' END AS estadoPaciente, "
            "r.idMedicamento, "
            "ISNULL(m.nombre, 'Medicamento no encontrado') AS medicamento, "
            "CASE WHEN m.Activo = 1 THEN 'Activo' ELSE 'Inactivo' END AS estadoMedicamento, "
            "r.dosisDiaria, r.dosisTomada "
            "FROM Recetas r "
            "LEFT JOIN Pacientes p ON p.idPaciente = r.idPaciente "
            "LEFT JOIN Medicamentos m ON m.idMedicamento = r.idMedicamento "
            "WHERE r.Activo = 0 "
            "ORDER BY r.idReceta", this->conexion);
        SqlDataAdapter^ adapter = gcnew SqlDataAdapter(sentenciaSQL);
        adapter->Fill(tabla);
        cerrarConexion();
        return tabla;
    }

    bool RecetaController::AgregarRecetaTXT(Receta^ receta) {
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "INSERT INTO Recetas(idReceta,idPaciente,idMedicamento,dosisDiaria,dosisTomada,Activo) "
            "VALUES(@idReceta,@idPaciente,@idMedicamento,@dosisDiaria,@dosisTomada,1)",
            this->conexion);
        sentenciaSQL->Parameters->AddWithValue("@idReceta", receta->getIdReceta());
        sentenciaSQL->Parameters->AddWithValue("@idPaciente", receta->getIdPaciente());
        sentenciaSQL->Parameters->AddWithValue("@idMedicamento", receta->getMedicamento()->getId());
        sentenciaSQL->Parameters->AddWithValue("@dosisDiaria", receta->getDosisDiaria());
        sentenciaSQL->Parameters->AddWithValue("@dosisTomada", receta->getDosisTomada());
        bool agregado = sentenciaSQL->ExecuteNonQuery() > 0;
        cerrarConexion();
        return agregado;
    }

    bool RecetaController::EliminarRecetaTXT(int id) {
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "UPDATE Recetas SET Activo=0 WHERE idReceta=@id AND Activo=1", this->conexion);
        sentenciaSQL->Parameters->AddWithValue("@id", id);
        bool eliminado = sentenciaSQL->ExecuteNonQuery() > 0;
        cerrarConexion();
        return eliminado;
    }

    bool RecetaController::RestaurarRecetaTXT(int id, String^% mensajeError) {
        mensajeError = "";
        abrirConexion();

        SqlCommand^ validar = gcnew SqlCommand(
            "SELECT r.idPaciente, r.idMedicamento, "
            "CASE WHEN p.idPaciente IS NULL THEN -1 ELSE p.Activo END AS pacienteActivo, "
            "CASE WHEN m.idMedicamento IS NULL THEN -1 ELSE m.Activo END AS medicamentoActivo "
            "FROM Recetas r "
            "LEFT JOIN Pacientes p ON p.idPaciente = r.idPaciente "
            "LEFT JOIN Medicamentos m ON m.idMedicamento = r.idMedicamento "
            "WHERE r.idReceta=@id AND r.Activo=0", this->conexion);
        validar->Parameters->AddWithValue("@id", id);
        SqlDataReader^ data = validar->ExecuteReader();

        if (!data->Read()) {
            data->Close();
            cerrarConexion();
            mensajeError = "La receta seleccionada ya no esta disponible para restaurar.";
            return false;
        }

        int pacienteActivo = Convert::ToInt32(data["pacienteActivo"]);
        int medicamentoActivo = Convert::ToInt32(data["medicamentoActivo"]);
        data->Close();

        if (pacienteActivo != 1) {
            cerrarConexion();
            mensajeError = "No se puede restaurar la receta porque el paciente asociado sigue inactivo.";
            return false;
        }

        if (medicamentoActivo != 1) {
            cerrarConexion();
            mensajeError = "No se puede restaurar la receta porque el medicamento asociado sigue inactivo.";
            return false;
        }

        SqlCommand^ restaurar = gcnew SqlCommand(
            "UPDATE Recetas SET Activo=1 WHERE idReceta=@id AND Activo=0", this->conexion);
        restaurar->Parameters->AddWithValue("@id", id);
        bool restaurado = restaurar->ExecuteNonQuery() > 0;
        cerrarConexion();

        if (!restaurado)
            mensajeError = "No se pudo restaurar la receta seleccionada.";

        return restaurado;
    }

    bool RecetaController::ValidarReceta(int idPaciente, Medicamento^ medicamento, int dosisDiaria, List<TimeSpan>^ horarios, String^% mensajeError) {
        mensajeError = "";

        if (idPaciente <= 0) {
            mensajeError = "Seleccione un paciente valido.";
            return false;
        }

        PacienteController^ pacienteController = gcnew PacienteController();
        if (pacienteController->BuscarPacientePorIdTXT(idPaciente) == nullptr) {
            mensajeError = "El paciente seleccionado no existe.";
            return false;
        }

        if (medicamento == nullptr) {
            mensajeError = "Seleccione un medicamento valido.";
            return false;
        }

        MedicamentoController^ medicamentoController = gcnew MedicamentoController();
        if (medicamentoController->BuscarMedicamentoPorIdTXT(medicamento->getId()) == nullptr) {
            mensajeError = "El medicamento seleccionado no existe.";
            return false;
        }

        if (dosisDiaria <= 0) {
            mensajeError = "La dosis diaria debe ser mayor que cero.";
            return false;
        }

        if (horarios == nullptr || horarios->Count == 0) {
            mensajeError = "Debe registrar al menos una hora programada.";
            return false;
        }

        if (horarios->Count != dosisDiaria) {
            mensajeError = "Debe registrar exactamente una hora por cada dosis diaria.";
            return false;
        }

        if (ContieneHorasDuplicadas(horarios)) {
            mensajeError = "No se permiten horas repetidas en la misma receta.";
            return false;
        }

        return true;
    }

    List<TimeSpan>^ RecetaController::GenerarHorariosPorFrecuencia(TimeSpan horaInicial, int frecuenciaHoras, int cantidadDosis, String^% mensajeError) {
        mensajeError = "";

        if (frecuenciaHoras <= 0) {
            mensajeError = "La frecuencia debe ser mayor que cero.";
            return nullptr;
        }

        if (cantidadDosis <= 0) {
            mensajeError = "Ingrese una dosis diaria valida antes de generar horarios.";
            return nullptr;
        }

        List<TimeSpan>^ horarios = gcnew List<TimeSpan>();
        DateTime inicio = DateTime(2000, 1, 1, horaInicial.Hours, horaInicial.Minutes, 0);

        for (int i = 0; i < cantidadDosis; i++)
            horarios->Add(NormalizarHora(inicio.AddHours(frecuenciaHoras * i).TimeOfDay));

        if (ContieneHorasDuplicadas(horarios)) {
            mensajeError = "La frecuencia seleccionada genera horas repetidas para la cantidad de dosis indicada.";
            return nullptr;
        }

        return horarios;
    }

    bool RecetaController::RegistrarRecetaConHorarios(int idPaciente, Medicamento^ medicamento, int dosisDiaria, List<TimeSpan>^ horarios, int% idRecetaGenerado, String^% mensajeError) {
        idRecetaGenerado = 0;
        if (!ValidarReceta(idPaciente, medicamento, dosisDiaria, horarios, mensajeError))
            return false;

        SqlTransaction^ transaccion = nullptr;

        try {
            abrirConexion();
            transaccion = this->conexion->BeginTransaction();

            SqlCommand^ obtenerReceta = gcnew SqlCommand(
                "SELECT ISNULL(MAX(idReceta), 0) + 1 FROM Recetas", this->conexion, transaccion);
            int idReceta = Convert::ToInt32(obtenerReceta->ExecuteScalar());

            SqlCommand^ insertarReceta = gcnew SqlCommand(
                "INSERT INTO Recetas(idReceta,idPaciente,idMedicamento,dosisDiaria,dosisTomada,Activo) "
                "VALUES(@idReceta,@idPaciente,@idMedicamento,@dosisDiaria,@dosisTomada,1)",
                this->conexion, transaccion);
            insertarReceta->Parameters->AddWithValue("@idReceta", idReceta);
            insertarReceta->Parameters->AddWithValue("@idPaciente", idPaciente);
            insertarReceta->Parameters->AddWithValue("@idMedicamento", medicamento->getId());
            insertarReceta->Parameters->AddWithValue("@dosisDiaria", dosisDiaria);
            insertarReceta->Parameters->AddWithValue("@dosisTomada", Convert::ToInt32(0));

            if (insertarReceta->ExecuteNonQuery() <= 0) {
                mensajeError = "No se pudo registrar la receta.";
                transaccion->Rollback();
                cerrarConexion();
                return false;
            }

            SqlCommand^ obtenerHorario = gcnew SqlCommand(
                "SELECT ISNULL(MAX(idHorario), 0) + 1 FROM HorariosReceta", this->conexion, transaccion);
            int idHorario = Convert::ToInt32(obtenerHorario->ExecuteScalar());

            for each (TimeSpan hora in horarios) {
                SqlCommand^ insertarHorario = gcnew SqlCommand(
                    "INSERT INTO HorariosReceta(idHorario,idReceta,horaProgramada) "
                    "VALUES(@idHorario,@idReceta,@horaProgramada)", this->conexion, transaccion);
                insertarHorario->Parameters->AddWithValue("@idHorario", idHorario++);
                insertarHorario->Parameters->AddWithValue("@idReceta", idReceta);
                insertarHorario->Parameters->AddWithValue("@horaProgramada", NormalizarHora(hora));

                if (insertarHorario->ExecuteNonQuery() <= 0) {
                    mensajeError = "No se pudieron registrar todos los horarios.";
                    transaccion->Rollback();
                    cerrarConexion();
                    return false;
                }
            }

            transaccion->Commit();
            cerrarConexion();
            idRecetaGenerado = idReceta;
            return true;
        }
        catch (Exception^) {
            if (transaccion != nullptr)
                transaccion->Rollback();
            if (this->conexion->State != System::Data::ConnectionState::Closed)
                cerrarConexion();
            mensajeError = "Ocurrio un error al registrar la receta y sus horarios.";
            return false;
        }
    }

    bool RecetaController::ModificarRecetaConHorarios(int idReceta, int idPaciente, Medicamento^ medicamento, int dosisDiaria, int dosisTomada, List<TimeSpan>^ horarios, String^% mensajeError) {
        if (!ValidarReceta(idPaciente, medicamento, dosisDiaria, horarios, mensajeError))
            return false;

        SqlTransaction^ transaccion = nullptr;

        try {
            abrirConexion();
            transaccion = this->conexion->BeginTransaction();

            SqlCommand^ actualizarReceta = gcnew SqlCommand(
                "UPDATE Recetas SET idPaciente=@idPaciente,idMedicamento=@idMedicamento,"
                "dosisDiaria=@dosisDiaria,dosisTomada=@dosisTomada WHERE idReceta=@idReceta AND Activo=1",
                this->conexion, transaccion);
            actualizarReceta->Parameters->AddWithValue("@idPaciente", idPaciente);
            actualizarReceta->Parameters->AddWithValue("@idMedicamento", medicamento->getId());
            actualizarReceta->Parameters->AddWithValue("@dosisDiaria", dosisDiaria);
            actualizarReceta->Parameters->AddWithValue("@dosisTomada", dosisTomada);
            actualizarReceta->Parameters->AddWithValue("@idReceta", idReceta);

            if (actualizarReceta->ExecuteNonQuery() <= 0) {
                mensajeError = "No se encontro la receta que desea modificar.";
                transaccion->Rollback();
                cerrarConexion();
                return false;
            }

            SqlCommand^ eliminarHorarios = gcnew SqlCommand(
                "DELETE FROM HorariosReceta WHERE idReceta=@idReceta", this->conexion, transaccion);
            eliminarHorarios->Parameters->AddWithValue("@idReceta", idReceta);
            eliminarHorarios->ExecuteNonQuery();

            SqlCommand^ obtenerHorario = gcnew SqlCommand(
                "SELECT ISNULL(MAX(idHorario), 0) + 1 FROM HorariosReceta", this->conexion, transaccion);
            int idHorario = Convert::ToInt32(obtenerHorario->ExecuteScalar());

            for each (TimeSpan hora in horarios) {
                SqlCommand^ insertarHorario = gcnew SqlCommand(
                    "INSERT INTO HorariosReceta(idHorario,idReceta,horaProgramada) "
                    "VALUES(@idHorario,@idReceta,@horaProgramada)", this->conexion, transaccion);
                insertarHorario->Parameters->AddWithValue("@idHorario", idHorario++);
                insertarHorario->Parameters->AddWithValue("@idReceta", idReceta);
                insertarHorario->Parameters->AddWithValue("@horaProgramada", NormalizarHora(hora));

                if (insertarHorario->ExecuteNonQuery() <= 0) {
                    mensajeError = "No se pudieron registrar todos los horarios actualizados.";
                    transaccion->Rollback();
                    cerrarConexion();
                    return false;
                }
            }

            transaccion->Commit();
            cerrarConexion();
            return true;
        }
        catch (Exception^) {
            if (transaccion != nullptr)
                transaccion->Rollback();
            if (this->conexion->State != System::Data::ConnectionState::Closed)
                cerrarConexion();
            mensajeError = "Ocurrio un error al modificar la receta y sus horarios.";
            return false;
        }
    }

    Receta^ RecetaController::BuscarRecetaPorIdTXT(int id) {
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "SELECT r.idReceta, r.idPaciente, r.dosisDiaria, r.dosisTomada, "
            "m.idMedicamento, m.nombre, m.tamano "
            "FROM Recetas r "
            "INNER JOIN Medicamentos m ON m.idMedicamento = r.idMedicamento AND m.Activo = 1 "
            "WHERE r.idReceta=@id AND r.Activo=1",
            this->conexion);
        sentenciaSQL->Parameters->AddWithValue("@id", id);
        SqlDataReader^ data = sentenciaSQL->ExecuteReader();
        Receta^ receta = nullptr;

        if (data->Read()) {
            Medicamento^ medicamento = gcnew Medicamento(
                Convert::ToInt32(data["idMedicamento"]),
                Convert::ToString(data["nombre"]),
                Convert::ToString(data["tamano"]));

            receta = gcnew Receta(
                Convert::ToInt32(data["idReceta"]),
                Convert::ToInt32(data["idPaciente"]),
                medicamento,
                Convert::ToInt32(data["dosisDiaria"]),
                Convert::ToInt32(data["dosisTomada"]));
        }

        data->Close();
        cerrarConexion();
        return receta;
    }

    List<Receta^>^ RecetaController::BuscarRecetaPorIdListaTXT(int id) {
        List<Receta^>^ resultados = gcnew List<Receta^>();
        Receta^ receta = BuscarRecetaPorIdTXT(id);
        if (receta != nullptr)
            resultados->Add(receta);
        return resultados;
    }

    List<Receta^>^ RecetaController::BuscarRecetasActivasPorCronogramaIdTXT(int id) {
        List<Receta^>^ resultados = gcnew List<Receta^>();
        for each (Receta ^ receta in ObtenerTodosRecetasTXT())
            if (receta->getIdPaciente() == id)
                resultados->Add(receta);
        return resultados;
    }
}
