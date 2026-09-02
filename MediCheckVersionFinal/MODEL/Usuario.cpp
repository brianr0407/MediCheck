#include "pch.h"
#include "Usuario.h"

namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;

	Usuario::Usuario() {

		}
	Usuario::Usuario(int id, String^ nombre, String^ apellido) {
		this->id = id;
		this->Nombre = nombre;
		this->Apellido = apellido;
	}

	int Usuario::getId() {
		return this->id;
		}
	void Usuario::setId(int id) {
		this->id = id;
		}

	String^ Usuario::getNombre() {
		return this->Nombre;
		}
	void Usuario::setNombre(String^ nombre) {
		this->Nombre = nombre;
		}
	String^ Usuario::getApellido() {
		return this->Apellido;
		}
	void Usuario::setApellido(String^ apellido) {
		this->Apellido = apellido;
		}
}