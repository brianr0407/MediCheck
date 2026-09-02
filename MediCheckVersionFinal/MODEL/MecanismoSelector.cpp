#include "pch.h"
#pragma once
#include "MecanismoSelector.h"

namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;

	MecanismoSelector::MecanismoSelector(int posicionActual) {
		this->posicionActual = posicionActual;
	}
	int MecanismoSelector::getPosicionActual() {
		return this->posicionActual;
	}
	void MecanismoSelector::setPosicionActual(int posicionActual) {
		this->posicionActual = posicionActual;
	}
	void MecanismoSelector::regresarAInicio() {
		// Lógica para regresar el mecanismo selector a la posición de inicio
	}

	void MecanismoSelector::posicionarEnCompartimiento(int compID) {
		// Lógica para posicionar el mecanismo selector en el compartimiento especificado por compID
	}
	
}