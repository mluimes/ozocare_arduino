/**@file Beacon.h */
//------------------
// Mario Luis Mesa
// 28/09/2024
//------------------


#ifndef SENSOR_TEMP_H
#define SENSOR_TEMP_H

#include <Arduino.h>

/**
 * @brief Clase que representa un sensor de temperatura.
 * 
 * La clase SensorTemp se encarga de manejar la lectura del sensor de temperatura
 * conectado a un pin específico de la placa.
 */
class SensorTemp {
public:
/**
     * @brief Constructor de la clase SensorTemp.
     * 
     * Inicializa el sensor de temperatura, especificando el pin al que está conectado.
     * 
     * @param tempPin Pin donde está conectado el sensor de temperatura.
     */
  SensorTemp(int tempPin);

  /**
     * @brief Lee la temperatura ambiente detectada por el sensor.
     * 
     * Realiza una lectura del valor analógico del sensor y lo convierte en grados Celsius.
     * 
     * @return La temperatura en grados Celsius.
     */
  float leerTemperatura();

private:
  int pinTemp; ///< Pin donde está conectado el sensor de temperatura
};

#endif