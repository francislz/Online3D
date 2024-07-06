#include <AsyncWebSocket.h>
#include <ArduinoJson.h>
#include "handlers.hpp"

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
  switch (type) {
    case WS_EVT_CONNECT:
      Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
      break;
    case WS_EVT_DISCONNECT:
      Serial.printf("WebSocket client #%u disconnected\n", client->id());
      break;
    case WS_EVT_DATA:
      // handleWebSocketMessage(arg, data, len);
      break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
      break;
  }
}

String parseMessage(Positions* pos, Temps* temps, Times* times) {
    JsonDocument doc;
    doc["x"] = pos->x;
    doc["y"] = pos->y;
    doc["z"] = pos->z;
    doc["bedTemp"] = temps->bed;
    doc["nozzle"] = temps->nozzle;
    doc["ellapsed"] = times->ellapse;
    doc["remaining"] = times->remaining;

    String output;
    serializeJson(doc, output);
    return output;
}