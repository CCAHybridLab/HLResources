/*********
  CCA Hybrid Lab HC-SR04 + OLED SSD1306 Display Demo
  by Romy Aboudarham
*********/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Distance Sensor
const int trigPin = 6;
const int echoPin = 5;
long duration;
int distanceInch;
int distanceCm;

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);

  // Distance sensor setup
  pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);

  // OLED setup
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
}

void loop() {
  // Distance Sensor Data
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	duration = pulseIn(echoPin, HIGH);
	distanceInch = duration * 0.0133 / 2;
  distanceCm = duration * 0.034 / 2;

  // Print distance to display
  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 0); // start of yellow section
  display.println("Distance:");

  display.setTextSize(3);
  display.setCursor(0, 16); // start of blue section
  display.print(distanceCm);
  display.print(" cm");
  delay(10);
  display.setCursor(0, 40);
  display.print(distanceInch);
  display.print(" inch");
  delay(10);

  display.display();
}