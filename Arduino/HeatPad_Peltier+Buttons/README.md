# <b> Electric Heatpad + Peltier Thermo-Electric Cooler </b> 
|<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/HeatPad_Peltier%2BButtons/assets/Heatpad_01.jpg" width="400"/>|<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/HeatPad_Peltier%2BButtons/assets/Heatpad_Fritzing.jpg" width="600"/>|
|--|--| 

## Equipment
- [Arduino Uno](https://airtable.com/appCpmcjYA1vwj8jn/tblOHGyZIGOZuJhCj/viwcQ6Lj5fpoG6Hvh/recQ1P43HKyVMjA79?blocks=hide)
- [Breadboard](https://airtable.com/appCpmcjYA1vwj8jn/tblZz5NUA546g9J6o/viwu3SMJU1AEGhMGK/recF514LASWf2n9LH?blocks=hide)
- [Buttons](https://www.adafruit.com/product/1481)
- [MOSFET Module Driver](https://www.adafruit.com/product/1481)
- [Electric Heatpad](https://www.adafruit.com/product/1481)
- [Peltier Thermo-Electric Cooler Module](https://www.adafruit.com/product/1331)

## 🔴 Step 1: Buttons
These little clicky switches are standard input "buttons" on electronic projects and have two modes (on & off). The buttons work by two pins that are normally open (disconnected) and when the button is pressed they are momentarily closed causing a reaction in response. 

<img src="https://github.com/CCAHybridLab/HLResources/blob/main/assets/Tactile_Button.jpg" width="500"/>

**Arduino Code:** <br /> 
```C++
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
```
## 🔴 Step 2: MOSFET Module Driver
The IRF520 MOSFET Driver Module is used to drive and control MOSFETs in various electronic circuits. Specifically, it is often used in situations where you need to provide high-power to devices or components (like motors, LEDs, or other loads) with a lower-power control signal, typically from a microcontroller (e.g., Arduino, Raspberry Pi). So, the module allows you to use a small control signal (like from a microcontroller or an Arduino) to switch the MOSFET on and off, which in turn controls a larger, high-power load (like a motor, LED strip, etc.).
### How does the MOSFET Module Driver work?
In order to send a high-voltage source of power to your components, you first need to power the MOSFET Module in order to "open the gate" to the high voltage. So, an Arduino (or microcontroller) sends a signal to the SIG pin on the MOSFET which then powers the driver and creates a circuit by conecting it to the GND pin and back to the Arduino. The Arduino's low voltage sent to the MOSFET essentially "opens the gate", allowing higher voltages inputed into the MOSFET externally to power other components. 

Across the board of the driver are the VIN pin and GND pins. These pins are used to supply your output with a high-voltage source of power. You would attached your high-source of power (9V battery pack, 12v power pack, etc) to these pins. 

The <b> V- & V+ </b> pins on the driver are used as the positive and negative for your other components (heatpad, peltier, solenoid, etc)

<img src="https://github.com/CCAHybridLab/HLResources/blob/main/assets/MOSFET_Driver.jpg" width="550"/>

<b> *Please note, if the SIG signal is high (e.g., 5V), the MOSFET turns on, and current flows. If the SIG signal is low (0V), the MOSFET is off, and no current flows through. </b>

Here is a video further explaning how the MOSFET Driver works (https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/)

**Arduino Code:** <br /> 
```C++
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
```
#### Move on to Step 2 once you're seeing accurate distance data on serial monitor
## 🔴 Step 3: Electric Heating Pad
There are a great many heating elements on the market but most require a great deal of energy to provide heating and most of those products are way beyond the cope of the maker. The Adafruit 10cm x 5cm heating pad is different. When 5-12VDC is applied, the stainless steel fibers in the heating fabric will warm up, creating a flexible, light heating pad that can be wrapped around and maniopulated for a wearable project.

### How does the Electric Heating Pad work?
The sensor is composed of two ultrasonic transducers. One is transmitter which outputs ultrasonic sound pulses and the other is receiver which listens for reflected waves. It’s basically a SONAR which is used in submarines for detecting underwater objects.
<img src="https://github.com/CCAHybridLab/HLResources/blob/main/assets/Heat_Pad.jpg" width="600"/>

Here is a video further explaing the mechanics of the heatpad (https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/) 

**Arduino Code:** <br /> 
```C++
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
```

#### Move on to Step 2 once you're seeing accurate distance data on serial monitor
## Step 4: Peltier Thermo-Electric Cooler
A distance measuring sensor which has a range from 2cm to 400cm (about an inch to 13 feet). Best used for accurately measuring the distance to an object within a specific range, particularly when you want to detect the presence or proximity of an object without direct contact, making it useful for applications like obstacle avoidance, line following, automated door opening, or level detection in a robot or device. 
### How does the Peltier work?
The sensor is composed of two ultrasonic transducers. One is transmitter which outputs ultrasonic sound pulses and the other is receiver which listens for reflected waves. It’s basically a SONAR which is used in submarines for detecting underwater objects.
|<img src="https://github.com/CCAHybridLab/HLResources/blob/main/assets/Peltier_Thermo_Electric.jpeg" width="650"/>

**Arduino Code:** <br /> 
```C++

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
|<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/HeatPad_Peltier%2BButtons/assets/Heatpad_Fritzing.jpg" width="600"/>|<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/HeatPad_Peltier%2BButtons/assets/Heatpad_01.jpg" width="400"/>|
|--|
The sensor is composed of two ultrasonic transducers. One is transmitter which outputs ultrasonic sound pulses and the other is receiver which listens for reflected waves. It’s basically a SONAR which is used in submarines for detecting underwater objects.

<br/>
