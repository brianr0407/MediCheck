#include "pch.h"
#pragma once
namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;
	public ref class SistemaHidratacion {
	private:
		bool nivelAguaCritico;
	public:
		SistemaHidratacion(bool niverlAguaHidratacion);

		bool getNivelAguaCritico();
		void setNivelAguaCritico(bool nivelAguaCritico);

		void suministrarManual();
		void suministrarAutomatico();
	};
}