#include "pch.h"
#pragma once
#pragma once
namespace MODEL {
	using namespace System;
	using namespace Collections::Generic;
	public ref class Sensor {
	private:
		int idSensor;
	public:
		Sensor();
		Sensor(int idSensor);
		int getIdSensor();
		void setIdSensor(int id);
	};
}