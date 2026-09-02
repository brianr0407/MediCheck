#include "pch.h"
#include "SensorPresencia.h"

namespace MODEL {
    using namespace System;

    bool SensorPresencia::detectarVaso() {
        Console::WriteLine("Sensor Presencia: Verificando si el vaso está en la bandeja...");
        return true; // Simulamos que el vaso está colocado correctamente
    }

    void SensorPresencia::calibrar() {
        Console::WriteLine("Sensor Presencia: Ajustando sensibilidad óptica para evitar falsos positivos con la luz ambiente.");
    }
}