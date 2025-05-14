#include <main.h>

// ----------------------------------------------------------------------------
// Definition of global constants
// ----------------------------------------------------------------------------

// Replace with your network credentials
const char *ssid = "Curie";
const char *password = "two2dogs";

// Set web server port number to 80
WiFiServer wifiServer(80);

// Set up Json
JsonDocument readings;

// ----------------------------------------------------------------------------
// Connecting to the WiFi network
// ----------------------------------------------------------------------------

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
  Serial.printf(" %s\n", WiFi.localIP().toString().c_str());
}

tm *buildTime;

void setup()
{
  Serial.begin(115200);

  readings["sensor"] = "ambientTemperature";
  readings["temperature"] = 0.0;

  initWiFi();
  initTime();

  buildTime = getTime();

  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  wifiServer.begin();

  // Start up the library
  initTemperatureSensors();

  // locate devices on the bus
  Serial.println("V0.3");
  Serial.println("Locating devices...");
  Serial.print("Found ");
  int deviceCount = getTemperatureSensorCount();
  Serial.print(deviceCount, DEC);
  Serial.println(" devices.");
  Serial.println("");

  printTemperatureSensorAddresses();

  initDisplay();
}

void loop()
{
  float temperature = getTemperature(temperatureSensor1);
  displayTemperature(temperature, buildTime);

  WiFiClient client = wifiServer.available(); // Listen for incoming clients
  char buffer[20];
  int i = 0;

  if (client)
  { // If a new client connects,
    Serial.println("client connected");

    while (client.connected())
    { // loop while the client's connected
      Serial.print("client available: ");
      Serial.println(String(client.available()));
      while (client.available() > 0)
      {                         // if there's bytes to read from the client,
        char c = client.read(); // read a byte, then
        Serial.write(c);        // print it out the serial monitor
      }

      float temperature = getTemperature(temperatureSensor1);
      displayTemperature(temperature, buildTime);

      char output[256];
      readings["temperature"] = temperature;
      serializeJson(readings, output);

      sprintf(buffer, "%d", i);
      String colon = ": ";
      Serial.println(output);
      client.println(output);
      i++;
      delay(1000);
    }
    client.stop();
    Serial.println("Client disconnected.");
  }
}
