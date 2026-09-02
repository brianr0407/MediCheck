#include "pch.h"
#include "HorarioReceta.h"

namespace MODEL {
	HorarioReceta::HorarioReceta() {
		this->idHorario = 0;
		this->idReceta = 0;
		this->horaProgramada = TimeSpan::Zero;
	}

	HorarioReceta::HorarioReceta(int idHorario, int idReceta, TimeSpan horaProgramada) {
		this->idHorario = idHorario;
		this->idReceta = idReceta;
		this->horaProgramada = horaProgramada;
	}

	int HorarioReceta::getIdHorario() {
		return this->idHorario;
	}

	void HorarioReceta::setIdHorario(int idHorario) {
		this->idHorario = idHorario;
	}

	int HorarioReceta::getIdReceta() {
		return this->idReceta;
	}

	void HorarioReceta::setIdReceta(int idReceta) {
		this->idReceta = idReceta;
	}

	TimeSpan HorarioReceta::getHoraProgramada() {
		return this->horaProgramada;
	}

	void HorarioReceta::setHoraProgramada(TimeSpan horaProgramada) {
		this->horaProgramada = horaProgramada;
	}
}
