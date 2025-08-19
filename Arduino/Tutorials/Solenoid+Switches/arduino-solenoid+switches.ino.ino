const int solenoid = 2;
const int tsolenoid = 3;
const int button = 4;
const int tbutton = 5;

void setup() {
  pinMode(solenoid, OUTPUT);
  pinMode(button, INPUT_PULLUP);// put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(tsolenoid, OUTPUT);
  pinMode(tbutton, INPUT_PULLUP);// put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(button);
  int tbuttonState = digitalRead(tbutton);
  Serial.println(buttonState);
  if (buttonState == HIGH) {
    digitalWrite(solenoid, LOW);
  } else {
    digitalWrite(solenoid, HIGH);
  }
  delay(20);
  // put your main code here, to run repeatedly:
  Serial.println(buttonState);
  if (tbuttonState == HIGH) {
    digitalWrite(tsolenoid, LOW); // solenoid on
  } else {
    digitalWrite(tsolenoid, HIGH); // solenoid off
  }
  delay(20);
}