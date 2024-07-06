#include <Arduino.h>
#include <HardwareSerial.h>
#include <string.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "web_socket.hpp"
#include "handlers.hpp"

HardwareSerial Printer(1);
WebSocket *ws;

const char* ssid = "TP-Link_F436";
const char* password = "10817308";

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
  AwsFrameInfo *info = (AwsFrameInfo*)arg;
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
    data[len] = 0;
    if (strcmp((char*)data, "toggle") == 0) {
      // ledState = !ledState;
      // notifyClients();
    }
  }
}


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
  Printer.begin(115200, SERIAL_8N1, 4, 2);

  setupWifi();
  ws = new WebSocket(onEvent);
}

void loop() {
  if (Printer.available()) {
    String data = Printer.readStringUntil('\n');
    Serial.println("Data" + data);
    ws->sendMessage(data);
  }
}