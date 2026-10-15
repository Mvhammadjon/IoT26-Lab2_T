#include <Arduino.h>

const int RED = 26;
const int GREEN = 27;
const int BLUE = 14;
const int YELLOW = 12;
const int BUTTON = 25;

int counter = 0;
int previousButtonState = LOW;

void setup() {
  Serial.begin(115200);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(BLUE, OUTPUT);

  // Button is active HIGH
  pinMode(BUTTON, INPUT);

  Serial.println("count=0");
}

void loop() {
  int buttonState = digitalRead(BUTTON);

  // Detect a new press: LOW -> HIGH
  if (buttonState == HIGH &&
      previousButtonState == LOW) {

    counter++;

    if (counter > 4) {
      counter = 0;
    }

    Serial.print("count=");
    Serial.println(counter);

    // Update the LED pattern
    digitalWrite(RED, counter >= 1 ? HIGH : LOW);
    digitalWrite(GREEN, counter >= 2 ? HIGH : LOW);
    digitalWrite(YELLOW, counter >= 3 ? HIGH : LOW);
    digitalWrite(BLUE, counter >= 4 ? HIGH : LOW);
  }

  previousButtonState = buttonState;

  delay(20); // Small debounce delay
}