#ifndef _SWITCHES_H
#define _SWITCHES_H

#include "hal.h"
#include "devices.h"

enum class Switches;

void initSwitches();
int getSwitches(Switches switchName);

#endif
