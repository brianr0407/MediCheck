#pragma once
#include "Alarma.h"

namespace MODEL {
    using namespace System;

    // Clase intermedia abstracta para alarmas visuales (pacientes sordos)
    // Espejo de AlarmaAuditiva pero para señales visuales (luces, pantalla, etc.)
    public ref class AlarmaVisual abstract : public Alarma {
    public:
        AlarmaVisual();
        AlarmaVisual(int id, bool estado, String^ tipo);

        // Aquí irán los métodos visuales del ESP32 cuando estén listos
        // Por ejemplo: virtual void EncenderLuz();

        virtual void activar()    override = 0;
        virtual void desactivar() override = 0;
    };
}