# Notesy wiring map — provisional

This map reflects the current draft schematic and must be checked against the exact hardware modules before use.

| Function | ESP32-S3 GPIO | Net |
|---|---:|---|
| OLED SDA | GPIO11 | OLED_SDA |
| OLED SCL | GPIO12 | OLED_SCL |
| microSD SCK | GPIO5 | SD_SCK |
| microSD MOSI / CMD | GPIO6 | SD_MOSI |
| microSD MISO / DAT0 | GPIO7 | SD_MISO |
| microSD CS / DAT3 | GPIO8 | SD_CS |
| Microphone BCLK | GPIO17 | MIC_BCLK |
| Microphone WS | GPIO18 | MIC_WS |
| Microphone data out | GPIO21 | MIC_DOUT |
| Up button | GPIO1 | BTN_UP |
| Down button | GPIO2 | BTN_DOWN |
| Select button | GPIO3 | BTN_SELECT |

Power:
- 3V3 is intended to feed the ESP32 module and compatible peripherals.
- GND is the common return.
- USB_5V must remain separate from 3V3 until the power circuit is designed.
- The battery charger/protection/regulator block is not finalized.

Do not use this provisional map to order or assemble hardware without verifying the exact ESP32-S3 module, microphone breakout, OLED, socket and USB-C footprints.
