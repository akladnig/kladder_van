#ifndef _TEMPERATURE_H
#define _TEMPERATURE_H

#include "hal.h"
#include "devices.h"

#include <DallasTemperature.h>
#include <OneWire.h>

enum class Sensors;

void initTemperatureSensors();
int getTemperatureSensorCount();
void printTemperatureSensorAddresses();
void printAddress(DeviceAddress deviceAddress);
float getTemperature(Sensors sensor);

#endif
