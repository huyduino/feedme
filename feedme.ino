int led = 13;

void setup() {
  // init the digital pin as an output
  pinMode(led, OUTPUT);
  // init serial
  Serial.begin(9600);
  while (!Serial); // wait until Serial is ready
  Serial.println("Welcome, Huy");
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
  // if below 800, need water
  if (val < 800) {
    // output feed me
    Serial.println("I'M HUNGRY! FEED MEEEE!!! >\"<");
    // blink the led
    blink();
  } else {
    // make sure led is low
    digitalWrite(led, LOW);
    // output I'm good
    Serial.println("I'M GOOD!!! ( ^ __ ^ )");
    delay(1000);
  }
}

