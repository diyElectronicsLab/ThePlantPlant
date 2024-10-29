# ESP32

![esp32](https://github.com/user-attachments/assets/f43872e1-5f64-4dd2-a360-c91a35e8ee3e)

The ESP32 is a microcontroller, and therefore it is generally similar to - for example - an Arduino Uno (you might have worked with that one in the past). However, there are some important differences.

### Whats so cool about ESP32:

- the ESP32 has WIFI and Bluetooth on board
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
<b>

![doc-esp32-pinout-reference-wroom-devkit](https://github.com/user-attachments/assets/1454dd5c-e0d4-4fc4-acd8-fd1eb1b5e7ae)

*Please Note:*
- *the numbers in the bottom of our ESP32 correspond to the actual GPIO numbering. GPIO19 on the image = 19 on our board.
- *the curvy line next to a pin on the drawing marks a PWM pin. These pins can be used to immitate an analog output signal using PWM - pulse width modulation.*
- *GPIO 6,7,8,9,10,11 can not be used by us*
- *the "ADC" pins can be used as analog input pins. ADC2 pins can not be used when Wifi is turned on (GPIO 25,26,27,14,12,13,15,2,0,4).*

# Getting Started

The first thing we want to do are a basic tests that shows us if our computer can connect to the microcontroller and if everything is working correctly. 

## Hello World: Blink

![IMG_7808](https://github.com/user-attachments/assets/e7033a8f-7dae-4b0c-a2fe-ad56e2c33116)

Our first "Hello World" program will let the ESP32 blink in a certain sequence. We can decide how long the LED will be turned on and off.

### Preparations
- open a new window in VScode and click on the alien head icon to open the Platform I/O extension
- create a new project (toolbar on the left, scroll down if you need to)
- enter a name and choose the board: "Espressif ESP32 Dev Module"
- choose a location for the project and click finish.
- go to the "src" folder in the side bar and click on "main.cpp" (this is our main c++ file that will run on the ESP32)
- copy the code inside the folder "ESP32-Blink" from the file "main.cpp" into your own "main.cpp" file.

### The Code
You can find the code needed in the ESP32-Blink folder of this repository. What the code is doing:

`
#include <Arduino.h>
`
- include the Arduino library to allow us writing Arduino style code in main.c++

`
#define LED_PIN 2
`
- assign GPIO pin number 2 to the "name" (the variable) "LED_PIN", so we can use it throughout our code without remembering the pin number everytime we want to do something with it.
- GPIO number 2 is connected to the onboard LED light of the ESP32.

```
void setup()
{
  pinMode(LED_PIN, OUTPUT);
}
```
- the code inside the setup(){} block will only run once in the beginning.
- we define the LED_PIN (GPIO pin number 2) as an output pin. In the OUTPUT mode, a pin can produce a voltage signal between 0 and 3.3 V.

```
void loop()
{
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}
```
- the code inside the loop(){} block will run over and over again in an endless loop.
- we tell the microcontroller to continouesly turn the LED_PIN on `digitalWrite(LED_PIN, HIGH)`, wait for one second or 1000 milliseconds `delay (1000)`, turn the pin off `digitalWrite(LED_PIN, LOW)` and again wait for 1000 milliseconds `delay (1000)`. Thats all!

### Compile and Upload

Now we are ready to compile / "Build" (ckeck if our code fits the rules of Arduino and c/c++) and upload the code to our ESP32!

- go to your main.cpp file and click on the little hook symbol in the upper right corner. Your code will be compiled: it is checked for errors and converted to machine code that the ESP32 can understand. We will not see this machine code - that`s ok because we would not really be able to read it.
- click on the little arrow next to the compile symbol and click on "upload" in the dropdown. Your Code will be uploaded to the ESP32 and it should start to blink! 

*Please Note:*
If you have a Windows machine, you should check if your ESP32 will show up in the COM port list inside of Platform I/O --> devices. If not, you need to install a driver for the USB chip.
- Visit [this website](https://randomnerdtutorials.com/install-esp32-esp8266-usb-drivers-cp210x-windows/) and follow the tutorial
- [direct link to the driver](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads) --> choose "CP210x Windows Drivers"

## Hello World: Serial Monitor

![SerialOut](https://github.com/user-attachments/assets/e793218f-48bf-46eb-8fd2-d4206fadf262)


Our second "Hello World" program will establish a communication port between the ESP32 and our computer so we will be able to send messages between both devices.

### Preparations
- click on the file "platformio.ini" in the sidebar of the "files" tab.
- add the line `monitor_speed = 9600` to the bottom of the file and safe.
- copy the code inside the folder "ESP32-Serial" from the file "main.cpp" and replace the code in your "main.cpp" file with the new code example.

### The Code 

You will notice that the code did not change too much. We only added a few lines that allow us to communicate and send messages from the ESP32 to our computer.

- the line `Serial.begin(9600);` opens a communication channel over the USB cable. 9600 is the speed at which we are communicating, it must fit the speed you added to the platformio.ini file `monitor_speed = 9600`.
- the line `  Serial.println("HELLO CLASSROOM!");` sends a message "HELLO CLASSROOOM" from the ESP32 to our computer once in the beginning.
- further down, you see the same line of code but with another message. Whenever the LED is on, we want to send "LED IS ON", when its off we send "LED IS OFF".
- you can see that the code is executed from top to bottom and line by line.

### Compile, Upload and Receive the Messages

Again, we are ready to compile and upload the code. Additionally, we will open the Serial Monitor to receive the messages we are sending.

- go to your main.cpp file and click on the little hook symbol in the upper right corner. Your code will be compiled.
- click on the little arrow next to the compile symbol and click on "upload" in the dropdown.
- once the code is uploaded, click on the "plug" symbol next to the upload/compile button. A new terminal window will open in the bottom and you will see the messages!


