#include "pch.h"
#include "MedicamentoController.h"
#include "ConexionBD.h"

namespace CONTROLLER {
    MedicamentoController::MedicamentoController() {
        this->listaMedicamentos = gcnew List<Medicamento^>();
        this->conexion = ConexionBD::CrearConexion();
    }

    MedicamentoController::MedicamentoController(List<Medicamento^>^ listaMedicamentos) {
        this->listaMedicamentos = listaMedicamentos;
        this->conexion = ConexionBD::CrearConexion();
    }

    void MedicamentoController::abrirConexion() {
        if (this->conexion == nullptr)
            this->conexion = ConexionBD::CrearConexion();
        if (this->conexion->State != System::Data::ConnectionState::Open)
            this->conexion->Open();
    }

    void MedicamentoController::cerrarConexion() {
        if (this->conexion != nullptr && this->conexion->State != System::Data::ConnectionState::Closed)
            this->conexion->Close();
    }

    void MedicamentoController::AgregarAlBackup(Medicamento^ medicamento) {
        // Respaldo delegado a la base de datos.
    }

    void MedicamentoController::ActualizarBackup(Medicamento^ medicamento) {
        // Respaldo delegado a la base de datos.
    }

    int MedicamentoController::ObtenerSiguienteId() {
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "SELECT ISNULL(MAX(idMedicamento), 0) + 1 FROM Medicamentos", this->conexion);
        int id = Convert::ToInt32(sentenciaSQL->ExecuteScalar());
        cerrarConexion();
        return id;
    }

    void MedicamentoController::EscribirArchivo(List<Medicamento^>^ listaMedicamentos) {
        abrirConexion();
        SqlCommand^ desactivar = gcnew SqlCommand("UPDATE Medicamentos SET Activo=0", this->conexion);
        desactivar->ExecuteNonQuery();

        for each (Medicamento ^ medicamento in listaMedicamentos) {
            Antibiotico^ antibiotico = dynamic_cast<Antibiotico^>(medicamento);
            SuplementoVitaminico^ suplemento = dynamic_cast<SuplementoVitaminico^>(medicamento);
            String^ clase = antibiotico != nullptr ? "Antibiotico" : "Suplemento";
            String^ extra = antibiotico != nullptr
                ? antibiotico->getEsPrioridadCritica().ToString()->ToLower()
                : suplemento->getTipo();

            SqlCommand^ actualizar = gcnew SqlCommand(
                "UPDATE Medicamentos SET nombre=@nombre,tamano=@tamano,clase=@clase,extra=@extra,Activo=1 "
                "WHERE idMedicamento=@id", this->conexion);
            actualizar->Parameters->AddWithValue("@nombre", medicamento->getNombre());
            actualizar->Parameters->AddWithValue("@tamano", medicamento->getTamano());
            actualizar->Parameters->AddWithValue("@clase", clase);
            actualizar->Parameters->AddWithValue("@extra", extra);
            actualizar->Parameters->AddWithValue("@id", medicamento->getId());

            if (actualizar->ExecuteNonQuery() <= 0) {
                SqlCommand^ insertar = gcnew SqlCommand(
                    "INSERT INTO Medicamentos(idMedicamento,nombre,tamano,clase,extra,Activo) "
                    "VALUES(@id,@nombre,@tamano,@clase,@extra,1)", this->conexion);
                insertar->Parameters->AddWithValue("@id", medicamento->getId());
                insertar->Parameters->AddWithValue("@nombre", medicamento->getNombre());
                insertar->Parameters->AddWithValue("@tamano", medicamento->getTamano());
                insertar->Parameters->AddWithValue("@clase", clase);
                insertar->Parameters->AddWithValue("@extra", extra);
                insertar->ExecuteNonQuery();
            }
        }

        cerrarConexion();
    }

    String^ MedicamentoController::ObtenerTipo(Medicamento^ medicamento) {
        if (dynamic_cast<Antibiotico^>(medicamento) != nullptr)
            return "Antibiotico";
        if (dynamic_cast<SuplementoVitaminico^>(medicamento) != nullptr)
            return "SuplementoVitaminico";
        return "Desconocido";
    }

    bool MedicamentoController::ActualizarArchivo(Medicamento^ medicamento) {
        Antibiotico^ antibiotico = dynamic_cast<Antibiotico^>(medicamento);
        SuplementoVitaminico^ suplemento = dynamic_cast<SuplementoVitaminico^>(medicamento);
        String^ clase = antibiotico != nullptr ? "Antibiotico" : "Suplemento";
        String^ extra = antibiotico != nullptr
            ? antibiotico->getEsPrioridadCritica().ToString()->ToLower()
            : suplemento->getTipo();

        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "UPDATE Medicamentos SET nombre=@nombre, tamano=@tamano, clase=@clase, extra=@extra "
            "WHERE idMedicamento=@id AND Activo=1", this->conexion);
        sentenciaSQL->Parameters->AddWithValue("@nombre", medicamento->getNombre());
        sentenciaSQL->Parameters->AddWithValue("@tamano", medicamento->getTamano());
        sentenciaSQL->Parameters->AddWithValue("@clase", clase);
        sentenciaSQL->Parameters->AddWithValue("@extra", extra);
        sentenciaSQL->Parameters->AddWithValue("@id", medicamento->getId());
        bool actualizado = sentenciaSQL->ExecuteNonQuery() > 0;
        cerrarConexion();
        return actualizado;
    }

    List<Medicamento^>^ MedicamentoController::ObtenerTodosMedicamentosTXT() {
        List<Medicamento^>^ lista = gcnew List<Medicamento^>();
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "SELECT idMedicamento, nombre, tamano, clase, extra FROM Medicamentos "
            "WHERE Activo=1 ORDER BY idMedicamento", this->conexion);
        SqlDataReader^ data = sentenciaSQL->ExecuteReader();

        while (data->Read()) {
            int id = Convert::ToInt32(data["idMedicamento"]);
            String^ nombre = Convert::ToString(data["nombre"]);
            String^ tamano = Convert::ToString(data["tamano"]);
            String^ clase = Convert::ToString(data["clase"]);
            String^ extra = data["extra"] == DBNull::Value ? "" : Convert::ToString(data["extra"]);

            if (clase == "Antibiotico")
                lista->Add(gcnew Antibiotico(id, nombre, tamano, extra->ToLower() == "true"));
            else
                lista->Add(gcnew SuplementoVitaminico(id, nombre, tamano, extra));
        }

        data->Close();
        cerrarConexion();
        return lista;
    }

    List<Medicamento^>^ MedicamentoController::ObtenerMedicamentosInactivosTXT() {
        List<Medicamento^>^ lista = gcnew List<Medicamento^>();
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "SELECT idMedicamento, nombre, tamano, clase, extra FROM Medicamentos "
            "WHERE Activo=0 ORDER BY idMedicamento", this->conexion);
        SqlDataReader^ data = sentenciaSQL->ExecuteReader();

        while (data->Read()) {
            int id = Convert::ToInt32(data["idMedicamento"]);
            String^ nombre = Convert::ToString(data["nombre"]);
            String^ tamano = Convert::ToString(data["tamano"]);
            String^ clase = Convert::ToString(data["clase"]);
            String^ extra = data["extra"] == DBNull::Value ? "" : Convert::ToString(data["extra"]);

            if (clase == "Antibiotico")
                lista->Add(gcnew Antibiotico(id, nombre, tamano, extra->ToLower() == "true"));
            else
                lista->Add(gcnew SuplementoVitaminico(id, nombre, tamano, extra));
        }

        data->Close();
        cerrarConexion();
        return lista;
    }

    bool MedicamentoController::AgregarMedicamentoTXT(Medicamento^ medicamento) {
        if (medicamento == nullptr || !PuedeAgregarMedicamento())
            return false;

        Antibiotico^ antibiotico = dynamic_cast<Antibiotico^>(medicamento);
        SuplementoVitaminico^ suplemento = dynamic_cast<SuplementoVitaminico^>(medicamento);
        String^ clase = antibiotico != nullptr ? "Antibiotico" : "Suplemento";
        String^ extra = antibiotico != nullptr
            ? antibiotico->getEsPrioridadCritica().ToString()->ToLower()
            : suplemento->getTipo();

        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "INSERT INTO Medicamentos(idMedicamento,nombre,tamano,clase,extra,Activo) "
            "VALUES(@id,@nombre,@tamano,@clase,@extra,1)", this->conexion);
        sentenciaSQL->Parameters->AddWithValue("@id", medicamento->getId());
        sentenciaSQL->Parameters->AddWithValue("@nombre", medicamento->getNombre());
        sentenciaSQL->Parameters->AddWithValue("@tamano", medicamento->getTamano());
        sentenciaSQL->Parameters->AddWithValue("@clase", clase);
        sentenciaSQL->Parameters->AddWithValue("@extra", extra);
        bool agregado = sentenciaSQL->ExecuteNonQuery() > 0;
        cerrarConexion();
        return agregado;
    }

    bool MedicamentoController::EliminarMedicamentoTXT(int id) {
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "UPDATE Medicamentos SET Activo=0 WHERE idMedicamento=@id AND Activo=1", this->conexion);
        sentenciaSQL->Parameters->AddWithValue("@id", id);
        bool eliminado = sentenciaSQL->ExecuteNonQuery() > 0;
        cerrarConexion();
        return eliminado;
    }

    bool MedicamentoController::RestaurarMedicamentoTXT(int id) {
        if (!PuedeAgregarMedicamento())
            return false;

        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "UPDATE Medicamentos SET Activo=1 WHERE idMedicamento=@id AND Activo=0", this->conexion);
        sentenciaSQL->Parameters->AddWithValue("@id", id);
        bool restaurado = sentenciaSQL->ExecuteNonQuery() > 0;
        cerrarConexion();
        return restaurado;
    }

    int MedicamentoController::ObtenerCantidadMedicamentos() {
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "SELECT COUNT(*) FROM Medicamentos WHERE Activo=1", this->conexion);
        int cantidad = Convert::ToInt32(sentenciaSQL->ExecuteScalar());
        cerrarConexion();
        return cantidad;
    }

    bool MedicamentoController::PuedeAgregarMedicamento() {
        return ObtenerCantidadMedicamentos() < 4;
    }

    Medicamento^ MedicamentoController::BuscarMedicamentoPorIdTXT(int id) {
        Medicamento^ medicamento = nullptr;
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "SELECT idMedicamento,nombre,tamano,clase,extra FROM Medicamentos "
            "WHERE idMedicamento=@id AND Activo=1", this->conexion);
        sentenciaSQL->Parameters->AddWithValue("@id", id);
        SqlDataReader^ data = sentenciaSQL->ExecuteReader();

        if (data->Read()) {
            String^ nombre = Convert::ToString(data["nombre"]);
            String^ tamano = Convert::ToString(data["tamano"]);
            String^ clase = Convert::ToString(data["clase"]);
            String^ extra = data["extra"] == DBNull::Value ? "" : Convert::ToString(data["extra"]);
            medicamento = clase == "Antibiotico"
                ? safe_cast<Medicamento^>(gcnew Antibiotico(id, nombre, tamano, extra->ToLower() == "true"))
                : safe_cast<Medicamento^>(gcnew SuplementoVitaminico(id, nombre, tamano, extra));
        }

        data->Close();
        cerrarConexion();
        return medicamento;
    }

    List<Medicamento^>^ MedicamentoController::BuscarMedicamentosPorIdListaTXT(int id) {
        List<Medicamento^>^ resultados = gcnew List<Medicamento^>();
        Medicamento^ medicamento = BuscarMedicamentoPorIdTXT(id);
        if (medicamento != nullptr)
            resultados->Add(medicamento);
        return resultados;
    }
}
