#include "pch.h"
#include "Paciente.h"
namespace MODEL {
	using namespace System;
	using namespace System:: Collections::Generic;

	Paciente::Paciente() {

	}

	Paciente::Paciente(int id, String^ nombre, String^ apellido, int HuellaID, bool enCasa, CronogramaToma^ cronogramaToma): Usuario(id, nombre, apellido){
			this->HuellaID = HuellaID;
			this->enCasa = enCasa;
			this->cronogramaToma = cronogramaToma;
	}

	int Paciente::getHuellaID() {
		return this->HuellaID;
	}
	void Paciente::setHuellaID(int HuellaID) {
		this->HuellaID = HuellaID;
	}

	bool Paciente::getEnCasa() {
		return this->enCasa;
	}
	void Paciente::setEnCasa(bool enCasa) {
		this->enCasa = enCasa;
	}

	CronogramaToma^ Paciente::getCronogramaToma() {
		return this->cronogramaToma;
	}
	void Paciente::setCronogramaToma(CronogramaToma^ cronogramaToma) {
		this->cronogramaToma = cronogramaToma;
	}
}