#pragma once
#include "AlarmaAuditiva.h"  // cambia aquí

namespace MODEL {
    using namespace System;

    public ref class AlarmaCritica : public AlarmaAuditiva {  // cambia aquí
    public:
        AlarmaCritica();
        AlarmaCritica(int id, bool estado);

        virtual void activar()    override;
        virtual void desactivar() override;
    };
}