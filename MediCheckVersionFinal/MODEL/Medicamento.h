#include "pch.h"
#pragma once

namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;
	public ref class Medicamento {
	public:
		Medicamento();
		Medicamento(int id, String^ nombre, String^ tamano);

		int getId();
		void setId(int id);

		String^ getNombre();
		void setNombre(String^ nombre);

		String^ getTamano();
		void setTamano(String^ tamano);
	private:
		int id;
		String^ nombre;
		String^ tamano;
	};
}