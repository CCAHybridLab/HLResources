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
| **[Diffused RGB (Tri-Color) LED - CATHODE](https://www.adafruit.com/product/159?srsltid=AfmBOoqQ8dGMa6cjChJbZBdz2py7uabAm7BrxtUhuQIJAAsMwGzsS3r9Ke8)** | 1 | Our changing variable. 🚨 |
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

| <img src="https://github.com/CCAHybridLab/HLResources/blob/c60550c68361cf4cfb2a90c3e3447d3c2d78a2c3/Arduino/Tutorials/Potentiometer%2BRGB_LED/assets/pot-pins.jpg" width="600" /> | <img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/Tutorials/Potentiometer%2BRGB_LED/assets/pot%20and%20arduino%20example.png" width="600"/> |
|:---|:---:|


  <p>
   When we connect our potentiometer to the Arduino, we can read it's output values with the following program:
   
  </p>
  
**Arduino Code:** <br />
```C++
// Constants:

const int PotPin = A4;

// Runs once when the Arduino turns on, resets, or after code upload
void setup() {
  Serial.begin(9600);
}

// Runs infinitely
void loop() {
  updatePot(); // call this function that runs all the potentiometer code
  delay(200); // wait 200 ms 
}

void updatePot() {
  int valuePot = analogRead(PotPin);  //reading data from the pot

  Serial.print("Pot: ");
  Serial.println(valuePot);
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
  
  Next we want to actually show that value change created by the potentiometer by adding an LED that we can adjust the brightness of. Single color RGB leds only have two legs. Copy the set up shown below. 
  
  
| <img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/Tutorials/Potentiometer%2BRGB_LED/assets/led_example.png" width="600" /> | <img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/Tutorials/Potentiometer%2BRGB_LED/assets/pot%20and%20led%20example.png" width="600"/> |
|:---|:---:|
  
Now is when we need to convert the data we are reading from the potentiometer into signals that can be sent to the LED. For this we will “map” the large set of data from the potentiometer (0-1023) to the smaller set sent to the LED (0-255), think of it like scaling the numbers to translate it between elements. 

Potentiometers can unfortunately not always read accurately at the high and low ends of the spectrum, so here we eliminate that issue by setting a minimum and maximum for the potentiometer data. This allows any value over 1000 to equal 255 on the LED and any value under 100 to be 0. Then we just have to send the data to the LED by “writing” to its pin! 
  
  **Arduino Code:** <br /> 
  ```C++
 // Constants:
const int rLedPin = 3;

const int rPotPin = A4;

const int potMin = 100;
const int potMax = 1000;

void setup() {
  Serial.begin(9600);

  pinMode(rLedPin, OUTPUT);
}

void loop() {
  updateRedPot();

  delay(200);  // Main loop delay
}

void updateRedPot() {
  int valueRedPot = analogRead(rPotPin));  //reading data from the red pot
  int valueRed = map(valueRedPot, potMin, potMax, 0, 255);
  if (valueRedPot <= potMin) valueRed = 0;
  if (valueRedPot >= potMax) valueRed = 255;

  Serial.print("RedPot: ");
  Serial.println(valueRedPot);
  Serial.print("RedLEDVal: ");
  Serial.println(valueRed);
  Serial.println("----------");

  analogWrite(rLedPin, valueRed);
}
  ```
  
</details>

<details>
  <summary>
     <h2> Step 3: Putting it all together! </h2>
  </summary>
  <br>
 
  Okay, now let’s add the rest! Since we are trying to change a single bulb, we’ll need to use an RGB LED, this has 4 pins instead of 2, the long one is now ground, (make sure this is a common cathode bulb!) and the other 3 correlate to data for each color. Adding the potentiometers and LEDs for green and blue is our last hardware step. 
 

 |<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/Tutorials/Potentiometer%2BRGB_LED/assets/common_cathode_rgbled.jpg" width="275"/> | <img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/Tutorials/Potentiometer%2BRGB_LED/assets/pot-rgbLED.png" width="350"/> | <img src="https://github.com/CCAHybridLab/HLResources/blob/fa7a3add5fc75af1b4023a3aabdd741d9873b29a/Arduino/Tutorials/Potentiometer%2BRGB_LED/assets/IMG_0090.png" width="325" /> |
 |:---|:---:|:---|
  

As mentioned before, potentiometer readings are not always stable. To combat this further, we can add an averaging system. This is done by creating an integer that will read data from the potentiometer for a certain amount of time, and then divide the data by how long it was counting to receive an average. Now we have to replace where analogRead was in the last example with readAveragedAnalog so we are only using the averaged numbers when writing to the LED’s. Since we connected the RGB LED on the breadboard to where our regular LED’s are, we only need to write to one pin per color. All that’s left is to make green and blue versions of each command! 
  
  **Arduino Code:** <br /> 
  ```C++
  // Constants:
const int rLedPin = 9;
const int gLedPin = 6;
const int bLedPin = 3;

const int rPotPin = A0;
const int gPotPin = A2;
const int bPotPin = A4;

const int potMin = 100;
const int potMax = 1000;

void setup() {
  Serial.begin(9600);

  pinMode(rLedPin, OUTPUT);
  pinMode(gLedPin, OUTPUT);
  pinMode(bLedPin, OUTPUT);
}

void loop() {
  updateRed();
  updateGreen();
  updateBlue();

  delay(200);  // Main loop delay
}

// Reads averaged analog value over a short duration
int readAveragedAnalog(int pin, int durationMs) {
  unsigned long startTime = millis();
  long total = 0;
  int count = 0;

  while (millis() - startTime < durationMs) {
    total += analogRead(pin);
    count++;
    delay(5);  // Small delay between samples
  }

  return total / count;
}

void updateRed() {
  int valueRedPot = readAveragedAnalog(rPotPin, 50);  // Averaging over 50 ms
  int valueRed = map(valueRedPot, potMin, potMax, 0, 255);
  if (valueRedPot <= potMin) valueRed = 0;
  if (valueRedPot >= potMax) valueRed = 255;

  Serial.print("RedPot: ");
  Serial.println(valueRedPot);
  Serial.print("RedLEDVal: ");
  Serial.println(valueRed);
  Serial.println("----------");

  analogWrite(rLedPin, valueRed);
}

void updateGreen() {
  int valueGreenPot = readAveragedAnalog(gPotPin, 50);
  int valueGreen = map(valueGreenPot, potMin, potMax, 0, 255);
  if (valueGreenPot <= potMin) valueGreen = 0;
  if (valueGreenPot >= potMax) valueGreen = 255;

  analogWrite(gLedPin, valueGreen);
}

void updateBlue() {
  int valueBluePot = readAveragedAnalog(bPotPin, 50);
  int valueBlue = map(valueBluePot, potMin, potMax, 0, 255);
  if (valueBluePot <= potMin) valueBlue = 0;
  if (valueBluePot >= potMax) valueBlue = 255;

  analogWrite(bLedPin, valueBlue);
}
  ```
  <br/>
</details>

