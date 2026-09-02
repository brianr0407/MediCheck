#include "pch.h"
#include "CronogramaTomaController.h"
#include "RecetaController.h"
#include "ConexionBD.h"

namespace CONTROLLER {
    CronogramaTomaController::CronogramaTomaController() {
        this->listaCronogramasToma = gcnew List<CronogramaToma^>();
        this->conexion = ConexionBD::CrearConexion();
    }

    CronogramaTomaController::CronogramaTomaController(List<CronogramaToma^>^ listaCronogramasToma) {
        this->listaCronogramasToma = listaCronogramasToma;
        this->conexion = ConexionBD::CrearConexion();
    }

    void CronogramaTomaController::abrirConexion() {
        if (this->conexion == nullptr)
            this->conexion = ConexionBD::CrearConexion();
        if (this->conexion->State != System::Data::ConnectionState::Open)
            this->conexion->Open();
    }

    void CronogramaTomaController::cerrarConexion() {
        if (this->conexion != nullptr && this->conexion->State != System::Data::ConnectionState::Closed)
            this->conexion->Close();
    }

    void CronogramaTomaController::EscribirArchivo(List<CronogramaToma^>^ listaCronogramasToma) {
        abrirConexion();
        SqlCommand^ eliminar = gcnew SqlCommand("DELETE FROM CronogramasToma", this->conexion);
        eliminar->ExecuteNonQuery();
        cerrarConexion();
        for each (CronogramaToma ^ cronograma in listaCronogramasToma)
            AgregarCronogramaTomaTXT(cronograma);
    }

    bool CronogramaTomaController::ActualizarArchivo(CronogramaToma^ cronogramaToma) {
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "UPDATE CronogramasToma SET estaActivo=@estaActivo WHERE idCronograma=@id",
            this->conexion);
        sentenciaSQL->Parameters->AddWithValue("@estaActivo", cronogramaToma->getEstaActivo());
        sentenciaSQL->Parameters->AddWithValue("@id", cronogramaToma->getId());
        bool actualizado = sentenciaSQL->ExecuteNonQuery() > 0;
        cerrarConexion();
        return actualizado;
    }

    List<CronogramaToma^>^ CronogramaTomaController::ObtenerTodosCronogramasTomaTXT() {
        List<CronogramaToma^>^ lista = gcnew List<CronogramaToma^>();
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "SELECT idCronograma,estaActivo FROM CronogramasToma", this->conexion);
        SqlDataReader^ data = sentenciaSQL->ExecuteReader();
        RecetaController^ recetaController = gcnew RecetaController();

        while (data->Read()) {
            int id = Convert::ToInt32(data["idCronograma"]);
            List<Receta^>^ recetas = recetaController->BuscarRecetasActivasPorCronogramaIdTXT(id);
            lista->Add(gcnew CronogramaToma(id, recetas, Convert::ToBoolean(data["estaActivo"])));
        }

        data->Close();
        cerrarConexion();
        return lista;
    }

    bool CronogramaTomaController::AgregarCronogramaTomaTXT(CronogramaToma^ cronogramaToma) {
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "INSERT INTO CronogramasToma(idCronograma,estaActivo) VALUES(@id,@estaActivo)",
            this->conexion);
        sentenciaSQL->Parameters->AddWithValue("@id", cronogramaToma->getId());
        sentenciaSQL->Parameters->AddWithValue("@estaActivo", cronogramaToma->getEstaActivo());
        bool agregado = sentenciaSQL->ExecuteNonQuery() > 0;
        cerrarConexion();
        return agregado;
    }

    bool CronogramaTomaController::EliminarCronogramaTomaTXT(int id) {
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "DELETE FROM CronogramasToma WHERE idCronograma=@id", this->conexion);
        sentenciaSQL->Parameters->AddWithValue("@id", id);
        bool eliminado = sentenciaSQL->ExecuteNonQuery() > 0;
        cerrarConexion();
        return eliminado;
    }

    CronogramaToma^ CronogramaTomaController::BuscarCronogramaPorIdTXT(int id) {
        for each (CronogramaToma ^ cronograma in ObtenerTodosCronogramasTomaTXT())
            if (cronograma->getId() == id)
                return cronograma;
        return nullptr;
    }

    List<CronogramaToma^>^ CronogramaTomaController::BuscarCronogramasPorIdListaTXT(int id) {
        List<CronogramaToma^>^ resultados = gcnew List<CronogramaToma^>();
        CronogramaToma^ cronograma = BuscarCronogramaPorIdTXT(id);
        if (cronograma != nullptr)
            resultados->Add(cronograma);
        return resultados;
    }
}
