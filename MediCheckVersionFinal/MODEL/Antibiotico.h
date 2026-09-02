#include "pch.h"
#pragma once
#include "Medicamento.h"

namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;
	public ref class Antibiotico : public Medicamento {
	private:
		bool esPrioridadCritica;
	public:
		Antibiotico();
		Antibiotico(int id, String^ nombre, String^ aperturaServo, bool esPrioridadCritica);

		bool getEsPrioridadCritica();
		void setEsPrioridadCritica(bool prioridad);
	};
}