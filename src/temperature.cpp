#include <temperature.h>

// ----------------------------------------------------------------------------
// Definition of the Temperature Sensors
// ----------------------------------------------------------------------------

//TODO all of this should be in a class

const uint8_t temperatureSensor1[8] = {0x28, 0x64, 0x43, 0x46, 0xD4, 0xD9, 0x09, 0xBE};
const uint8_t temperatureSensor2[8] = {0x28, 0xFF, 0x64, 0x1E, 0x87, 0x23, 0xE1, 0x50};

const uint8_t *ambientTemperatureSensor = temperatureSensor1;
const uint8_t *batteryBoxTemperatureSensor = temperatureSensor2;

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

void initTemperatureSensors()
{
  sensors.begin();
}

int getTemperatureSensorCount()
{
  return sensors.getDeviceCount();
}

/// @brief Helper function to print the addresses of the attached temperature sensors
/// which should then be physically labelled.
void printTemperatureSensorAddresses()
{
  int deviceCount = sensors.getDeviceCount();

  // variable to hold device addresses
  DeviceAddress Thermometer;

  Serial.println("Printing addresses...");
  for (int i = 0; i < deviceCount; i++)
  {
    Serial.print("Sensor ");
    Serial.print(i + 1);
    Serial.print(" : ");
    sensors.getAddress(Thermometer, i);
    printAddress(Thermometer);
  }
}

void printAddress(DeviceAddress deviceAddress)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    Serial.print("0x");
    if (deviceAddress[i] < 0x10)
      Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
    if (i < 7)
      Serial.print(", ");
  }
  Serial.println("");
}

/// @brief Returns the temperature of the selected `Sensor` from the `Devices` enum.
///
/// Ignores any *non* temperature `Sensors`
/// @param sensor - a sensor from the Devices enum
/// @return The temperature as a float
float getTemperature(Sensors sensor)
{

  const uint8_t *sensorId;

  switch (sensor)
  {
  case Sensors::ambientTemperature:
    sensorId = ambientTemperatureSensor;
    break;

  case Sensors::batteryBoxTemperature:
    sensorId = batteryBoxTemperatureSensor;
    break;
    //
  default:
    break;
  }

  sensors.requestTemperatures();
  float temperature = sensors.getTempC(sensorId);
  return temperature;
}
