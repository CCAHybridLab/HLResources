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
| **[Breadboard](https://airtable.com/appCpmcjYA1vwj8jn/tblZz5NUA546g9J6o/viwu3SMJU1AEGhMGK/recF514LASWf2n9LH?blocks=hide)** | 2 | For building the circuit. |
| **[Diffused RGB (Tri-Color) LED](https://www.adafruit.com/product/159?srsltid=AfmBOoqQ8dGMa6cjChJbZBdz2py7uabAm7BrxtUhuQIJAAsMwGzsS3r9Ke8)** | 1 | Our changing variable. 🚨 |
| **[Red LED](https://www.adafruit.com/product/159?srsltid=AfmBOoqQ8dGMa6cjChJbZBdz2py7uabAm7BrxtUhuQIJAAsMwGzsS3r9Ke8)** | 1 | Visual aid for red potentiometer. |
| **[Green LED](https://www.adafruit.com/product/159?srsltid=AfmBOoqQ8dGMa6cjChJbZBdz2py7uabAm7BrxtUhuQIJAAsMwGzsS3r9Ke8)** | 1 | Visual aid for green potentiometer. |
| **[Blue LED](https://www.adafruit.com/product/159?srsltid=AfmBOoqQ8dGMa6cjChJbZBdz2py7uabAm7BrxtUhuQIJAAsMwGzsS3r9Ke8)** | 1 | Visual aid for blue potentiometer. |
| **[10K Potentiometer](https://www.adafruit.com/product/562?srsltid=AfmBOoqtB6Lbhd8nUAGzxMfThQJemVqiWrplyxYimvI-uLNBoEpAtYPYYGA)** | 3 | Controls our LED output. |
| **[220 ohm Resistor](https://www.adafruit.com/product/2780?srsltid=AfmBOopmkZkIUP5s_hycNqkQo98pfRENfjLETCFsG8mRPr04hxSWfXWS)** | 3 | Controls electrical curent to the LED. |
| **[Jumper Wires](https://www.adafruit.com/category/306?srsltid=AfmBOook5BsXkN5B8NOekLEvpqA6bxxpfq-iHHaRTnXBJzHQmaL5iwjg)** | 1 Bundle | For connecting all the components. |
| **[(Optional) Potemtiometer Cap](https://www.adafruit.com/product/1481)** | 3 | For easier control of the potentiometer; one per color. |

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
   
The potentiometer has 3 terminals-- the two outer terminals are fixed, while the middle terminal is variable.
 </p>

For this project, connect the potentiometer to the arduino and bread board as follows:

| <img src="https://github.com/CCAHybridLab/HLResources/blob/c60550c68361cf4cfb2a90c3e3447d3c2d78a2c3/Arduino/Tutorials/Potentiometer%2BRGB_LED/assets/pot-pins.jpg" width="600" /> | <img src="https://github.com/CCAHybridLab/HLResources/blob/c60550c68361cf4cfb2a90c3e3447d3c2d78a2c3/Arduino/Tutorials/Potentiometer%2BRGB_LED/assets/pot-arduino-wiring.png" width="600"/> |
|:---|:---:|


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
</details>

<p>


 
</p>


<details>
 
  <summary>
     <h2> Step 2: Connecting the Potentiometer + LED </h2>
  </summary>
  <br>
  
  Most heating elements on the market demand high power and are often impractical for hobbyists and makers. The Adafruit 10cm x 5cm Heating Pad is different. Powered by 5V, its stainless  steel fibers generate heat in a thin, flexible fabric—perfect for wrapping, bending, or integrating into wearable projects.
  
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
  
</details>

<details>
  <summary>
     <h2> Step 3: Putting it all together! </h2>
  </summary>
  <br>
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
</details>

