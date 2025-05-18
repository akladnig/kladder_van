#include "devices.h"

class Characteristics
{
  byte voltage = 0x01;
  byte amperage = 0x02;
  byte kwH = 0x03;
  byte temperature = 0x04;
  byte humidity = 0x05;
  byte percentage = 0x06;
  byte capacity = 0x07;
  byte flowRate = 0x08;
  byte switchState = 0x09;
};

Devices::Devices()
{
  jsonDeviceStr[0] = String("[");
  jsonDeviceStr[3] = String("]");
}

float Devices::getSensor(Sensors sensor)
{
  switch (sensor)
  {
  case Sensors::ambientTemperature:
    return getTemperature(sensor);

  case Sensors::batteryBoxTemperature:
    return getTemperature(sensor);

  default:
    return 0.0;
  }
}

void Devices::updateValues()
{
  ambientTemperature = getTemperature(Sensors::ambientTemperature);
}

/// @brief Initialise the JSON string. Each device is referenced by it's ID, with the value
/// to be updated starting at offset 5
String *Devices::toJson()
{
  updateValues();
  String atStr = String(ambientTemperature, 1);
  String atJsonStr = String("{\"01\":" + atStr + "}");

  jsonDeviceStr[1] = atJsonStr;
  return jsonDeviceStr;
}
