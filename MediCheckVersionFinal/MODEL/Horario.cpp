#include "pch.h"
#pragma once
#include "Horario.h"

namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;
	
	Horario::Horario() {

	}
	Horario::Horario(int minutosDelDia) {
		this->minutosDelDia = minutosDelDia;
	}

	int Horario::getMinutosDelDia() {
		return this->minutosDelDia;
	}
	void Horario::setMinutosDelDia(int minutosDelDia) {
		this->minutosDelDia = minutosDelDia;
	}
	
}