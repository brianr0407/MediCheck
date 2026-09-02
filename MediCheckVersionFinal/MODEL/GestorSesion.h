#include "pch.h"
#pragma once
namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;
	public ref class GestorSesion {
	public:
		GestorSesion();
		GestorSesion(bool estarLogueado);

		bool getEstarLogueado();
		void setEstarLogueado(bool estarLogueado);
	private:
		bool estarLogueado;
	};
}