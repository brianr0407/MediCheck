#include "pch.h"
#pragma once
#include "Medicamento.h"
#include "Antibiotico.h"
namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;
	
	Antibiotico::Antibiotico() {
		this->esPrioridadCritica = true;

	}
	Antibiotico::Antibiotico(int id, String^ nombre, String^ tamano, bool esPrioridadCritica):Medicamento(id, nombre, tamano) {
		this->esPrioridadCritica = esPrioridadCritica;
	}

	bool Antibiotico::getEsPrioridadCritica() {
		return this->esPrioridadCritica; // Por defecto, todos los antibióticos son de prioridad crítica
		// Aquí puedes definir la lógica para determinar si el antibiótico es de prioridad crítica
		// Por ejemplo, podrías basarte en el nombre del medicamento o en la apertura del servo
		//if (this->getNombre()->ToLower()->Contains("penicilina") || this->getAperturaServo() > 50) {
		//	return true; // Es de prioridad crítica
		//}
		//return false; // No es de prioridad crítica
	}

	void Antibiotico::setEsPrioridadCritica(bool prioridad) {
		this->esPrioridadCritica = prioridad;
	}
}