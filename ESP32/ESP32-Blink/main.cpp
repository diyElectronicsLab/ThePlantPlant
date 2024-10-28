#include <Arduino.h>

// assign the constant varibale LED_PIN to GPIO 2 (onboard led)
#define LED_PIN 2

void setup()
{
  // put your setup code here, to run once:
  // define LEP_PIN as an output pin
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  // turn LED_PIN on
  digitalWrite(LED_PIN, HIGH);
  // wait for xxxxx milliseconds
  delay(1000);
  // turn LED_PIN off
  digitalWrite(LED_PIN, LOW);
  // wait for xxxxx milliseconds
  delay(1000);
}
