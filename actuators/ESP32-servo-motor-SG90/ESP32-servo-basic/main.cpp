#include <Arduino.h>
// include the servo library
#include <Servo.h>

// assign variable "SERVO_PIN" to GPIO 26
#define SERVO_PIN 26

// create Servo object
Servo myServo;

void setup()
{
  // start Serial Monitor
  Serial.begin(9600);
  // define GPIO 26 ("SERVO_PIN") as signal pin of servo motor
  myServo.attach(SERVO_PIN);
}

void loop()
{
  // in +1 steps from 0 to 180
  for (int posDegrees = 0; posDegrees <= 180; posDegrees++)
  {
    // drive servo to +1 step from 0 to 180
    myServo.write(posDegrees);
    // print +1 step from 0 to 180 to serial monitor
    Serial.println(posDegrees);
    // give servo 20 milliseconds to react
    delay(20);
  }
  // in -1 steps from 180 to 0
  for (int posDegrees = 180; posDegrees >= 0; posDegrees--)
  {
    // drive servo to -1 step from 180 to 0
    myServo.write(posDegrees);
    // print -1 step from 180 to 0 to serial monitor
    Serial.println(posDegrees);
    // give servo 20 milliseconds to react
    delay(20);
  }
}
