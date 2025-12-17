// joystick inputs (active LOW)
#define drukvooruit 25
#define drukachteruit 21
#define druklinks 22
#define drukrechts 17

// vooruit achteruit auto
const int switchPin1 = 2;
const int switchPin2 = 15;

// sturing motor (H-brug)
const int IN1A = 27;
const int IN2A = 26;

// basis tijdlimiet (centrum)
const unsigned long basisLimiet = 6000; // 2s

// maximale extra tijd als we aan een kant zitten
const unsigned long extraLimiet = 4000; // 4s, totaal dus max. 6s

// positie variabele (-100 = links, 0 = midden, 100 = rechts)
int stuurPositie = 0;

// timers & blokkades
unsigned long startTijdLinks = 0;
unsigned long startTijdRechts = 0;
bool blockedLeft = false;
bool blockedRight = false;

void setup() {
  pinMode(drukvooruit, INPUT_PULLUP);
  pinMode(drukachteruit, INPUT_PULLUP);
  pinMode(druklinks, INPUT_PULLUP);
  pinMode(drukrechts, INPUT_PULLUP);

  pinMode(switchPin1, OUTPUT);
  pinMode(switchPin2, OUTPUT);

  pinMode(IN1A, OUTPUT);
  pinMode(IN2A, OUTPUT);

  Serial.begin(9600);
}

unsigned long berekenLimiet() {
  // absolute afstand tot midden
  int afstand = abs(stuurPositie); // 0–100

  // hoe dichter bij uiterste stand, hoe meer limiet
  float factor = afstand / 100.0; // 0.0 – 1.0

  return basisLimiet + (extraLimiet * factor);
}

void loop() {
  bool vooruit = (digitalRead(drukvooruit) == LOW);
  bool achteruit = (digitalRead(drukachteruit) == LOW);
  bool links = (digitalRead(druklinks) == LOW);
  bool rechts = (digitalRead(drukrechts) == LOW);

  unsigned long now = millis();

  // ---- Vooruit/achteruit zoals eerder ----
  digitalWrite(switchPin1, HIGH);
  digitalWrite(switchPin2, HIGH);

  if (vooruit) {
    digitalWrite(switchPin1, LOW);
    digitalWrite(switchPin2, HIGH);
  }

  if (achteruit) {
    digitalWrite(switchPin1, HIGH);
    digitalWrite(switchPin2, LOW);
  }

  // ---- Dynamische tijdlimiet ----
  unsigned long huidigeLimiet = berekenLimiet();

  // --- LINKS ---
  if (links) {
    if (startTijdLinks == 0) startTijdLinks = now;

    if (!blockedLeft && (now - startTijdLinks < huidigeLimiet)) {
      digitalWrite(IN1A, HIGH);
      digitalWrite(IN2A, LOW);
      if (stuurPositie > -100) stuurPositie--;   // links = negatief
    }
    else {
      blockedLeft = true;
      digitalWrite(IN1A, LOW);
      digitalWrite(IN2A, LOW);
      Serial.println("LIMIT LINKS bereikt");
    }
  }
  else {
    startTijdLinks = 0;
    blockedLeft = false;
  }

  // --- RECHTS ---
  if (rechts) {
    if (startTijdRechts == 0) startTijdRechts = now;

    if (!blockedRight && (now - startTijdRechts < huidigeLimiet)) {
      digitalWrite(IN1A, LOW);
      digitalWrite(IN2A, HIGH);
      if (stuurPositie < 100) stuurPositie++;   // rechts = positief
    }
    else {
      blockedRight = true;
      digitalWrite(IN1A, LOW);
      digitalWrite(IN2A, LOW);
      Serial.println("LIMIT RECHTS bereikt");
    }
  }
  else {
    startTijdRechts = 0;
    blockedRight = false;
  }

  // Extra veiligheid
  if (!links && !rechts) {
    digitalWrite(IN1A, LOW);
    digitalWrite(IN2A, LOW);
  }

  // debug
  Serial.print("Positie: ");
  Serial.print(stuurPositie);
  Serial.print("    Limiet: ");
  Serial.println(huidigeLimiet);

  delay(10);
}