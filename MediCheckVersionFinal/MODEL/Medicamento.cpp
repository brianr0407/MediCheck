#include "pch.h"
#pragma once
#include "Medicamento.h"
namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;
	
	Medicamento::Medicamento() {

	}
	Medicamento::Medicamento(int id, String^ nombre, String^ tamano) {
		this->id = id;
		this ->nombre = nombre;
		this->tamano = tamano;

	}


	int Medicamento::getId() {
		return this->id;
	}

	void Medicamento::setId(int id) {
		this->id = id;
	}

	String^ Medicamento::getNombre() {
		return this->nombre;
	}
	void Medicamento::setNombre(String^ nombre) {
		this->nombre = nombre;
	}
	String^ Medicamento::getTamano() {
		return this->tamano;
	}
	void Medicamento::setTamano(String^ tamano) {
		this->tamano = tamano;
	}
	
}