# ESP32

The ESP32 is a microcontroller. As a microcontroller, it is generally similar to - for example - an Arduino Uno (you might have worked with that one in the past). However, there are some important differences – some of them are:

- unlike the Arduino Uno, the ESP32 has WIFI and Bluetooth on board!
- the Arduino Uno runs entirely on 5V, the ESP32 runs on 3.3V. **This is very important, because you can easily fry the ESP32 when applying too much voltage (for example 5V) to its pins.** Therefore: always double check the output voltages of your devices (sensors, ...) before connecting them to the ESP32 directly.
- depending on the version, the ESP32 has more GPIO pins than the Arduino Uno, although not all of them can be used for general input/output purposes. And be aware: some of the Analog pins can not be used when Wifi is turned on.
- the ESP32 is faster and has more memory. On top of that: it is cheaper than the Arduino.
- cool: the ESP32 can be programmed using the Arduino programming language.
- much more that goes to deep for now..

Some downsides of the ESP32:
- longer compile and upload times
- a little bit less documentation online
- most but not all the Arduino libraries available
- incompatibilities with some sensor modules due to 3.3V logic; additional parts needed (voltage regulator to 3.3V or voltage divider).

