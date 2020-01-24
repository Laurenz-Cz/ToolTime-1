// Ultraschallsensor 1
int trigPin1 = 12;
int echoPin1 = 13;

long dauer1 = 0;
long entfernung1 = 0;

// Ultraschallsensor 2
int trigPin2 = 10;
int echoPin2 = 11;

long dauer2 = 0;
long entfernung2 = 0;

// Ultraschallsensor 3
int trigPin3 = 6;
int echoPin3 = 5;

long dauer3 = 0;
long entfernung3 = 0;

//------------------------------------------

// MOTORSTEUERUNG
// rechts in Fahrtrichtung
int in1=8;
int in2=7;

// links in Fahrtrichtung
int in3=4;
int in4=2;

//Drehzahlregulierung
//int ENA = 3;
//int ENB = 9;
//int SPEED = 230;

void setup() {
  // Ultraschallsensor 1
  //Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  // Ultraschallsensor 2
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  // Ultraschallsensor 3
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

//-------------------------------------------
  
  // MOTORSTEUERUNG
  // rechts in Fahrtrichtung
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  // links in Fahrtrichtung
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  //Drehzahlregulierung
 // pinMode(ENA, OUTPUT);
 // pinMode(ENB, OUTPUT);
}

void loop() {
  // Ultraschallsensor 1
  digitalWrite(trigPin1, LOW);
  delay(5);
  digitalWrite(trigPin1, HIGH);
  delay(10);
  digitalWrite(trigPin1, LOW);
  dauer1 = pulseIn(echoPin1, HIGH);
  entfernung1 = (dauer1/2) * 0.03432;
  //Serial.print(entfernung1);
  //Serial.print(" cm");
  delay(100);

   // Ultraschallsensor 2
  digitalWrite(trigPin2, LOW);
  delay(5);
  digitalWrite(trigPin2, HIGH);
  delay(10);
  digitalWrite(trigPin2, LOW);
  dauer2 = pulseIn(echoPin2, HIGH);
  entfernung2 = (dauer2/2) * 0.03432;
  //Serial.print(entfernung2);
  //Serial.print(" cm");
  delay(100);

  // Ultraschallsensor 3
  digitalWrite(trigPin3, LOW);
  delay(5);
  digitalWrite(trigPin3, HIGH);
  delay(10);
  digitalWrite(trigPin3, LOW);
  dauer3 = pulseIn(echoPin3, HIGH);
  entfernung3 = (dauer3/2) * 0.03432;
  //Serial.print(entfernung3);
  //Serial.print(" cm");
  delay(100);

//-----------------------------------------------------  


  // MOTORSTEUERUNG
  // Abstand kleinergleich 25cm Sensor Mitte oder 20cm Sensor rechts --> stop und nach links drehen
  if (entfernung1 <=25 || entfernung2 <=20) {
    
    //analogWrite(ENA, SPEED); //speed 0 - 255
    //analogWrite(ENB, SPEED); //speed 0 - 255
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delay(2000);
   
    // drehen nach links
    //analogWrite(ENA, SPEED); //speed 0 - 255
    //analogWrite(ENB, SPEED); //speed 0 - 255
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(150);
  }

  // Abstand kleinergleich 25cm Sensor Mitte oder 20cm Sensor links --> stop und nach rechts drehen
  else if (entfernung1 <=25 || entfernung3 <=20) {

    //analogWrite(ENA, SPEED); //speed 0 - 255
    //analogWrite(ENB, SPEED); //speed 0 - 255
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delay(2000);
   
    // drehen nach rechts
    //analogWrite(ENA, SPEED); //speed 0 - 255
    //analogWrite(ENB, SPEED); //speed 0 - 255
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(150);
  }

  // Wenn der Abstand groß genug ist, fährt das Fahrzeug wieder gerade aus
  else {
    // vorwärts fahren
    //analogWrite(ENA, SPEED); //speed 0 - 255
    //analogWrite(ENB, SPEED); //speed 0 - 255
    // linke Seite
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // rechte Seite
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
   }
  
}  
