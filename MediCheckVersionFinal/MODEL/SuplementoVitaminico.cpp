#include "pch.h"
#include "SuplementoVitaminico.h"

namespace MODEL {
    using namespace System;
    SuplementoVitaminico::SuplementoVitaminico() {
		this->tipo = nullptr; // Por defecto los suplementos no tienen un tipo específico
    }
    SuplementoVitaminico::SuplementoVitaminico(int id, String^ nombre, String^ tamano, String^ tipo):Medicamento(id, nombre, tamano) {
		this->tipo = tipo;
    }

    String^ SuplementoVitaminico::getTipo() {
        return this->tipo;
    }

    void SuplementoVitaminico::setTipo(String^ tipo) {
        this->tipo = tipo;
    }
}


// Nota de implementación:
// Actualmente en tu archivo .h no has definido constructores, getters, ni setters en la sección "public:".
// Para que esta clase sea útil en Visual Studio, en tu SuplementoVitaminico.h deberías agregar:
/*
    public:
        SuplementoVitaminico();
        bool getEsPrioridadCritica();
        void setEsPrioridadCritica(bool prioridad);
*/

// Si los agregas, el .cpp se vería así:
/*
SuplementoVitaminico::SuplementoVitaminico() {
    this->esPrioridadCritica = false; // Por defecto los suplementos NO son críticos
}

bool SuplementoVitaminico::getEsPrioridadCritica() {
    return this->esPrioridadCritica;
}

void SuplementoVitaminico::setEsPrioridadCritica(bool prioridad) {
    this->esPrioridadCritica = prioridad;
}
*/