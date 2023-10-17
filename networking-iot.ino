#include <WiFi101.h>
#include <TBPubSubClient.h>

#include "config.h"

WiFiClient wifiClient;
PubSubClient client(wifiClient);

void setup() {
  Serial.begin(115200);
  delay(10);

  // Conexión WiFi
  Serial.println();
  Serial.print("Conectando a: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Conexión WiFi establecida");

  client.setServer(thingsboardServer, thingsboardPort);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }

  // Simula la lectura de un sensor y envía el valor a ThingsBoard
  float sensorValue = analogRead(A0) * 5.0 / 1023.0;
  String payload = "{\"analog_sensor\": " + String(sensorValue, 2) + "}";
  client.publish("v1/devices/me/telemetry", payload.c_str());

  delay(10000); // Envía datos cada 10 segundos (ajustable)
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando a ThingsBoard...");
    if (client.connect("ArduinoMKR1000", token, NULL)) {
      Serial.println("Conectado");
    } else {
      Serial.print("falló, rc=");
      Serial.print(client.state());
      Serial.println(" Intentando de nuevo en 5 segundos");
      delay(5000);
    }
  }
}