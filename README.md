# LCDdogmSPI library

This is my first stab at adopting the Arduino LCD library code for usage with 
the EA DOG-M display series, especially in SPI mode (as it is, pincount wise the most desirable mode)

It is tested with an EA DOGM163W-A display and should (in theory) also work with 
the 081 and the 162 types, but I'd need the hardware to verify this (So feel free to send me the displays :)

The aforementioned device does not have a backlight. It does support an ST7036 controller, which is supposed to be compatible with an HF44780 controller, but there may be some incompatabilities.

Compatibility
-------------
The library has been developed under Arduino011.

Installation
------------
Simply unpack the ZIP inside your libraries folder (The folder location seems to vary heavily from system to system...). After restarting the Arduino Software, you should be able to import the Library into your Sketch.

Usage
-----

Software
--------

See examples.

CAUTION: 

Please note that this implementation currently thinks it is the only one in 
the world using the SPI lines, as it doesn't preserve the state of the SPI
control registers nor does it care for any other CS lines beeing low.
Using this in conjunction with other SPI devices might require some additional
work on your behalf.




Wiring it up
------------

DISPLAY    < - >   ARDUINO
--------------------------
SI           -     11 (MOSI)
CLK          -     13 (SPI-Clock)
RS           -     <rs_pin> (2nd parameter to the library initializer)
CSB          -     <csb_pin> (3rd parameter to the library initializer)
+5V          -     5V (O RLY?)
GND          -     GND (YAH, RLY)

That makes 6 impressive pins for driving a real LCD display. Plus, CLK and SI
are still usable for other SPI devices.

## Breadboard cheatsheet using SPI, 5V

This is an example of how I wired up my breadboard on 08-Jan-2018

| S1   | S2   | NAME    | SPI  | DUPONT | ARD  | PI     |
| ---- | ---- | ------- | ---- | ------ | ---- | ------ |
| 1    | 40   | RESET   | 5V   |        |      |        |
| 2    | 39   | RS      | MISO | green  | DP09 | BCM 25 |
| 3    | 38   | CSB     | SS   | yellow | DP10 | BCM  8 |
| 4    | 37   | RW      | GND  |        |      |        |
| 5    | 36   | E       | 5V   |        |      |        |
| 6    | 35   | D0      | 5V   |        |      |        |
| 7    | 34   | D1      | 5V   |        |      |        |
| 8    | 33   | D2      | 5V   |        |      |        |
| 9    | 32   | D3      | 5V   |        |      |        |
| 10   | 31   | D4      | 5V   |        |      |        |
| 11   | 30   | D5      | 5V   |        |      |        |
| 12   | 29   | D6, CLK | CLK  | orange | DP13 | BCM 11 |
| 13   | 28   | D7, SI  | MOSI | blue   | DP11 | BCM 10 |
| 14   | 27   | VSS     | GND  |        |      |        |
| 15   | 26   | VDD     | 5V   |        |      |        |
| 16   | 25   | VI      | 5V   |        |      |        |
| 17   | 24   | VO      | 5V   |        |      |        |
| 18   | 23   | SB      | GND  |        |      |        |
| 19   | 22   | -       | -    |        |      |        |
| 20   | 21   | -       | -    |        |      |        |


Legend:

* S1: Scheme 1: the numbering of the pins from left to right, assuming the device is face up
* S2: Scheme 2: the numbering scheme of the pins used by the device manufacturer
* NAME: Manufacturer's name for the pin
* SPI: wiring of the device assuming that it is configured for the SPI (Serial Peripheral Interface) protocol, running under 5V
* DUPONT: suggested colouring scheme for the Dupont cables. Additionally, you might opt to use red for 5V, and brown for GND.
* ARD: suggested pin usage on the Arduino. DPnn refers to Digital Pin nn
* PI: suggested pin usage on the Raspberry Pi.

In practise, VCC is the same as VDD

Glossay:

* CSB =  chip select wire, aka SS in more modern parlance
* RS = Register Select, aka MISO in more modern parlance. Low=command, high=data
* RW = Read/Write. Low=write, high=read
* SI = Serial In, aka MOSI in more modern parlance
* SCK = Serial clock
* SPI = Serial Perihperal Interface
* SS = Slave Select
* `-` = unconnected pin

## References

* [Datasheet](http://www.lcd-module.com/eng/pdf/doma/dog-me.pdf) - PDF containing technical details about the display
* [Display-O-Tron](https://shop.pimoroni.com/products/display-o-tron-lcd) - where I bought the product. It also gives background information
* 
