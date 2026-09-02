#include "pch.h"
#pragma once

namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;

	public ref class AutentificadorBiometrico {
	public:
		bool escanearHuella(int idEsperado);
	};
}