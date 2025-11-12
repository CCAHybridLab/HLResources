# Ultrasonic Distance Sensor + OLED Display
| <img src="https://github.com/CCAHybridLab/HLResources/blob/bb51a844462a34f7b36e1c35edf2b8283f620cd7/Arduino/Tutorials/Ultrasonic_Sensor%2BOLED-Display/tutorial%20images/IMG_0359.jpeg" width="600"/> | <img src="https://github.com/CCAHybridLab/HLResources/blob/bfd2ba10d00b36ba7951d288e42c2c2b350f071e/Arduino/Tutorials/Ultrasonic_Sensor%2BOLED-Display/tutorial%20images/Ultrasonic%20Distance%20%2B%20OLED%20Display_bb.jpg" width="600"/> |
|:---|:---:|



 ## ⚙️ Equipment & Components

<p>
  This project uses an ultrasonic d.
</p>

| Component | Quantity | Notes |
|:---|:---:|:---|
| **[Arduino Uno](https://airtable.com/appCpmcjYA1vwj8jn/tblOHGyZIGOZuJhCj/viwcQ6Lj5fpoG6Hvh/recQ1P43HKyVMjA79?blocks=hide)** | 1 | The brain of our project. |
| **[Breadboard](https://airtable.com/appCpmcjYA1vwj8jn/tblZz5NUA546g9J6o/viwu3SMJU1AEGhMGK/recF514LASWf2n9LH?blocks=hide)** | 1 | For building the circuit. |
| **[Ultrasonic Distance Sensor 5V](https://www.sparkfun.com/products/13959)** | 1 | For sensing and detecting distance. |
| **[OLED Display](https://www.amazon.com/DIYmall-Serial-128x64-Display-Arduino/dp/B00O2KDQBE)** | 1 | Our output display. |
| **[Jumper Wires](https://www.adafruit.com/category/306?srsltid=AfmBOook5BsXkN5B8NOekLEvpqA6bxxpfq-iHHaRTnXBJzHQmaL5iwjg)** | 1 Bundle | For connecting all the components. |

  <p>
    <strong>Important Note:</strong>
 Always make sure you have all equipment before starting a project.
  </p>

<details>
  <summary>
     <h2> Step 1: Ultrasonic Distance Sensor </h2>
  </summary>
  <br>
  <p>
   This sensor uses ultrasonic waves to detect distance. There are two transducers on the sensor: one transmits sound waves outward, and one detects the returning sound waves once they bounce off of an object. When the reciever detects these retruning waves, it produces a output signal which it then sends to your Arduino-- we can write a code that allows us to read these distances in real time!
 </p>

For this project, connect the motion sensor to the arduino and bread board as follows:

| <img src="https://github.com/CCAHybridLab/HLResources/blob/181289ec43455e864a690efa55493ebef9532c9c/Arduino/Tutorials/Ultrasonic_Sensor%2BOLED-Display/tutorial%20images/177109536.webp" width="600"/> | <img src="https://github.com/CCAHybridLab/HLResources/blob/11662159ac278d2a206332ef090c7668a1254620/Arduino/Tutorials/Ultrasonic_Sensor%2BOLED-Display/tutorial%20images/Ultrasonic%20Distance%20%2B%20OLED%20Display_bb.png" width="600"/> |
|:---|:---:|


  <p>
   To make the coding process easier, we can utilize a library that has simplified the complex operations needed to utilize this sensor. To install the NewPing Library:
   
   1. First open your Arduino IDE program. Then click on the Library Manager icon on the left sidebar.
   2. Type “newping” in the search box to filter your results.
   3. Look for the newping library created by Tim Eckel.
   4. Click the Install button to add it to your Arduino IDE.
   
   When we connect the distance sensor to the Arduino, we can read it's output values with the following program:
   
  </p>
  
**Arduino Code:** <br />
```C++
#include "NewPing.h"

#define TRIGGER_PIN 9
#define ECHO_PIN 10

#define MAX_DISTANCE 400

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Distance = ");
  Serial.print(sonar.ping_cm());
  Serial.println(" cm");
  delay(500);
}
```

<p>
Run the code above and check the serial monitor. Place your hand in front of your sensor-- did the output change? Try moving your hand a bit farther or closer. If your distance reading gets higer or lower accordingly, congrats, you did it! Move on to step 2. 
</p>

</details>

<details>
 
  <summary>
     <h2> Step 2: OLED Display </h2>
  </summary>
  <br>
Next, we’ll create a simple circuit to evenly distribute power to the LEDs and make them light up. To do this, follow the wiring diagram below.
LEDs need three key connections: power, ground, and a resistor (typically 220 Ω for warm colors and 100 Ω for cool colors). Each LED has two legs, the longer leg is the positive (anode) side and the shorter leg is the negative (cathode) side.
<br> </br> 
Resistors are an important part of the circuit as they limit the amount of current flowing to each LED. Without a resistor, too much current could pass through, which can burn out or damage the LED bulb. The resistor helps make sure each LED receives just the right amount of power to glow safely and evenly.
<br> </br>
When connected to a microcontroller (like an Arduino), the LEDs get their power through digital output pins. Each pin can switch between HIGH (on) and LOW (off), sending small bursts of electrical current that make the LEDs light up. This digital control is what allows you to turn LEDs on and off in patterns using code.
<br> </br>
  
 |<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/Tutorials/Potentiometer%2BRGB_LED/assets/led_example.png" width="600" /> | <img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/Tutorials/Potentiometer%2BRGB_LED/assets/led_example.png" width="600" />| <img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/Motion_Sensor+LEDs/assets/LEDs_bb.jpg" width="600"/> |
 |:---|:---:|:---|

Once the LEDs are wired correctly, we can use the code to control how and when they light up. In this tutorial, each LED will turn on one after another in sequence but that’s just one example. You can program them in many creative ways! Try having them all light up at once, skip every other LED, or turn on two or three at a time. The possibilities are endless so experiment and make it your own!
  
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

<details>
  <summary>
     <h2> Step 4 (Optional): 3D Printing Case for Motion Sensor </h2>
  </summary>
To help secure the Peltier module and keep it from shifting around, we’ve included a custom 3D-printed case design. You can find the print file in the “3D Assets” folder of this tutorial. As a bonus, the file is already set up for easy printing on a Bambu printer, but you can adapt it for other 3D printers as well.
<br> </br>
<img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/Motion_Sensor+LEDs/assets/3D_model.jpg" width="500"/>
</details>
