#include "pch.h"
#pragma once

namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;
	public ref class BombaAgua {
	private:
		int flujoUML;
	public:
		BombaAgua(int flujoUML);
		
		int getFlujoUML();
		void setFlujoUML(int flujoUML);

		void activar();
		bool verificarNivel();
	};
}