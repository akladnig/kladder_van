#ifndef _DEVICES_H
#define _DEVICES_H

#include <Arduino.h>
#include "temperature.h"

enum class Sensors
{
  ambientTemperature,
  batteryBoxTemperature
};

class Devices
{
private:
  float ambientTemperature;    // ID: 0x01 range: -xx.x to xx.x
  float batteryBoxTemperature; // ID: 0x02
  float duoettoTemperature;    // ID: 0x03
  String jsonDeviceStr[4];

public:
  Devices();
  float getSensor(Sensors sensor);
  void updateValues();
  String *toJson();
};

#endif
