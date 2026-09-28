# Arduino Digital Dice

A simple electronic dice made using an Arduino UNO, MAX7219 8x8 LED matrix and a push button.

## Features
- Displays numbers from 1 to 6
- Button controlled dice roll
- Random rolling time and speed
- Rolling number animation
- Startup LED animation
- Compact enclosure suitable for a finished project build

## Components
- Arduino UNO
- MAX7219 8x8 LED matrix module
- Push button
- Breadboard
- Jumper wires
- USB cable

## Wiring
| Component | Arduino UNO |
|---|---|
| MAX7219 DIN | D11 |
| MAX7219 CS / LOAD | D10 |
| MAX7219 CLK | D13 |
| MAX7219 VCC | 5V |
| MAX7219 GND | GND |
| Push button | D2 |
| Other side of button | GND |

The button uses the Arduino internal pull-up resistor, so an external resistor is not required.

## Software
The project uses the `LedControl` library. Install it through **Arduino IDE → Library Manager → search for LedControl → Install**.

## How It Works
When the board is powered on, the LED matrix runs a short startup animation. When the push button is pressed, the program rapidly displays different numbers from 1 to 6. The rolling continues for a short random period and then stops at a randomly selected number.

## Uploading
1. Connect the Arduino UNO to the computer.
2. Open `Arduino_Digital_Dice.ino`.
3. Select Arduino UNO and the correct port.
4. Make sure LedControl is installed.
5. Upload the program.
