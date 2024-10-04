#include "Beacon.h"

Beacon::Beacon(const char* nombre, const uint8_t* uuid)
  : nombreDispositivo(nombre) {
  memcpy(beaconUUID, uuid, 16);
}

void Beacon::empezarEmision(float cGas) {
  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();
  Bluefruit.Advertising.addName();
  
  BLEBeacon elBeacon(beaconUUID, (uint32_t)(cGas * 100), 0, 0);
  elBeacon.setManufacturer(0x004C);  // Apple ID
  
  Bluefruit.Advertising.setBeacon(elBeacon);
  
  Bluefruit.Advertising.restartOnDisconnect(true);
  Bluefruit.Advertising.setInterval(32, 244);  // in units of 0.625 ms
  Bluefruit.Advertising.setFastTimeout(30);    // number of seconds in fast mode
  Bluefruit.Advertising.start(0);              // 0 = Don't stop advertising after n seconds
}