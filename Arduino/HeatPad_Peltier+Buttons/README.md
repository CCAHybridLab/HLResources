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
The IRF520 MOSFET Driver Module is used to drive and control MOSFETs in various electronic circuits. Specifically, it is often used in situations where you need to provide high-power to devices or components (like motors, LEDs, or other loads) with a lower-power control signal, typically from a microcontroller (e.g., Arduino, Raspberry Pi). So, the module allows you to use a small control signal (like from a microcontroller or an Arduino) to switch the MOSFET on and off, which in turn controls a larger, high-power load (like a motor, LED strip, etc.).
### How does the MOSFET Module Driver work?
In order to send a high-voltage source of power to your components, you first need to power the MOSFET Module in order to "open the gate" to the high voltage. So, an Arduino (or microcontroller) sends a signal to the SIG pin on the MOSFET which then powers the driver and creates a circuit by conecting it to the GND pin and back to the Arduino. The Arduino's low voltage sent to the MOSFET essentially "opens the gate", allowing higher voltages inputed into the MOSFET externally to power other components. 

Across the board of the driver are the VIN pin and GND pins. These pins are used to supply your output with a high-voltage source of power. You would attached your high-source of power (9V battery pack, 12v power pack, etc) to these pins. 

The <b> V- & V+ </b> pins on the driver are used as the positive and negative for your other components (heatpad, peltier, solenoid, etc)

<img src="https://github.com/CCAHybridLab/HLResources/blob/main/assets/MOSFET_Driver.jpg" width="550"/>

<b> *Please note, if the SIG signal is high (e.g., 5V), the MOSFET turns on, and current flows. If the SIG signal is low (0V), the MOSFET is off, and no current flows through. </b>

Here is a video further explaning how the MOSFET Driver works (https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/)

## 🔴 Step 3: Connecting the Electric Heat Pad to the MOSFET Driver
There are a great many heating elements on the market but most require a great deal of energy to provide heating and most of those products are way beyond the cope of the maker. The Adafruit 10cm x 5cm heating pad is different. When 5-12VDC is applied, the stainless steel fibers in the heating fabric will warm up, creating a flexible, light heating pad that can be wrapped around and maniopulated for a wearable project.

### How does the Electric Heating Pad work?
The sensor is composed of two ultrasonic transducers. One is transmitter which outputs ultrasonic sound pulses and the other is receiver which listens for reflected waves. It’s basically a SONAR which is used in submarines for detecting underwater objects.
<img src="https://github.com/CCAHybridLab/HLResources/blob/main/assets/Heat_Pad.jpg" width="500"/>

Here is a video further explaing the mechanics of the heatpad (https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/) 

**Arduino Code:** <br /> 
```C++
// Define pins for the MOS Module
const int heatPadPin = 13;        // Output signal to the MOS Module

// Timer variables
unsigned long heatPadStartTime = 0;
const unsigned long maxOnDuration = 30000; // 2 minutes in milliseconds

bool heatPadOn = false;

void setup() {
 // Set pin modes
 pinMode(heatPadPin, OUTPUT);      // MOS Module control pin

 // Ensure heating pad starts OFF
 digitalWrite(heatPadPin, LOW);

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

## Step 4: Connecting the Peltier Thermo-Electric Cooler to the MOSFET Driver
Keep it cool with a Peltier module. These unique electronic components can generate a temperature differential when powered. That is to say, apply 5V to the red (positive) and black (negative) wires and one side will get cold while the other side gets hot. For best results, you'll need to wick away that heat (otherwise the cold side will slowly get warmer). A fan and/or heatsink is ideal.
### How does the Peltier work?
The peltier works similiar to the Heatpad as it requires 5V of power at 1.5 amps through a MOSFET Driver. For the code follow the same instructions as the heatpad, making sure to assign it pins, adding it in the void loop and 
|<img src="https://github.com/CCAHybridLab/HLResources/blob/main/assets/Peltier_Thermo_Electric.jpeg" width="500"/>

## Step 5: Connecting all components together! 

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
