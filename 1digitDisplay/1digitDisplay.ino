// Pin assignments
int segA = 2;
int segB = 3;
int segC = 4;
int segD = 5;
int segE = 6;
int segF = 7;
int segG = 8;
int segDP = 9; // optional

// Segment patterns for digits 0–9 (common cathode)
// Order: a b c d e f g
byte digits[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

int segPins[7] = {segA, segB, segC, segD, segE, segF, segG};

void setup() {
  for(int i=0; i<7; i++) {
    pinMode(segPins[i], OUTPUT);
  }
}

void loop() {
  for(int num=1; num<=9; num++) {
    showDigit(num);
    delay(1000); // wait 1 second
  }
}

void showDigit(int num) {
  for(int i=0; i<7; i++) {
    digitalWrite(segPins[i], digits[num][i] ? HIGH : LOW);
  }
}