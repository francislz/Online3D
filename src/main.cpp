#include <Arduino.h>
#include <HardwareSerial.h>
#include <string.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "web_socket.hpp"
#include "handlers.hpp"
#include "defs.hpp"

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
  Positions pos;
  pos.x = "10.0";
  pos.y = "11.0";
  pos.z = "0.4";

  Times time;
  time.ellapse = "00:01:31";
  time.remaining = "00:03:07";

  Temps temps;
  temps.bed = "65";
  temps.nozzle = "215";

  String output = parseMessage(&pos, &temps, &time);
  ws->sendMessage(output);
  if (Printer.available()) {
    Serial.println("UART Connect started");
    String data = Printer.readStringUntil('\n');
    Serial.println("Data: " + data);
  }
  delay(5000);
}