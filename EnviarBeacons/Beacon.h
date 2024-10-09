#ifndef BEACON_H
#define BEACON_H

#include <bluefruit.h>

class Beacon {
public:
  Beacon();

  void definirNombre(const char* nombre);
  void empezarEmision(float cGas, float temp);
};

#endif
