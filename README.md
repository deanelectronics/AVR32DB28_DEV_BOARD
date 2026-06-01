# AVR32DB28 Dev Board

Open-source development board based on the Microchip AVR32DB28 microcontroller.

## Features

- AVR32DB28 microcontroller (32 KB flash, 8-bit, 4 MHz internal oscillator)
- All GPIO ports broken out via headers for external connections
- Two programming modes via onboard switch: Atmel-ICE (Mode 1) or USB-C Serial UPDI (Mode 2)
- Expandable via addon boards

## Repository Structure

```
hardware/        KiCad schematics and PCB layouts
  mainboard/     Main dev board
  addons/        Addon board designs

firmware/        C firmware projects
  examples/      Standalone example programs
  addons/        Firmware for addon boards

docs/            Documentation
tools/           Development setup scripts
```

## Getting Started

See [docs/programming.md](docs/programming.md) for instructions on setting up the toolchain and flashing firmware.

## Hardware

Schematics and PCB files are located in `hardware/`. Designed in KiCad.

## License

MIT License — see [LICENSE](LICENSE).
