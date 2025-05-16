#ifndef __VANWEBSOCKET_H
#define __VANWEBSOCKET_H

#include <ArduinoJson.h>
#include <ESPAsyncWebServer.h>

#include "configuration.h"

void initWebSocket();
void notifyClients();
void handleWebSocketMessage(void *arg, uint8_t *data, size_t len);

#endif
