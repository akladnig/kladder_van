#ifndef _CONFIGURATION_H
#define _CONFIGURATION_H

#define USE_HOME_WIFI

#define HOME_SSID "Curie"
#define HOME_PWD "two2dogs"

#define VAN_SSID "kladderVan"
#define VAN_PWD "two2dogs"

#ifdef USE_HOME_WIFI
#define WIFI_MODE WIFI_MODE_STA
#define MY_SSID HOME_SSID
#define MY_PWD HOME_PWD
#else
#define WIFI_MODE WIFI_MODE_AP
#define MY_SSID VAN_SSID
#define MY_PWD VAN_PWD
#endif

#endif