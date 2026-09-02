#include "pch.h"
#pragma once
namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;


	public ref class Usuario {
	public:
		Usuario();
		Usuario(int id, String^ nombre, String^ apellido);
		
		int getId();
		void setId(int id);

		String^ getNombre();
		void setNombre(String^ nombre);

		String^ getApellido();
		void setApellido(String^ apellido);

	private:
		int id;
		String^ Nombre;
		String^ Apellido;
	};
}