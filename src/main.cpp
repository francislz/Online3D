#include <Arduino.h>
#include <HardwareSerial.h>
#include <string.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "web_socket.hpp"
#include "handlers.hpp"

WebSocket *ws;

const char* ssid = "TP-Link_F436";
const char* password = "10817308";


void setupWifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); 
}

void setup() {
  Serial.begin(9600);
  Serial1.begin(115200, SERIAL_8N1, 4, 2);

  setupWifi();
  ws = new WebSocket(onEvent);
}

void loop() {
  if (Serial1.available()) {
    String data = Serial1.readStringUntil('\n');
    Serial.println("Data" + data);
    ws->sendMessage(data);
  }
}