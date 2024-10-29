# Controlling Servo Motors with ESP32

Regular DC motors spin endlessly without knowing how far they went. A servo motor is a motor with a built-in feedback mechanism (a sensor). As soon as the motor spins, it produces information about how much it spinned until this moment. 

In turn, this means that we can tell the motor exactly how far it should spin and when (or where) it should stop. In this tutorial, we are focusing on the SG90 miniature servo motor that is low-cost, easy to use and therefore often found in DIY projects. This particular servo motor is a positional model. Unlike a continuesly spinning motor, it is able to spin between 0 and 180 degrees and hold any location in between.

![servo motor](https://www.brainpad.com/wp-content/uploads/2021/07/servos-1.gif)

## Connecting SG90 to ESP32

Lets connect the motor to our ESP32 microcontroller! The motor has 3 leads:
- Brown / left = GND --> ground, connect to GND pin of ESP32
- Red / middle = VCC --> power, connect to 5V pin of ESP32 
- Orange / right = SIG --> singal, connect to GPIO 13 or any other PWM pin (marked with a wavy line)

![servo esp32 connections](https://esp32io.com/images/tutorial/esp32-servo-motor-wiring-diagram.jpg)

*Please Note: if you are using any larger servo motor than this miniature version, you need to connect an external power supply. If you are using a regular DC or stepper motor, you need additional motor drivers. This is important – you can easily damage the ESP32 microcontroller by pulling too much current from its 5V pin.*

# More Information

- [tutorial on espio](https://esp32io.com/tutorials/esp32-servo-motor)
