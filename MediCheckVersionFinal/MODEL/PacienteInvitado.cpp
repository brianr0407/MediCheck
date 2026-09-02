#include "pch.h"
#include "PacienteInvitado.h"

namespace MODEL {
    using namespace System;

    // Constructor por defecto
    PacienteInvitado::PacienteInvitado() {
    }

    // Constructor con parámetros (pasa datos a la clase base Paciente)
    PacienteInvitado::PacienteInvitado(int id, String^ nombre, String^ apellido, int HuellaID, bool enCasa, CronogramaToma^ cronogramaToma, int diasEstancia)
        : Paciente(id, nombre, apellido, HuellaID, enCasa, cronogramaToma) {
        this->diasEstancia = diasEstancia;
    }

    // Getter y Setter
    int PacienteInvitado::getDiasEstancia() {
        return this->diasEstancia;
    }

    void PacienteInvitado::setDiasEstancia(int diasEstancia) {
        this->diasEstancia = diasEstancia;
    }
}