# DHT 22 Temperature and Humidity Sensor

The DHT22 is a sensor for temperature and humidity measurements. The sensor exists as a 3 pin "breakout board" (the sensor is soldered on a kind of adapter) and as the raw 4 pin sensor module. At university, we are using the 4 pin version:

- PIN 1 --> VCC (3-5V, connect to 3.3V "3V3" PIN of ESP32)
- PIN 2 --> DATA (communication pin, connect to GPTO PIN 33 of ESP32, **important: add a 10K resistor between DATA and 3V3 of ESP32**, see both red dots on image below, direction of resistor does not matter)
- PIN 3 --> NC (not connected)
- PIN 4 --> GND (connect to GND PIN of ESP32)

![pinout](https://github.com/user-attachments/assets/727a5af7-77e1-41f5-a8da-ae4ef4a6f7d3)

*Why we need to add a resistor between DATA and ESP32* <br>
We need that resistor in order to get stable readings from the sensor. The resistor is a pull-up resistor. It ensures that the pin of the ESP32 is normally kept at a HIGH level and is only LOW if intended. If we do not use this resistor, the pin will have inconsistant readings. For more information see [pull-up resistor](https://learn.sparkfun.com/tutorials/pull-up-resistors/all)

![dht11-schema](https://github.com/user-attachments/assets/1b0c1225-c1c7-448d-8d85-ba437e9d7799)

## Additional information:
- [Tutorial on esp32.io]([https://www.example.com](https://esp32io.com/tutorials/esp32-dht22?utm_content=cmp-true))
- [DHT22 datasheet](https://www.sparkfun.com/datasheets/Sensors/Temperature/DHT22.pdf)
