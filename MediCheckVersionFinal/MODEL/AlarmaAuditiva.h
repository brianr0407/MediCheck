#pragma once
#include "Alarma.h"

namespace MODEL {
    using namespace System;

    // Clase intermedia abstracta para alarmas que usan sonido
    // Aquí irán los métodos de audio del ESP32 cuando estén listos
    public ref class AlarmaAuditiva abstract : public Alarma {
    public:
        AlarmaAuditiva();
        AlarmaAuditiva(int id, bool estado, String^ tipo);

        // Método de audio compartido por Snooze y Critica
        // Lo implementarás cuando tengas la comunicación con el ESP32
        virtual void TonoConfirmacion();

        // activar y desactivar siguen siendo abstractos,
        // cada subclase (Snooze, Critica) los implementa a su manera
        virtual void activar()    override = 0;
        virtual void desactivar() override = 0;
    };
}