
#include "pch.h"
#include "Pastillero.h"
namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;
	
	Pastillero::Pastillero() {

	}
	Pastillero::Pastillero(List<Compartimento^>^ compartimentos) {
		this->compartimentos = compartimentos;
	}

	List<Compartimento^>^ Pastillero::getCompartimentos() {
		return this->compartimentos;
	}
	void Pastillero::setCompartimentos(List<Compartimento^>^ compartimentos) {
		this->compartimentos = compartimentos;
	}

}