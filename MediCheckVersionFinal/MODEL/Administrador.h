#include "pch.h"
#pragma once
#include "Usuario.h"

namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;
	public ref class Administrador : public Usuario {
	
	private:
		int PIN;
	
	public:
		Administrador();
		Administrador(int id, String^ nombre, String^ apellido, int PIN);
		
		int getPIN();
		void setPIN(int PIN);
	};
}