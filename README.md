# TempSync Automatic Fan

This Arduino project controls a fan based on the temperature read from an LM35 temperature sensor. It also displays the temperature and fan speed on an LCD.

## Components Used
- Arduino Uno
- LM35 Temperature Sensor
- 16x2 LCD Display
- Fan
- LED
- Resistors
- Connecting wires

## Connections
- LM35 Temperature Sensor: Connect the output pin to A0.
- LCD Display: Connect pins 2, 3, 4, 5, 6, 7 to the corresponding pins on the Arduino.
- Fan: Connect to pin 11.
- LED: Connect to pin 8.

## Code Explanation
- The `setup` function initializes the pins and the LCD.
- The `loop` function reads the temperature, controls the fan speed, and updates the LCD display.
- The `readTemp` function reads the analog value from the temperature sensor and converts it to Celsius.

## Usage
1. Connect the components as described.
2. Upload the code to the Arduino.
3. The fan will start spinning when the temperature exceeds 30°C and will reach maximum speed at 60°C.
4. The LCD will display the current temperature and fan speed.

## License
This project is open-source and available under the MIT License.
