#include "switches.h"
#include "devices.h"
#include "hal.h"

void initSwitches()
{
  pinMode(PWR_SW, INPUT);
}


/// @brief Returns the temperature of the selected `Sensor` from the `Devices` enum.
///
/// Ignores any *non* temperature `Sensors`
/// @param sensor - a sensor from the Devices enum
/// @return The temperature as a float
int getSwitches(Switches switchName)
{
  int switchState;
  switch (switchName)
  {
  case Switches::powerSwitch:
    switchState = digitalRead(PWR_SW);
    break;

  case Switches::battery2Switch:
    switchState = digitalRead(BAT_2_SW);
    break;
    
  default:
    break;
  }
  return switchState;
}
