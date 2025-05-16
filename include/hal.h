
#ifndef _HAL_H
#define _HAL_H

#include <Arduino.h>

const uint8_t temperatureSensor1[8] = {0x28, 0x64, 0x43, 0x46, 0xD4, 0xD9, 0x09, 0xBE};
const uint8_t temperatureSensor2[8] = {0x28, 0xFF, 0x64, 0x1E, 0x87, 0x23, 0xE1, 0x50};

// Data wire is plugged into pin 15 on the ESP32
#define ONE_WIRE_BUS 15

// OLED Display pins - SCL and SDA are already defined by ESP32
#define SCL_OLED 22
#define SDA_OLED 21

#endif
