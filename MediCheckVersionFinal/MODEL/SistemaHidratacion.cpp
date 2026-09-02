#include "pch.h"
#include "SistemaHidratacion.h"

namespace MODEL {
    using namespace System;

    // Constructor
    SistemaHidratacion::SistemaHidratacion(bool nivelAguaCritico) {
        this->nivelAguaCritico = nivelAguaCritico;
    }

    // Getters y Setters
    bool SistemaHidratacion::getNivelAguaCritico() {
        return this->nivelAguaCritico;
    }

    void SistemaHidratacion::setNivelAguaCritico(bool nivelAguaCritico) {
        this->nivelAguaCritico = nivelAguaCritico;
    }

    // Métodos de acción
    void SistemaHidratacion::suministrarManual() {
        if (!this->nivelAguaCritico) {
            Console::WriteLine("Sistema de Hidratación: Sirviendo agua de forma manual al paciente...");
        }
        else {
            Console::WriteLine("ALERTA: Nivel de agua crítico. Por favor, rellene el tanque de agua.");
        }
    }

    void SistemaHidratacion::suministrarAutomatico() {
        if (!this->nivelAguaCritico) {
            Console::WriteLine("Sistema de Hidratación: Sirviendo dosis de agua automática junto con la pastilla...");
        }
        else {
            Console::WriteLine("ALERTA: Nivel de agua crítico. Abortando suministro automático.");
        }
    }
}