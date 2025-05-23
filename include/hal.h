#ifndef _HAL_H
#define _HAL_H

#include <Arduino.h>

// Data wire is plugged into pin 15 on the ESP32
#define ONE_WIRE_BUS 15

// OLED Display pins - SCL and SDA are already defined by ESP32
#define SCL_OLED 22
#define SDA_OLED 21

// Batteries 
#define BAT_1_IN 36

// Switches
#define PWR_SW 39
#define BAT_2_SW 34

#endif
