const int knockPin = 3;   // KY-031 signal pin
const int ledPin = 13;    // onboard LED

void setup() {
  pinMode(knockPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  digitalWrite(ledPin, HIGH); 
  delay(500);
  digitalWrite(ledPin, LOW);
}

void loop() {
  int knockState = digitalRead(knockPin);

  if (knockState == HIGH) {
    digitalWrite(ledPin, HIGH);   // LED ON when knock detected
    Serial.println("Knock detected!");
    delay(200);                   // debounce delay
  } else {
    digitalWrite(ledPin, LOW);    // LED OFF otherwise
  }
}