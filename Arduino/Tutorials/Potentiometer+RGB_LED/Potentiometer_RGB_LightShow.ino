//Constants:
  const int rLedPin = 9;
  const int gLedPin = 6;
  const int bLedPin = 3;

  const int rPotPin = A0;
  const int gPotPin = A2;
  const int bPotPin = A4;

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(rLedPin, OUTPUT);
  pinMode(gLedPin, OUTPUT);
  pinMode(bLedPin, OUTPUT);

  pinMode(rPotPin, INPUT);
  pinMode(gPotPin, INPUT);
  pinMode(bPotPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  updateRed();
  updateGreen();
  updateBlue();

  delay(200);
}

void updateRed() {
  int valueRedPot = analogRead(rPotPin);
  int valueRed = map(valueRedPot, 100, 950, 0, 255);

  // Serial.print("RedPot: ");
  // Serial.println(valueRedPot);
  // Serial.print("RedLEDVal: ");
  // Serial.println(valueRed);
  // Serial.println("----------");

  if (valueRedPot <= 100) {
    valueRed = 0;
  }

  analogWrite(rLedPin, valueRed);
  delay(100);
}

void updateGreen() {
  int valueGreenPot = analogRead(gPotPin);
  int valueGreen = map(valueGreenPot, 100, 950, 0, 255);

  if (valueGreenPot <= 100) {
    valueGreen = 0;
  }

  analogWrite(gLedPin, valueGreen);
  delay(100);
}

void updateBlue() {
  int valueBluePot = analogRead(bPotPin);
  int valueBlue = map(valueBluePot, 100, 950, 0, 255);

  Serial.print("BluePot: ");
  Serial.println(valueBluePot);
  Serial.print("BlueLEDVal: ");
  Serial.println(valueBlue);
  Serial.println("----------");

  if (valueBluePot <= 100) {
    valueBlue = 0;
  }
  analogWrite(bLedPin, valueBlue);
  delay(100);
}
