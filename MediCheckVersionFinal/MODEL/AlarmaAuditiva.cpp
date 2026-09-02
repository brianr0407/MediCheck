#include "pch.h"
#include "AlarmaAuditiva.h"

namespace MODEL {
    using namespace System;

    AlarmaAuditiva::AlarmaAuditiva() {}

    AlarmaAuditiva::AlarmaAuditiva(int id, bool estado, String^ tipo)
        : Alarma(id, estado, tipo)
    {
    }

    // Vacío por ahora, aquí irá la lógica de audio con el ESP32
    void AlarmaAuditiva::TonoConfirmacion() {}
}