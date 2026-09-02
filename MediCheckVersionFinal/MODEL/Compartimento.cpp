#include "pch.h"
#pragma once
#include "Compartimento.h"
namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;
	
	Compartimento::Compartimento(){
		
	}
	Compartimento::Compartimento(int id,  int cantidadInicial, int cantidadActual, String ^ medicamentoAsignado) {
			this->cantidadInicial = cantidadInicial;
	}

	int Compartimento::getId() {
		return this->id;
	}
	void Compartimento::setId(int id) {
		this->id = id;
	}

		int Compartimento::getCantidadInicial() {
			return this->cantidadInicial;
		}
		void Compartimento::setCantidadInicial(int cantidadInicial) {
			this->cantidadInicial = cantidadInicial;
		}

		int Compartimento::getCantidadActual() {
			return this->cantidadActual;
		}
		void Compartimento::setCantidadActual(int cantidadActual) {
			this->cantidadActual = cantidadActual;
		}

		String^ Compartimento::getMedicamentoAsignado() {
			return this->medicamentoAsignado;
		}
		void Compartimento::setMedicamentoAsignado(String^ medicamentoAsignado) {
		}

		//void Compartimento::descontarDosis();
}