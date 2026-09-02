#pragma once
#include "pch.h"


namespace CONTROLLER {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace System::Data::SqlClient;
    using namespace MODEL;
    using namespace IO;

    public ref class PacienteController {
    private:
        List<Paciente^>^ listaPacientes;
        SqlConnection^ conexion;

    public:
        PacienteController();
        PacienteController(List<Paciente^>^ listaPacientes);
        void abrirConexion();
        void cerrarConexion();

        //backup
        
        void AgregarAlBackup(Paciente^ paciente);
        void ActualizarBackup(Paciente^ paciente);
        int ObtenerSiguienteId();

		// operaciones crud de persistencia de lista

        void EscribirArchivo(List<Paciente^>^ listaPacientes);
        bool ActualizarArchivo(Paciente^ paciente);

        List<Paciente^>^ ObtenerTodosPacientesTXT();
        List<Paciente^>^ ObtenerPacientesInactivosTXT();
        int ObtenerCantidadPacientesActivos();

        bool AgregarPacienteTXT(Paciente^ paciente);
        bool EliminarPacienteTXT(int id);
        bool RestaurarPacienteTXT(int id);


        Paciente^ BuscarPacientePorIdTXT(int id);
        List<Paciente^>^ BuscarPacientesPorIdListaTXT(int id);
        List<Paciente^>^ BuscarPacientesPorNombreTXT(String^ nombre);
        List<Paciente^>^ BuscarPacientesPorApellidoTXT(String^ apellido);

        // Operaciones CRUD
        void AgregarPaciente(Paciente^ paciente);
        bool EliminarPaciente(int id);
        bool ModificarPaciente(int id, String^ nombre, String^ apellido);
        bool ExistePaciente(int id);
		//operaciones de consulta
        Paciente^ BuscarPacientePorId(int id);
        List<Paciente^>^ ObtenerTodosPacientes();
        List<Paciente^>^ BuscarPacientesPorIdentificador(int id);

    };
}
