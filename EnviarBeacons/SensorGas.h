#ifndef SENSOR_GAS_H
#define SENSOR_GAS_H

#include <Arduino.h>

class GasSensor {
public:
    GasSensor(int gasPin, int refPin);
    float readGasConcentration();

private:
    int pinGas;
    int pinRef;
};

#endif
