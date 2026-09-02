#include "pch.h"
#pragma once
#include "Compartimento.h"

namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;
	public ref class Pastillero {
	private:
		List<Compartimento^>^ compartimentos;
	public:
		Pastillero();
		Pastillero(List<Compartimento^>^ compartimentos);

		List<Compartimento^>^ getCompartimentos();
		void setCompartimentos(List<Compartimento^>^ compartimentos);
	};
}