# Sensor Actuator Systems

Now it's time to go one step further and connect what we learned about sensors with what we learned about actuators to create our first sensor-actuator system! 

![images](https://github.com/user-attachments/assets/5f7f1624-7aae-4e93-96e4-cb38c51478f2)

# Getting Started

In order to do so, you should first recreate the basic circuit for the DHT22 temperature/humidity sensor as well as the basic circuit for the servo motor. You can find a summary of both in the respective folders on this repository. 

Once you have both circuits set up again and you made sure that everything is connected the right way, we can combine both codes in order to make the sensor (DHT22) and the actuator (Servo) work at the same time.
<br><br>

![snesorActuatorSystem](https://github.com/user-attachments/assets/e8976c53-43eb-4ad3-a7ed-610a24073b6f)

## Preparations

- create a new project in VScode / Platform IO
- add `monitor_speed = 9600` to your "platformio.ino" file
- add both libraries for the DHT22 sensor and the servo motor to your project
- go to the "ESP32-DHT22-SG90" folder in this repository and copy/paste the code inside the main.cpp file

--> compile and upload: you should see the sensor readings in your serial monitor. Try to exhale on the sensor. Whenever the humidity goes over 75%, your servo should react!

## The Idea

With this simple program, I want to demostrate how a sensor and an actuator can interact with each other. Once the sensor produces values that exceed a certain threshold, the actuator should react and - in case of a feedback mechanism - have an influence on the sensor value through its physical action. 

Now in case of this little setup, our servo reacts whenever the humidity value exceeds a certain threshold (for example 75%, but you can also choose your own). The servo performs a "waving" geusture - so if you were to attach some kind of "flap" to the servo and place it close to the sensor, it could bring fresh air into the sensor and help the humidity value decrease again, until it reaches a level below the threshold.

## The Code

Looking at the code, you will notice that it basically consists of a cobination of both codes we were using for each device on its own. Only the loop function is a bit different and may look intimidating at first glance. No worries, we will have a closer look to understand whats happening:

`void setup(){}` 
--> this code and the code above the setup function should look familiar, just in another order.

`
dht.temperature().getEvent(&event);
const int temperature = event.temperature;
dht.humidity().getEvent(&event);
const int humidity = event.relative_humidity;
`
--> in this code block, we are saving the sensor readings for temperature and humidity in their own variable, so we can use it later on in our code.

`
  const int HUMIDITY_THRESHOLD = 75;
`
--> with this line, we make a variable in which we save the number 75. This will be our threshold for the humidity value at which the servo should start reacting.

`
 if (humidity >= HUMIDITY_THRESHOLD)
    {
      // go to position 90
      myServo.write(90);
      delay(100);
      // go to position 45
      myServo.write(45);
      delay(100);
    }
`
--> in this if statement, we check if the humidity value is greater or equal to the threshold (the number 75). If yes, we drive the servo back and forth between 45 and 90 degrees.


