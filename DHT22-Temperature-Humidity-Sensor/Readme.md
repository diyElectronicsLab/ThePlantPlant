# DHT 22 Temperature and Humidity Sensor

The DHT22 is a sensor for temperature and humidity measurements. The sensor exists as a 3 pin "breakout board" (the sensor is soldered on a kind of adapter) and as the raw 4 pin sensor module. At university, we are using the 4 pin version.

## Connections

- PIN 1 --> VCC (3-5V, connect to 3.3V "3V3" PIN of ESP32)
- PIN 2 --> DATA (communication pin, connect to GPTO PIN 33 of ESP32
- **important: add a 10K resistor between DATA and 3V3 of ESP32**, see both red dots on image below, direction of resistor does not matter)
- PIN 3 --> NC (not connected)
- PIN 4 --> GND (connect to GND PIN of ESP32)

You can follow the connections in my photo or in the drawing below; they are basically the same and only look different.

<br>

![pinout](https://github.com/user-attachments/assets/727a5af7-77e1-41f5-a8da-ae4ef4a6f7d3)
![esp32 dht22](https://esp32io.com/images/tutorial/esp32-dht22-temperature-humidity-sensor-wiring-diagram.jpg)
![dht11-schema](https://github.com/user-attachments/assets/1b0c1225-c1c7-448d-8d85-ba437e9d7799)


## Getting Started

- open VScode, click on Platform I/O icon and then on "new project"
- choose the board name "Espressif ESP32 Dev Module"
- framework: Arduino, choose location and click "finish"

### Serial Monitor
- in the side bar on the left, click on "platformio.ini"
- add 'monitor_speed = 9600' to bottom of that file and save. This will allow using the serial monitor

### Include Library
- go to "PIO Home" or click on PIO icon, click on "libraries" and search for DHT22 sensor library by Adafruit. Click on "Add to project", choose your project name and click "add".
- go back to your "platformio.ini" file. You will find "lib_deps = adafruit/DHT sensor library@^VERSION" added in the bottom. Ready to go!
- go back to PIO Home -> libraries -> DHT22 sensor library (Adafruit) and look at the basic example code on the front page. You can adjust this code to your needs (change DHTPIN!) or look at the "DHT22 basic example" code in this repo.

### Upload!
- double check your connections, compile the code, connect your board and hit upload.
- Click on the serial monitor button (the power plug icon in the upper right) to see the measurements


## Why we need to add a resistor between DATA and ESP32*

We need that resistor in order to get stable readings from the sensor. The resistor is a pull-up resistor. It ensures that the pin of the ESP32 is normally kept at a HIGH level and is only LOW if intended. If we do not use this resistor, the pin will have inconsistant readings. For more information see [pull-up resistor](https://learn.sparkfun.com/tutorials/pull-up-resistors/all)

## Additional information:
- [Tutorial on esp32.io](https://esp32io.com/tutorials/esp32-dht22?utm_content=cmp-true)
- [Adafruit Tutorial DHT22](https://learn.adafruit.com/dht/overview)
- [DHT22 datasheet](https://www.sparkfun.com/datasheets/Sensors/Temperature/DHT22.pdf)
