//------------------
// SensorGas.h
// Mario Luis Mesa
// 28/09/2024
//------------------

/**
 * @brief Clase que maneja el sensor de gas
 * 
 * Esta clase se encarga de las lecturas del sensor de gas y realizar 
 * cálculos relacionados con la concentración de gas.
 */

#ifndef SENSOR_GAS_H
#define SENSOR_GAS_H

#include <Arduino.h>

class SensorGas {
public:
  /**
     * @brief Constructor de la clase SensorGas.
     * 
     * @param pinGas Pin donde está conectado el sensor de gas.
     * @param pinRef Pin de referencia para el sensor de gas.
     */
  SensorGas(int gasPin, int refPin);
  /**
     * @brief Lee la concentración de gas detectada por el sensor.
     * 
     * @return La concentración de gas en partes por millón (ppm).
     */
  float leerConcentracionGas();

private:
  int pinGas;  ///< Pin donde está conectado el sensor de gas.
  int pinRef;  ///< Pin de referencia para calibración del sensor de gas.
};

#endif
