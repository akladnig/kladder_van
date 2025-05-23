#ifndef _BATTERY_H
#define _BATTERY_H

#include "hal.h"
#include "devices.h"

enum class Sensors;

void initBattery();
float getBattery(Sensors sensors);

#endif
