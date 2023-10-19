# Proyecto de Redes e IoT con Arduino

Este proyecto se centra en la implementación de funcionalidades de redes e IoT (Internet de las Cosas) utilizando Arduino.Detecta el monóxido de carbono del ambiente y emite alarmas sonoras, visuales y notificaciones en panel de ThingsBoard.

## Requerimientos

Kit:
- Arduino MKR1000
- Sensor de Gas MQ7
- Buzzer
- Leds

Librerias:
- [WiFi101](https://www.arduino.cc/reference/en/libraries/wifi101/)
- [ThingsBoard Client SDK](https://github.com/thingsboard/thingsboard-client-sdk)

## Uso
1. `config_example.h`: Un archivo de cabecera de ejemplo que contiene configuraciones y credenciales para la conexión.
2. `networking-iot.ino`: El archivo principal de sketch de Arduino que implementa la funcionalidad de redes e IoT.
3. Abre el archivo `networking-iot.ino` en el IDE de Arduino o editor/IDE de preferencia y sube el sketch a la placa Arduino.

## Contribuidores
- Camilo Godoy
- Constanza Moya
- Gabriel Aillapán
- Jorge Mainhard