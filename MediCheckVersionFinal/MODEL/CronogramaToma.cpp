#include "pch.h"
#pragma once
#include "Receta.h"
#include "CronogramaToma.h"

namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;

	CronogramaToma::CronogramaToma() {
	}
	CronogramaToma::CronogramaToma(int id, List<Receta^>^ recetasActivas, bool estaActivo) {
		this->id = id;
		this->recetasActivas = recetasActivas;
				this->estaActivo = estaActivo;
		}
	
	int CronogramaToma::getId() {
		return this->id;
	}
	void CronogramaToma::setId(int id) {
		this->id = id;
	}

	List<Receta^>^ CronogramaToma::getRecetasActivas() {
		return this->recetasActivas;
		}
	void CronogramaToma::setRecetasActivas(List<Receta^>^ recetasActivas) {
		this->recetasActivas = recetasActivas;
		}

	bool CronogramaToma::getEstaActivo() {
		return this->estaActivo;
		}
		void CronogramaToma::setEstaActivo(bool estaActivo) {
		this->estaActivo = estaActivo;
		}
}