#include <bluefruit.h>
#include "SensorGas.h"
#include "Beacon.h"

#define pinGas 5
#define pinRef 28
// #define pinTemp 29

// UUID for the beacon
uint8_t beaconUUID[16] = {
    'S', 'O', 'Y', '-', 'M', 'A', 'R', 'I',
    'O', '-', 'L', 'O', 'L', 'A', 'S', 'O'
};

SensorGas sensorGas(pinGas, pinRef);
Beacon beacon("GTI-3X", beaconUUID);

void setup() {
    Serial.begin(115200);
    while (!Serial) delay(10);
    
    Bluefruit.begin();
    Serial.println("Bluefruit inicializada");
    
    // Start advertising with initial cGas value
    beacon.empezarEmision(0.0); // Start with a dummy value
}

void loop() {
    float cGas = sensorGas.leerConcentracionGas(); // Read gas concentration

    // Print the values to the serial monitor
    Serial.print("cGas = ");
    Serial.print(cGas);
    Serial.println(" ppm");

    // Update beacon advertising with the new cGas value
    beacon.empezarEmision(cGas);

    delay(500); // Wait before the next loop iteration
}
