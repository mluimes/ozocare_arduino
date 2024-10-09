//------------------
// Beacon.h
// Mario Luis Mesa
// 28/09/2024
//------------------

#ifndef BEACON_H
#define BEACON_H

#include <bluefruit.h>

/**
 * @brief Clase de un Beacon de transmisión de datos.
 * 
 * Esta clase se encarga de la configuración y transmisión de datos usando un beacon.
 */
class Beacon {
public:
  /**
     * @brief Constructor de la clase SensorGas.
     */
  Beacon();

  /**
     * @brief Establece el nombre del Beacon.
     * 
     * @param nombre El nombre que se le asignará al Beacon.
     */
  void definirNombre(const char* nombre);

  /**
     * @brief Inicia la emisión del beacon con los valores de gas y temperatura.
     * 
     * @param concentracionGas Concentración de gas en partes por millón (ppm).
     * @param temperatura Temperatura en grados Celsius.
     */
  void empezarEmision(float cGas, float temp);
};

#endif
