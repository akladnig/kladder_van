#ifndef _DISPLAY_H
#define _DISPLAY_H

#include "globals.h"

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using I2C
#define OLED_RESET -1 // Reset pin
#define SCREEN_ADDRESS 0x3C

void initDisplay();
void displayTemperature(float temperature, tm *time);

#endif
