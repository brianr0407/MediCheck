#include "pch.h"
#include "Receta.h"

namespace MODEL {
    using namespace System;

    // Constructor por defecto
    Receta::Receta() {
    }

    // Constructor con parámetros
    Receta::Receta(int idReceta, int idPaciente, Medicamento^ medicamento, int dosisDiaria, int dosisTomada) {
        this->idReceta = idReceta;
        this->idPaciente = idPaciente;
        this->medicamento = medicamento;
        this->dosisDiaria = dosisDiaria;
        this->dosisTomada = dosisTomada;
    }

    // Getters y Setters
	Medicamento^ Receta::getMedicamento() {
		return this->medicamento;
	}

	void Receta::setMedicamento(Medicamento^ medicamento) {
		this->medicamento = medicamento;
	}

    int Receta::getIdReceta() {
        return this->idReceta;
    }

    void Receta::setIdReceta(int idReceta) {
        this->idReceta = idReceta;
    }

    int Receta::getIdPaciente() {
        return this->idPaciente;
    }

    void Receta::setIdPaciente(int idPaciente) {
        this->idPaciente = idPaciente;
    }
    
    int Receta::getDosisDiaria() {
        return this->dosisDiaria;
    }

    void Receta::setDosisDiaria(int dosisDiaria) {
        this->dosisDiaria = dosisDiaria;
    }

    int Receta::getDosisTomada() {
        return this->dosisTomada;
    }
    void Receta::setDosisTomada(int dosisTomada) {
        this->dosisTomada = dosisTomada;
    }

}