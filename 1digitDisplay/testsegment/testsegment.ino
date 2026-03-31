int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
int dp = 9;

void setup() {
  int pins[] = {a,b,c,d,e,f,g,dp};
  for(int i=0; i<8; i++) {
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], LOW); // all OFF initially
  }

}

void loop() {
  int pins[] = {a,b,c,d,e,f,g,dp};
 for(int i=0; i<8; i++) {
    digitalWrite(pins[i], HIGH);
    delay(1000);
    digitalWrite(pins[i], LOW);
  }
}
