//------------------
// EnviarBeacons.ino
// Mario Luis Mesa
// 28/09/2024
//------------------

#include <bluefruit.h>
#include "SensorGas.h"
#include "SensorTemp.h"
#include "Beacon.h"

/// Pins sparkfun
#define pinGas 5
#define pinRef 28
#define pinTemp 29

/// Variables
float cGas;
float temp;

/// Objetos de sensores
SensorGas sensorGas(pinGas, pinRef);
SensorTemp sensorTemp(pinTemp);

/// Objeto beacon
Beacon beacon;

/**
 * @brief Función de configuración inicial.
 *
 * Se inicializa la comunicación serial, se configuran los sensores de gas y temperatura, 
 * y se establece la comunicación con el beacon. También se lee una vez los valores de gas y temperatura
 * antes de comenzar la emisión del beacon.
 */
void setup() {
    Serial.begin(115200);
    while (!Serial) delay(10);
    
    // Inicializar Bluetooth con Bluefruit
    Bluefruit.begin();
    Serial.println("Bluefruit inicializada");
    
    // Nombre del beacon
    beacon.definirNombre("GTI-3X");

    // Leer gas y temperatura antes de empezar a emitir
    cGas = sensorGas.leerConcentracionGas(); 
    temp = sensorTemp.leerTemperatura();

    // Iniciar la emisión del beacon
    beacon.empezarEmision(cGas, temp); 
}

/**
 * @brief Función principal que se ejecuta en bucle.
 *
 * En este bucle se leen los valores del sensor de gas y temperatura en cada iteración, 
 * se imprimen por consola y se espera 3 segundos antes de la siguiente lectura.
 */
void loop() {
    // Leer la concentración de gas
    cGas = sensorGas.leerConcentracionGas(); 
    
    // Leer la temperatura
    temp = sensorTemp.leerTemperatura();

    // Imprimir los valores en la consola serial
    Serial.print("cGas = ");
    Serial.print(cGas);
    Serial.println(" ppm");
    Serial.print("temp = ");
    Serial.print(temp);
    Serial.println("ºC");
    Serial.println("///////////");

    // Esperar 3 segundos antes de la próxima iteración
    delay(3000); 
}
