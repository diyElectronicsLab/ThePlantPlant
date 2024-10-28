# DHT 22 Temperature and Humidity Sensor

The DHT22 is a sensor for temperature and humidity measurements. The sensor exists as a 3 pin "breakout board" (the sensor is soldered on a kind of adapter) and as the raw 4 pin sensor module. At university, we are using the 4 pin version.

## Connections

- PIN 1 --> VCC (3-5V, connect to 3.3V "3V3" PIN of ESP32)
- PIN 2 --> DATA (communication pin, connect to GPTO PIN 33 of ESP32
- **important: add a 10K resistor between DATA and 3V3 of ESP32**, see both red dots on image below, direction of resistor does not matter)
- PIN 3 --> NC (not connected)
- PIN 4 --> GND (connect to GND PIN of ESP32)

You can follow the connections in my photo or in the drawing below; they are basically the same and only look different.

![pinout](https://github.com/user-attachments/assets/727a5af7-77e1-41f5-a8da-ae4ef4a6f7d3)

*Why we need to add a resistor between DATA and ESP32* <br>
We need that resistor in order to get stable readings from the sensor. The resistor is a pull-up resistor. It ensures that the pin of the ESP32 is normally kept at a HIGH level and is only LOW if intended. If we do not use this resistor, the pin will have inconsistant readings. For more information see [pull-up resistor](https://learn.sparkfun.com/tutorials/pull-up-resistors/all)

![esp32 dht22](https://esp32io.com/images/tutorial/esp32-dht22-temperature-humidity-sensor-wiring-diagram.jpg)
![dht11-schema](https://github.com/user-attachments/assets/1b0c1225-c1c7-448d-8d85-ba437e9d7799)

## Code

- open VScode, click on Platform I/O icon and then on "new project"
- choose the board name "Espressif ESP32 Dev Module"
- framework: Arduino, choose location and click "finish"
- in the side bar on the left, click on "platformio.ini"
- add 'monitor_speed = 115200' to bottom of that file and save. This will allow using the serial monitor
- go to "PIO Home" or click on PIO icon, click on "libraries" and search for DHT22 sensor library by Adafruit. Click on "Add to project", choose your project name and click "add".
- go back to your "platformio.ini" file. You will find "lib_deps = adafruit/DHT sensor library@^VERSION" added in the bottom.
- go back to PIO Home -> libraries -> DHT22 sensor library (Adafruit) and look at the basic example code on the front page. As you can see below, I added <Arduino.h> and changed the DATA pin. The rest is the same.

`
#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 33 // DATA pin, changed to 33
#define DHTTYPE DHT22 // model of sensor (DHT22)

DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

void setup() {
  Serial.begin(9600);
  // Initialize device.
  dht.begin();
  Serial.println(F("DHTxx Unified Sensor Example"));
  // Print temperature sensor details.
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  Serial.println(F("------------------------------------"));
  Serial.println(F("Temperature Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("°C"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("°C"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("°C"));
  Serial.println(F("------------------------------------"));
  // Print humidity sensor details.
  dht.humidity().getSensor(&sensor);
  Serial.println(F("Humidity Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("%"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("%"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("%"));
  Serial.println(F("------------------------------------"));
  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay / 1000;
}

void loop() {
  // Delay between measurements.
  delay(delayMS);
  // Get temperature event and print its value.
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
  }
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  }
  else {
    Serial.print(F("Humidity: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));
  }
}
`

## Additional information:
- [Tutorial on esp32.io]([https://www.example.com](https://esp32io.com/tutorials/esp32-dht22?utm_content=cmp-true))
- [DHT22 datasheet](https://www.sparkfun.com/datasheets/Sensors/Temperature/DHT22.pdf)
