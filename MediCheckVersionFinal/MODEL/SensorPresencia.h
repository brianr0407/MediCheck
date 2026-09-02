#include "pch.h"
#pragma once
#include "Sensor.h"
namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;
	public ref class SensorPresencia: public Sensor {
	private:

	public:
		bool detectarVaso();
		void calibrar();
	};
}