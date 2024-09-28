#include <bluefruit.h>
#include "SensorGas.h"
#include "Beacon.h"

#define pinGas 5
#define pinRef 28
// #define pinTemp 29

// UUID for the beacon
uint8_t beaconUUID[16] = {
    'E', 'P', 'S', 'G', '-', 'G', 'T', 'I',
    '-', 'P', 'R', 'O', 'Y', '-', '3', 'A'
};

GasSensor gasSensor(pinGas, pinRef);
Beacon beacon("GTI-3X", beaconUUID);

void setup() {
    Serial.begin(115200);
    while (!Serial) delay(10);
    
    Bluefruit.begin();
    Serial.println("Bluefruit inicializada");
    
    // Start advertising with initial cGas value
    beacon.startAdvertising(0.0); // Start with a dummy value
}

void loop() {
    float cGas = gasSensor.readGasConcentration(); // Read gas concentration

    // Print the values to the serial monitor
    Serial.print("cGas = ");
    Serial.print(cGas);
    Serial.println(" ppm");

    // Update beacon advertising with the new cGas value
    beacon.startAdvertising(cGas);

    delay(2000); // Wait before the next loop iteration
}
