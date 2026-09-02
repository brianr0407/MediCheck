#include "pch.h"
#include "ValidarAlmuerzo.h"

namespace MODEL {
    using namespace System;

    // Constructor por defecto
    ValidarAlmuerzo::ValidarAlmuerzo() {
    }

    // Método principal
    bool ValidarAlmuerzo::validarAlmuerzo() {
        Console::WriteLine("Validador: Preguntando al paciente si ya ha ingerido sus alimentos...");
        // En un entorno gráfico, esto podría abrir un MessageBox preguntando "Sí" o "No"

        // Por ahora simulamos que el paciente SÍ comió
        return true;
    }
}