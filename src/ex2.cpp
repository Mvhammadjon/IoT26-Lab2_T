#include <Arduino.h>

const int LIGHT = 33;

unsigned long lastSampleTime = 0;
const unsigned long interval = 1000;

void setup() {
  Serial.begin(115200);
  pinMode(LIGHT, INPUT);
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - lastSampleTime >= interval) {
    lastSampleTime = currentTime;

    int minValue = 4095;
    int maxValue = 0;
    long sum = 0;

    for (int i = 0; i < 10; i++) {
      int reading = analogRead(LIGHT);

      if (reading < minValue) {
        minValue = reading;
      }

      if (reading > maxValue) {
        maxValue = reading;
      }

      sum += reading;
    }

    float average = sum / 10.0;

    Serial.print("min=");
    Serial.print(minValue);
    Serial.print(" max=");
    Serial.print(maxValue);
    Serial.print(" avg=");
    Serial.println(average, 0);
  }
}