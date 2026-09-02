#include "pch.h"
#pragma once

namespace MODEL {
	using namespace System;

	public ref class HorarioReceta {
	private:
		int idHorario;
		int idReceta;
		TimeSpan horaProgramada;

	public:
		HorarioReceta();
		HorarioReceta(int idHorario, int idReceta, TimeSpan horaProgramada);

		int getIdHorario();
		void setIdHorario(int idHorario);

		int getIdReceta();
		void setIdReceta(int idReceta);

		TimeSpan getHoraProgramada();
		void setHoraProgramada(TimeSpan horaProgramada);
	};
}
