#ifndef _VANWIFI_H
#define _VANWIFI_H

#include <Arduino.h>

#include "configuration.h"
#include <WiFi.h>

void initWiFi();
WiFiClient getWiFiClient();

#endif
