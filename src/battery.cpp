#include "battery.h"
#include "devices.h"
#include "esp32-hal-adc.h"
#include "hal.h"

void initBattery()
{
  pinMode(BAT_1_IN, INPUT);
}


/// @brief Returns the temperature of the selected `Sensor` from the `Devices` enum.
///
/// Ignores any *non* temperature `Sensors`
/// @param sensor - a sensor from the Devices enum
/// @return The temperature as a float
float getBattery(Sensors battery)
{
  uint16_t analogValue;
  switch (battery)
  {
  case Sensors::battery1in:
    analogValue = analogReadMilliVolts(BAT_1_IN);
    break;
  case Sensors::battery2in:
    analogValue = analogReadMilliVolts(BAT_1_IN);
    break;

  default:
    break;
  }
  // convert the analog value to a voltage.
  // It is expected that the nominal battery voltage range is between 10V-14.4V
  // Given the non-linear conversion the voltage has been set to provide a voltage
  // of 3.0V at 15.0V which is equivalent to 4095 
  
  return analogValue;
}
