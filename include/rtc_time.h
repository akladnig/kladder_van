#ifndef _RTC_TIME_H
#define _RTC_TIME_H

#include <Arduino.h>

#include <time.h>

void initTime();
tm *getTime();
void displayTimeStamp();

#endif
