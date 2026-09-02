#include "pch.h"
#pragma once


namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;
	public ref class MecanismoSelector {
	private:
		int posicionActual;
	public:
		MecanismoSelector(int posicionActual);

		void posicionarEnCompartimiento(int compID);

		int getPosicionActual();
		void setPosicionActual(int posicionActual);
		void regresarAInicio();
	};
}