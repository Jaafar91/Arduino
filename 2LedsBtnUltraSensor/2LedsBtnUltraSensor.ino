const int buttonPin = 4;
const int led1Pin = 8;   // LED controlled by button
const int led2Pin = 7;   // LED controlled by distance
const int trigPin = 5;   // Ultrasonic trigger
const int echoPin = 6;   // Ultrasonic echo

bool led1State = false;
bool lastButtonState = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // --- Button toggle logic ---
  bool buttonState = digitalRead(buttonPin);
  if (lastButtonState == HIGH && buttonState == LOW) {
    led1State = !led1State;
    digitalWrite(led1Pin, led1State ? HIGH : LOW);
    delay(50); // debounce
  }
  lastButtonState = buttonState;

  // --- Distance measurement only if LED1 is ON ---
  if (led1State) {
    long duration, distance;

    // Trigger ultrasonic pulse
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read echo
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2; // convert to cm

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Control LED2 based on distance
    if (distance >= 10 && distance <= 20) {
      digitalWrite(led2Pin, HIGH);
      digitalWrite(led1Pin, LOW);
    } else {
      digitalWrite(led2Pin, LOW);
      digitalWrite(led1Pin, HIGH);
    }
  } else {
    digitalWrite(led2Pin, LOW); // ensure LED2 is off if LED1 is off
  }
}