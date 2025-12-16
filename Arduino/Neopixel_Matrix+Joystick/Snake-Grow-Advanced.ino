#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#define PIN 3  // NeoPixel data pin

const int WIDTH = 8;
const int HEIGHT = 8;

// Initialize an 8x8 NeoMatrix
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(
    WIDTH, HEIGHT, PIN,
    NEO_MATRIX_TOP + NEO_MATRIX_LEFT +
    NEO_MATRIX_ROWS + NEO_MATRIX_ZIGZAG,
    NEO_GRB + NEO_KHZ800);

#define JOYSTICK_X A0  // Joystick X-axis
#define JOYSTICK_Y A1  // Joystick Y-axis
#define JOYSTICK_BTN_PIN 2       // Joystick button (optional)

bool matrixState[WIDTH][HEIGHT];   // store last color written
bool isDanceParty = false;

int snakeSize = 1; // 1x1
int snakeX, prevX = 0;  // Initial square position
int snakeY, prevY = 0;
int foodX = 3;
int foodY = 3;
uint16_t snakeColor = matrix.Color(0, 200, 160); // starting color

void setup() {
    Serial.begin(9600);
    matrix.begin();
    matrix.setBrightness(40);
    matrix.show(); // Clear the matrix

    pinMode(JOYSTICK_X, INPUT);
    pinMode(JOYSTICK_Y, INPUT);
    pinMode(JOYSTICK_BTN_PIN, INPUT_PULLUP);
}

void loop() {
    int xValue = analogRead(JOYSTICK_X);
    int yValue = analogRead(JOYSTICK_Y);
    int btnValue = digitalRead(JOYSTICK_BTN_PIN);
    Serial.print(" X: ");
    Serial.println(xValue);
    Serial.print("Y: ");
    Serial.println(yValue);
    Serial.print("BTN: ");
    Serial.println(btnValue);

    if (btnValue == 0) {
      int randRed = random(0, 255);
      int randGreen = random(0, 255);
      int randBlue = random(0, 255);
      snakeColor = matrix.Color(randRed, randGreen, randBlue); // random(min, max)
    } 
  
    checkFoodCollision();
    // Map joystick values (adjust sensitivity if needed) & Movement Direction + Bound check
    mapJoystick(xValue, yValue);
    movePixel(snakeColor); // Red square
    if (snakeSize >= WIDTH) {
      checkMatrixAllOn();
    }
    if (isDanceParty) {
      delay(200);
      danceParty();
      resetGame();
    }
    delay(150); // Adjust speed of movement
}

void checkFoodCollision() {
  for (int i = 0; i < snakeSize; i++) {
    for (int j = 0; j < snakeSize; j++) {
      if (snakeX+i == foodX && snakeY+j == foodY) { // collision
        respawnFood();
        snakeSize++;
        break;
      }
    }
  }

  matrix.drawPixel(foodX, foodY, matrix.Color(255, 0, 0));
}

void respawnFood() {
  bool validFood = false;
  while (!validFood) {
      foodX = random(0, WIDTH);
      foodY = random(0, HEIGHT);
      validFood = true;

      for (int i = 0; i < snakeSize; i++) {
          for (int j = 0; j < snakeSize; j++) {
              int px = snakeX + i;
              int py = snakeY + j;
              if (!isOutBounds(px, py) && px == foodX && py == foodY) {
                  validFood = false;
              }
          }
      }
  }
}

bool isOutBounds(int x, int y) {
  return (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT);
}

void checkMatrixAllOn() {
  isDanceParty = true; // assume dance party
  for (int x = 0; x < WIDTH; x++) {
    for (int y = 0; y < HEIGHT; y++) {
      if (!matrixState[x][y]) { // any off pixel
        isDanceParty = false;
        return;
      }
    }
  }
}

// Function to draw snake in new position and erase the previous position
void movePixel(uint16_t color) {

    // Turn off the previous pixel
    for (int i = 0; i < snakeSize; i++) {
      for (int j = 0; j < snakeSize; j++) {
        matrix.drawPixel(prevX+i, prevY+j, matrix.Color(0, 0, 0)); // Black (off)
        int px = prevX + i;
        int py = prevY + j;
        if (!isOutBounds(px, py))
            matrixState[px][py] = 0;
      }
    }
    
    // Draw the new pixel
    for (int i = 0; i < snakeSize; i++) {
      for (int j = 0; j < snakeSize; j++) {
        matrix.drawPixel(snakeX+i, snakeY+j, color);
        int px = snakeX + i;
        int py = snakeY + j;
        if (!isOutBounds(px, py))
            matrixState[px][py] = 1;
      }
    }

    // Update matrix display
    matrix.show();

    // Update previous position
    prevX = snakeX;
    prevY = snakeY;
}

// Map joystick values (adjust sensitivity if needed) & Movement Direction + Bound check
void mapJoystick(int xValue, int yValue) {
  if (xValue < 400) { // move left
    snakeX = snakeX - 1; // snake--
    if (snakeX < 0) { // out of bounds
      snakeX = snakeX + WIDTH;
    }
  } else if (xValue > 600) { // move right
  snakeX = snakeX +1; // snake++
    if (snakeX >= WIDTH ) { //out of bounds
      snakeX = 0;
    }   
  } else if (yValue < 400) { //move up
    snakeY = snakeY + 1; //snake ++
    if (snakeY >= HEIGHT) { //out of bounds
      snakeY = 0;
    }
  } else if (yValue > 600) { //move down
    snakeY = snakeY - 1; //snake --
    if (snakeY < 0) { //out of bounds
      snakeY = snakeY + HEIGHT;
    }
  }
}

void danceParty() {
  static uint16_t hue = 0; // rainbow hue
  unsigned long startTime = millis(); // record start time

  while (millis() - startTime < 3000) { // run for 5 seconds
    for (int x = 0; x < WIDTH; x++) {
      for (int y = 0; y < HEIGHT; y++) {
        matrix.drawPixel(x, y, matrix.ColorHSV(hue + (x*65536/WIDTH), 255, 255));
      }
    }
    matrix.show();
    hue += 3000; // advance rainbow
    if (hue >= 65536) hue = 0;
    delay(50); // controls animation speed
  }

  // After 5 seconds, clear the matrix
  for (int x = 0; x < WIDTH; x++) {
    for (int y = 0; y < HEIGHT; y++) {
      matrix.drawPixel(x, y, matrix.Color(0, 0, 0));
      matrixState[x][y] = false; // reset state array
    }
  }
  matrix.show();

  isDanceParty = false; // stop dance party
}

void resetGame() {
    // Clear the matrix and the state array
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            matrix.drawPixel(x, y, matrix.Color(0, 0, 0)); // turn off pixel
            matrixState[x][y] = false;
        }
    }
    matrix.show();

    // Reset snake
    snakeSize = 1;
    snakeX = 0;
    snakeY = 0;
    prevX = 0;
    prevY = 0;
    snakeColor = matrix.Color(0, 200, 160); // starting color

    // Reset food
    foodX = 3;
    foodY = 3;
    matrix.drawPixel(foodX, foodY, matrix.Color(255, 0, 0));

    // Reset dance party flag
    isDanceParty = false;
}
