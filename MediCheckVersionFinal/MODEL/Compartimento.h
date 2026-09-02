#include "pch.h"
#pragma once
namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;
	public ref class Compartimento {
	private:
		int id;
		int cantidadInicial;
		int cantidadActual;
		String^ medicamentoAsignado;
	public:
		Compartimento();
		Compartimento(int id, int cantidadInicial, int cantidadActual, String^ medicamentoAsignado);
		
		int getId();
		void setId(int id);

		int getCantidadInicial();
		void setCantidadInicial(int cantidadInicial);

		int getCantidadActual();
		void setCantidadActual(int cantidadActual);

		String^ getMedicamentoAsignado();
		void setMedicamentoAsignado(String^ medicamentoAsignado);

		//void descontarDosis();
	};
}