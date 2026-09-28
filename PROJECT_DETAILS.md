# Project Details

## Project Title
**Arduino Based Digital Dice Using MAX7219 LED Matrix**

## Objective
To design a simple electronic dice that generates a random number from 1 to 6 and displays it on an 8x8 LED matrix.

## Working Principle
The Arduino UNO reads the state of a push button. When the button is pressed, the program generates a sequence of random numbers and displays them on the MAX7219 LED matrix to create a rolling effect. After a short random duration, the rolling stops and one final number between 1 and 6 is displayed.

## Main Concepts Used
- Arduino digital input
- Internal pull-up resistor
- LED matrix control
- MAX7219 communication
- Random number generation
- Timing using `millis()`
- Button debouncing
- Embedded C/C++ programming
