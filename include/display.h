#ifndef _DISPLAY_H
#define _DISPLAY_H

#include <globals.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

void initDisplay();
void displayTemperature(float temperature, tm *time);

#endif
