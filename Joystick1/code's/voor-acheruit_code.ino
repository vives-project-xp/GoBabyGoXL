// Schakelaar testprogramma

const int switchPin1 = 22;   // eerste stand
const int switchPin2 = 21;   // tweede stand

void setup() {
  Serial.begin(9600);
  
  pinMode(switchPin1, INPUT_PULLUP);
  pinMode(switchPin2, INPUT_PULLUP);

  Serial.println("Schakelaar test gestart!");
  Serial.println("Zet de schakelaar in verschillende standen...");
}

void loop() {
  int state1 = digitalRead(switchPin1);
  int state2 = digitalRead(switchPin2);

  if (state1 == LOW && state2 == HIGH) {
    Serial.println("Stand 1 actief vooruit");
  } else if (state2 == LOW && state1 == HIGH) {
    Serial.println("Stand 2 actief achteruit");
  } else if (state1 == HIGH && state2 == HIGH) {
    Serial.println("neutraal (middelste stand)");
  } else {
    Serial.println("Beide pinnen laag neutraal");
  }

  delay(500);
}