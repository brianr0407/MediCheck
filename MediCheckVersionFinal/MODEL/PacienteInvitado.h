#include "pch.h"
#pragma once

#include "Paciente.h"
namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;
	public ref class PacienteInvitado : public Paciente {
	private:
		int diasEstancia;
	public:
		PacienteInvitado();
		PacienteInvitado(int id, String^ nombre, String^ apellido, int HuellaID, bool enCasa, CronogramaToma^ cronogramaToma, int diasEstancia);
		
		int getDiasEstancia();
		void setDiasEstancia(int diasEstancia);
	};
}