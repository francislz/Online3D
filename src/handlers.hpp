#include <AsyncWebSocket.h>

#ifndef HANDLERS_HPP
#define HANDLERS_HPP

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len);

#endif