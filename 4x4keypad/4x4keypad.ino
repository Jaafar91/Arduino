#include <Keypad.h>

const byte ROWS = 4; // four rows
const byte COLS = 4; // four columns

// Define the keymap
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Connect keypad ROW0–ROW3 to Arduino pins 9,8,7,6
byte rowPins[ROWS] = {9, 8, 7, 6};
// Connect keypad COL0–COL3 to Arduino pins 5,4,3,2
byte colPins[COLS] = {5, 4, 3, 2};

// Create keypad object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    Serial.print("Key pressed: ");
    Serial.println(key);
  }
}