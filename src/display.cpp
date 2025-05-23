#include <display.h>

// ----------------------------------------------------------------------------
// Definition of Oled Display
// ----------------------------------------------------------------------------

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// initialize the OLED object
void initDisplay()
{
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }

  // Clear the buffer.
  display.clearDisplay();
}

void displayTemperature(float temperature, tm *time)
// void displayTemperature(float temperature)
{
  display.setTextColor(WHITE);
  display.setCursor(0, 16);
  display.setTextSize(3);
  display.clearDisplay();
  display.print(temperature, 1);
  display.setTextSize(2);
  display.write(0xF7);
  display.setTextSize(3);
  display.print("C");
  display.setCursor(0, 50);
  display.setTextSize(1);
  display.print(time, "%H");
  display.print(":");
  display.print(time, "%M");
  display.display();
}
