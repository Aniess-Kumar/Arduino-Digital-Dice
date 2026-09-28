# Wiring

## MAX7219 8x8 LED Matrix

| MAX7219 Pin | Arduino UNO Pin |
|---|---|
| DIN | D11 |
| CS / LOAD | D10 |
| CLK | D13 |
| VCC | 5V |
| GND | GND |

## Push Button

| Button Connection | Arduino UNO |
|---|---|
| One terminal | D2 |
| Other terminal | GND |

The program uses `INPUT_PULLUP`, so no external resistor is required.
