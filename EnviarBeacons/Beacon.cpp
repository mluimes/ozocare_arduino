#include "Beacon.h"

Beacon::Beacon() {
}

void Beacon::definirNombre(const char* nombre) {
  Bluefruit.setName(nombre);
  Bluefruit.ScanResponse.addName();
}

void Beacon::empezarEmision(float cGas, float temp) {
  Serial.println(" empezarEmision() ");

  Serial.println(" Bluefruit.Advertising.stop(); ");
  Bluefruit.Advertising.stop();  // ya lo enchufo luego

  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();

  // incluir nombre
  Serial.println(" Bluefruit.Advertising.addName(); ");
  Bluefruit.Advertising.addName();

  // definir beacon
  Serial.println(" Bluefruit.Advertising.setBeacon( elBeacon ); ");
  // UUID
  uint8_t beaconUUID[16] = {
    'S', 'O', 'Y', '-', 'M', 'A', 'R', 'I',
    'O', '-', 'L', 'O', 'L', 'A', 'S', 'O'
  };
  BLEBeacon elBeacon(beaconUUID, (cGas * 100), temp, 0);
  elBeacon.setManufacturer(0x004C);  // Apple ID
  Bluefruit.Advertising.setBeacon(elBeacon);

  //
  //
  //
  Bluefruit.Advertising.restartOnDisconnect(true);
  Bluefruit.Advertising.setInterval(32, 244);  // in units of 0.625 ms
  Bluefruit.Advertising.setFastTimeout(30);    // number of seconds in fast mode
  Bluefruit.Advertising.start(0);              // 0 = Don't stop advertising after n seconds
  Serial.println(" Bluefruit.Advertising.start(0);");
}