#include <Arduino.h>
#include <HardwareSerial.h>
#include <string.h>
#include <WiFi.h>

HardwareSerial Printer(1);
WiFiClient client;

const char* ssid = "TP-Link_F436";
const char* password = "";

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
}

void loop() {

}