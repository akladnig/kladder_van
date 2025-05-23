#include <main.h>

// Set up Json
JsonDocument readings;

tm *buildTime;

void setup()
{
  Serial.begin(115200);

  readings["sensor"] = "ambientTemperature";
  readings["temperature"] = 0.0;

  initWebSocket();
  initTime();

  buildTime = getTime();

  // Start up the library
  initTemperatureSensors();
  initSwitches();
  initBattery();

  // locate devices on the bus
  Serial.println("V0.1");
  Serial.println("Locating devices...");
  Serial.print("Found ");
  int deviceCount = getTemperatureSensorCount();
  Serial.print(deviceCount, DEC);
  Serial.println(" devices.");
  Serial.println("");

  // printTemperatureSensorAddresses();

  initDisplay();
}

static uint32_t lastWS{0};
static uint32_t deltaWS{1000};
static auto devices = Devices();
static String json;

void loop()
{
  uint32_t now = millis();

  if (now - lastWS >= deltaWS)
  {
    devices.updateValues();
    json = devices.toJson();
    Serial.println(json);
    float temperature = devices.getSensor(Sensors::ambientTemperature);
    displayTemperature(temperature, buildTime);
    notifyClients(json);
    lastWS = millis();
  }
}
