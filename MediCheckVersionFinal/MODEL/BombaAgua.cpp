#include "pch.h"
#pragma once
#include "BombaAgua.h"
namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;
	
	BombaAgua::BombaAgua(int flujoUML) {
		this->flujoUML = flujoUML;
	}

	int BombaAgua::getFlujoUML() {
		return this->flujoUML;
		}
	void BombaAgua::setFlujoUML(int flujoUML) {
		this->flujoUML = flujoUML;
		}

	void BombaAgua::activar() {
		// Aquí puedes implementar la lógica para activar la bomba de agua
		}
	bool BombaAgua::verificarNivel() {
		// Aquí puedes implementar la lógica para verificar el nivel de agua
		return true; // Simulación de nivel adecuado
		}
}