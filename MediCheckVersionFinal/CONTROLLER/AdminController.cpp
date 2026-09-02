#include "pch.h"
#include "AdminController.h"
#include "ConexionBD.h"

namespace CONTROLLER {
    AdminController::AdminController() {
        this->listaAdministradores = gcnew List<Administrador^>();
        this->conexion = ConexionBD::CrearConexion();
    }

    AdminController::AdminController(List<Administrador^>^ listaAdministradores) {
        this->listaAdministradores = listaAdministradores;
        this->conexion = ConexionBD::CrearConexion();
    }

    void AdminController::abrirConexion() {
        if (this->conexion == nullptr)
            this->conexion = ConexionBD::CrearConexion();
        if (this->conexion->State != System::Data::ConnectionState::Open)
            this->conexion->Open();
    }

    void AdminController::cerrarConexion() {
        if (this->conexion != nullptr && this->conexion->State != System::Data::ConnectionState::Closed)
            this->conexion->Close();
    }

    void AdminController::AgregarAlBackup(Administrador^ administrador) {
        // Respaldo delegado a la base de datos.
    }

    void AdminController::ActualizarBackup(Administrador^ administrador) {
        // Respaldo delegado a la base de datos.
    }

    int AdminController::ObtenerSiguienteId() {
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "SELECT ISNULL(MAX(idAdministrador), 0) + 1 FROM Administradores", this->conexion);
        int id = Convert::ToInt32(sentenciaSQL->ExecuteScalar());
        cerrarConexion();
        return id;
    }

    void AdminController::EscribirArchivo(List<Administrador^>^ listaAdministradores) {
        abrirConexion();
        SqlCommand^ desactivar = gcnew SqlCommand("UPDATE Administradores SET Activo=0", this->conexion);
        desactivar->ExecuteNonQuery();

        for each (Administrador ^ administrador in listaAdministradores) {
            SqlCommand^ actualizar = gcnew SqlCommand(
                "UPDATE Administradores SET nombre=@nombre,apellido=@apellido,pin=@pin,Activo=1 "
                "WHERE idAdministrador=@id", this->conexion);
            actualizar->Parameters->AddWithValue("@nombre", administrador->getNombre());
            actualizar->Parameters->AddWithValue("@apellido", administrador->getApellido());
            actualizar->Parameters->AddWithValue("@pin", administrador->getPIN());
            actualizar->Parameters->AddWithValue("@id", administrador->getId());

            if (actualizar->ExecuteNonQuery() <= 0) {
                SqlCommand^ insertar = gcnew SqlCommand(
                    "INSERT INTO Administradores(idAdministrador,nombre,apellido,pin,Activo) "
                    "VALUES(@id,@nombre,@apellido,@pin,1)", this->conexion);
                insertar->Parameters->AddWithValue("@id", administrador->getId());
                insertar->Parameters->AddWithValue("@nombre", administrador->getNombre());
                insertar->Parameters->AddWithValue("@apellido", administrador->getApellido());
                insertar->Parameters->AddWithValue("@pin", administrador->getPIN());
                insertar->ExecuteNonQuery();
            }
        }

        cerrarConexion();
    }

    bool AdminController::ActualizarArchivo(Administrador^ administrador) {
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "UPDATE Administradores SET nombre=@nombre,apellido=@apellido,pin=@pin "
            "WHERE idAdministrador=@id AND Activo=1", this->conexion);
        sentenciaSQL->Parameters->AddWithValue("@nombre", administrador->getNombre());
        sentenciaSQL->Parameters->AddWithValue("@apellido", administrador->getApellido());
        sentenciaSQL->Parameters->AddWithValue("@pin", administrador->getPIN());
        sentenciaSQL->Parameters->AddWithValue("@id", administrador->getId());
        bool actualizado = sentenciaSQL->ExecuteNonQuery() > 0;
        cerrarConexion();
        return actualizado;
    }

    List<Administrador^>^ AdminController::ObtenerTodosAdministradoresTXT() {
        List<Administrador^>^ lista = gcnew List<Administrador^>();
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "SELECT idAdministrador,nombre,apellido,pin FROM Administradores "
            "WHERE Activo=1 ORDER BY idAdministrador", this->conexion);
        SqlDataReader^ data = sentenciaSQL->ExecuteReader();

        while (data->Read()) {
            lista->Add(gcnew Administrador(
                Convert::ToInt32(data["idAdministrador"]),
                Convert::ToString(data["nombre"]),
                Convert::ToString(data["apellido"]),
                Convert::ToInt32(data["pin"])));
        }

        data->Close();
        cerrarConexion();
        return lista;
    }

    List<Administrador^>^ AdminController::ObtenerAdministradoresInactivosTXT() {
        List<Administrador^>^ lista = gcnew List<Administrador^>();
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "SELECT idAdministrador,nombre,apellido,pin FROM Administradores "
            "WHERE Activo=0 ORDER BY idAdministrador", this->conexion);
        SqlDataReader^ data = sentenciaSQL->ExecuteReader();

        while (data->Read()) {
            lista->Add(gcnew Administrador(
                Convert::ToInt32(data["idAdministrador"]),
                Convert::ToString(data["nombre"]),
                Convert::ToString(data["apellido"]),
                Convert::ToInt32(data["pin"])));
        }

        data->Close();
        cerrarConexion();
        return lista;
    }

    bool AdminController::AgregarAdministradorTXT(Administrador^ administrador) {
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "INSERT INTO Administradores(idAdministrador,nombre,apellido,pin,Activo) "
            "VALUES(@id,@nombre,@apellido,@pin,1)", this->conexion);
        sentenciaSQL->Parameters->AddWithValue("@id", administrador->getId());
        sentenciaSQL->Parameters->AddWithValue("@nombre", administrador->getNombre());
        sentenciaSQL->Parameters->AddWithValue("@apellido", administrador->getApellido());
        sentenciaSQL->Parameters->AddWithValue("@pin", administrador->getPIN());
        bool agregado = sentenciaSQL->ExecuteNonQuery() > 0;
        cerrarConexion();
        return agregado;
    }

    bool AdminController::EliminarAdministradorTXT(int id) {
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "UPDATE Administradores SET Activo=0 WHERE idAdministrador=@id AND Activo=1", this->conexion);
        sentenciaSQL->Parameters->AddWithValue("@id", id);
        bool eliminado = sentenciaSQL->ExecuteNonQuery() > 0;
        cerrarConexion();
        return eliminado;
    }

    bool AdminController::RestaurarAdministradorTXT(int id) {
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "UPDATE Administradores SET Activo=1 WHERE idAdministrador=@id AND Activo=0", this->conexion);
        sentenciaSQL->Parameters->AddWithValue("@id", id);
        bool restaurado = sentenciaSQL->ExecuteNonQuery() > 0;
        cerrarConexion();
        return restaurado;
    }

    Administrador^ AdminController::BuscarAdministradorPorIdTXT(int id) {
        Administrador^ administrador = nullptr;
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "SELECT idAdministrador,nombre,apellido,pin FROM Administradores "
            "WHERE idAdministrador=@id AND Activo=1", this->conexion);
        sentenciaSQL->Parameters->AddWithValue("@id", id);
        SqlDataReader^ data = sentenciaSQL->ExecuteReader();
        if (data->Read()) {
            administrador = gcnew Administrador(
                Convert::ToInt32(data["idAdministrador"]),
                Convert::ToString(data["nombre"]),
                Convert::ToString(data["apellido"]),
                Convert::ToInt32(data["pin"]));
        }
        data->Close();
        cerrarConexion();
        return administrador;
    }

    List<Administrador^>^ AdminController::BuscarAdministradoresPorIdListaTXT(int id) {
        List<Administrador^>^ resultados = gcnew List<Administrador^>();
        Administrador^ administrador = BuscarAdministradorPorIdTXT(id);
        if (administrador != nullptr)
            resultados->Add(administrador);
        return resultados;
    }

    void AdminController::AgregarAdministrador(Administrador^ administrador) {
        this->listaAdministradores->Add(administrador);
    }

    bool AdminController::EliminarAdministrador(int id) {
        Administrador^ administrador = BuscarAdministradorPorId(id);
        if (administrador == nullptr)
            return false;
        this->listaAdministradores->Remove(administrador);
        return true;
    }

    Administrador^ AdminController::BuscarAdministradorPorId(int id) {
        for each (Administrador ^ administrador in this->listaAdministradores)
            if (administrador->getId() == id)
                return administrador;
        return nullptr;
    }

    List<Administrador^>^ AdminController::ObtenerTodosAdministradores() {
        return this->listaAdministradores;
    }

    bool AdminController::ModificarAdministrador(int id, String^ nombre, String^ apellido) {
        Administrador^ administrador = BuscarAdministradorPorId(id);
        if (administrador == nullptr)
            return false;
        administrador->setNombre(nombre);
        administrador->setApellido(apellido);
        return true;
    }

    bool AdminController::ExisteAdministrador(int id) {
        return BuscarAdministradorPorId(id) != nullptr;
    }

    List<Administrador^>^ AdminController::BuscarAdministradoresPorIdentificador(int id) {
        List<Administrador^>^ resultados = gcnew List<Administrador^>();
        Administrador^ administrador = BuscarAdministradorPorId(id);
        if (administrador != nullptr)
            resultados->Add(administrador);
        return resultados;
    }
}
