#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
int tempPin = A0; // the output pin of LM35
int fan = 11; // the pin where fan is
int led = 8; // led pin
int temp;
int tempMin = 30; // the temperature to start the fan 0%
int tempMax = 60; // the maximum temperature when fan is at 100%
int fanSpeed;
int fanLCD;

void setup() {
    pinMode(fan, OUTPUT);
    pinMode(led, OUTPUT);
    pinMode(tempPin, INPUT);
    lcd.begin(16,2);
    Serial.begin(9600);
}

void loop() {
    temp = readTemp(); // get the temperature
    Serial.print(temp);
    if(temp < tempMin) {
        fanSpeed = 0; // fan is not spinning
        analogWrite(fan, fanSpeed);
        fanLCD = 0;
        digitalWrite(fan, LOW);
    }
    if((temp >= tempMin) && (temp <= tempMax)) {
        fanSpeed = temp;
        fanSpeed = 1.5 * fanSpeed;
        fanLCD = map(temp, tempMin, tempMax, 0, 100); // speed of fan to display on LCD
        analogWrite(fan, fanSpeed); // spin the fan at the fanSpeed speed
    }

    if(temp > tempMax) {
        digitalWrite(led, HIGH); // turn on led
    } else {
        digitalWrite(led, LOW); // turn off led
    }

    lcd.print("TEMP: ");
    lcd.print(temp); // display the temperature
    lcd.print("C ");
    lcd.setCursor(0,1); // move cursor to next line
    lcd.print("FANS: ");
    lcd.print(fanLCD); // display the fan speed
    lcd.print("%");
    delay(200);
    lcd.clear();
}

int readTemp() { // get the temperature and convert it to celsius
    temp = analogRead(tempPin);
    return temp * 0.48828125;
}
