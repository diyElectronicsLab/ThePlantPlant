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
  // drive servo to 0 degree position
  myServo.write(0);
  Serial.println("0");
  delay(500);

  // drive servo to 45 degree position
  myServo.write(45);
  Serial.println("45");
  delay(500);

  // drive servo to 90 degree position
  myServo.write(90);
  Serial.println("90");
  delay(500);

  // drive servo to 135 degree position
  myServo.write(135);
  Serial.println("135");
  delay(500);

  // drive servo to 180 degree position
  myServo.write(180);
  Serial.println("180");
  delay(1000);
}
