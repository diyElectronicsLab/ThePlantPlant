# Controlling Servo Motors with ESP32

Regular DC motors spin endlessly without knowing how far they went. A servo motor is a motor with a built-in feedback mechanism (a sensor). As soon as the motor spins, it produces information about how much it spinned until this moment. 

In turn, this means that we can tell the motor exactly how far it should spin and when (or where) it should stop. In this tutorial, we are focusing on the SG90 miniature servo motor that is often used for hobbyist / DIY projects. This particular servo motor is a positional model. Unlike a continuesly spinning motor, it is able to spin between 0 and 180 degrees and hold any location in between.

[servo motor](https://www.brainpad.com/wp-content/uploads/2021/07/servos-1.gif)

