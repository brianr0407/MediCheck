#include "pch.h"
#pragma once


namespace CONTROLLER {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace System::Data::SqlClient;
    using namespace MODEL;
    using namespace IO;
    public ref class AdminController {
    private:
        List<Administrador^>^ listaAdministradores;
        SqlConnection^ conexion;

    public:
        AdminController();
        AdminController(List<Administrador^>^ listaAdministradores);
        void abrirConexion();
        void cerrarConexion();
        //BackUp
        //BACK UP //////////////////////////////////////
        void AgregarAlBackup(Administrador^ administrador);
        void ActualizarBackup(Administrador^ administrador);
        int ObtenerSiguienteId();
        // Operaciones CRUD
        void AgregarAdministrador(Administrador^ administrador);
        bool EliminarAdministrador(int id);
        bool ModificarAdministrador(int id, String^ nombre, String^ apellido);
        bool ExisteAdministrador(int id);
        //Operaciones CRUD con persistencia de Datos
        void EscribirArchivo(List<Administrador^>^ listaAdministradores);
        bool ActualizarArchivo(Administrador^ administrador);

        List<Administrador^>^ ObtenerTodosAdministradoresTXT();
        List<Administrador^>^ ObtenerAdministradoresInactivosTXT();

        bool AgregarAdministradorTXT(Administrador^ administrador);
        bool EliminarAdministradorTXT(int id);
        bool RestaurarAdministradorTXT(int id);


        Administrador^ BuscarAdministradorPorIdTXT(int id);
        List<Administrador^>^ BuscarAdministradoresPorIdListaTXT(int id);


        //operaciones de consulta
        Administrador^ BuscarAdministradorPorId(int id);
        List<Administrador^>^ ObtenerTodosAdministradores();
        List<Administrador^>^ BuscarAdministradoresPorIdentificador(int id);
    };
}
