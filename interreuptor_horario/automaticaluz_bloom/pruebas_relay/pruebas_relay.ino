int RelayPin1 = 2;
int RelayPin2 = 6;
int RelayPin4 = 7;

void setup() {
  // Set RelayPin as an output pin
  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  pinMode(RelayPin4, OUTPUT);
}

void loop() {
  // Let's turn on the relay...
  digitalWrite(RelayPin1, LOW);
  digitalWrite(RelayPin2, LOW);
  digitalWrite(RelayPin4, LOW);
  delay(3000);
  
  // Let's turn off the relay...
  digitalWrite(RelayPin1, HIGH);
  digitalWrite(RelayPin2, HIGH);
  digitalWrite(RelayPin4, HIGH);
  delay(4000);
}
