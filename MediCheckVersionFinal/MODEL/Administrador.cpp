#include "pch.h"
#pragma once
#include "Administrador.h"
namespace MODEL {
	using namespace System;

	Administrador::Administrador() {

	}
	Administrador::Administrador(int id, String^ nombre, String^ apellido, int PIN):Usuario(id, nombre, apellido){
		this->PIN = PIN;
	}

	int Administrador::getPIN() {
		return this->PIN;
	}
	void Administrador::setPIN(int PIN) {
		this->PIN = PIN;
	}


 }