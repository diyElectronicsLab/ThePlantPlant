#include <Arduino.h>

#define LED_PIN 2

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);

  Serial.println("HELLO CLASSROOM!");
}

void loop()
{
  // put your main code here, to run repeatedly:
  digitalWrite(LED_PIN, HIGH);
  Serial.println("LED IS ON");
  delay(1000);

  digitalWrite(LED_PIN, LOW);
  Serial.println("LED IS OFF");
  delay(1000);
}
