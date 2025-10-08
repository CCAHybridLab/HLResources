//Constants:
  const int rLedPin = 9;
  const int gLedPin = 6;
  const int bLedPin = 3;

  const int rPotPin = A0;
  const int gPotPin = A2;
  const int bPotPin = A4;

//Variables:
  int valueRed;
  int valueGreen;
  int valueBlue;

void setup() {
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
  valueRed = analogRead(rPotPin);
  valueRed = map(valueRed, 0, 1023, 0, 255);
  analogWrite(rLedPin, valueRed);
  delay(50);
  valueGreen = analogRead(gPotPin);
  valueGreen = map(valueGreen, 0, 1023, 0, 255);
  analogWrite(gLedPin, valueGreen);
  delay(50);
  valueBlue = analogRead(bPotPin);
  valueBlue = map(valueBlue, 0, 1023, 0, 255);
  analogWrite(bLedPin, valueBlue);
  delay(50);
}
