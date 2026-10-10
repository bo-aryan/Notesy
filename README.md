# Notesy

A compact, voice-first note-taking device designed to capture ideas without opening a phone and getting pulled into distractions.

Notesy is a personal hardware project inspired by minimalist note-taking devices. The goal is to build a standalone device that makes it easy to capture quick thoughts and review them later, with a simple on-device interface.

> **Project status:** Early design and hardware-planning stage. The electronics, firmware, enclosure, and final feature set are still being developed. Details below describe the current plan, not a completed or tested device.

## Goals

- Capture spoken notes with a physical control.
- Show a simple interface on a small display.
- Save recordings locally and leave room for transcription/search features.
- Keep the device focused on note-taking rather than general-purpose phone features.
- Document the build process, decisions, tests, and revisions as the project develops.

## Planned hardware

| Part | Current plan | Status |
| --- | --- | --- |
| Microcontroller | ESP32 USB development board | Exact board/model to be confirmed |
| Display | 1.3-inch, 4-pin I²C OLED | Controller, resolution, voltage, and pinout to be confirmed |
| Microphone | Digital I²S microphone module | Exact module and pinout to be confirmed |
| Storage | Local storage for recordings/notes; microSD is under consideration | Not finalised |
| Input | Physical recording/control button(s) | Layout to be decided |
| Power | USB during development; portable rechargeable power planned | Battery and charging/protection design not finalised |
| Enclosure | Compact handheld enclosure | Dimensions and mounting design not finalised |

The exact ESP32 board and module datasheets must be checked before assigning KiCad footprints or committing to GPIO pins. Do not treat the current parts list as a verified wiring diagram.

## Repository structure

The project files will be organised as they are created. The intended structure is:

```text
Notesy/
├── README.md
├── BOM.md                  # Parts list / funding log
├── JOURNAL.md              # Build journal mirrored from Hack Club Half Life
├── hardware/
│   ├── kicad/               # KiCad schematic, PCB, libraries and project files
│   ├── datasheets/          # Reference datasheets, where licensing permits
│   └── renders/             # PCB renders and design screenshots
├── firmware/                # Embedded software
├── enclosure/               # CAD files and exports
└── docs/
    ├── decisions.md         # Design decisions and trade-offs
    ├── wiring.md            # Verified pin mappings and wiring notes
    └── test-log.md          # Bench tests and results
```

Directories will be added when there are actual files to put in them.

## Development roadmap

- [x] Sketch the initial device concept.
- [ ] Confirm the exact ESP32 development board.
- [ ] Identify the OLED controller, resolution, and pinout.
- [ ] Select the I²S microphone and confirm its electrical requirements.
- [ ] Draw the first KiCad schematic using the verified pinouts.
- [ ] Review power, USB, GPIO availability, and connector orientation.
- [ ] Assign footprints based on the actual modules and mechanical dimensions.
- [ ] Lay out the PCB and run ERC/DRC checks.
- [ ] Prototype and test audio capture, display, storage, and power separately.
- [ ] Build the firmware interface and note workflow.
- [ ] Design and test the enclosure.
- [ ] Document working features, limitations, and build instructions.

## Design notes

- **Prototype-first:** verify modules and pinouts before designing around them.
- **Keep the hardware honest:** distinguish planned features from features that have been tested.
- **Record decisions:** note why components, pins, libraries, and mechanical choices were selected.
- **Protect recordings:** before adding cloud transcription or other network services, define what data leaves the device and make network-dependent features optional.

## Progress log

Development notes and milestone updates belong in [JOURNAL.md](JOURNAL.md). The current parts/funding record is in [BOM.md](BOM.md).

## Inspiration

Notesy is an independent implementation inspired by the idea of a minimalist, distraction-free note device. Component choices, circuit design, firmware, and enclosure are being developed for this build.

---

*This README will be updated as the design becomes concrete and features are tested.*
