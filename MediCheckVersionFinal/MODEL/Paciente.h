#include "pch.h"
#pragma once
#include "Usuario.h"
#include "Pastillero.h"
#include "CronogramaToma.h"
namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;
	using namespace System::Collections::Generic;
	public ref class Paciente : public Usuario {
	private:
		int HuellaID;
		bool enCasa;
		Pastillero^ pastillero;
		CronogramaToma^ cronogramaToma;
		
	public:
		Paciente();
		Paciente(int id, String^ nombre, String^ apellido, int HuellaID, bool enCasa, CronogramaToma^ cronogramaToma);
		
		int getHuellaID();
		void setHuellaID(int HuellaID);

		bool getEnCasa();
		void setEnCasa(bool enCasa);

		CronogramaToma^ getCronogramaToma();
		void setCronogramaToma(CronogramaToma^ cronogramaToma);
	};
}