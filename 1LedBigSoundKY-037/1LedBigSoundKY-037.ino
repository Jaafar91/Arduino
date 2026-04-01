int soundPin = 2; // KY-037 D0 connected to Arduino pin 2
int ledPin = 13;  // onboard LED
int analogPin = A0;

void setup() {
  pinMode(soundPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  int soundState = digitalRead(soundPin);
  int soundLevel = analogRead(analogPin);
  Serial.println(soundLevel);
  delay(100);
  if (soundLevel > 14) {
    digitalWrite(ledPin, HIGH); // LED ON when loud sound detected
  } else {
    digitalWrite(ledPin, LOW);  // LED OFF otherwise
  }
}

