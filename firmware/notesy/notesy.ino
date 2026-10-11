/*
 * Notesy firmware prototype
 * Target: ESP32-S3 (Arduino framework)
 *
 * Scope: button input + OLED status UI + microSD initialization.
 * Audio capture/transcription are intentionally not claimed as implemented:
 * the exact I2S microphone breakout and power design still need verification.
 *
 * Libraries: Adafruit GFX, Adafruit SSD1306 (install via Arduino Library Manager).
 * Hardware pin map follows the current provisional Notesy schematic; verify before use.
 */
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

namespace Pins {
constexpr int buttonUp = 1;
constexpr int buttonDown = 2;
constexpr int buttonSelect = 3;
constexpr int oledSda = 11;
constexpr int oledScl = 12;
constexpr int sdSck = 5;
constexpr int sdMiso = 7;
constexpr int sdMosi = 6;
constexpr int sdCs = 8;
}

constexpr int SCREEN_WIDTH = 128;
constexpr int SCREEN_HEIGHT = 64;
constexpr uint8_t OLED_ADDRESS = 0x3C;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
SPIClass sdSpi(FSPI);

const char *menuItems[] = {"New voice note", "Saved notes", "Settings"};
constexpr int MENU_COUNT = sizeof(menuItems) / sizeof(menuItems[0]);
int selectedItem = 0;
bool sdReady = false;

bool pressed(int pin) {
  static unsigned long lastChange[3] = {0, 0, 0};
  static bool previous[3] = {HIGH, HIGH, HIGH};
  const int index = pin == Pins::buttonUp ? 0 : pin == Pins::buttonDown ? 1 : 2;
  const bool current = digitalRead(pin);
  if (current != previous[index]) {
    previous[index] = current;
    lastChange[index] = millis();
  }
  return current == LOW && millis() - lastChange[index] > 35;
}

void drawScreen(const char *status = nullptr) {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(F("NOTESY"));
  display.println(F("----------------"));
  for (int i = 0; i < MENU_COUNT; ++i) {
    display.print(i == selectedItem ? F("> ") : F("  "));
    display.println(menuItems[i]);
  }
  display.println();
  display.print(F("SD: "));
  display.println(sdReady ? F("ready") : F("not found"));
  if (status) display.println(status);
  display.display();
}

void setup() {
  Serial.begin(115200);
  pinMode(Pins::buttonUp, INPUT_PULLUP);
  pinMode(Pins::buttonDown, INPUT_PULLUP);
  pinMode(Pins::buttonSelect, INPUT_PULLUP);

  Wire.begin(Pins::oledSda, Pins::oledScl);
  const bool oledReady = display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS);
  if (!oledReady) {
    Serial.println(F("OLED init failed: check address, wiring, and display controller."));
  } else {
    drawScreen("Booting...");
  }

  sdSpi.begin(Pins::sdSck, Pins::sdMiso, Pins::sdMosi, Pins::sdCs);
  sdReady = SD.begin(Pins::sdCs, sdSpi);
  Serial.println(sdReady ? F("microSD initialized") : F("microSD not detected"));
  if (oledReady) drawScreen("Ready");
}

void loop() {
  static bool upWasPressed = false;
  static bool downWasPressed = false;
  static bool selectWasPressed = false;
  const bool upNow = pressed(Pins::buttonUp);
  const bool downNow = pressed(Pins::buttonDown);
  const bool selectNow = pressed(Pins::buttonSelect);

  if (upNow && !upWasPressed) {
    selectedItem = (selectedItem + MENU_COUNT - 1) % MENU_COUNT;
    drawScreen();
  }
  if (downNow && !downWasPressed) {
    selectedItem = (selectedItem + 1) % MENU_COUNT;
    drawScreen();
  }
  if (selectNow && !selectWasPressed) {
    if (selectedItem == 0) {
      drawScreen("Audio capture TBD");
      Serial.println(F("New voice note selected; I2S recording is not implemented yet."));
    } else if (selectedItem == 1) {
      drawScreen(sdReady ? "Storage ready" : "Insert/check card");
    } else {
      drawScreen("Prototype build");
    }
  }
  upWasPressed = upNow;
  downWasPressed = downNow;
  selectWasPressed = selectNow;
  delay(5);
}
