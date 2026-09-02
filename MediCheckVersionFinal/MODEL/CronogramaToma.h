#include "pch.h"
#pragma once
#include "Receta.h"

namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;

	public ref class CronogramaToma {
	private: 
		int id;
		List<Receta^>^ recetasActivas;
		bool estaActivo;

	public:
		CronogramaToma();
		CronogramaToma(int id, List<Receta^>^ recetasActivas, bool estaActivo);
		
		int getId();
		void setId(int id);

		List<Receta^>^ getRecetasActivas();
		void setRecetasActivas(List<Receta^>^ recetasActivas);
		
		bool getEstaActivo();
		void setEstaActivo(bool estaActivo);
	};
}