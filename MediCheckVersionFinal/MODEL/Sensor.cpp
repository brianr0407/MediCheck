#include "pch.h"
#include "Sensor.h"


namespace MODEL {
    using namespace System;

    // Constructor por defecto
    Sensor::Sensor() {
    }

    // Constructor con parámetros
    Sensor::Sensor(int idSensor) {
        this->idSensor = idSensor;
    }

    // Getter y Setter
    int Sensor::getIdSensor() {
        return this->idSensor;
    }

    void Sensor::setIdSensor(int id) {
        this->idSensor = id;
    }
}