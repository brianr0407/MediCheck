#include "pch.h"
#include "GeneradorReportesController.h"
#include "ConexionBD.h"

namespace CONTROLLER {
    GeneradorReportesController::GeneradorReportesController() {
        this->conexion = ConexionBD::CrearConexion();
        this->eventos = gcnew List<LogEvento^>();
        this->generador = gcnew MODEL::GeneradorReportes(this->eventos);
        this->datosCargados = false;
        CargarDatos();
    }

    GeneradorReportesController::GeneradorReportesController(String^ rutaArchivo) {
        this->conexion = ConexionBD::CrearConexion();
        this->eventos = gcnew List<LogEvento^>();
        this->generador = gcnew MODEL::GeneradorReportes(this->eventos);
        this->datosCargados = false;
        CargarDatos();
    }

    void GeneradorReportesController::abrirConexion() {
        if (this->conexion == nullptr)
            this->conexion = ConexionBD::CrearConexion();
        if (this->conexion->State != System::Data::ConnectionState::Open)
            this->conexion->Open();
    }

    void GeneradorReportesController::cerrarConexion() {
        if (this->conexion != nullptr && this->conexion->State != System::Data::ConnectionState::Closed)
            this->conexion->Close();
    }

    String^ GeneradorReportesController::Limpiar(String^ valor) {
        return String::IsNullOrWhiteSpace(valor) ? "" : valor->Trim();
    }

