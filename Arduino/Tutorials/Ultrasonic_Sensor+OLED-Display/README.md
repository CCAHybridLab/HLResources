# Ultrasonic Distance Sensor + OLED Display
|<img src="https://github.com/CCAHybridLab/HLResources/assets/63166855/fdc98498-3b51-4776-a57e-e7fd0a68bac4" width="400"/>|<img src="Arduino/Ultrasonic_Sensor+OLED-Display/wiring-ultrasonic-distance+OLED-display.png" width="600"/>|
|--|--|

## Equipment
Don't have the parts? Build and test digitally on [Tinkercad](https://www.tinkercad.com/things/cYTtEqcJcwH-amazing-fulffy/editel?tenant=circuits)
- [Arduino Uno](https://airtable.com/appCpmcjYA1vwj8jn/tblOHGyZIGOZuJhCj/viwcQ6Lj5fpoG6Hvh/recQ1P43HKyVMjA79?blocks=hide)
- [HC-SR04 Ultrasonic distance sensor](https://airtable.com/appCpmcjYA1vwj8jn/tblZBoJcxkwHEMrXX/viwnKOWwUT76Q9RQV/recMg76eFUkjVesqo?blocks=hide)
- [SSD1306 0.96 inch I2C OLED](https://airtable.com/appCpmcjYA1vwj8jn/tblZz5NUA546g9J6o/viwu3SMJU1AEGhMGK/recW9AWeKOTIZbg60?blocks=hide)
- [Breadboard](https://airtable.com/appCpmcjYA1vwj8jn/tblZz5NUA546g9J6o/viwu3SMJU1AEGhMGK/recF514LASWf2n9LH?blocks=hide)
## Step 1: Ultrasonic Distance Sensor
A distance measuring sensor which has a range from 2cm to 400cm (about an inch to 13 feet). Best used for accurately measuring the distance to an object within a specific range, particularly when you want to detect the presence or proximity of an object without direct contact, making it useful for applications like obstacle avoidance, line following, automated door opening, or level detection in a robot or device. 
### How does the sensor work?
The sensor is composed of two ultrasonic transducers. One is transmitter which outputs ultrasonic sound pulses and the other is receiver which listens for reflected waves. It’s basically a SONAR which is used in submarines for detecting underwater objects.
|<img src="https://github.com/CCAHybridLab/HLResources/blob/main/assets/Ultrasonic-Technical.png" width="650"/>|<img src="https://github.com/CCAHybridLab/HLResources/blob/main/assets/Ultrasonic-Pinout.png" width="350"/>|

More thorough hardware details in [Mechatronic's Guide](https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/)
### How to the calculate distance
Distance = (Speed x Time) / 2 <br /> <br /> 
Example: Let’s say the Echo pin was HIGH for 2ms. If we want the get the distance result in **cm**, we can convert the speed of sound value from 340m/s to 34cm/ms. <br />
- Speed = 34cm/ms <br />
- Time = 2ms <br />

Distance = (Speed x Time) / 2 = (34cm/ms x 2ms) / 2 = 25.5cm.  <br />  <br /> 
**Arduino Code:** <br /> 
Code Step-by-Step Explanation in [Mechatronic's Guide](https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/)
```C++
  /*
  Ultrasonic Sensor HC-SR04 and Arduino Tutorial

  by Dejan Nedelkovski,
  www.HowToMechatronics.com
*/

// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
}
```
#### Move on to Step 2 once you're seeing accurate distance data on serial monitor
## Step 2: OLED Display
- Follow [this guide](https://randomnerdtutorials.com/guide-for-oled-display-with-arduino/) <br/>
  *note: complete through the "“Hello, world!” OLED Display"*
#### Move on to Step 3 once you see "Hello, world!" printed on display
## Step 3: Put them together!
```C++
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Distance Sensor
const int trigPin = 6;
const int echoPin = 5;
long duration;
int distanceInch;
int distanceCm;

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);

  // Distance sensor setup
  pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);

  // OLED setup
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
}

void loop() {
  // Distance Sensor Data
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceInch = duration * 0.0133 / 2;
  distanceCm = duration * 0.034 / 2;

  // Print distance to display
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0); // start of yellow section
  display.println("Distance:");

  display.setTextSize(3);
  display.setCursor(0, 16); // start of blue section
  display.print(distanceCm);
  display.print(" cm");
  delay(10);
  display.setCursor(0, 40);
  display.print(distanceInch);
  display.print(" inch");
  delay(10);

  display.display();
}
```

- Watch [Mechatronics Video Tutorial (included in above tutorial)](https://www.youtube.com/watch?v=ZejQOX69K5M&t=20s) <br/>
*note: the video uses pin 9 and 10 for trig and echo respectively. Our demo uses pin 6 and 5 for trig and echo respectively.*
