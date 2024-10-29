// include libraries
#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Servo.h>

// define the pins
#define DHTPIN 33
#define SERVO_PIN 26

// general set up of DHT 22
#define DHTTYPE DHT22
DHT_Unified dht(DHTPIN, DHTTYPE);
int delayMS = 250;

// general set up of servo motor
Servo myServo;

void setup()
{
  // start serial monitor
  Serial.begin(9600);
  // Initialize DHT22
  dht.begin();
  // attach servo motor
  myServo.attach(SERVO_PIN);
  // go to start position of 45 degrees
  delay(500);
  myServo.write(45);
}

void loop()
{
  // Delay between measurements
  delay(delayMS);

  // create a sensor event
  sensors_event_t event;

  // put the sensor readings in their own variable
  dht.temperature().getEvent(&event);
  const int temperature = event.temperature;
  dht.humidity().getEvent(&event);
  const int humidity = event.relative_humidity;

  //  make sure the content of the events are a valid data
  if (isnan(temperature) || isnan(humidity))
  {
    Serial.println(F("Error reading sensor data!"));
  }
  else
  {
    // print the sensor readings
    Serial.print(F("Temperature: "));
    Serial.print(temperature);
    Serial.println(F("°C"));
    Serial.print(F("Humidity: "));
    Serial.print(humidity);
    Serial.println(F("%"));

    // define a fixed humidity threshold at which the servo should react
    const int HUMIDITY_THRESHOLD = 75;

    // if the threshold is exceeded, let the servo react
    if (humidity >= HUMIDITY_THRESHOLD)
    {
      // go to position 90
      myServo.write(90);
      delay(100);
      // go to position 45
      myServo.write(45);
      delay(100);
    }
  }
}
