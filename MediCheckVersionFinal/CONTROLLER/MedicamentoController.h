#include "pch.h"
#pragma once


namespace CONTROLLER {
    using namespace System;
    using namespace System::Collections::Generic;
    using namespace System::Data::SqlClient;
    using namespace MODEL;
    using namespace IO;

    public ref class MedicamentoController {
    private:
        List<Medicamento^>^ listaMedicamentos;
        SqlConnection^ conexion;

    public:
        MedicamentoController();
        MedicamentoController(List<Medicamento^>^ listaMedicamentos);
        void abrirConexion();
        void cerrarConexion();
        //BackupS
        void ActualizarBackup(Medicamento^ medicamento);
        void AgregarAlBackup(Medicamento^ medicamento);
        int ObtenerSiguienteId();

        //operaciones CRUD persistencia de datos
        void EscribirArchivo(List<Medicamento^>^ listaMedicamentos);
        bool ActualizarArchivo(Medicamento^ medicamento);

        List<Medicamento^>^ ObtenerTodosMedicamentosTXT();
        List<Medicamento^>^ ObtenerMedicamentosInactivosTXT();

        bool AgregarMedicamentoTXT(Medicamento^ medicamento);
        bool EliminarMedicamentoTXT(int id);
        bool RestaurarMedicamentoTXT(int id);
        int ObtenerCantidadMedicamentos();
        bool PuedeAgregarMedicamento();


        Medicamento^ BuscarMedicamentoPorIdTXT(int id);
        List<Medicamento^>^ BuscarMedicamentosPorIdListaTXT(int id);
        String^ ObtenerTipo(Medicamento^ medicamento);













  
    };
}
