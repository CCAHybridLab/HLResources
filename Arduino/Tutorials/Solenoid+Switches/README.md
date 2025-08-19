# <b> Solenoid + Switches </b> 
|<img src="https://github.com/CCAHybridLab/HLResources/blob/main/assets/MOSFET_Driver.jpg" width="400"/>|<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/Tutorials/Solenoid%2BSwitches/images/Solenoid_Digital_Circuit.png" width="600"/>|
|--|--|

## Equipment
Don't have the parts? Build and test digitally on [Tinkercad](https://www.tinkercad.com/things/cYTtEqcJcwH-amazing-fulffy/editel?tenant=circuits)
- [Arduino Uno](https://airtable.com/appCpmcjYA1vwj8jn/tblOHGyZIGOZuJhCj/viwcQ6Lj5fpoG6Hvh/recQ1P43HKyVMjA79?blocks=hide)
- [Breadboard](https://airtable.com/appCpmcjYA1vwj8jn/tblZz5NUA546g9J6o/viwu3SMJU1AEGhMGK/recF514LASWf2n9LH?blocks=hide)
- [Buttons](https://www.adafruit.com/product/1481)
- [TIP 120 Transistor](https://www.adafruit.com/product/1481)
- [1k Ω](https://www.adafruit.com/product/1481)
- [1n4001 diode](https://www.adafruit.com/product/1331)
- [6v 2A solenoid](https://www.adafruit.com/product/1331)
- [external power source](https://www.adafruit.com/product/1331)
- [LED](https://www.adafruit.com/product/1331)

we will be testing each parts before combining them, it is easier to catch errors and understand how it works.

## 🔴 Step 1: Buttons
<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/Tutorials/Solenoid%2BSwitches/images/4pinbutton.jpg" width="500"/>

This is a 4-pin button, commonly used to trigger interactive action in your project. Unlike 2-pin buttons, 4-pin buttons work in different ways. The pins must be connected diagonally. For this project, we will only be using two pins. Therefore, you can use a 2-pin or a 4-pin button.

<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/Tutorials/Solenoid%2BSwitches/images/4pinbuttonwork.png" width="500"/>

<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/Tutorials/Solenoid%2BSwitches/images/Arduino_Button_InternalLED_Animation_Edited.gif" width="800"/>
Read more to understand how 4 pin button work from (https://makeabilitylab.github.io/physcomp/arduino/buttons.html)

### Pullup Resistor
This part is to explain how the coding works and why 'pullup' was used instead of 'input'
What is a pull up? 
why not just use input? - arduino is a very sensitive device, if you just leave it as input it will be effected my the surroundings, it is like a antanna that collects any signal. it will randomly pick up the signals when you put your finger near even before pressing a button. and this is called a **floating state**.
Therefore you would need a pullup command so that the arduino would be stable state(high) and react when it is pressed(low)

### Build It
Follow this diagram to test out for your own, **watch out for the LED placement:** the longer side is **positive** that goes to digital pin 13 and 12, shorter side is **negative** that goes to ground. 


<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/Tutorials/Solenoid%2BSwitches/images/button%2Bled_bb.png" width="500"/>


**Arduino Code:** <br /> 
Similar Code Step-by-Step Explanation in [Little Bird Electrionic's Guide](https://learn.littlebirdelectronics.com.au/arduino/use-a-push-button-with-arduino)
```C++
  /*
  Switches with LED Arduino Tutorial

  referenced Cherie Tan
  https://learn.littlebirdelectronics.com.au/arduino/use-a-push-button-with-arduino
*/

const int blueledPin = 2;
const int bluebuttonPin = 3;
const int yellowledPin = 12;
const int yellowbuttonPin = 13;

void setup()
{
  pinMode(blueledPin,OUTPUT); // Set the LED Pin as an output
  pinMode(bluebuttonPin,INPUT_PULLUP); // Set the Tilt Switch as an input

  pinMode(yellowledPin,OUTPUT); // Set the LED Pin as an output
  pinMode(yellowbuttonPin,INPUT_PULLUP); // Set the Tilt Switch as an input
}

void loop()
{
  int bdigitalVal = digitalRead(bluebuttonPin);// Take a blue pin reading
  int ydigitalVal = digitalRead(yellowbuttonPin);// Take a yellow pin reading


  if(HIGH == bdigitalVal) //when yellow button is pressed
  {
    digitalWrite(blueledPin,LOW); //Turn the LED off
  }
  else
  {
    digitalWrite(blueledPin,HIGH); //Turn the LED on
  }

  if(HIGH == ydigitalVal) //when yellow button is pressed
  {
    digitalWrite(yellowledPin,LOW); //Turn the LED off
  }
  else
  {
    digitalWrite(yellowledPin,HIGH);//Turn the LED on
  }
}
```


More details about how the pins work (https://forum.arduino.cc/t/is-a-two-pin-button-the-same-as-the-arduino-four-pin-button/533619/6)

#### Move on to Step 2 once you've mimiced the diagram above. 
## Step 2: MOSFET Module Driver
The IRF520 MOSFET Driver Module is used to drive and control MOSFETs in various electronic circuits. Specifically, it is often used in situations where you need to provide high-power to devices or components (like motors, LEDs, or other loads) with a lower-power control signal, typically from a microcontroller (e.g., Arduino, Raspberry Pi). So, the module allows you to use a small control signal (like from a microcontroller or an Arduino) to switch the MOSFET on and off, which in turn controls a larger, high-power load (like a motor, LED strip, etc.).
### How does the MOSFET Module Driver work?
In order to send a high-voltage source of power to your components, you first need to power the MOSFET Module in order to "open the gate" to the high voltage. So, an Arduino (or microcontroller) sends a signal to the SIG pin on the MOSFET which then powers the driver and creates a circuit rhough conecting it to the GND pin and back to the Arduino.

Across the board of the driver are the VIN pin and GND pins. These pins are used to supply your output with a high-voltage source of power. You would attached your high-source of power (9V battery pack, 12v power pack, etc) to these pins. 

Lastly, the <b> V- & V+ </b> pins on the driver are used as the positive and negative for your ouput source. 

<b> *Please note, if the SIG signal is high (e.g., 5V), the MOSFET turns on, and current flows. If the SIG signal is low (0V), the MOSFET is off, and no current flows through. </b>

<img src="https://github.com/CCAHybridLab/HLResources/blob/main/assets/MOSFET_Driver.jpg" width="550"/>

More thorough hardware details in [Mechatronic's Guide](https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/)
### How to the calculate voltage
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
## Step 3: Electric Heating Pad
There are a great many heating elements on the market but most require a great deal of energy to provide heating. And most of those products are way too much for the needs of the Maker.

The Adafruit 10cm x 5cm heating pad is different. Apply 5-12VDC and the stainless steel fibers in the heating fabric will warm up, creating a little heating pad. On one hand, it's just a gigantic resistor. On the other hand, it's flexible, light, and can be wrapped around a project. Originally designed for portable wearable heating pads, the fabric can be used for wearables, weather balloons, diy-bio projects, thermal cycling for materials testing, etc.

### How does the Electric Heating Pad work?
The sensor is composed of two ultrasonic transducers. One is transmitter which outputs ultrasonic sound pulses and the other is receiver which listens for reflected waves. It’s basically a SONAR which is used in submarines for detecting underwater objects.
<img src="https://github.com/CCAHybridLab/HLResources/blob/main/assets/Heat_Pad.jpg" width="650"/>

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
## Step 4: Peltier Thermo-Electric Cooler
A distance measuring sensor which has a range from 2cm to 400cm (about an inch to 13 feet). Best used for accurately measuring the distance to an object within a specific range, particularly when you want to detect the presence or proximity of an object without direct contact, making it useful for applications like obstacle avoidance, line following, automated door opening, or level detection in a robot or device. 
### How does the Peltier work?
The sensor is composed of two ultrasonic transducers. One is transmitter which outputs ultrasonic sound pulses and the other is receiver which listens for reflected waves. It’s basically a SONAR which is used in submarines for detecting underwater objects.
|<img src="https://github.com/CCAHybridLab/HLResources/blob/main/assets/Peltier_Thermo_Electric.jpeg" width="650"/>

More thorough hardware details in [Mechatronic's Guide](https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/)

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
## Step 5: Put them all together!
The sensor is composed of two ultrasonic transducers. One is transmitter which outputs ultrasonic sound pulses and the other is receiver which listens for reflected waves. It’s basically a SONAR which is used in submarines for detecting underwater objects.
|<img src="https://github.com/CCAHybridLab/HLResources/blob/main/assets/Peltier_Thermo_Electric.jpeg" width="500"/>
<br/>
