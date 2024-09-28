#include "SensorGas.h"
#include <math.h>

GasSensor::GasSensor(int gasPin, int refPin) : pinGas(gasPin), pinRef(refPin) {}

float GasSensor::readGasConcentration() {
    float vGas = analogRead(pinGas);
    float vRef = analogRead(pinRef);

    // Convertir analogico a voltage
    float voltios = abs((vGas - vRef) / pow(2, 10) * 3.3);

    // Calcular conecntracion de gas (ppm)
    float cGas = (vGas - vRef) / (-35.35 * 499 * pow(10, 6));
    
    return cGas; // Devolver concentracion en ppm
}
