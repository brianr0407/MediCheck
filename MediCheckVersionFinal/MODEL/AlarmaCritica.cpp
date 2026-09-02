#include "pch.h"
#include "AlarmaCritica.h"

namespace MODEL {
    using namespace System;

    AlarmaCritica::AlarmaCritica() {}

    AlarmaCritica::AlarmaCritica(int id, bool estado)
        : AlarmaAuditiva(id, estado, "Critica")  // sube por AlarmaAuditiva a Alarma
    {
    }

    void AlarmaCritica::activar() {}
    void AlarmaCritica::desactivar() {}
}