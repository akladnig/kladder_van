#include <temperature.h>

// ----------------------------------------------------------------------------
// Definition of the Temperature Sensors
// ----------------------------------------------------------------------------

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

float getTemperature(const uint8_t *sensor)
{
  sensors.requestTemperatures();
  float temperature = sensors.getTempC(sensor);
  return temperature;
}
