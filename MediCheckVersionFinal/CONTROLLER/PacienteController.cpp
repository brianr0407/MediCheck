#include "pch.h"
#include "PacienteController.h"
#include "ConexionBD.h"
#include "CronogramaTomaController.h"

namespace CONTROLLER {
    PacienteController::PacienteController() {
        this->listaPacientes = gcnew List<Paciente^>();
        this->conexion = ConexionBD::CrearConexion();
    }

    PacienteController::PacienteController(List<Paciente^>^ listaPacientes) {
        this->listaPacientes = listaPacientes;
        this->conexion = ConexionBD::CrearConexion();
    }

    void PacienteController::abrirConexion() {
        if (this->conexion == nullptr)
            this->conexion = ConexionBD::CrearConexion();
        if (this->conexion->State != System::Data::ConnectionState::Open)
            this->conexion->Open();
    }

    void PacienteController::cerrarConexion() {
        if (this->conexion != nullptr && this->conexion->State != System::Data::ConnectionState::Closed)
            this->conexion->Close();
    }

    void PacienteController::AgregarAlBackup(Paciente^ paciente) {
        // Respaldo delegado a la base de datos.
    }

    void PacienteController::ActualizarBackup(Paciente^ paciente) {
        // Respaldo delegado a la base de datos.
    }

