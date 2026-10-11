# Notesy design decisions (working draft)

Updated: 2026-10-11

## Current architecture
- ESP32-S3-based device.
- Small I2C OLED UI.
- Replaceable digital I2S microphone breakout is intended.
- Local microSD storage is intended.
- Three buttons: up, down, select.
- USB-C is planned for wired power/programming.

## Current schematic state
The KiCad schematic has symbols and provisional net labels for the ESP32-S3 module, OLED connector, I2S microphone connector, microSD socket, three buttons, USB-C receptacle, CC resistors, and basic EN/decoupling components. ERC has been brought to zero errors during the current session.

Zero ERC errors does not prove electrical correctness. The schematic is not approved for manufacture yet.

## Open decisions / blockers
1. Confirm the exact ESP32-S3-WROOM-1 variant and its matching footprint.
2. Select an actual assembled I2S microphone breakout and verify its pinout and channel-select wiring.
3. Verify the OLED module/controller, I2C address, voltage, connector order, and footprint.
4. Verify the Molex 104031-0811 microSD socket footprint against the official mechanical drawing.
5. Select the exact USB-C receptacle and verify its footprint/shield pads.
6. Design a proper single-cell battery charging, protection, and regulated 3.3 V power path. Do not connect USB 5 V or a LiPo directly to 3V3.
7. Verify GPIO assignments, strapping pins, and all physical header/module pin numbers.
8. Run PCB DRC and inspect all clearances, antenna keep-out, connector orientation, and mounting constraints before exporting fabrication files.

## Firmware status
An early Arduino-framework UI prototype is in firmware/notesy/notesy.ino. It is not hardware-tested. Audio capture, file recording, transcription, Wi-Fi sync, and battery management are not implemented.
