# Notesy

A compact, voice-first note-taking device designed to capture ideas without opening a phone and getting pulled into distractions.

Notesy is a personal hardware project inspired by minimalist note-taking devices. The goal is to build a standalone device that makes it easy to capture quick thoughts and review them later, with a simple on-device interface.

> **Project status:** Early design and hardware-planning stage. The schematic is a draft; firmware is an untested prototype. The PCB, power system, enclosure, and final feature set are still being developed. Nothing is claimed as assembled or hardware-tested.

## Project photos and design progress

### Initial concept
![Notesy initial concept sketch](https://halflife.hackclub-assets.com/hackclub-half-life/sessions/GnAePInLRlFkH5MpBRWBChfFoisaIEa2/c4c9b72636034144d44615ec4fb1f01b2aa5403239aa7c53c3cc9c22d83e3f12.jpg)

### KiCad schematic progress
![Notesy KiCad schematic progress](https://halflife.hackclub-assets.com/hackclub-half-life/sessions/GnAePInLRlFkH5MpBRWBChfFoisaIEa2/1af3a69d3f122e02bc7a7494b126e7ea0508af64af50fa75102be85eb5378785.png)

## Goals

- Capture spoken notes with a physical control.
- Show a simple interface on a small display.
- Save recordings locally and leave room for transcription/search features.
- Keep the device focused on note-taking rather than general-purpose phone features.
- Document the build process, decisions, tests, and revisions as the project develops.

## Planned hardware

| Part | Current plan | Status |
| --- | --- | --- |
| Microcontroller | ESP32-S3 module | Exact variant and footprint need confirmation |
| Display | Small I²C OLED | Controller, resolution, voltage, address, and pinout need confirmation |
| Microphone | Digital I²S microphone breakout | Exact assembled module and pinout need confirmation |
| Storage | microSD card socket | Molex 104031-0811 is a candidate; footprint needs verification |
| Input | Three physical buttons | Switch footprints need selection |
| Power | USB-C and rechargeable single-cell battery | Charger, protection, and regulated 3.3 V power path are not finalized |
| Enclosure | Compact handheld enclosure | Dimensions and mounting design not finalized |

The exact module and peripheral datasheets must be checked before assigning final footprints or committing to GPIO pins. The current wiring map is provisional, not a verified build instruction.

## Repository structure

```text
Notesy/
├── README.md
├── BOM.md                  # Half Life funding/parts summary
├── BOM.csv                 # Working component list
├── JOURNAL.md              # Half Life build journal mirror
├── firmware/notesy/
│   └── notesy.ino          # Early Arduino UI/storage-init prototype
├── docs/
│   ├── decisions.md        # Decisions and open hardware blockers
│   ├── wiring.md           # Provisional pin map
│   └── test-log.md         # Current status and next tests
└── hardware/
    ├── kicad/              # KiCad project files to add
    └── renders/             # PCB screenshots/renders to add
```

## Firmware status

The Arduino prototype sets up the OLED, polls the three buttons, and attempts to initialize microSD over SPI. It is **not hardware-tested**. Audio capture, recording files, transcription, Wi-Fi sync, and battery monitoring are not implemented yet. See [firmware/notesy/notesy.ino](firmware/notesy/notesy.ino).

## Current design blockers

- Confirm exact ESP32-S3 module variant and matching footprint.
- Confirm OLED module/controller and connector pin order.
- Select an assembled I²S microphone breakout and verify its pinout.
- Verify the microSD socket footprint against the manufacturer drawing.
- Select and verify the USB-C receptacle footprint and shield-pad handling.
- Design the battery charging/protection and regulated 3.3 V power path.
- Run PCB DRC after assigning real footprints and checking antenna keep-out.
- Generate Gerbers and BOM only from the final reviewed PCB; current fabrication files are not available yet.

## Development notes

- [Design decisions and blockers](docs/decisions.md)
- [Provisional wiring map](docs/wiring.md)
- [Test log](docs/test-log.md)
- [Build journal](JOURNAL.md)
- [Working BOM CSV](BOM.csv)

## Design principles

- **Prototype first:** verify modules and pinouts before designing around them.
- **Keep the hardware honest:** distinguish planned features from features that have been tested.
- **Record decisions:** document why components, pins, libraries, and mechanical choices were selected.
- **Protect recordings:** make network-dependent features optional and clarify what data leaves the device before adding cloud transcription.

---

*Notesy is an ongoing personal hardware project. The repository documents the work-in-progress rather than claiming a finished device.*