    int PacienteController::ObtenerSiguienteId() {
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "SELECT ISNULL(MAX(idPaciente), 0) + 1 FROM Pacientes", this->conexion);
        int id = Convert::ToInt32(sentenciaSQL->ExecuteScalar());
        cerrarConexion();
        return id;
    }

    void PacienteController::EscribirArchivo(List<Paciente^>^ listaPacientes) {
        abrirConexion();
        SqlCommand^ desactivar = gcnew SqlCommand("UPDATE Pacientes SET Activo=0", this->conexion);
        desactivar->ExecuteNonQuery();

        for each (Paciente ^ paciente in listaPacientes) {
            PacienteInvitado^ invitado = dynamic_cast<PacienteInvitado^>(paciente);
            Object^ diasEstancia = invitado == nullptr
                ? safe_cast<Object^>(DBNull::Value)
                : safe_cast<Object^>(invitado->getDiasEstancia());

            SqlCommand^ actualizar = gcnew SqlCommand(
                "UPDATE Pacientes SET nombre=@nombre,apellido=@apellido,huellaID=@huellaID,"
                "enCasa=@enCasa,diasEstancia=@diasEstancia,Activo=1 WHERE idPaciente=@id",
                this->conexion);
            actualizar->Parameters->AddWithValue("@nombre", paciente->getNombre());
            actualizar->Parameters->AddWithValue("@apellido", paciente->getApellido());
            actualizar->Parameters->AddWithValue("@huellaID", paciente->getHuellaID());
            actualizar->Parameters->AddWithValue("@enCasa", paciente->getEnCasa());
            actualizar->Parameters->AddWithValue("@diasEstancia", diasEstancia);
            actualizar->Parameters->AddWithValue("@id", paciente->getId());

            if (actualizar->ExecuteNonQuery() <= 0) {
                SqlCommand^ insertar = gcnew SqlCommand(
                    "INSERT INTO Pacientes(idPaciente,nombre,apellido,huellaID,enCasa,diasEstancia,Activo) "
                    "VALUES(@id,@nombre,@apellido,@huellaID,@enCasa,@diasEstancia,1)",
                    this->conexion);
                insertar->Parameters->AddWithValue("@id", paciente->getId());
                insertar->Parameters->AddWithValue("@nombre", paciente->getNombre());
                insertar->Parameters->AddWithValue("@apellido", paciente->getApellido());
                insertar->Parameters->AddWithValue("@huellaID", paciente->getHuellaID());
                insertar->Parameters->AddWithValue("@enCasa", paciente->getEnCasa());
                insertar->Parameters->AddWithValue("@diasEstancia", diasEstancia);
                insertar->ExecuteNonQuery();
            }
        }

        cerrarConexion();
    }

    bool PacienteController::ActualizarArchivo(Paciente^ paciente) {
        PacienteInvitado^ invitado = dynamic_cast<PacienteInvitado^>(paciente);
        Object^ diasEstancia = invitado == nullptr
            ? safe_cast<Object^>(DBNull::Value)
            : safe_cast<Object^>(invitado->getDiasEstancia());

        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "UPDATE Pacientes SET nombre=@nombre,apellido=@apellido,huellaID=@huellaID,"
            "enCasa=@enCasa,diasEstancia=@diasEstancia WHERE idPaciente=@id AND Activo=1", this->conexion);
        sentenciaSQL->Parameters->AddWithValue("@nombre", paciente->getNombre());
        sentenciaSQL->Parameters->AddWithValue("@apellido", paciente->getApellido());
        sentenciaSQL->Parameters->AddWithValue("@huellaID", paciente->getHuellaID());
        sentenciaSQL->Parameters->AddWithValue("@enCasa", paciente->getEnCasa());
        sentenciaSQL->Parameters->AddWithValue("@diasEstancia", diasEstancia);
        sentenciaSQL->Parameters->AddWithValue("@id", paciente->getId());
        bool actualizado = sentenciaSQL->ExecuteNonQuery() > 0;
        cerrarConexion();
        return actualizado;
    }

    List<Paciente^>^ PacienteController::ObtenerTodosPacientesTXT() {
        List<Paciente^>^ lista = gcnew List<Paciente^>();
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "SELECT idPaciente,nombre,apellido,huellaID,enCasa,diasEstancia FROM Pacientes "
            "WHERE Activo=1 ORDER BY idPaciente",
            this->conexion);
        SqlDataReader^ data = sentenciaSQL->ExecuteReader();
        CronogramaTomaController^ cronogramaController = gcnew CronogramaTomaController();

        while (data->Read()) {
            int id = Convert::ToInt32(data["idPaciente"]);
            String^ nombre = Convert::ToString(data["nombre"]);
            String^ apellido = Convert::ToString(data["apellido"]);
            int huellaID = Convert::ToInt32(data["huellaID"]);
            bool enCasa = Convert::ToBoolean(data["enCasa"]);
            CronogramaToma^ cronograma = cronogramaController->BuscarCronogramaPorIdTXT(id);

            if (data["diasEstancia"] == DBNull::Value)
                lista->Add(gcnew Paciente(id, nombre, apellido, huellaID, enCasa, cronograma));
            else
                lista->Add(gcnew PacienteInvitado(
                    id, nombre, apellido, huellaID, enCasa, cronograma,
                    Convert::ToInt32(data["diasEstancia"])));
        }

        data->Close();
        cerrarConexion();
        return lista;
    }

    List<Paciente^>^ PacienteController::ObtenerPacientesInactivosTXT() {
        List<Paciente^>^ lista = gcnew List<Paciente^>();
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "SELECT idPaciente,nombre,apellido,huellaID,enCasa,diasEstancia FROM Pacientes "
            "WHERE Activo=0 ORDER BY idPaciente",
            this->conexion);
        SqlDataReader^ data = sentenciaSQL->ExecuteReader();
        CronogramaTomaController^ cronogramaController = gcnew CronogramaTomaController();

        while (data->Read()) {
            int id = Convert::ToInt32(data["idPaciente"]);
            String^ nombre = Convert::ToString(data["nombre"]);
            String^ apellido = Convert::ToString(data["apellido"]);
            int huellaID = Convert::ToInt32(data["huellaID"]);
            bool enCasa = Convert::ToBoolean(data["enCasa"]);
            CronogramaToma^ cronograma = cronogramaController->BuscarCronogramaPorIdTXT(id);

            if (data["diasEstancia"] == DBNull::Value)
                lista->Add(gcnew Paciente(id, nombre, apellido, huellaID, enCasa, cronograma));
            else
                lista->Add(gcnew PacienteInvitado(
                    id, nombre, apellido, huellaID, enCasa, cronograma,
                    Convert::ToInt32(data["diasEstancia"])));
        }

        data->Close();
        cerrarConexion();
        return lista;
    }

    int PacienteController::ObtenerCantidadPacientesActivos() {
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "SELECT COUNT(*) FROM Pacientes WHERE Activo=1", this->conexion);
        int cantidad = Convert::ToInt32(sentenciaSQL->ExecuteScalar());
        cerrarConexion();
        return cantidad;
    }

    bool PacienteController::AgregarPacienteTXT(Paciente^ paciente) {
        PacienteInvitado^ invitado = dynamic_cast<PacienteInvitado^>(paciente);
        Object^ diasEstancia = invitado == nullptr
            ? safe_cast<Object^>(DBNull::Value)
            : safe_cast<Object^>(invitado->getDiasEstancia());

        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "INSERT INTO Pacientes(idPaciente,nombre,apellido,huellaID,enCasa,diasEstancia,Activo) "
            "VALUES(@id,@nombre,@apellido,@huellaID,@enCasa,@diasEstancia,1)", this->conexion);
        sentenciaSQL->Parameters->AddWithValue("@id", paciente->getId());
        sentenciaSQL->Parameters->AddWithValue("@nombre", paciente->getNombre());
        sentenciaSQL->Parameters->AddWithValue("@apellido", paciente->getApellido());
        sentenciaSQL->Parameters->AddWithValue("@huellaID", paciente->getHuellaID());
        sentenciaSQL->Parameters->AddWithValue("@enCasa", paciente->getEnCasa());
        sentenciaSQL->Parameters->AddWithValue("@diasEstancia", diasEstancia);
        bool agregado = sentenciaSQL->ExecuteNonQuery() > 0;
        cerrarConexion();
        return agregado;
    }

    bool PacienteController::EliminarPacienteTXT(int id) {
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "UPDATE Pacientes SET Activo=0 WHERE idPaciente=@id AND Activo=1", this->conexion);
        sentenciaSQL->Parameters->AddWithValue("@id", id);
        bool eliminado = sentenciaSQL->ExecuteNonQuery() > 0;
        cerrarConexion();
        return eliminado;
    }

    bool PacienteController::RestaurarPacienteTXT(int id) {
        abrirConexion();
        SqlCommand^ sentenciaSQL = gcnew SqlCommand(
            "UPDATE Pacientes SET Activo=1 WHERE idPaciente=@id AND Activo=0", this->conexion);
        sentenciaSQL->Parameters->AddWithValue("@id", id);
        bool restaurado = sentenciaSQL->ExecuteNonQuery() > 0;
        cerrarConexion();
        return restaurado;
    }

    Paciente^ PacienteController::BuscarPacientePorIdTXT(int id) {
        for each (Paciente ^ paciente in ObtenerTodosPacientesTXT())
            if (paciente->getId() == id)
                return paciente;
        return nullptr;
    }

    List<Paciente^>^ PacienteController::BuscarPacientesPorIdListaTXT(int id) {
        List<Paciente^>^ resultados = gcnew List<Paciente^>();
        Paciente^ paciente = BuscarPacientePorIdTXT(id);
        if (paciente != nullptr)
            resultados->Add(paciente);
        return resultados;
    }

    List<Paciente^>^ PacienteController::BuscarPacientesPorNombreTXT(String^ nombre) {
        List<Paciente^>^ resultados = gcnew List<Paciente^>();
        for each (Paciente ^ paciente in ObtenerTodosPacientesTXT())
            if (paciente->getNombre()->IndexOf(nombre, StringComparison::OrdinalIgnoreCase) >= 0)
                resultados->Add(paciente);
        return resultados;
    }

    List<Paciente^>^ PacienteController::BuscarPacientesPorApellidoTXT(String^ apellido) {
        List<Paciente^>^ resultados = gcnew List<Paciente^>();
        for each (Paciente ^ paciente in ObtenerTodosPacientesTXT())
            if (paciente->getApellido()->IndexOf(apellido, StringComparison::OrdinalIgnoreCase) >= 0)
                resultados->Add(paciente);
        return resultados;
    }

    void PacienteController::AgregarPaciente(Paciente^ paciente) {
        this->listaPacientes->Add(paciente);
    }

    bool PacienteController::EliminarPaciente(int id) {
        Paciente^ paciente = BuscarPacientePorId(id);
        if (paciente == nullptr)
            return false;
        this->listaPacientes->Remove(paciente);
        return true;
    }

    Paciente^ PacienteController::BuscarPacientePorId(int id) {
        for each (Paciente ^ paciente in this->listaPacientes)
            if (paciente->getId() == id)
                return paciente;
        return nullptr;
    }

    List<Paciente^>^ PacienteController::ObtenerTodosPacientes() {
        return this->listaPacientes;
    }

    bool PacienteController::ModificarPaciente(int id, String^ nombre, String^ apellido) {
        Paciente^ paciente = BuscarPacientePorId(id);
        if (paciente == nullptr)
            return false;
        paciente->setNombre(nombre);
        paciente->setApellido(apellido);
        return true;
    }

    bool PacienteController::ExistePaciente(int id) {
        return BuscarPacientePorId(id) != nullptr;
    }

    List<Paciente^>^ PacienteController::BuscarPacientesPorIdentificador(int id) {
        List<Paciente^>^ resultados = gcnew List<Paciente^>();
        Paciente^ paciente = BuscarPacientePorId(id);
        if (paciente != nullptr)
            resultados->Add(paciente);
        return resultados;
    }
}
