#ifndef SENSOR_GAS_H
#define SENSOR_GAS_H

#include <Arduino.h>

class SensorGas {
public:
    SensorGas(int gasPin, int refPin);
    float leerConcentracionGas();

private:
    int pinGas;
    int pinRef;
};

#endif
