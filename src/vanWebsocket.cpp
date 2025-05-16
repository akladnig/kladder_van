#include <vanWebsocket.h>

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

void notifyClients()
{
  JsonDocument json;

  char buffer[17];
  size_t len = serializeJson(json, buffer);
  ws.textAll(buffer, len);
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

    const char *action = json["action"];
    if (strcmp(action, "toggle") == 0)
    {
      notifyClients();
    }
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
  const char *ssid = VAN_SSID;
  const char *password = VAN_PWD;

  int channel = 1;
  int ssid_hidden = 1; // hides the network
  int max_connection = 2;

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password, channel, ssid_hidden, max_connection);
  ws.onEvent(onEvent);
  server.addHandler(&ws);
}
