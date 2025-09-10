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

## 🔴 Step 1: Two Pin Buttons
These little clicky switches are standard input "buttons" on electronic projects and have two modes (on & off). The buttons work by two pins that are normally open (disconnected) and when the button is pressed they are momentarily closed causing a reaction in response. 

|<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/HeatPad_Peltier%2BButtons/assets/Two_Buttons.jpg" width="500"/>|<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/HeatPad_Peltier%2BButtons/assets/Two_Pin.jpg" width="500"/>|
|--|--| 

**Arduino Code:** <br /> 
```C++
const int button_OnPin = 12;
const int button_OffPin = 10;

void setup() {
 // Set pin modes

 Serial.begin(9600);

 pinMode(button_OnPin, INPUT_PULLUP);  // Button 1 with pull-up resistor
 pinMode(button_OffPin, INPUT_PULLUP); // Button 2 with pull-up resistor
}

void loop() {
 // Read button states
int button_OnState = digitalRead(button_OnPin);
 int button_OffState = digitalRead(button_OffPin);

 if (button_OnState == LOW) {
   Serial.println("Button 1 PRESSED");
 }

 if (button_OffState == LOW) {
   Serial.println("Button 2 PRESSED");
 }

 // Add a small delay to debounce the buttons
 delay(50);
}
```
## 🔴 Step 2: MOSFET Module Driver
The IRF520 MOSFET Driver Module lets a low-power control signal (from microcontrollers such as an Arduino, Raspberry Pi, etc.) switch on the MOSFET to allow high-power voltage to flow to components such motors, LED strips, solenoids and more.

### How does the MOSFET Module Driver work?
A microcontroller sends a signal to the SIG pin, which activates the MOSFET and connects the circuit through GND. This “opens the gate,” allowing an external high-voltage source (connected to VIN and GND) to power your load. Your component connects to V+ and V-, which deliver the high-voltage power to the device.

<b> *Please note, if the SIG signal is high (e.g., 5V), the MOSFET turns on, and current flows. If the SIG signal is low (0V), the MOSFET is off, and no current flows through. </b>

<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/HeatPad_Peltier%2BButtons/assets/MOSFET.jpg" width="1000"/>

## 🔴 Step 3: Connecting the Electric Heat Pad to the MOSFET Driver
Most heating elements on the market demand high power and are often impractical for hobbyists and makers. The Adafruit 10cm x 5cm Heating Pad is different. Powered by 5V, its stainless-steel fibers generate heat in a thin, flexible fabric—perfect for wrapping, bending, or integrating into wearable projects.

The pad runs safely on 5V / 1A, but for stronger heating, it can be driven with up to 12V, 1A. 

<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/HeatPad_Peltier%2BButtons/assets/Heatpad.jpg" width="500"/>

Here is a video further explaing the mechanics of the heatpad (https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/) 

**Arduino Code:** <br /> 
```C++
// Define pins for the MOS Module
const int heatPadPin = 13;        // Output signal to the MOS Module

// Timer variables
unsigned long heatPadStartTime = 0;
const unsigned long maxOnDuration = 30000; // 30 seconds in milliseconds

bool heatPadOn = false;

void setup() {
 // Set pin modes
 pinMode(heatPadPin, OUTPUT);      // MOS Module control pin

 digitalWrite(heatPadPin, LOW);  // Ensure heating pad starts OFF

    digitalWrite(heatPadPin, HIGH);
   heatPadOn = true;
   heatPadStartTime = millis(); // Record the start time
}

void loop() {

 // Check if the heating pad has been on for too long
 if (heatPadOn && (millis() - heatPadStartTime >= maxOnDuration)) {
   digitalWrite(heatPadPin, LOW);
   heatPadOn = false;
 }
}
```

## 🔴 Step 4: Connecting the Peltier Thermo-Electric Cooler to the MOSFET Driver
Keep it cool with a Peltier module. These unique electronic components can generate a temperature differential when powered. That is to say, apply 5V to the red (positive) and black (negative) wires and one side will get cold while the other side gets hot. For best results, you'll need to wick away that heat (otherwise the cold side will slowly get warmer). A fan and/or heatsink is ideal.
### How does the Peltier work?
The peltier works similiar to the Heatpad as it requires 5V of power at 1.5 amps through a MOSFET Driver. For the code follow the same instructions as the heatpad, making sure to assign it pins, adding it in the void loop and 
|<img src="https://github.com/CCAHybridLab/HLResources/blob/main/assets/Peltier_Thermo_Electric.jpeg" width="500"/>

## 🔴 Step 5: Connecting all components together! 

The sensor is composed of two ultrasonic transducers. One is transmitter which outputs ultrasonic sound pulses and the other is receiver which listens for reflected waves. It’s basically a SONAR which is used in submarines for detecting underwater objects.

|<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/HeatPad_Peltier%2BButtons/assets/Heatpad_Fritzing.jpg" width="600"/>|<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/HeatPad_Peltier%2BButtons/assets/Heatpad_01.jpg" width="400"/>|

**Arduino Code:** <br /> 
```C++
// Define pins for the MOS Module
const int heatPadPin = 13;        // Output signal to the MOS Module
const int buttonOnPin = 2;       // Button to turn the heating pad ON
const int buttonOffPin = 3;      // Button to turn the heating pad OFF
const int peltierPin = 9;        // Output signal to the peltier


// Timer variables
unsigned long heatPadStartTime = 0;
const unsigned long maxOnDuration = 120000; // 2 minutes in milliseconds


bool heatPadOn = false;


void setup() {
 // Set pin modes
 pinMode(heatPadPin, OUTPUT);      // MOS Module control pin
 pinMode(peltierPin, OUTPUT);      // MOS Module control pin
 pinMode(buttonOnPin, INPUT_PULLUP);  // Button ON with pull-up resistor
 pinMode(buttonOffPin, INPUT_PULLUP); // Button OFF with pull-up resistor


 // Ensure heating pad starts OFF
 digitalWrite(heatPadPin, LOW);
}


void loop() {
 // Read button states
 int buttonOnState = digitalRead(buttonOnPin);
 int buttonOffState = digitalRead(buttonOffPin);


 // Turn on the heating pad if the ON button is pressed
 if (buttonOnState == LOW && !heatPadOn) {
   digitalWrite(heatPadPin, HIGH);
   digitalWrite(peltierPin, HIGH);
   heatPadOn = true;
   heatPadStartTime = millis(); // Record the start time
 }


 // Turn off the heating pad if the OFF button is pressed
 if (buttonOffState == LOW && heatPadOn) {
   digitalWrite(heatPadPin, LOW);
   digitalWrite(peltierPin, LOW);
   heatPadOn = false;
 }


 // Check if the heating pad has been on for too long
 if (heatPadOn && (millis() - heatPadStartTime >= maxOnDuration)) {
   digitalWrite(heatPadPin, LOW);
   digitalWrite(peltierPin, LOW);
   heatPadOn = false;
}
```
<br/>

## 🔴 Extra Step: 3D model for Peltier
The sensor is composed of two ultrasonic transducers. One is transmitter which outputs ultrasonic sound pulses and the other is receiver which listens for reflected waves. It’s basically a SONAR which is used in submarines for detecting underwater objects.

|<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/HeatPad_Peltier%2BButtons/assets/3D_Peltier.png" width="500"/>
