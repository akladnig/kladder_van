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
  jsonDeviceStr[0] = String("{");
  jsonDeviceStr[5] = String("}");
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
  batteryBoxTemperature = getTemperature(Sensors::batteryBoxTemperature);
  powerSwitch = getSwitches(Switches::powerSwitch);
  battery1in = getBattery(Sensors::battery1in);
}

/// @brief Initialise the JSON string. Each device is referenced by it's ID, with the value
/// to be updated starting at offset 5
String Devices::toJson()
{
  String jsonStr = String();

  updateValues();
  String bbtStr = String(batteryBoxTemperature, 1);
  String bbtJsonStr = String("\"0x06\":{\"0x04\":" + bbtStr + "},");

  String atStr = String(ambientTemperature, 1);
  String atJsonStr = String("\"0x20\":{\"0x04\":" + atStr + "},");

  String pswStr = String(powerSwitch, 1);
  String pswJsonStr = String("\"0x0E\":{\"0x09\":" + pswStr + "},");

  String b1iStr = String(battery1in, 1);
  String b1iJsonStr = String("\"0x08\":{\"0x01\":" + b1iStr + "}");

  jsonDeviceStr[1] = bbtJsonStr;
  jsonDeviceStr[2] = atJsonStr;
  jsonDeviceStr[3] = pswJsonStr;
  jsonDeviceStr[4] = b1iJsonStr;

  for (String str : jsonDeviceStr)
  {
    jsonStr += str;
  }
  return jsonStr;
}
