/*SHARP GP2Y0A21YK0F IR distance sensor with 
  Arduino and SharpIR library example code. 
  More info: https://www.makerguides.com */

// Include the library:
#include "SharpIR.h"

#include <Servo.h>

/* Model :
  GP2Y0A02YK0F --> 20150
  GP2Y0A21YK0F --> 1080
  GP2Y0A710K0F --> 100500
  GP2YA41SK0F --> 430
*/

// Define model and input pin:
#define IRPin A0
#define IRModel 1080

// Variable to store the distance
int distance_cm;

// Create a new instance of the SharpIR class:
SharpIR irSensor = SharpIR(IRPin, IRModel);
Servo servo;  // create servo object to control a servo

bool triggered = false;

void setup() {
  // Serial communication at a baudrate of 9600
  Serial.begin(9600);
  servo.attach(9);  // attaches the servo on pin 9 to the servo object
  servo.write(0); // move servo 0 degrees
  delay(1000);
}

void loop() {
  // Get a distance measurement and store it as distance_cm
  distance_cm = irSensor.distance();

  // Print the measured distance to the serial monitor
  Serial.print("Mean distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  if (distance_cm < 15) {
    servo.write(90); // move servo 0 degrees
    delay(3000);
    servo.write(0);
  } else {
    servo.write(0);
  }

  // TODO: determine distance range
  delay(10);
}