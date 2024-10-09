#include <bluefruit.h>
#include "SensorGas.h"
#include "SensorTemp.h"
#include "Beacon.h"

#define pinGas 5
#define pinRef 28
#define pinTemp 29

float cGas;
float temp;


SensorGas sensorGas(pinGas, pinRef);
SensorTemp sensorTemp(pinTemp);
Beacon beacon;

void setup() {
    Serial.begin(115200);
    while (!Serial) delay(10);
    
    Bluefruit.begin();
    Serial.println("Bluefruit inicializada");
    
    beacon.definirNombre("GTI-3X");

    // leemos una vez antes de empezar emision
    cGas = sensorGas.leerConcentracionGas(); 
    temp = sensorTemp.leerTemperatura();

    // empezamos a emitir
    beacon.empezarEmision(cGas, temp); 
}

void loop() {
    // Leemos gas y temperatura
    cGas = sensorGas.leerConcentracionGas(); 
    temp = sensorTemp.leerTemperatura();

    // Imprimir en Serial
    Serial.print("cGas = ");
    Serial.print(cGas);
    Serial.println(" ppm");
    Serial.print("temp = ");
    Serial.print(temp);
    Serial.println("ºC");
    Serial.println("///////////");

    delay(3000); // Wait before the next loop iteration
}
