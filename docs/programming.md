# Programming the AVR32DB28

The board has two programming modes, selectable via the onboard switch:

| Mode | Connector | Programmer |
|------|-----------|------------|
| 1    | UPDI header | Atmel-ICE |
| 2    | USB-C | Serial UPDI (no external programmer needed) |

---

## Linux Setup (USB-C / Serial UPDI)

### 1. Install the toolchain

```bash
sudo apt install gcc-avr avr-libc binutils-avr avrdude
pip install pymcuprog
```

### 2. Install device support for AVR32DB28

Run the provided script (requires MPLAB X to be installed):

```bash
bash tools/install_dfp.sh
```

### 3. Build and flash

Set the switch to **Mode 2**, connect the USB-C cable, then:

```bash
cd firmware/examples/blink
make flash
```

---

## Windows Setup (USB-C / Serial UPDI, Microchip Studio)

### 1. Install avrdude

Download the avrdude 7.x Windows release (a single `.exe`, no installer needed):
- Search for **avrdude/avrdude releases** on GitHub
- Download the Windows x64 zip and extract `avrdude.exe`
- Create the folder `C:\avrdude\` and place `avrdude.exe` inside it

### 2. Find your COM port

Set the switch to **Mode 2** and connect the USB-C cable. Open Device Manager
(`Win+X` → Device Manager) and look under **Ports (COM & LPT)** for an entry
like `USB-SERIAL CH340 (COM3)`. Note the COM number.

### 3. Configure Microchip Studio

Go to **Tools → External Tools → Add** and fill in:

| Field             | Value                                                                                         |
|-------------------|-----------------------------------------------------------------------------------------------|
| Title             | Flash Serial UPDI                                                                             |
| Command           | `C:\avrdude\avrdude.exe`                                                                      |
| Arguments         | `-c serialupdi -p avr32db28 -P COMXX -b 115200 -U flash:w:"$(ProjectDir)$(TargetName).hex":i` |
| Initial directory | `$(ProjectDir)`                                                                               |

Replace `COMXX` with your actual COM port (e.g. `COM3`).

Check **Use Output Window**, then click OK.

### 4. Build and flash

1. Build the project as usual (`F7` or **Build → Build Solution**)
2. Go to **Tools → Flash Serial UPDI**
3. The output window will show the result

---

## Troubleshooting

| Error | Cause | Fix |
|-------|-------|-----|
| `cannot open port` | Wrong COM port | Check Device Manager, update Arguments in External Tools |
| `UPDI initialisation failed` | Wrong mode or bad connection | Verify switch is in Mode 2 and USB-C is connected |
| No entry under COM & LPT | Missing CH340 driver | Search for and install "CH340 driver" |
