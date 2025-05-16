#include <vanWiFi.h>

// ----------------------------------------------------------------------------
// Connecting to the WiFi network
// ----------------------------------------------------------------------------

// Set web server port number to 80
WiFiServer wifiServer(80);

void initWiFi()
{
  // Network credentials for the home wifi network.
  const char *ssid = HOME_SSID;
  const char *password = HOME_PWD;

  IPAddress local_IP(192, 168, 20, 7);
  IPAddress gateway(192, 168, 20, 1);
  IPAddress subnet(255, 255, 255, 0);

  WiFi.mode(WIFI_STA);

  if (!WiFi.config(local_IP, gateway, subnet))
  {
    Serial.println("STA Failed to configure");
  }

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