    int GeneradorReportesController::ObtenerSiguienteId() {
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "SELECT ISNULL(MAX(idEvento), 0) + 1 FROM LogEventos", this->conexion);
        int id = Convert::ToInt32(sentenciaSQL->ExecuteScalar());
        cerrarConexion();
        return id;
    }

    LogEvento^ GeneradorReportesController::CrearEvento(
        int idPaciente,
        String^ nombrePaciente,
        int idMedicamento,
        String^ medicamento,
        String^ tipoEvento,
        String^ estado,
        String^ origen,
        DateTime fechaHoraProgramada,
        DateTime fechaHoraReal,
        int cantidad,
        String^ detalle)
    {
        if (String::IsNullOrWhiteSpace(tipoEvento))
            throw gcnew ArgumentException("Debe seleccionar un tipo de evento.");
        if (String::IsNullOrWhiteSpace(estado))
            throw gcnew ArgumentException("Debe seleccionar un estado.");
        if (cantidad < 0)
            throw gcnew ArgumentException("La cantidad no puede ser negativa.");

        return gcnew LogEvento(
            0, Math::Max(0, idPaciente), Limpiar(nombrePaciente),
            Math::Max(0, idMedicamento), Limpiar(medicamento),
            Limpiar(tipoEvento), Limpiar(estado), Limpiar(origen),
            fechaHoraProgramada, fechaHoraReal, cantidad, Limpiar(detalle));
    }

    void GeneradorReportesController::AgregarEvento(LogEvento^ evento) {
        if (evento == nullptr)
            throw gcnew ArgumentNullException("evento");

        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "INSERT INTO LogEventos(idPaciente,nombrePaciente,idMedicamento,medicamento,"
            "tipoEvento,estado,origen,fechaHoraProgramada,fechaHoraReal,cantidad,detalle) "
            "VALUES(@idPaciente,@nombrePaciente,@idMedicamento,@medicamento,"
            "@tipoEvento,@estado,@origen,@programada,@real,@cantidad,@detalle); "
            "SELECT CAST(SCOPE_IDENTITY() AS INT);", this->conexion);
        sentenciaSQL->Parameters->AddWithValue("@idPaciente", evento->getIdPaciente());
        sentenciaSQL->Parameters->AddWithValue("@nombrePaciente", evento->getNombrePaciente());
        sentenciaSQL->Parameters->AddWithValue("@idMedicamento", evento->getIdMedicamento());
        sentenciaSQL->Parameters->AddWithValue("@medicamento", evento->getMedicamento());
        sentenciaSQL->Parameters->AddWithValue("@tipoEvento", evento->getTipoEvento());
        sentenciaSQL->Parameters->AddWithValue("@estado", evento->getEstado());
        sentenciaSQL->Parameters->AddWithValue("@origen", evento->getOrigen());
        sentenciaSQL->Parameters->AddWithValue("@programada", evento->getFechaHoraProgramada());
        sentenciaSQL->Parameters->AddWithValue("@real", evento->getFechaHoraReal() == DateTime::MinValue
            ? safe_cast<Object^>(DBNull::Value) : evento->getFechaHoraReal());
        sentenciaSQL->Parameters->AddWithValue("@cantidad", evento->getCantidad());
        sentenciaSQL->Parameters->AddWithValue("@detalle", evento->getDetalle());
        evento->setId(Convert::ToInt32(sentenciaSQL->ExecuteScalar()));
        cerrarConexion();
        RefrescarDatos();
    }

    void GeneradorReportesController::ActualizarEvento(LogEvento^ evento) {
        if (evento == nullptr)
            throw gcnew ArgumentNullException("evento");

        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "UPDATE LogEventos SET idPaciente=@idPaciente,nombrePaciente=@nombrePaciente,"
            "idMedicamento=@idMedicamento,medicamento=@medicamento,tipoEvento=@tipoEvento,"
            "estado=@estado,origen=@origen,fechaHoraProgramada=@programada,"
            "fechaHoraReal=@real,cantidad=@cantidad,detalle=@detalle WHERE idEvento=@idEvento",
            this->conexion);
        sentenciaSQL->Parameters->AddWithValue("@idPaciente", evento->getIdPaciente());
        sentenciaSQL->Parameters->AddWithValue("@nombrePaciente", evento->getNombrePaciente());
        sentenciaSQL->Parameters->AddWithValue("@idMedicamento", evento->getIdMedicamento());
        sentenciaSQL->Parameters->AddWithValue("@medicamento", evento->getMedicamento());
        sentenciaSQL->Parameters->AddWithValue("@tipoEvento", evento->getTipoEvento());
        sentenciaSQL->Parameters->AddWithValue("@estado", evento->getEstado());
        sentenciaSQL->Parameters->AddWithValue("@origen", evento->getOrigen());
        sentenciaSQL->Parameters->AddWithValue("@programada", evento->getFechaHoraProgramada());
        sentenciaSQL->Parameters->AddWithValue("@real", evento->getFechaHoraReal() == DateTime::MinValue
            ? safe_cast<Object^>(DBNull::Value) : evento->getFechaHoraReal());
        sentenciaSQL->Parameters->AddWithValue("@cantidad", evento->getCantidad());
        sentenciaSQL->Parameters->AddWithValue("@detalle", evento->getDetalle());
        sentenciaSQL->Parameters->AddWithValue("@idEvento", evento->getId());
        int filas = sentenciaSQL->ExecuteNonQuery();
        cerrarConexion();
        if (filas == 0)
            throw gcnew KeyNotFoundException("No se encontro el evento que desea editar.");
        RefrescarDatos();
    }

    void GeneradorReportesController::EliminarEvento(int id) {
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "DELETE FROM LogEventos WHERE idEvento=@id", this->conexion);
        sentenciaSQL->Parameters->AddWithValue("@id", id);
        int filas = sentenciaSQL->ExecuteNonQuery();
        cerrarConexion();
        if (filas == 0)
            throw gcnew KeyNotFoundException("No se encontro el evento que desea eliminar.");
        RefrescarDatos();
    }

    LogEvento^ GeneradorReportesController::BuscarPorId(int id) {
        for each (LogEvento ^ evento in this->eventos)
            if (evento->getId() == id)
                return evento;
        return nullptr;
    }

    List<LogEvento^>^ GeneradorReportesController::ObtenerTodos() {
        return gcnew List<LogEvento^>(this->eventos);
    }

    List<LogEvento^>^ GeneradorReportesController::ObtenerEventosReporte(String^ nombreReporte) {
        return this->generador->ObtenerEventosReporte(nombreReporte);
    }

    Dictionary<String^, double>^ GeneradorReportesController::ObtenerValoresGrafico(String^ nombreReporte) {
        return this->generador->ObtenerValoresGrafico(nombreReporte);
    }

    String^ GeneradorReportesController::GenerarResumen(String^ nombreReporte) {
        return this->generador->GenerarResumen(nombreReporte);
    }

    String^ GeneradorReportesController::ClasificarPuntualidad(LogEvento^ evento) {
        return this->generador->ClasificarPuntualidad(evento);
    }

    double GeneradorReportesController::ObtenerPorcentajeCumplimientoGlobal() {
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "SELECT "
            "SUM(CASE WHEN (tipoEvento LIKE '%Dosis%' OR tipoEvento LIKE '%Toma%') AND estado NOT LIKE '%Pausa%' THEN 1 ELSE 0 END) AS programadas, "
            "SUM(CASE WHEN (tipoEvento LIKE '%Dosis%' OR tipoEvento LIKE '%Toma%') "
            "AND estado NOT LIKE '%Pausa%' "
            "AND (estado LIKE '%Tomada%' OR estado LIKE '%A tiempo%' OR estado LIKE '%Retraso%' OR estado LIKE '%Exitosa%') "
            "THEN 1 ELSE 0 END) AS tomadas "
            "FROM LogEventos",
            this->conexion);
        SqlDataReader^ data = sentenciaSQL->ExecuteReader();
        double porcentaje = -1.0;

        if (data->Read()) {
            int programadas = data["programadas"] == DBNull::Value ? 0 : Convert::ToInt32(data["programadas"]);
            int tomadas = data["tomadas"] == DBNull::Value ? 0 : Convert::ToInt32(data["tomadas"]);
            porcentaje = programadas <= 0 ? -1.0 : (tomadas * 100.0 / programadas);
        }

        data->Close();
        cerrarConexion();
        return porcentaje;
    }

    void GeneradorReportesController::CargarDatos() {
        if (this->datosCargados)
            return;

        this->eventos->Clear();
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "SELECT idEvento,idPaciente,nombrePaciente,idMedicamento,medicamento,tipoEvento,"
            "estado,origen,fechaHoraProgramada,fechaHoraReal,cantidad,detalle "
            "FROM LogEventos ORDER BY fechaHoraProgramada DESC, idEvento DESC",
            this->conexion);
        SqlDataReader^ data = sentenciaSQL->ExecuteReader();

        while (data->Read()) {
            int idEvento = data["idEvento"] == DBNull::Value ? 0 : Convert::ToInt32(data["idEvento"]);
            int idPaciente = data["idPaciente"] == DBNull::Value ? 0 : Convert::ToInt32(data["idPaciente"]);
            String^ nombrePaciente = data["nombrePaciente"] == DBNull::Value ? "" : Convert::ToString(data["nombrePaciente"]);
            int idMedicamento = data["idMedicamento"] == DBNull::Value ? 0 : Convert::ToInt32(data["idMedicamento"]);
            String^ medicamento = data["medicamento"] == DBNull::Value ? "" : Convert::ToString(data["medicamento"]);
            String^ tipoEvento = data["tipoEvento"] == DBNull::Value ? "" : Convert::ToString(data["tipoEvento"]);
            String^ estado = data["estado"] == DBNull::Value ? "" : Convert::ToString(data["estado"]);
            String^ origen = data["origen"] == DBNull::Value ? "" : Convert::ToString(data["origen"]);
            DateTime fechaProgramada = data["fechaHoraProgramada"] == DBNull::Value
                ? DateTime::MinValue : Convert::ToDateTime(data["fechaHoraProgramada"]);
            DateTime fechaReal = data["fechaHoraReal"] == DBNull::Value
                ? DateTime::MinValue : Convert::ToDateTime(data["fechaHoraReal"]);
            int cantidad = data["cantidad"] == DBNull::Value ? 0 : Convert::ToInt32(data["cantidad"]);
            String^ detalle = data["detalle"] == DBNull::Value ? "" : Convert::ToString(data["detalle"]);

            this->eventos->Add(gcnew LogEvento(
                idEvento, idPaciente, nombrePaciente, idMedicamento, medicamento,
                tipoEvento, estado, origen, fechaProgramada, fechaReal, cantidad, detalle));
        }

        data->Close();
        cerrarConexion();
        this->generador->setLogEventos(this->eventos);
        this->datosCargados = true;
    }

    void GeneradorReportesController::RefrescarDatos() {
        this->datosCargados = false;
        CargarDatos();
    }

    void GeneradorReportesController::GuardarDatos() {
        // Cada cambio se guarda directamente con INSERT, UPDATE o DELETE.
    }
}
