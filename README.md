## Open-source Shiftlight

# A project to add a shift indicator into my 2008 Honda S2000 gauge cluster where the green indicator would be on a CR S2000. 2008+ clusters already have the space where the LED would be if it was soldered onto the PCB. I added a green LED Diode and removed the paint that blocks this hole on the lens with some alcohol. 

In this repository you will find;
- The .ino file that you can upload directly to your Arduino 
- A .png image of the wiring diagram
- A .jpeg image of how the finished assembly should look
- An .md file containing a detailed parts list.

## Please note, there is a mistake in this schematic. A corrected schematic is shown in issue #4

- This example uses a voltage divider and transistor to pull down the the tacho signal from 12v,

if your car uses a 5v tacho signal this is not needed.

- You will need to download and install the adafruit neopixel library for IDE
