//------------------
// SensorTemp.cpp
// Mario Luis Mesa
// 28/09/2024
//------------------

#include "SensorTemp.h"

SensorTemp::SensorTemp(int tempPin) : pinTemp(tempPin) {}

float SensorTemp::leerTemperatura() {
  // leer valor analogico del pin
    float vTemp = analogRead(pinTemp);
    // Serial.println(vTemp);

  // convertir a temperatura
    float temp = (87.0 / 3.3) * vTemp - 18;

    return temp;
}