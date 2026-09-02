#include "pch.h"
#include "SensorCaida.h"

// Usamos los namespaces necesarios
namespace MODEL {
    using namespace System;

    // Implementación de los métodos lógicos
    bool SensorCaida::confirmar() {
        Console::WriteLine("Sensor Caída: Detectando paso de la pastilla por el conducto...");
        // Aquí en el futuro iría la lectura del PIN de Arduino. Por ahora simulamos que sí cayó.
        return true;
    }

    void SensorCaida::calibrar() {
        Console::WriteLine("Sensor Caída: Calibrando el lector infrarrojo...");
        this->reintentos = 0; // Reiniciamos los reintentos al calibrar
    }
}