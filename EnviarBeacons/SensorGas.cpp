//------------------
// SensorGas.cpp
// Mario Luis Mesa
// 28/09/2024
//------------------

#include "SensorGas.h"
#include <math.h>

SensorGas::SensorGas(int gasPin, int refPin) : pinGas(gasPin), pinRef(refPin) {}

float SensorGas::leerConcentracionGas() {
    float vGas = analogRead(pinGas);
    float vRef = analogRead(pinRef);

    // Convertir analogico a voltage
    float voltios = abs((vGas - vRef) / pow(2, 10) * 3.3);

    // Calcular concentracion de gas (ppm)
    float cGas = abs(vGas - vRef) / (-35.35 * 499 * pow(10, 6));

    // Implementacion funcion de calibrado
    float res = (cGas - 3.955) / 1.69;
    
    return res; // Devolver concentracion en ppm
}
