# OzoCare - Arduino

## Descripción

Este repositorio contiene el código para el dispositivo **Arduino** del proyecto OzoCare que recolecta mediciones de sensores ambientales como la temperatura y concentración de gases. Los datos son enviados al backend mediante una conexión WiFi utilizando una API REST.

### Funcionalidades:
- Leer mediciones de sensores (temperatura y concentración de gases).
- Enviar las mediciones al backend para su almacenamiento.

## Despliegue

### Requisitos previos:
- **Arduino IDE** instalado.
- Placa Arduino con capacidad WiFi (por ejemplo, **ESP8266** o **ESP32**).
- Sensores de temperatura y gas conectados a la placa.

### Pasos para desplegar:

1. Clonar el repositorio:
    ```bash
    git clone https://github.com/usuario/ozocare-arduino.git
    cd ozocare-arduino
    ```

2. Abrir el archivo `.ino` en el **Arduino IDE**.

3. Configurar la red WiFi y la URL del servidor:
    - En el archivo `.ino`, modifica las siguientes líneas con tu red WiFi y el URL del backend:
      ```cpp
      const char* ssid = "tuSSID";
      const char* password = "tuPASSWORD";
      const char* serverUrl = "http://192.168.x.x:3000/api/v1/medidas";
      ```

4. Seleccionar la placa adecuada y el puerto correspondiente en el **Arduino IDE**.

5. Compilar y cargar el código en la placa Arduino.