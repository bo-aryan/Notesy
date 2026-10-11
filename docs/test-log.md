# Notesy test log

## 2026-10-11 — Schematic review
- KiCad schematic assembled with ESP32-S3 module, OLED and microphone connectors, microSD socket, three buttons, USB-C input symbol, CC resistors, decoupling capacitors, and EN pull-up/reset capacitor.
- ERC was reported at zero errors after adding no-connect markers and power flags.
- No physical hardware has been assembled or tested.
- No PCB DRC, Gerber export, or electrical test is claimed as complete yet.

## Next tests
- Verify symbols, GPIO assignments and module variant against official datasheets.
- Complete charger/protection/regulator design.
- Assign exact footprints and run DRC.
- Test firmware on actual hardware after modules and wiring are verified.
