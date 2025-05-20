#include <vanWebsocket.h>

// Based on example code from https://github.com/ESP32Async/ESPAsyncWebServer/blob/main/examples/WebSocket/WebSocket.ino

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

void notifyClients(String json)
{
  int len = json.length() + 1;
  char buffer[len];
  json.toCharArray(buffer, len);
  Serial.println(buffer);
  ws.textAll(buffer);
}

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len)
{
  AwsFrameInfo *info = (AwsFrameInfo *)arg;
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT)
  {

    JsonDocument json;
    DeserializationError err = deserializeJson(json, data);
    if (err)
    {
      Serial.print(F("deserializeJson() failed with code "));
      Serial.println(err.c_str());
      return;
    }

    // const char *action = json["action"];
    // if (strcmp(action, "toggle") == 0)
    // {
    //   notifyClients();
    // }
  }
}

void onEvent(AsyncWebSocket *server,
             AsyncWebSocketClient *client,
             AwsEventType type,
             void *arg,
             uint8_t *data,
             size_t len)
{

  switch (type)
  {
  case WS_EVT_CONNECT:
    // ws.textAll("new client connected");
    Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
    break;
  case WS_EVT_DISCONNECT:
    Serial.printf("WebSocket client #%u disconnected\n", client->id());
    break;
  case WS_EVT_DATA:
    handleWebSocketMessage(arg, data, len);
    break;
  case WS_EVT_PONG:
  case WS_EVT_ERROR:
    break;
  }
}

void initWebSocket()
{
  // Network credentials for the van wifi network.
  const char *ssid = MY_SSID;
  const char *password = MY_PWD;

  int channel = 1;
  int ssid_hidden = 1; // hides the network
  int max_connection = 2;

  WiFi.mode(WIFI_MODE);

  IPAddress local_IP(192, 168, 20, 7);
  IPAddress gateway(192, 168, 20, 1);
  IPAddress subnet(255, 255, 255, 0);

  IPAddress myIP;

#ifdef USE_HOME_WIFI
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

  myIP = WiFi.localIP();
#else
  if (!WiFi.softAPConfig(local_IP, gateway, subnet))
  {
    Serial.println("AP Failed to configure");
  }

  WiFi.softAP(ssid, password, channel, ssid_hidden, max_connection);

  myIP = WiFi.softAPIP();
#endif

  Serial.print("IP address: ");
  Serial.println(myIP);

  ws.onEvent(onEvent);
  server.addHandler(&ws);
  server.begin();
}
