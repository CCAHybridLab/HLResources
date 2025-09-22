# WELCOME to the WORKSHOP!!

## Section 1 - Setting up the Arduino IDE
### 0.1 Install Arduino Software
Arduino software (IDE) runs on Windows, Mac OSX, and Linux. Please download and install the (free) [Arduino software here](http://arduino.cc/en/Main/Software).
   - MAC: Intel or Silicon chip? Check by clicking  >About this Mac > The first line "Chip" Should say either "Intel" or "Apple" (Silicon). Intel chips are typically Macs older than 2021.
   - You'll be prompted to DONATE. Do as you wish but below everything will be the "Just Download" for free button.

Please bring your laptop, with the software installed, to the workshop. **Laptops with the Arduino IDE installed will be provided for those without one**

Additional instructions [on M5Stack's Arduino instructions here](https://docs.m5stack.com/en/arduino/arduino_ide) and [Adafruit's Arduino lessons here](https://learn.adafruit.com/ladyadas-learn-arduino-lesson-number-0/download-software)

### Introducing the Arduino:
- Place on your left hand
<img src="https://github.com/romyaboudarham/M5StickCPlus2-Workshop/blob/main/media/m5stick_powerBtn.png" style="width: 500px; height: auto;">

#### Features
- high level technical features

### 1.1 First steps: Verifying correct installation

**1.1.1** Connect M5Stick via USB cable &nbsp;&nbsp;&nbsp;&nbsp;
   - Windows? Might see “New Hardware Discovered” and later might see “New Hardware Ready for Use”.
   - Mac OS X? Might see “New Network Interface Found”. Click “Network Preferences…”,  click “Apply”, and when it finishes, click “Close”. It doesn’t matter if the configuration fails.
   - Linux? Nothing to do here

**1.1.2** Open Arduino software (IDE) &nbsp;&nbsp;&nbsp;&nbsp;

**1.1.3** Select _Tools > Board > M5Stack > M5StickCPlus2_ (If you don't see "M5StickCPlus2" you may not have correctly installed the board manager URL in the previous step) &nbsp;&nbsp;&nbsp;&nbsp;

**1.1.4** Select _Tools  >  Port_ &nbsp;&nbsp;&nbsp;&nbsp;
   - Windows? Chose the largest COM number
     - No COMs? Raise your hand for help
   - Mac OS X? Chose either usbserial - you should also see _(LilyGo T-Display)_
     - No usbserial? Raise your hand for help
   - Linux? There is only one choice

**1.1.5** Should look something like this &nbsp;&nbsp;&nbsp;&nbsp;

   <img src="https://github.com/romyaboudarham/M5StickCPlus2-Workshop/blob/main/media/successful-install.png" style="width: 700px; height: auto;">

*******************************************************************************
### 1.2 Is this thing on?
**1.2.1**  Copy the code below and paste it into a new, **EMPTY** Arduino sketch _OR_ download and open this example sketch: [HelloWorld.ino](/examples/01_HelloWorld/HelloWorld/HelloWorld.ino) &nbsp;&nbsp;&nbsp;&nbsp;

```cpp
#include <M5StickCPlus2.h> // this 'include' line includes the M5StickCPlus2 library
                           // this allows us to use functions written for this specific device

// and "int" is an "integer" which is a WHOLE number (not a fraction) i.e. 1, 6, 17, 394
int screenWidth = 0;  // this variable is used to set the screen width
int screenHeight = 0; // this variable is used to set the screen height

void setup() {
  // initiatlize the device using the M5StickCPlus2 library
  auto cfg = M5.config();
  StickCP2.begin(cfg);

  StickCP2.Display.setRotation(1); // this function sets the rotation of the display
  								           // 0: portrait, 1: landscape, 2: portrait-flipped, 3: landscape-flipped
  screenWidth = StickCP2.Display.width(); // 240
  screenHeight = StickCP2.Display.height(); // 135

  // text reference point options: https://github.com/lovyan03/LovyanGFX/blob/55a0f66d9278faa596c8d51a8e8a3e537dd8f44f/src/lgfx/v1/misc/enum.hpp#L135
  StickCP2.Display.setTextDatum(top_left);
}

void loop() {
  StickCP2.update();

  /*** CUSTOMIZE BEGIN ***/
  // font options: https://github.com/lovyan03/LovyanGFX/blob/55a0f66d9278faa596c8d51a8e8a3e537dd8f44f/src/lgfx/v1/lgfx_fonts.hpp#L329
  StickCP2.Display.setTextFont(&fonts::Orbitron_Light_24); // 24 pixels high
  // color options: https://github.com/m5stack/M5GFX/blob/b1a0e54e79a1c50d1d0d628524bbde7275423b5f/src/M5GFX.h#L143
  StickCP2.Display.setTextColor(GREEN);
  StickCP2.Display.setTextSize(1); // try 2!
  StickCP2.Display.drawString("Hello World!", 0, 0); // 0,0 = x,y
  // no text wrapping, so print another string lower on the screen with y = 30
  /*** CUSTOMIZE END ***/
}
```
**1.2.2a** "Compile" the code to the device by clicking the **checkmark** in the top left corner &nbsp;&nbsp;&nbsp;&nbsp;
   - Compile = translate this code (C++) into machine-readable language
   - Use compile when manipulating code to make sure you haven't caused errors as you're working

**1.2.2b** "Upload" the code to the device by clicking the **right arrow** in the top left corner &nbsp;&nbsp;&nbsp;&nbsp;
- Upload = sending the code to the device, where the code is now stored on the device, so when you disconnect it form your computer the code still lives on the device.
- use upload when you are ready to upload. It will automagically compile first (becasue uploading code with syntax errors would be silly)!

<img src="https://github.com/romyaboudarham/M5StickCPlus2-Workshop/blob/main/media/arduinoIDE-Buttons.png" style="width: 720px; height: auto;">  
(don't worry about "Serial" for this workshop)

#### How is this working??
- The [setup()](https://www.arduino.cc/reference/en/language/structure/sketch/setup/) function is called when a sketch starts.
  - Use it to initialize variables, pin modes, start using libraries, etc. In our case, this is where we set up the screen display features (text color, font, orientation, default text etc.) 
  - The setup() function will only run once, after each power-up or reset of the Arduino board.
- The [loop()](https://www.arduino.cc/reference/en/language/structure/sketch/loop/) the loop() function does precisely what its name suggests, and _loops_ consecutively through your list of instructions to control the Arduino.
  - The loop() functions runs continuously as long as the Arduino is powered on.
  - Each instruction is executed in order from top to bottom.
  - Arduino only executes one instruction at a time.
 
Success!
   
<img src="https://github.com/romyaboudarham/M5StickCPlus2-Workshop/blob/main/media/HelloWorldM5Stick.jpeg" style="width: 500px; height: auto;"> 
 
#### YOUR TURN
- Change the code to display "Hello YOUR-NAME" on the watch and in the Serial Monitor
- Change the color, font, size, placement of the text
- CHALLENGE: center the text (hint: will need to use screenWidth and screenHeight from lines 16 and 17)

### Save your project & open a NEW sketch
- File > Save
- File > New Sketch
  
<img src="https://github.com/romyaboudarham/M5StickCPlus2-Workshop/blob/main/media/how-to-save.png" style="width: 600px; height: auto;"> 

*******************************************************************************

## Section 2 - Breadboard
## Section 3 - Power + Ground
- connect power and ground to the breadboard
- explain the "bus"
## Section 4 - LED 
- pos / neg
- connect to breadboard
## Section 5 - Resistor
## Section 6 - copy and paste

Things to know
- Digital vs analog
