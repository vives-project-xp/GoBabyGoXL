#define drukvooruit 25
#define drukachteruit 21
#define druklinks 22
#define drukrechts 17
 
boolean vooruitStatus =  true;
boolean achteruitStatus =  true;
boolean linksStatus = true;
boolean rechtsStatus =  true;
 
 
void setup() {
  pinMode(drukvooruit, INPUT_PULLUP);
  pinMode(drukachteruit, INPUT_PULLUP);
  pinMode(druklinks, INPUT_PULLUP);
  pinMode(drukrechts, INPUT_PULLUP);
  Serial.begin(9600);
}
 
void loop() {
  vooruitStatus = digitalRead(drukvooruit);
  achteruitStatus = digitalRead(drukachteruit);
  linksStatus = digitalRead(druklinks);
  rechtsStatus = digitalRead(drukrechts);
 
  if (vooruitStatus == false){
    Serial.println("vooruit");
  }
  if (achteruitStatus == false){
    Serial.println("achteruit");
  }
  if (linksStatus == false){
    Serial.println("links");
  }
  if (rechtsStatus == false){
    Serial.println("rechts");
  }
 
}