# JoffeGarage

## BOM
In addition to the 3D printed parts, you need:

- Hinges
- Various nuts and bolts
- Arduino UNO
- Stepper motor, NEMA-17 200steps/rev
- Stepper driver
- Ultrasonic sensor, HC-SR04
- Light dependent resistor
- 10k resistor
- Wires

## Arduino wiring
| Pin nr | Stepper driver | Ultrasonic sensor |
|--------|----------------|-------------------|
| 3      | AIN2           |                   |
| 4      | AIN1           |                   |
| 5      | STBY           |                   |
| 6      | BIN2           |                   |
| 7      | BIN1           |                   |
| 8      |                | VCC               |
| 9      |                | TRIG              |
| 10     |                | ECHO              |
| 11     |                | GND               |