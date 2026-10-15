#include <Arduino.h>

const int RED = 26;
const int GREEN = 27;
const int BLUE = 14;
const int YELLOW = 12;

const int leds[] = {RED, GREEN, YELLOW, BLUE, YELLOW, GREEN};
const char* names[] = {
  "RED", "GREEN", "YELLOW", "BLUE", "YELLOW", "GREEN"
};

int stepIndex = 0;

void setup() {
  Serial.begin(115200);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(YELLOW, OUTPUT);
}

void loop() {
  // Turn all LEDs off
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  digitalWrite(YELLOW, LOW);

  // Turn on the current LED
  digitalWrite(leds[stepIndex], HIGH);

  Serial.print("chase=");
  Serial.println(names[stepIndex]);

  delay(150);

  stepIndex++;
  if (stepIndex >= 6) {
    stepIndex = 0;
  }
}