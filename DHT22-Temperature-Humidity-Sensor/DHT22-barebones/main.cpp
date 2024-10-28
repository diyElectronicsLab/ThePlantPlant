#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 33     // DATA pin
#define DHTTYPE DHT22 // sensor version, we are using DHT22

DHT_Unified dht(DHTPIN, DHTTYPE);

int delayMS = 2000; // add 2 seconds delay after each reading

void setup()
{
  Serial.begin(9600);
  dht.begin(); // Initialize device.
}

void loop()
{
  // Delay between measurements
  delay(delayMS);

  // Get access to sensor event through custom sensor event type
  sensors_event_t event;

  // get temperature event (by reference, not by copy) and print its value.
  // "event" is  - after this - filled with information from the sensor.
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature))
  {
    Serial.println(F("Error reading temperature!"));
  }
  else
  {
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
  }

  // get humidity event (by reference, not by copy) and print its value.
  // "event" is  - after this - filled with information from the sensor.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity))
  {
    Serial.println(F("Error reading humidity!"));
  }
  else
  {
    Serial.print(F("Humidity: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));
  }
}
