#ifndef BEACON_H
#define BEACON_H

#include <bluefruit.h>

class Beacon {
public:
    Beacon(const char* nombre, const uint8_t* uuid);
    void empezarEmision(float cGas);

private:
    const char* nombreDispositivo;
    uint8_t beaconUUID[16];
};

#endif
