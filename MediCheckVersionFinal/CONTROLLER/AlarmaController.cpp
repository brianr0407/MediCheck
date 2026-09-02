#include "pch.h"
#include "AlarmaController.h"
#include "ConexionBD.h"

namespace CONTROLLER {
    AlarmaController::AlarmaController() {
        this->listaAlarmas = gcnew List<Alarma^>();
        this->conexion = ConexionBD::CrearConexion();
    }

    AlarmaController::AlarmaController(List<Alarma^>^ listaAlarmas) {
        this->listaAlarmas = listaAlarmas;
        this->conexion = ConexionBD::CrearConexion();
    }

    void AlarmaController::abrirConexion() {
        if (this->conexion == nullptr)
            this->conexion = ConexionBD::CrearConexion();
        if (this->conexion->State != System::Data::ConnectionState::Open)
            this->conexion->Open();
    }

    void AlarmaController::cerrarConexion() {
        if (this->conexion != nullptr && this->conexion->State != System::Data::ConnectionState::Closed)
            this->conexion->Close();
    }

    void AlarmaController::InicializarArchivos() {
        // Ya no se crean archivos: la tabla Alarmas reemplaza la persistencia TXT.
    }

void AlarmaController::AgregarAlBackup(Alarma^ alarma) {
    // Respaldo delegado a la base de datos.
}

void AlarmaController::ActualizarBackup(Alarma^ alarma) {
    // Respaldo delegado a la base de datos.
}

    String^ AlarmaController::FormatearLinea(Alarma^ alarma) {
        AlarmaSnooze^ snooze = dynamic_cast<AlarmaSnooze^>(alarma);
        return snooze == nullptr ? "0" : snooze->getTiempoDeEspera().ToString();
    }

    int AlarmaController::ObtenerSiguienteId() {
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "SELECT ISNULL(MAX(idAlarma), 0) + 1 FROM Alarmas", this->conexion);
        int id = Convert::ToInt32(sentenciaSQL->ExecuteScalar());
        cerrarConexion();
        return id;
    }

    void AlarmaController::EscribirArchivo(List<Alarma^>^ listaAlarmas) {
        abrirConexion();
        SqlCommand^ eliminar = gcnew SqlCommand("DELETE FROM Alarmas", this->conexion);
        eliminar->ExecuteNonQuery();
        cerrarConexion();
        for each (Alarma ^ alarma in listaAlarmas)
            AgregarAlarmaTXT(alarma);
    }

    List<Alarma^>^ AlarmaController::ObtenerTodasAlarmasTXT() {
        List<Alarma^>^ lista = gcnew List<Alarma^>();
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "SELECT idAlarma,estado,tipo,extra FROM Alarmas", this->conexion);
        SqlDataReader^ data = sentenciaSQL->ExecuteReader();

        while (data->Read()) {
            int id = Convert::ToInt32(data["idAlarma"]);
            bool estado = Convert::ToBoolean(data["estado"]);
            String^ tipo = Convert::ToString(data["tipo"]);
            String^ extra = data["extra"] == DBNull::Value ? "0" : Convert::ToString(data["extra"]);
            if (tipo == "Snooze")
                lista->Add(gcnew AlarmaSnooze(id, estado, Convert::ToInt32(extra)));
            else
                lista->Add(gcnew AlarmaCritica(id, estado));
        }

        data->Close();
        cerrarConexion();
        return lista;
    }

    int AlarmaController::ObtenerCantidadAlarmas() {
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "SELECT COUNT(*) FROM Alarmas", this->conexion);
        int cantidad = Convert::ToInt32(sentenciaSQL->ExecuteScalar());
        cerrarConexion();
        return cantidad;
    }

    bool AlarmaController::AgregarAlarmaTXT(Alarma^ alarma) {
        String^ tipo = dynamic_cast<AlarmaSnooze^>(alarma) != nullptr ? "Snooze" : "Critica";
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "INSERT INTO Alarmas(idAlarma,estado,tipo,extra) VALUES(@id,@estado,@tipo,@extra)",
            this->conexion);
        sentenciaSQL->Parameters->AddWithValue("@id", alarma->getId());
        sentenciaSQL->Parameters->AddWithValue("@estado", alarma->getEstado());
        sentenciaSQL->Parameters->AddWithValue("@tipo", tipo);
        sentenciaSQL->Parameters->AddWithValue("@extra", FormatearLinea(alarma));
        bool agregado = sentenciaSQL->ExecuteNonQuery() > 0;
        cerrarConexion();
        return agregado;
    }

    bool AlarmaController::EliminarAlarmaTXT(int id) {
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "DELETE FROM Alarmas WHERE idAlarma=@id", this->conexion);
        sentenciaSQL->Parameters->AddWithValue("@id", id);
        bool eliminado = sentenciaSQL->ExecuteNonQuery() > 0;
        cerrarConexion();
        return eliminado;
    }

    bool AlarmaController::ActualizarArchivo(Alarma^ alarma) {
        String^ tipo = dynamic_cast<AlarmaSnooze^>(alarma) != nullptr ? "Snooze" : "Critica";
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "UPDATE Alarmas SET estado=@estado,tipo=@tipo,extra=@extra WHERE idAlarma=@id",
            this->conexion);
        sentenciaSQL->Parameters->AddWithValue("@estado", alarma->getEstado());
        sentenciaSQL->Parameters->AddWithValue("@tipo", tipo);
        sentenciaSQL->Parameters->AddWithValue("@extra", FormatearLinea(alarma));
        sentenciaSQL->Parameters->AddWithValue("@id", alarma->getId());
        bool actualizado = sentenciaSQL->ExecuteNonQuery() > 0;
        cerrarConexion();
        return actualizado;
    }

    Alarma^ AlarmaController::BuscarAlarmaPorIdTXT(int id) {
        for each (Alarma ^ alarma in ObtenerTodasAlarmasTXT())
            if (alarma->getId() == id)
                return alarma;
        return nullptr;
    }
}
