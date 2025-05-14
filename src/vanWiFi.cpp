#include <vanWiFi.h>

// ----------------------------------------------------------------------------
// Connecting to the WiFi network
// ----------------------------------------------------------------------------

// Set web server port number to 80
WiFiServer wifiServer(80);

// Replace with your network credentials
const char *ssid = "Curie";
const char *password = "two2dogs";

void initWiFi()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.printf("Trying to connect [%s] ", WiFi.macAddress().c_str());
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println(WiFi.localIP());
}

WiFiClient getWiFiClient()
{
  return wifiServer.available(); // Listen for incoming clients
}
