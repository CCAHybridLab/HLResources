# <b> Electric Heatpad + Peltier Thermo-Electric Cooler </b> 
|<img src="https://github.com/CCAHybridLab/HLResources/blob/main/assets/MOSFET_Driver.jpg" width="400"/>|<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/Ultrasonic_Sensor+OLED-Display/wiring-ultrasonic-distance+OLED-display.png" width="600"/>|
|--|--|

## Equipment
Don't have the parts? Build and test digitally on [Tinkercad](https://www.tinkercad.com/things/cYTtEqcJcwH-amazing-fulffy/editel?tenant=circuits)
- [Arduino Uno](https://airtable.com/appCpmcjYA1vwj8jn/tblOHGyZIGOZuJhCj/viwcQ6Lj5fpoG6Hvh/recQ1P43HKyVMjA79?blocks=hide)
- [Breadboard](https://airtable.com/appCpmcjYA1vwj8jn/tblZz5NUA546g9J6o/viwu3SMJU1AEGhMGK/recF514LASWf2n9LH?blocks=hide)
- [Buttons](https://www.adafruit.com/product/1481)
- [MOSFET Module Driver](https://www.adafruit.com/product/1481)
- [Electric Heatpad](https://www.adafruit.com/product/1481)
- [Peltier Thermo-Electric Cooler Module](https://www.adafruit.com/product/1331)

## 🔴 Step 1: Buttons
Little clicky switches are standard input "buttons" on electronic projects. These work best in a PCB but can be used on a solderless breadboard as shown in this tutorial. The pins are normally open (disconnected) and when the button is pressed they are momentarily closed.

<img src="https://github.com/CCAHybridLab/HLResources/blob/main/assets/Tactile_Button.jpg" width="500"/>

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
A distance measuring sensor which has a range from 2cm to 400cm (about an inch to 13 feet). Best used for accurately measuring the distance to an object within a specific range, particularly when you want to detect the presence or proximity of an object without direct contact, making it useful for applications like obstacle avoidance, line following, automated door opening, or level detection in a robot or device. 
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
