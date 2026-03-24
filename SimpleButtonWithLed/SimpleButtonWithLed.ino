const int buttonPin = 4;
const int ledPin = 7;

bool ledState = false;
bool lastButtonState = HIGH; // INPUT_PULLUP means HIGH when not pressed

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // button to GND
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);        // LED off initially
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  // Detect press (HIGH -> LOW transition)
  if (lastButtonState == HIGH && buttonState == LOW) {
    ledState = !ledState; // toggle LED
    digitalWrite(ledPin, ledState ? HIGH : LOW);
    delay(50); // debounce
  }

  lastButtonState = buttonState;
}
