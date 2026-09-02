#include "pch.h"
#pragma once
#include "Medicamento.h"
namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;
	public ref class Receta {
	public:
		Receta();
		Receta(int idReceta,int idPaciente, Medicamento^ medicamento, int dosisDiaria, int dosisTomada);
		
		int getIdReceta();
		void setIdReceta(int idReceta);

		int getIdPaciente();
		void setIdPaciente(int idPaciente);

		int getDosisDiaria();
		void setDosisDiaria(int dosisDiaria);

		int getDosisTomada();
		void setDosisTomada(int dosisTomada);

		Medicamento^ getMedicamento();

		void setMedicamento(Medicamento^ medicamento);

	private:
		int idReceta;
		int idPaciente;
		Medicamento^ medicamento;
		int dosisDiaria;
		int dosisTomada;
	};
}