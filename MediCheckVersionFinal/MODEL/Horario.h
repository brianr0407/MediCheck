#include "pch.h"
#pragma once

namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;
	public ref class Horario {
	private:
		int minutosDelDia;
	public: 
		Horario();
		Horario(int minutosDelDia);
		
		int getMinutosDelDia();
		void setMinutosDelDia(int minutosDelDia);
	};
}