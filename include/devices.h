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

  float solarPanel1; // ID: 0x01
  float solarPanel2; // ID: 0x02
  float solarPanel3; // ID: 0x03
  float solarPanel4; // ID: 0x04

  //Starter Battery Module
  float starterBattery; // ID: 0x05

  // Battery Box Module
  float batteryBoxTemperature; // ID: 0x06
  float batteryBoxFan; // ID: 0x07

  float battery1in; // ID: 0x08
  float battery2in; // ID: 0x09
  float battery1out; // ID: 0x0A
  float battery2out; // ID: 0x0B

  float dcdc20A; // ID: 0x0C
  float dcdc50A; // ID: 0x0D

  // Fuse and Switch Box Module
  float powerSwitch; // ID: 0x0E
  float battery2Switch; // ID: 0x0F
  float solarSwitchSensor; // ID: 0x00
  float inverterFuseSwitchSensor; // ID: 0x11
  float pumpFuseSwitchSensor; // ID: 0x12
  float fridgeFuseSwitchSensor; // ID: 0x13
  float lightsAuxFuseSwitchSensor; // ID: 0x14
  // Lights and Auxilliary Module

  float lightControl; // ID: 0x15

  // Water System Module
  float inputFlowSensor; // ID: 0x16
  float outputFlowSensor; // ID: 0x17
  float waterTank; // ID: 0x18
  float duoettoTemperature; // ID: 0x19

  // Environment Module
  float ambientTemperature; // ID: 0x20

  String jsonDeviceStr[4];

public:
  Devices();
  float getSensor(Sensors sensor);
  void updateValues();
  String toJson();
};

#endif
