#include <AsyncWebSocket.h>
#include "web_socket.hpp"

WebSocket::WebSocket(AwsEventHandler handler) {
    this->server = new AsyncWebServer(80);
    this->ws = new AsyncWebSocket("/ws");
    
    this->ws->onEvent(handler);
    this->server->addHandler(this->ws);
    this->server->begin();
}

WebSocket::~WebSocket() {
    this->ws->cleanupClients();
    this->server = NULL;
    this->ws = NULL;
}

bool WebSocket::sendMessage(String message) {
    this->ws->textAll(message);
    return true;
}