# ESP32

![esp32](https://github.com/user-attachments/assets/f43872e1-5f64-4dd2-a360-c91a35e8ee3e)

The ESP32 is a microcontroller, and therefore it is generally similar to - for example - an Arduino Uno (you might have worked with that one in the past). However, there are some important differences.

### Whats so cool about ESP32:

- the ESP32 has WIFI and Bluetooth on board! 
- the ESP32 runs on 3.3V, the Arduino Uno runs entirely on 5V. This is very important, because you can easily fry the ESP32 when applying too much voltage (for example 5V) to its pins. That can happen if you use your Arduino sensors with 5V logic directly on the ESP pins.
- depending on the version, the ESP32 has more GPIO pins than the Arduino Uno, although not all of them can be used for general input/output purposes.
- the ESP32 is faster and has more memory. On top of that: it is cheaper than the Arduino.
- cool: the ESP32 can be programmed using the Arduino programming language.
- much more that goes to deep for now..

*Please Note:* 
- *always double check the output voltages of your devices (sensors, ...) before connecting them to the ESP32 directly.*
- *some of the ESP pins are reserved for internal processes and things get weird if you try to use them for your projects.*
- *some of the analog GPIO pins can not be used when Wifi is turned on.*

### Some downsides of the ESP32:
- longer compile and upload times
- a little bit less documentation online
- most but not all the Arduino libraries available
- incompatibilities with some sensor modules due to 3.3V logic; additional parts needed (voltage regulator to 3.3V or voltage divider).
- most ESP Dev Kits are too large for a single breadboard.
- our ESP fits on a breadboard, however and for that reason, the pin labels are in the bottom..

# Pin Configurations

Our ESP32 model is similar to the 38 pin version of the ESP32 Dev Kit made by espressif. The following image gives an overview of the capabilities each pin has.

*Please Note:*
- *the numbers in the bottom of our ESP32 correspond to the actual GPIO numbering. GPIO19 on the image = 19 on our board.
- *the curvy line next to a pin on the drawing marks a PWM pin. These pins can be used to immitate an analog output signal using PWM - pulse width modulation.*
- *GPIO 6,7,8,9,10,11 can not be used by us*
- *the "ADC" pins can be used as analog input pins. ADC2 pins can not be used when Wifi is turned on (GPIO 25,26,27,14,12,13,15,2,0,4).*
