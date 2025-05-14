#ifndef _TEMPERATURE_H
#define _TEMPERATURE_H

#include <hal.h>
#include <DallasTemperature.h>
#include <OneWire.h>

void initTemperatureSensors();
int getTemperatureSensorCount();
void printTemperatureSensorAddresses();
void printAddress(DeviceAddress deviceAddress);
float getTemperature(const uint8_t *sensor);

#endif
