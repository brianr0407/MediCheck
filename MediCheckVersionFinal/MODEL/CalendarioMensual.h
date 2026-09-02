#include "pch.h"
#pragma once
namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;
	public ref class CalendarioMensual {
	private:
		List<String^>^ registros;
		float porcentajeCumplimiento;
	public:
		CalendarioMensual();
		CalendarioMensual(List<String^>^ registros, float porcentajeCumplimiento);

		float getPorcentajeCumplimiento();
		void setPorcentajeCumplimiento(float porcentajeCumplimiento);

		List<String^>^ getRegistros();
		void setRegistros(List<String^>^ registros);

		//void agregarRegistro(String^ registro);
		//float calcularPorcentajeCumplimiento();
	};
}