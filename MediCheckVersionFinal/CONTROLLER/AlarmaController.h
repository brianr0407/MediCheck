#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data::SqlClient;
using namespace System::IO;

namespace CONTROLLER {
    using namespace MODEL;

    public ref class AlarmaController {
    private:
        List<Alarma^>^ listaAlarmas;
        SqlConnection^ conexion;

        // Auxiliar interno - convierte cualquier Alarma a línea de texto
        String^ FormatearLinea(Alarma^ alarma);

    public:
        // Constructores
        AlarmaController();
        AlarmaController(List<Alarma^>^ listaAlarmas);
        void abrirConexion();
        void cerrarConexion();

        // Inicialización
        void InicializarArchivos();

        // Backup
        void AgregarAlBackup(Alarma^ alarma);
        void ActualizarBackup(Alarma^ alarma);

        // ID autoincremental
        int ObtenerSiguienteId();

        // Persistencia - archivo principal
        void           EscribirArchivo(List<Alarma^>^ listaAlarmas);
        List<Alarma^>^ ObtenerTodasAlarmasTXT();
        int            ObtenerCantidadAlarmas();
        bool           AgregarAlarmaTXT(Alarma^ alarma);
        bool           EliminarAlarmaTXT(int id);
        bool           ActualizarArchivo(Alarma^ alarma);

        // Búsqueda en TXT
        Alarma^ BuscarAlarmaPorIdTXT(int id);

        
    };
}
