#include <AsyncWebSocket.h>
#include "defs.hpp"

#ifndef HANDLERS_HPP
#define HANDLERS_HPP

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len);
String parseMessage(Positions* pos, Temps* temps, Times* times);

#endif