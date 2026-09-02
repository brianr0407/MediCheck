#include "pch.h"
#pragma once
#include "CalendarioMensual.h"

namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;
	
		CalendarioMensual::CalendarioMensual() {
			
		}
		CalendarioMensual::CalendarioMensual(List<String^>^ registros, float porcentajeCumplimiento) {
			this->registros = registros;
			this->porcentajeCumplimiento = porcentajeCumplimiento;
		}

		float CalendarioMensual::getPorcentajeCumplimiento(){
			return this->porcentajeCumplimiento;
		}
		void CalendarioMensual::setPorcentajeCumplimiento(float porcentajeCumplimiento) {
			this->porcentajeCumplimiento = porcentajeCumplimiento;
		}
		List<String^>^ CalendarioMensual::getRegistros() {
			return this->registros;
		}
		void CalendarioMensual::setRegistros(List<String^>^ registros) {
			this->registros = registros;
		}

		//void CalendarioMensual::agregarRegistro(String^ registro);
		//float CalendarioMensual::calcularPorcentajeCumplimiento();
}