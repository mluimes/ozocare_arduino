#include "Beacon.h"

Beacon::Beacon(const char* nombre, const uint8_t* uuid) : deviceName(nombre) {
    memcpy(beaconUUID, uuid, 16);
}

void Beacon::startAdvertising(float cGas) {
    BLEBeacon elBeacon(beaconUUID, (uint32_t)(cGas * 100), 0, 0);
    elBeacon.setManufacturer(0x004C); // Apple ID
    Bluefruit.Advertising.setBeacon(elBeacon);

    Bluefruit.Advertising.restartOnDisconnect(true);
    Bluefruit.Advertising.setInterval(32, 244);    // in units of 0.625 ms
    Bluefruit.Advertising.setFastTimeout(30);      // number of seconds in fast mode
    Bluefruit.Advertising.start(0);                // 0 = Don't stop advertising after n seconds
}