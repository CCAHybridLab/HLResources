# <b> Neopixel Matrix + Joystick — Interactive Game </b> 
| <img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/Neopixel_Matrix%2BJoystick/media/Real%20Scene.jpg?raw=true" width="600"/> | <img src="https://github.com/CCAHybridLab/HLResources/blob/main/Arduino/Neopixel_Matrix%2BJoystick/media/Neopixel%20matrix%2Bjoystick.png?raw=true" width="600"/> |
|:---|:---:|

## ⚙️ Equipment & Components
<p>
  This project uses a joystick to control patterns on a NeoPixel LED matrix.
</p>

| Component | Quantity | Notes |
|:---|:---:|:---|
| **[Arduino Uno R3](https://airtable.com/appCpmcjYA1vwj8jn/shrkKEse5QyVzAMIc/tblOHGyZIGOZuJhCj/viwcQ6Lj5fpoG6Hvh/recQ1P43HKyVMjA79)** | 1 | The brain of our project. |
| **[Breadboard](https://airtable.com/appCpmcjYA1vwj8jn/tblZz5NUA546g9J6o/viwu3SMJU1AEGhMGK/recF514LASWf2n9LH?blocks=hide)** | 1 | For building the circuit. |
| **[Neopixel Matrix](https://airtable.com/appCpmcjYA1vwj8jn/shrkKEse5QyVzAMIc/tbl5EZ1pGlx6I9Mqy/viwj7SvoKaP2xgi9w/recjzIjnE0GcErlis)** | 1 | Our output will be displayed here. |
| **[Joystick](https://airtable.com/appCpmcjYA1vwj8jn/shrkKEse5QyVzAMIc/tbldSw9ZFUadEDJm4/viwrlpDYJJs9tKf52/recZUrb1Xb0vNxLGp)** | 1 | The joystick can controls the colors, brightness, or motion patterns displayed on the NeoPixel matrix. |

<p>
    Don't have the parts? Build and test digitally on [Wokwi](https://wokwi.com/)
</p>

## Step 1: Joystick
The thumbstick is an **analog joystick**, offering smoother and more precise control than simple directional ones. It measures movement on **two axes** — X and Y — using **analog signals** (read through two analog pins), and includes a **press-in button** (connected to a digital pin) for extra input.



<!-- last sentence above mentions a press-in button, we have the capability but in our model nothing happens with it -->



<img src="https://github.com/CCAHybridLab/HLResources/blob/main/assets/Joystick.jpeg" width="500"/>

#### Move on to Step 2 once your model looks like above. 

## Step 2: Neopixel Matrix
Put on your sunglasses before wiring up this LED matrix - 64 eye-blistering RGB LEDs adorn the NeoMatrix for a blast of configurable color. Arranged in an 8x8 matrix, each pixel is individually addressable. Only one microcontroller pin is required to control all the LEDs, and you get 24 bit color for each LED.

### How does the Neopixel Matrix work?
Wiring the panel is straightforward. It has two 3-pin ports — one for input (where data and power enter) and one for output (for chaining another panel).
Solder wires to the input port: connect +5V to your 5-volt power source, GND to ground, and DIN (data in) to your microcontroller’s data pin (usually pin 6 if you’re using the NeoPixel Arduino library). Because the microcontroller and the LED panel share signals, they must also share a common ground — meaning the ground wire of the power supply and the ground pin of the Arduino must be connected together.

Each LED can draw up to 60 mA when fully lit in white, so a 64-pixel panel could use up to 3.5 A at maximum brightness. In most cases, average use draws 1–2 A, so a 5 V 2 A power supply is usually sufficient.

<img src="https://github.com/CCAHybridLab/HLResources/blob/main/assets/Matrix_Off.jpg" width="550"/>

#### Move on to Step 3 once you're seeing accurate distance data on serial monitor


<!-- I'm confused what doesn the above sentence mean? what do you see and where -->



## Step 3: Adding interactive code to create a game!
A distance measuring sensor which has a range from 2cm to 400cm (about an inch to 13 feet). Best used for accurately measuring the distance to an object within a specific range, particularly when you want to detect the presence or proximity of an object without direct contact, making it useful for applications like obstacle avoidance, line following, automated door opening, or level detection in a robot or device. 

<img src="https://github.com/CCAHybridLab/HLResources/blob/main/assets/Joystick_Game.jpg" width="550"/>



<!-- I'm very confused why is there a distance sensor here?? and the image link is void -->



**Arduino Code:** <br /> 
```C++
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define PIN 6  // NeoPixel data pin

// Initialize an 8x8 NeoMatrix
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(
    8, 8, PIN,
    NEO_MATRIX_TOP + NEO_MATRIX_LEFT +
    NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
    NEO_GRB + NEO_KHZ800);

#define JOYSTICK_X A0  // Joystick X-axis
#define JOYSTICK_Y A1  // Joystick Y-axis
#define BUTTON 2       // Joystick button (optional)

int snakeX, prevX = 0;  // Initial square position
int snakeY, prevY = 0;
int foodX = 3;
int foodY = 3;


void setup() {
    Serial.begin(9600);
    matrix.begin();
    matrix.setBrightness(40);
    matrix.show(); // Clear the matrix

    pinMode(JOYSTICK_X, INPUT);
    pinMode(JOYSTICK_Y, INPUT);
    pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
    int xValue = analogRead(JOYSTICK_X);
    int yValue = analogRead(JOYSTICK_Y);
    Serial.print(" X: ");
    Serial.println(xValue);
    Serial.print("Y: ");
    Serial.println(yValue);
  
    checkFoodCollision();
    // Map joystick values (adjust sensitivity if needed) & Movement Direction + Bound check
    mapJoystick(xValue, yValue);
    movePixel(snakeX, snakeY, matrix.Color(0, 200, 160)); // Red square
    delay(150); // Adjust speed of movement
}

void checkFoodCollision() {
  if (snakeX == foodX & snakeY == foodY) { // collision
    foodX = random(0, 8); // generate a random number between 0 and 8
    foodY = random(0, 8); // generate a random number between 0 and 8
  }

  matrix.drawPixel(foodX, foodY, matrix.Color(255, 0, 0));
}

// Function to draw snake in new position and erase the previous position
void movePixel(int newX, int newY, uint16_t color) {
    // Turn off the previous pixel
    matrix.drawPixel(prevX, prevY, matrix.Color(0, 0, 0)); // Black (off)
    
    // Draw the new pixel
    matrix.drawPixel(newX, newY, color);

    // Update matrix display
    matrix.show();

    // Update previous position
    prevX = newX;
    prevY = newY;
}

// Map joystick values (adjust sensitivity if needed) & Movement Direction + Bound check
void mapJoystick(int xValue, int yValue) {
  if (xValue < 400) { // move left
      snakeX = snakeX - 1; // snake--
      if (snakeX < 0) { // out of bounds
        snakeX = snakeX + 8;
      }
    }
    if (xValue > 600) { // move right
    snakeX = snakeX +1; // snake++
      if (snakeX > 7) { //out of bounds
        snakeX = 0;
      }   
    }
    if (yValue < 400) { //move up
      snakeY = snakeY + 1; //snake ++
      if (snakeY > 7) { //out of bounds
        snakeY = 0;
      }
    }
    if (yValue > 600) { //move down
      snakeY = snakeY - 1; //snake --
      if (snakeY < 0) { //out of bounds
        snakeY = snakeY + 8;
      }
    }
}
```

#### Move on to Step 4 to play the game!
## Step 4:  Playing the Game!
Use the joystick to control and move around the single LED pixel. Once the red LED is on the same pixel square as the Cyan LED, it will randomly generate in a different spot, creating an interactive game where partcipants are able to try to capture the Cyan LED!

While this is just one game you can program with the Neopixel matrix, the possiblities are endless! Other examples that people have done are Snake, Connect Four and more!

|<img src="https://github.com/CCAHybridLab/HLResources/blob/main/assets/Peltier_Thermo_Electric.jpeg" width="500"/>
<br/>
