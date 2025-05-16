#ifndef _MAIN_H
#define _MAIN_H

// The mother of all embedded development...
#include <Arduino.h>

#include "globals.h"
#include "hal.h"

// #include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>

#include <SPI.h>
#include <Wire.h>

// My includes
#include "display.h"
#include "temperature.h"
#include "vanWiFi.h"
#include "vanWebsocket.h"
#include "rtc_time.h"

#endif