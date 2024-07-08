#include <AsyncWebSocket.h>
#include <string>
#include "handlers.hpp"


void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
  AwsFrameInfo *info = (AwsFrameInfo*)arg;
  String *parsedData = new String((char*) data);
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
    if (parsedData->startsWith("COMMAND")) {
      const int index = parsedData->indexOf("COMMAND:");
      String command = parsedData->substring(index + 8, len);
      Serial.printf("Command received: %s \n",command);
      Serial2.println(command + '\n');
    }
  }
}

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
  switch (type) {
    case WS_EVT_CONNECT:
      Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
      break;
    case WS_EVT_DISCONNECT:
      Serial.printf("WebSocket client #%u disconnected\n", client->id());
      break;
    case WS_EVT_DATA:
      handleWebSocketMessage(arg, data, len);
      break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
      break;
  }
}