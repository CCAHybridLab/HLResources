#include <Servo.h>

Servo servo;  // create servo object to control a servo

void setup() {
  servo.attach(9);  // attaches the servo on pin 9 to the servo object
  servo.write(0); // move servo 0 degrees
}

void loop() {
  servo.write(90); // move servo 90 degrees
  delay(3000); // leave servo in position for 3 seconds (1000 ms = 1 sec)
  servo.write(0); // move servo back to 0
  delay(1000); // leave servo in position for 1 second
}
