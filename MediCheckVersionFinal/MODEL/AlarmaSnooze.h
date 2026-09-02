#pragma once
#include "AlarmaAuditiva.h"  // cambia aquí

namespace MODEL {
    using namespace System;

    public ref class AlarmaSnooze : public AlarmaAuditiva {  // cambia aquí
    private:
        int tiempoDeEspera;

    public:
        AlarmaSnooze();
        AlarmaSnooze(int id, bool estado, int tiempoDeEspera);

        int  getTiempoDeEspera();
        void setTiempoDeEspera(int minutos);

        virtual void activar()    override;
        virtual void desactivar() override;
    };
}