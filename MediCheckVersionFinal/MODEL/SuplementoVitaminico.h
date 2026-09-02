#include "pch.h"
#pragma once
#include "Medicamento.h"
namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;
	public ref class SuplementoVitaminico : public Medicamento {
	private:
		String^ tipo;
	public:
		SuplementoVitaminico();
		SuplementoVitaminico(int id, String^ nombre, String^ tamano, String^ tipo);

		String^ getTipo();
		void setTipo(String^ tipo);
	};
}