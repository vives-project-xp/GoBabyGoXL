// joystick inputs
#define drukvooruit 25
#define drukachteruit 21
#define druklinks 22
#define drukrechts 17

// vooruit achteruit auto
const int switchPin1 = 2;   // uitgang voor stand 1
const int switchPin2 = 15;   // uitgang voor stand 2

// sturing 
const int IN1A = 27;  // Richting pin 1
const int IN2A = 26;  // Richting pin 2
 
boolean vooruitStatus =  true;
boolean achteruitStatus =  true;
boolean linksStatus = true;
boolean rechtsStatus =  true;
 
 
void setup() {
  pinMode(drukvooruit, INPUT_PULLUP);
  pinMode(drukachteruit, INPUT_PULLUP);
  pinMode(druklinks, INPUT_PULLUP);
  pinMode(drukrechts, INPUT_PULLUP);

  pinMode(switchPin1, OUTPUT);
  pinMode(switchPin2, OUTPUT);

  // Begin met alles uit
  digitalWrite(switchPin1, HIGH);
  digitalWrite(switchPin2, HIGH);

  pinMode(IN1A, OUTPUT);
  pinMode(IN2A, OUTPUT);

  Serial.begin(9600);
}
 
void loop() {
  vooruitStatus = digitalRead(drukvooruit);
  achteruitStatus = digitalRead(drukachteruit);
  linksStatus = digitalRead(druklinks);
  rechtsStatus = digitalRead(drukrechts);

  // Middelste stand (geen verbinding)
  digitalWrite(switchPin1, HIGH);
  digitalWrite(switchPin2, HIGH);
  Serial.println("Middelste stand (geen verbinding)");

  if (vooruitStatus == false) {
    digitalWrite(switchPin1, LOW);   
    digitalWrite(switchPin2, HIGH);
    Serial.println("Stand 1 actief (vooruit)");
  }

  if (achteruitStatus == false) {
    digitalWrite(switchPin1, HIGH);
    digitalWrite(switchPin2, LOW);
    Serial.println("Stand 2 actief (achteruit)");
  }

  if (linksStatus == false) {
    Serial.println("links");
    digitalWrite(IN1A, HIGH);
    digitalWrite(IN2A, LOW);
  } 
  else if (rechtsStatus == false) {
    Serial.println("rechts");
    digitalWrite(IN1A, LOW);
    digitalWrite(IN2A, HIGH);
  } 
  else {
    // Alleen uitzetten als er geen richting actief is
    digitalWrite(IN1A, LOW);
    digitalWrite(IN2A, LOW);
  }

  delay(200);  
}
