#!/bin/bash
DFP=/opt/microchip/mplabx/v6.30/packs/Microchip/AVR-Dx_DFP/2.7.321

sudo cp $DFP/gcc/dev/avr32db28/device-specs/specs-avr32db28 /usr/lib/gcc/avr/7.3.0/device-specs/
sudo cp $DFP/gcc/dev/avr32db28/avrxmega3/crtavr32db28.o /usr/lib/avr/lib/avrxmega3/
sudo cp $DFP/gcc/dev/avr32db28/avrxmega3/libavr32db28.a /usr/lib/avr/lib/avrxmega3/
sudo cp $DFP/include/avr/ioavr32db28.h /usr/lib/avr/include/avr/

echo "Klart!"
