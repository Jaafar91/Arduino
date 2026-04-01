int buzzer = 8; // KY-006 signal pin

void setup() {
  // Play tones for digits 1 to 9
  for(int i=1; i<=9; i++) {
    int freq = 200 * i; // frequency increases with digit
    tone(buzzer, freq, 500); // play for 500 ms
    delay(700); // wait before next tone
  }
}

void loop() {
  // nothing here
}
