#ifndef SENSOR_TEMP_H
#define SENSOR_TEMP_H

#include <Arduino.h>

class SensorTemp {
public:
  SensorTemp(int tempPin);
  float leerTemperatura();

private:
  int pinTemp;
};

#endif