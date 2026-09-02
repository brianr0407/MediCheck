#include "pch.h"
#include "Alarma.h"

namespace MODEL {
    using namespace System;

    Alarma::Alarma() {}

    Alarma::Alarma(int id, bool estado, String^ tipo) {
        this->id = id;
        this->estado = estado;
        this->tipo = tipo;
    }

    int  Alarma::getId() { return this->id; }
    void Alarma::setId(int id) { this->id = id; }

    bool Alarma::getEstado() { return this->estado; }
    void Alarma::setEstado(bool estado) { this->estado = estado; }

    String^ Alarma::getTipo() { return this->tipo; }
}