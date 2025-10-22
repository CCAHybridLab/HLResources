# <b> Potentiometer + Diffused RGB LED </b> 
| <img src="https://github.com/CCAHybridLab/HLResources/blob/fa7a3add5fc75af1b4023a3aabdd741d9873b29a/Arduino/Tutorials/Potentiometer%2BRGB_LED/assets/IMG_0090.png" width="600" /> | <img src="https://github.com/CCAHybridLab/HLResources/blob/67ee9a4bda74d94f8fefea2a7402bcb5880a7f00/Arduino/Tutorials/Potentiometer%2BRGB_LED/assets/pot-rgbLED.png" width="600"/> |
|:---|:---:|


 ## ⚙️ Equipment & Components

<p>
  This project uses a potentiometer to control RGB LED output.
</p>

| Component | Quantity | Notes |
|:---|:---:|:---|
| **[Arduino Uno](https://airtable.com/appCpmcjYA1vwj8jn/tblOHGyZIGOZuJhCj/viwcQ6Lj5fpoG6Hvh/recQ1P43HKyVMjA79?blocks=hide)** | 1 | The brain of our project. |
| **[Breadboard](https://airtable.com/appCpmcjYA1vwj8jn/tblZz5NUA546g9J6o/viwu3SMJU1AEGhMGK/recF514LASWf2n9LH?blocks=hide)** | 1 | For building the circuit. |
| **[Diffused RGB (Tri-Color) LED](https://www.adafruit.com/product/159?srsltid=AfmBOoqQ8dGMa6cjChJbZBdz2py7uabAm7BrxtUhuQIJAAsMwGzsS3r9Ke8)** | 1 | Our changing variable. 🚨 |
| **[10K Potentiometer](https://www.adafruit.com/product/562?srsltid=AfmBOoqtB6Lbhd8nUAGzxMfThQJemVqiWrplyxYimvI-uLNBoEpAtYPYYGA)** | 1 | Controls our LED output. |
| **[220 ohm Resistor](https://www.adafruit.com/product/2780?srsltid=AfmBOopmkZkIUP5s_hycNqkQo98pfRENfjLETCFsG8mRPr04hxSWfXWS)** | 3 | Controls electrical curent to the LED. |
| **[Jumper Wires](https://www.adafruit.com/category/306?srsltid=AfmBOook5BsXkN5B8NOekLEvpqA6bxxpfq-iHHaRTnXBJzHQmaL5iwjg)** | 1 Bundle | For connecting all the components. |
| **[(Optional) Potemtiometer Cap](https://www.adafruit.com/product/1481)** | 1 | For easier control of the potentiometer. |

  <p>
    <strong>Important Note:</strong>
 Always make sure you have all equipment before starting a project.
  </p>

<details>
  <summary>
     <h2> Step 1: Understanding the Potentiometer </h2>
  </summary>
  <br>
  <p>
    Potentiometers are variable resistors that have a number of useful applications when building a curciut. Remember, a resistor controls the amount of electrical current a component is recieving-- potentiometers allow us to alter that input!
  </p>
  <img src="path/to/image.jpg" width="500" alt="Wiring diagram for step 1">
</details>


<details>
  <summary>
     <h2> Step 3: Connecting the HeatPad + Peltier </h2>
  </summary>
  <br>
  <p>
    Here are the detailed instructions for this step. You can include text, images, and more.
  </p>
  <img src="path/to/image.jpg" width="500" alt="Wiring diagram for step 1">
</details>

<details>
  <summary>
     <h2> Step 4: Putting it all together! </h2>
  </summary>
  <br>
  <p>
    Here are the detailed instructions for this step. You can include text, images, and more.
  </p>
  <img src="path/to/image.jpg" width="500" alt="Wiring diagram for step 1">
</details>


<details>
  <summary>
     <h2> Step 5 (Optional): 3D Printing Case for Peltier </h2>
  </summary>
  <br>
  <p>
    Here are the detailed instructions for this step. You can include text, images, and more.
  </p>
  <img src="path/to/image.jpg" width="500" alt="Wiring diagram for step 1">
</details>

## 🔴 Step 1: Understanding the Potentiometer
Potentiometers are variable resistors that have a number of useful applications when building a curciut. Remember, a resistor controls the amount of electrical current a component is recieving-- potentiometers allow us to alter that input!

### How does the Potentiometer work?
The potentiometer has 3 terminals-- the two outer terminals are fixed, while the middle terminal is variable.

For this project, connect the potentiometer to the arduino and bread board as follows:

***this will be a diagram
Terminal 1 to GND
Terminal 2 to output
Terminal 3 to input

  <p>
   When we connect our potentiometer to the Arduino, we can read it's output values with the following program:
   
  </p>
  
**Arduino Code:** <br />
```C++
//Constants:
  const int potPin = A0;

//Variables:
  int potVal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(potPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  Serial.println(potVal);
  delay(100);
}
```

<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/HeatPad_Peltier%2BButtons/assets/MOSFET.jpg" width="1000"/>

## 🔴 Step 3: Connecting the Electric Heat Pad to the MOSFET Driver
Most heating elements on the market demand high power and are often impractical for hobbyists and makers. The Adafruit 10cm x 5cm Heating Pad is different. Powered by 5V, its stainless-steel fibers generate heat in a thin, flexible fabric—perfect for wrapping, bending, or integrating into wearable projects.

The pad runs safely on 5V / 1A, but for stronger heating, it can be driven with up to 12V, 1A. ⚠️ for warnings or cautions

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
