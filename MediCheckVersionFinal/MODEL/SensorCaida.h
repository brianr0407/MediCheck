#include "pch.h"
#pragma once
#include "Sensor.h"
namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;
	public ref class SensorCaida: public Sensor {
	private:
		int reintentos;
	public:
		bool confirmar();
		void calibrar();
	};
}