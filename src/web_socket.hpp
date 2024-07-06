#include <Arduino.h>
#include <AsyncWebSocket.h>

#ifndef WEB_SOCKET_HPP
#define WEB_SOCKET_HPP

class WebSocket {
    private:
        AsyncWebServer *server;
        AsyncWebSocket *ws;
    public:
        WebSocket(AwsEventHandler handler);
        ~WebSocket();
        void startServer();
        bool sendMessage(String message);
};

#endif