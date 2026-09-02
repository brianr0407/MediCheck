#include "pch.h"
#pragma once
#include "GestorSesion.h"
namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;

	GestorSesion::GestorSesion() {

		}
	GestorSesion::GestorSesion(bool estarLogueado) {
		this->estarLogueado = estarLogueado;
		}

	bool GestorSesion::getEstarLogueado() {
		return this->estarLogueado;
		}
	void GestorSesion::setEstarLogueado(bool estarLogueado) {
				this->estarLogueado = estarLogueado;
		}

}