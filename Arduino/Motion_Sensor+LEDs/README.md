# <b> Potentiometer + Diffused RGB LED </b> 
| <img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/Motion_Sensor+LEDs/assets/Motion_Sensor_LED_Board.jpg" width="600"/> | <img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/Motion_Sensor+LEDs/assets/PIR Motion + Leds.jpg" width="600"/> |
|:---|:---:|



 ## ⚙️ Equipment & Components

<p>
  This project uses a potentiometer to control RGB LED output.
</p>

| Component | Quantity | Notes |
|:---|:---:|:---|
| **[Arduino Uno](https://airtable.com/appCpmcjYA1vwj8jn/tblOHGyZIGOZuJhCj/viwcQ6Lj5fpoG6Hvh/recQ1P43HKyVMjA79?blocks=hide)** | 1 | The brain of our project. |
| **[Breadboard](https://airtable.com/appCpmcjYA1vwj8jn/tblZz5NUA546g9J6o/viwu3SMJU1AEGhMGK/recF514LASWf2n9LH?blocks=hide)** | 1 | For building the circuit. |
| **[Various LEDs](https://www.adafruit.com/product/159?srsltid=AfmBOoqQ8dGMa6cjChJbZBdz2py7uabAm7BrxtUhuQIJAAsMwGzsS3r9Ke8)** | 4 | Our output variable. 🚨 |
| **[PIR Motion Sensor](https://www.adafruit.com/product/159?srsltid=AfmBOoqQ8dGMa6cjChJbZBdz2py7uabAm7BrxtUhuQIJAAsMwGzsS3r9Ke8)** | 1 | For sensing and detecting motion. |
| **[220 ohm Resistor](https://www.adafruit.com/product/2780?srsltid=AfmBOopmkZkIUP5s_hycNqkQo98pfRENfjLETCFsG8mRPr04hxSWfXWS)** | 3 | Controls electrical curent to the LED. |
| **[Jumper Wires](https://www.adafruit.com/category/306?srsltid=AfmBOook5BsXkN5B8NOekLEvpqA6bxxpfq-iHHaRTnXBJzHQmaL5iwjg)** | 1 Bundle | For connecting all the components. |

  <p>
    <strong>Important Note:</strong>
 Always make sure you have all equipment before starting a project.
  </p>

<details>
  <summary>
     <h2> Step 1: PIR Motion Sensor </h2>
  </summary>
  <br>
  <p>
    Potentiometers are variable resistors that have a number of useful applications when building a curciut. Remember, a resistor controls the amount of electrical current a component is recieving-- potentiometers allow us to alter that input!
   
The potentiometer has 3 terminals-- the two outer terminals are fixed, while the middle terminal is variable.
 </p>

For this project, connect the potentiometer to the arduino and bread board as follows:

| <img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/Motion_Sensor+LEDs/assets/Motion_Sensor.jpeg" width="600"/> | <img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/Motion_Sensor+LEDs/assets/PIR Motion_bb.jpg" width="600"/> |
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
     <h2> Step 2: Powering LEDs + Parrellel Circuit </h2>
  </summary>
  <br>
  
  Next we want to actually show that value change created by the potentiometer by adding an LED that we can adjust the brightness of. Single color RGB leds only have two legs. Copy the set up shown below. 

 |<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/Tutorials/Potentiometer%2BRGB_LED/assets/led_example.png" width="600" /> | <img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/Tutorials/Potentiometer%2BRGB_LED/assets/led_example.png" width="600" />| <img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/Motion_Sensor+LEDs/assets/LEDs_bb.jpg" width="600"/> |
 |:---|:---:|:---|
  
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
     <h2> Step 3: Combining all components! </h2>
  </summary>
  <br>
 
  Okay, now let’s add the rest! Since we are trying to change a single bulb, we’ll need to use an RGB LED, this has 4 pins instead of 2, the long one is now ground, (make sure this is a common cathode bulb!) and the other 3 correlate to data for each color. Adding the potentiometers and LEDs for green and blue is our last hardware step. 

| <img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/Motion_Sensor+LEDs/assets/Motion_Sensor_LED_Board.jpg" width="600"/> | <img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/Motion_Sensor+LEDs/assets/PIR Motion + Leds.jpg" width="600"/> |
|:---|:---:|
  
As mentioned before, potentiometer readings are not always stable. To combat this further, we can add an averaging system. This is done by creating an integer that will read data from the potentiometer for a certain amount of time, and then divide the data by how long it was counting to receive an average. Now we have to replace where analogRead was in the last example with readAveragedAnalog so we are only using the averaged numbers when writing to the LED’s. Since we connected the RGB LED on the breadboard to where our regular LED’s are, we only need to write to one pin per color. All that’s left is to make green and blue versions of each command! 
  
  **Arduino Code:** <br /> 
  ```C++
 // Define pins
const int PIRPin = 2;
const int BlueLEDPin = 10;
const int YellowLEDPin = 11;
const int OrangeLEDPin = 12;
const int RedLEDPin = 13;

bool isMotionHandled = false;  // Flag to track if motion has already been handled

void setup() {
  Serial.begin(9600);
  pinMode(PIRPin, INPUT);
  pinMode(BlueLEDPin, OUTPUT);
  pinMode(YellowLEDPin, OUTPUT);
  pinMode(OrangeLEDPin, OUTPUT);
  pinMode(RedLEDPin, OUTPUT);
}

void loop() {
  int pirState = digitalRead(PIRPin);

  // motion triggered from no motion handling
  if (pirState == HIGH && !isMotionHandled) {
    Serial.println("motion FIRST triggered");
    // Trigger LEDs once per motion event
    isMotionHandled = true;

    Serial.println("Motion detected!");
    // LEDs loading up
    digitalWrite(BlueLEDPin, HIGH);
    delay(200);
    digitalWrite(YellowLEDPin, HIGH);
    delay(200);
    digitalWrite(OrangeLEDPin, HIGH);
    delay(200);
    digitalWrite(RedLEDPin, HIGH);
    delay(1000);
  } 
  
  if (pirState == LOW && isMotionHandled) {
    Serial.println("motion DONE triggerd");
    digitalWrite(RedLEDPin, LOW);
    delay(200);
    digitalWrite(OrangeLEDPin, LOW);
    delay(200);
    digitalWrite(YellowLEDPin, LOW);
    delay(200);
    digitalWrite(BlueLEDPin, LOW);
  }

  if (pirState == HIGH && isMotionHandled) {
    Serial.println("DETECTING MOTION");
  }

  // Reset the flag once PIR returns to LOW
  if (pirState == LOW) {
    Serial.println("NO MOTION");
    isMotionHandled = false;
  }

  delay(50); // Slight delay to avoid excessive polling
}
  ```
  <br/>
</details>
