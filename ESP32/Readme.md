# ESP32

![esp32](https://github.com/user-attachments/assets/f43872e1-5f64-4dd2-a360-c91a35e8ee3e)

The ESP32 is a microcontroller, and therefore it is generally similar to - for example - an Arduino Uno (you might have worked with that one in the past). However, there are some important differences:

- the ESP32 has WIFI and Bluetooth on board! 
- the ESP32 runs on 3.3V, the Arduino Uno runs entirely on 5V. This is very important, because you can easily fry the ESP32 when applying too much voltage (for example 5V) to its pins. That can happen if you use your Arduino sensors with 5V logic directly on the ESP pins.
- *Note: always double check the output voltages of your devices (sensors, ...) before connecting them to the ESP32 directly.*
- depending on the version, the ESP32 has more GPIO pins than the Arduino Uno, although not all of them can be used for general input/output purposes. And be aware: some of the Analog pins can not be used when Wifi is turned on.
- the ESP32 is faster and has more memory. On top of that: it is cheaper than the Arduino.
- cool: the ESP32 can be programmed using the Arduino programming language.
- much more that goes to deep for now..

### Some downsides of the ESP32:
- longer compile and upload times
- a little bit less documentation online
- most but not all the Arduino libraries available
- incompatibilities with some sensor modules due to 3.3V logic; additional parts needed (voltage regulator to 3.3V or voltage divider).

