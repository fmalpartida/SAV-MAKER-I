# SAV-MAKER-I
## Introduction

The SAV MAKER I is an “open hardware” project made in Spain based on the popular vinciDuino board, predecessor of 
Arduino's Leonardo board and fully compatible with it. 
This development has been carried out for the Telecom Engineering "Applied Electronics" course carried out in the
UMA (Universidad de Málaga). On day one, students receive a bare PCB and a set of components to assemble and will
use it for some of their course projects.

![SAV MAKER I Rev A] (https://github.com/fmalpartida/SAV-MAKER-I/blob/master/images/SAV%20MAKER%20I%20Rev%20A%20-%20PCBs.JPG)

The SAV MAKER I is an “open hardware” project, a board with an 8-bit microcontroller similar to the Arduino Leonardo
and fully compatible with it. The spirit of the project is to enable students to analyse, build on and share their work.
At the end of the year, the board will be revised with their contributions, and who knows, we may use the highest rated board
on next year's course. I will be fun to see how the board evolves over the years.

Beign an open project where anyone can be part of the design team; anyone can bring knowledge, comments and ideas for 
developing either an Arduino compatible training board or a programmable board using the Atmel environment without an 
external programmer. It is not limited to students. However, in comparison with other similar “open hardware” projects is 
that SAV MAKER I has been designed for people to  learn and build it. 

It is not a board designed to be sold or manufactured in large quantities but instead is designed for anyone to assemble it 
at home. This is the reason why it uses the largest possible SMD components. However, the design is perfectly fit to be ordered
in large quantities. The cost tries to reach the minimum possible in order to spread the SAV MAKER I board concept and the 
real open hardware’s spirit.

Cost transparency is a must when it comes to “open hardware” especially when a community works selflessly.
On this page, you will find all the information needed to order the electronic components and make the board from scratch, 
also you will find tutorials to start using the board and projects undertaken by its users.

Currently the latest version of the board is Rev A, you can find all the related files in the download section.

## Specifications
The SAV MAKER I has the same form factor and connectors as the Arduino Pro, however it uses a different processor, the 
Atmega32u4. This chip has the same features of the Atmega328 (used in UNO) with the added benefit of having built in USB.

- **Microcontroller**: ATmega32U4
- **Operating Voltage**: 5V
- **Input Voltage (recommended)**: 5V
- **Digital I/O Pins**: 14 (of which 6 provide PWM output) + 6 (analog pins)
- **Analog Input Pins**: 6
- **DC Current per I/O Pin**:	40 mA
- **DC Current for 3.3V Pin**: 50 mA
- **Flash Memory**: 32 KB (-2KB bootloader)
- **SRAM**: 2,5 KB
- **EEPROM**: 1 KB
- **Clock Speed**: 16 MHz

### Supply
The SAV MAKER I can be powered via the USB connection or with a 5V external power supply. The power source is selected 
automatically.
External (non-USB) power can come either from an AC-to-DC adapter (wall-wart) or battery. The adapter can be connected 
to its supply pins or via USB. Leads from a battery can be inserted in the Gnd and 5V pin headers of the POWER connector.
- *VIN*. Not used.
- *5V (in or out)*. The regulated power supply used to power the microcontroller and other components on the board. This can be used
as a voltage input or output, depending on how you are sourcing power to the board.
- *3V3 (out)*. Are derived from the on chip regulator and accessible through the 3.3V pin. This pin will only supply up to 
50mA (25 mA when the usb is in use).
- *GND*. Ground pins.

###Memory
The ATmega32U4 has 32 KB. It also has 2,5 KB of SRAM and 1 KB of EEPROM (which can be read and written with the EEPROM library).

### Input/Output
![SAV MAKER I Rev A Render] ()
#### Discrete IOs
Each of the 14 digital pins on the SAV MAKER I can be used as an input or output, using pinMode(), digitalWrite(), and 
digitalRead() functions. They operate at 5 volts. Each pin can provide or receive a maximum of 40mA and has an internal 
pull-up resistor (disconnected by default) of 20-50 kOhms. In addition, some pins have specialized functions:

- **Serial**: 0 (RX) and 1 (TX). Used to receive (RX) and transmit (TX) TTL serial data. Broken out on UART header too.
- **External Interrupts**: 2 and 3. These pins can be configured to trigger an interrupt on a low value, a rising or falling 
edge, or a change in value. See the attachInterrupt() function for details.
- **PWM**: 3 (8bits), 5 (8bits), 6 (FastPWM), 9 (16bits), 10 (16bits), and 11 (8/16bits). Provide PWM output with the 
analogWrite() function.
- **SPI**: Dedicated ISP conector: 14 (SS), 16 (MOSI), 17 (MISO), 15 (SCK). These pins support SPI communication using the 
SPI library.

#### Analog
The SAV MAKER I has 6 analog inputs, labeled A0 through A5, each of which provide 10 bits of resolution 
(i.e. 1024 different values). By default they measure from ground to 5 volts, though is it possible to change the upper 
end of their range using the AREF pin and the analogReference() function. 
- *AREF*. Reference voltage for the analog inputs. Used with analogReference().


#### Specialized functionality pins
- **TWI**: Dedicated pins SDA and SCL. Support TWI communication using the Wire library. Pins are shared with IO 2 and 3.
- **SPI**: ICSP header for programming and SPI operation.

#### Other
- **Reset**. Bring this line LOW to reset the microcontroller. Typically used to add a reset button to shields which 
block the one on the board.

### Communication
The SAV MAKER I has a number of interfaces for communicating with a computer, with another Arduino, or other microcontrollers.

The ATmega32U4The provides UART TTL (5V) serial communication, which is available on digital pins 0 (RX) and 1 (TX), 
or through the dedicated header connector.

The built-in USB controller channels this serial communication over USB and appears as a virtual com port to software on the 
computer. The 32U2 firmware uses the standard USB COM drivers, and no external driver is needed.
However, on Windows, a .inf file is required. The Arduino software includes a serial monitor which allows simple textual data 
to be sent to and from the Arduino board.

A SoftwareSerial library allows for serial communication on any of the SAV MAKER I’s digital pins.

The ATmega32U4 also supports I2C (TWI) and SPI communication. The Arduino software includes a Wire library to simplify use 
of the I2C bus; see the documentation for details. For SPI communication, use the SPI library.

### Programming
The SAV MAKER I can be programmed with the Arduino software (download). Select `*Arduino Leonardo* from the Tools > Board menu`. 
For details, see the reference and tutorials.
You can also bypass the bootloader and program the microcontroller through the ICSP (In-Circuit Serial Programming) header.

### Automatic (Software) Reset
Rather than requiring a physical press of the reset button before an upload, the SAV MAKER I is designed in a way that 
allows it to be reset by software running on a connected computer. 

You may also be able to disable the auto-reset by connecting a 10uF Capacitor from Reset line to GND.

### Overcurrent Protection
The SAV MAKER I has 2 resettable polyfuses that protects your computer’s USB ports from shorts and over-current. 
Although most computers today provide their own internal protection, the fuse gives you that extra layer. 
If more than 500 mA is required, the fuse will automatically break the connection until the short or overload is removed.

## Licensing
All information contained herein is licensed under CERN OHL (please refer to license file for details), so if someone 
wants to use this information to assemble kits, sell boards, etc. … feel free to do it.
