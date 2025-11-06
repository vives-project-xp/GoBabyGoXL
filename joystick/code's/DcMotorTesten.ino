const int IN1A = 25;  // Richting pin 1
const int IN2A = 26;  // Richting pin 2

void setup() {
  pinMode(IN1A, OUTPUT);
  pinMode(IN2A, OUTPUT);

  Serial.begin(9600);
  
}

void loop() {
  // links
  Serial.println("Links");
  digitalWrite(IN1A, HIGH);
  digitalWrite(IN2A, LOW);
  delay(10000);  

  // Stop kort 
  digitalWrite(IN1A, LOW);
  digitalWrite(IN2A, LOW);
  delay(500);

  // Rechts
  Serial.println("Rechts");
  digitalWrite(IN1A, LOW);
  digitalWrite(IN2A, HIGH);
  delay(10000);  

  // Stop kort 
  digitalWrite(IN1A, LOW);
  digitalWrite(IN2A, LOW);
  delay(500);
}