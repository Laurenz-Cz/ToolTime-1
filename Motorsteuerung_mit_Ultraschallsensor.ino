// Ultraschallsensor
int trigger=12;
int echo=13;

long dauer=0;
long entfernung=0;

// MOTORSTEUERUNG
// rechts in Fahrtrichtung
int in1=8;
int in2=7;

// links in Fahrtrichtung
int in3=4;
int in4=2;

void setup() {
  // Ultraschallsensor
  //Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  // MOTORSTEUERUNG
  // rechts in Fahrtrichtung
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  // links in Fahrtrichtung
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  // Ultraschallsensor
  digitalWrite(trigger, LOW);
  delay(5);
  digitalWrite(trigger, HIGH);
  delay(10);
  digitalWrite(trigger, LOW);
  dauer = pulseIn(echo, HIGH);
  entfernung = (dauer/2) * 0.03432;
  //Serial.print(entfernung);
  //Serial.print(" cm");
  delay(100);
  
  // MOTORSTEUERUNG
  // Abstand kleinergleich 20 cm stop
  if (entfernung <=20) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delay(2000);

    // rückwärts fahren
    //digitalWrite(in1, HIGH);
    //digitalWrite(in2, LOW);
    //digitalWrite(in3, HIGH);
    //digitalWrite(in4, LOW);
    //delay(250);

    // drehen
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(250);
  }
  else {
    // vorwärts fahren
    // rechts in Fahrtrichtung
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  
    // links in Fahrtrichtung
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
}
