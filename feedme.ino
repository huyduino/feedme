//#define DEBUG_FLAG;

int led = 13;

void setup() {
  // init the digital pin as an output
  pinMode(led, OUTPUT);
#ifdef DEBUG_FLAG
  // init serial
  Serial.begin(9600);
  while (!Serial); // wait until Serial is ready
  Serial.println("Welcome, Huy");
#endif
}

void blink() {
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
}

void loop() {
  // get moisture value
  int val = analogRead(A1);
#ifdef DEBUG_FLAG;
  Serial.print("moisture value: ");
  Serial.println(val);
#endif
  // if below 800, need water
  if (val < 800) {
#ifdef DEBUG_FLAG
    // output feed me
    Serial.println("I'M HUNGRY! FEED MEEEE!!! >\"<");
#endif
    // blink the led
    blink();
  } else {
#ifdef DEBUG_FLAG
    // output I'm good
    Serial.println("I'M GOOD!!! ( ^ __ ^ )");
#endif
    delay(1000);
  }
}

