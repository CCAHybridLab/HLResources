# <b> Electric Heatpad + Peltier Thermo-Electric Cooler </b> 
|<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/HeatPad_Peltier%2BButtons/assets/Heatpad_01.jpg" width="400"/>|<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/HeatPad_Peltier%2BButtons/assets/Heatpad_Fritzing.jpg" width="600"/>|
|--|--| 

 ## ⚙️ Equipment & Components

<p>
  This project uses a Heating Pad & Peltier module to output heat/cooling.
</p>

| Component | Quantity | Notes |
|:---|:---:|:---|
| **[Arduino Uno](https://airtable.com/appCpmcjYA1vwj8jn/tblOHGyZIGOZuJhCj/viwcQ6Lj5fpoG6Hvh/recQ1P43HKyVMjA79?blocks=hide)** | 1 | The brain of our project. |
| **[Breadboard](https://airtable.com/appCpmcjYA1vwj8jn/tblZz5NUA546g9J6o/viwu3SMJU1AEGhMGK/recF514LASWf2n9LH?blocks=hide)** | 1 | For connecting components together. |
| **[Peltier Thermo-Electric Cooler Module](https://www.adafruit.com/product/1331)** | 1 | Our target for heating & cooling. 🧊 |
| **[MOSFET Module Driver](https://www.adafruit.com/product/1481)** | 1 | Required to control the high current for the heating & cooling. |
| **[Electric Heatpad](https://www.adafruit.com/product/1481)** | 1 | Our target for heating. |
| **[Jumper Wires](https://www.adafruit.com/category/306?srsltid=AfmBOook5BsXkN5B8NOekLEvpqA6bxxpfq-iHHaRTnXBJzHQmaL5iwjg)** | 1 Bundle | For connecting all the components. |
| **[Two Pin Buttons](https://www.adafruit.com/product/1481)** | 2 | For turning components on & off. |

  <p>
    <strong>Important Note:</strong>
 Always make sure you have all equipment before starting a project.
  </p>

<details>
  <summary>
     <h2> Step 1: Setting up the Arduino + Buttons </h2>
  </summary>
 
  <p>
    Begin by connecting the wiring as follows.
  </p>

|<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/HeatPad_Peltier%2BButtons/assets/Two_Buttons.jpg" width="500"/>|<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/HeatPad_Peltier+Buttons/assets/Button_Fritzing_01.jpg" width="500"/>|
|--|--| 

| Component | Description |
|:---|:---|
| **[Two Pin Buttons](https://www.adafruit.com/product/1481)** | These switches are standard input "buttons" on electronic projects and have two modes <b>(On & Off).</b> The buttons work by two pins that are normally open (disconnected) and when the button is pressed they are momentarily closed causing a reaction in response.  

- Start by connecting the buttons to the breadboard. We will be using: (ON 🔴 & OFF 🔵) 
- Using the jumper wires connect the (+) for the ON 🔴 to Pin 12 & the (+) for the OFF 🔵 to Pin 10.
- Using the breadboard, connect ground to the Arduino. 
- Connect your Arduino to your laptop.
- Copy the code below and read the comments to understand how it works. 
<br> </br>
> 💡 **Tip:** Always double-check your wiring before powering on your circuit to avoid damaging components.

**Arduino Code:** <br /> 
```C++
const int button_OnPin = 12; // On button is connected to digital pin 12
const int button_OffPin = 10; // Off button is connected to digital pin 10

void setup() { // Set pin modes

 Serial.begin(9600); // Intialize serial communication on Arduino to send data
 pinMode(button_OnPin, INPUT_PULLUP);  // Button 1 uses internal pull-up (pin reads HIGH when unpressed, LOW when pressed)
 pinMode(button_OffPin, INPUT_PULLUP); // Button 2 uses internal pull-up (pin reads HIGH when unpressed, LOW when pressed)
}

void loop() { // Read button states; INPUT_PULLUP means unpressed = HIGH, pressed = LOW
                                                  
int button_OnState = digitalRead(button_OnPin);   // Button 1 state (starts HIGH = not pressed)
int button_OffState = digitalRead(button_OffPin); // Button 2 state (starts HIGH = not pressed)

if (button_OnState == LOW) { // Button is pressed (LOW because pin connects to GND when pressed)
  Serial.println("Button 1 PRESSED");
}

 if (button_OffState == LOW) { // Button is pressed (LOW because pin connects to GND when pressed)
   Serial.println("Button 2 PRESSED");}

 delay(50); // Add a small delay to debounce the buttons
}
```
Test out the code and look at the <strong> Serial Monitor </strong> to see if the buttons are connect correctly. 
<br> </br>
✅ If the serial monitor reads "Button PRESSED", you did it! Move on to Step 2.

</details>



<details>
  <summary>
     <h2> Step 2: Connecting Heatpad to MOSFET </h2>
  </summary>
 
 | Component | Description |
|:---|:---|
| **[MOSFET Module Driver](https://www.adafruit.com/product/1481)** | The IRF520 MOSFET Driver Module lets a low-power control signal (from microcontrollers such as an Arduino, Raspberry Pi, etc.) switch on the MOSFET to allow high-power voltage to flow to components such as motors, LED strips, solenoids and more. 

A microcontroller sends a signal to the SIG pin, which activates the MOSFET and connects the circuit through GND. This “opens the gate,” allowing an external high-voltage source (connected to VIN and GND) to power your load. Your component connects to V+ and V-, which deliver the high-voltage power to the device.

<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/HeatPad_Peltier%2BButtons/assets/MOSFET.jpg" width="1000"/>

> 📝  **Note:** If the SIG signal is high (e.g., 5V), the MOSFET turns on, and current flows. If the SIG signal is low (0V), the MOSFET is off, and no current flows through.

<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/HeatPad_Peltier%2BButtons/assets/Heatpad_Fritzing_01.jpg" width="1000"/>

| Component | Description |
|:---|:---|
| **[Electric Heatpad](https://www.adafruit.com/product/1481)** | Most heating elements on the market demand high power and are often impractical for hobbyists and makers. The Adafruit 10cm x 5cm Heating Pad is different. Powered by 5V, its stainless-steel fibers generate heat in a thin, flexible fabric—perfect for wrapping, bending, or integrating into wearable projects. 

- Start by connecting the MOSFET Driver to the heatpad/peltier using V- (for ground) ⚫ and V+ (for power) 🔴. 
- Next connect the barrel jack to the MOSFET using VIN & GND.
- After that conect the MOSFET to the Arduino using SIG on Pin 13 and GND.  
- Connect your Arduino to your laptop.
- Power the MOSFET using a 5V - 12V / 1A external power supply plugged into the barrel jack. 
- Copy the code below and read the comments to understand how it works. 
<br> </br>
> ⚠️ **Caution:** The heatpad runs safely on 5V / 1A, but for stronger heating it can be driven with up to 12V, but do not go above 1A as this will damage components.

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
Test out the code and test the heatpad to see if it feels warm.
<br> </br>
✅ If the heatpad feels warm and turns off after 30 seconds, you did it! Move on to Step 3.

</details>

<details>
  <summary>
     <h2> Step 3: Putting it all together! (and adding Peltier) </h2>
  </summary>
The sensor is composed of two ultrasonic transducers. One is transmitter which outputs ultrasonic sound pulses and the other is receiver which listens for reflected waves. It’s basically a SONAR which is used in submarines for detecting underwater objects.

|<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/HeatPad_Peltier%2BButtons/assets/Heatpad_01.jpg" width="400"/>|<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/HeatPad_Peltier%2BButtons/assets/Heatpad_Fritzing.jpg" width="600"/>|

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
</details>


<details>
  <summary>
     <h2> Step 4 (Optional): 3D Printing Case for Peltier </h2>
  </summary>
The sensor is composed of two ultrasonic transducers. One is transmitter which outputs ultrasonic sound pulses and the other is receiver which listens for reflected waves. It’s basically a SONAR which is used in submarines for detecting underwater objects.

|<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/HeatPad_Peltier%2BButtons/assets/3D_Peltier.png" width="500"/>
</details>
