#include "pch.h"
#include "AlarmaSnooze.h"

namespace MODEL {
    using namespace System;

    AlarmaSnooze::AlarmaSnooze() {}

    AlarmaSnooze::AlarmaSnooze(int id, bool estado, int tiempoDeEspera)
        : AlarmaAuditiva(id, estado, "Snooze")  // sube por AlarmaAuditiva a Alarma
    {
        this->tiempoDeEspera = tiempoDeEspera;
    }

    int  AlarmaSnooze::getTiempoDeEspera() { return this->tiempoDeEspera; }
    void AlarmaSnooze::setTiempoDeEspera(int minutos) { this->tiempoDeEspera = minutos; }

    void AlarmaSnooze::activar() {}
    void AlarmaSnooze::desactivar() {}
}