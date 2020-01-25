int degree = 0;
//int frontSensor;
//int leftSensor;
//int rightSensor;

//--------------Motoren-----------------------------------

//Motoren
//rechts in Fahrtrichtung
int in1=8;
int in2=7;

//links in Fahrtrichtung
int in3=4;
int in4=2;

//Drehzahlregulierung
int ENA = 3;
int ENB = 9;
int SPEED = 150;
int SPEED1= 150;

//--------------Ultraschallsensoren---------------------------

// Ultraschallsensor mitte
int trigPin1 = 12;
int echoPin1 = 13;

long dauer1 = 0;
long frontSensor = 0;

// Ultraschallsensor rechts
int trigPin2 = 10;
int echoPin2 = 11;

long dauer2 = 0;
long rightSensor = 0;

// Ultraschallsensor links
int trigPin3 = 6;
int echoPin3 = 5;

long dauer3 = 0;
long leftSensor = 0;


void setup(){
  
  // MOTORSTEUERUNG
  // rechts in Fahrtrichtung
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  // links in Fahrtrichtung
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

//------------------Ultraschallsensoren-----------------------

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

}


void loop()
{
  // Ultraschallsensor 1
  digitalWrite(trigPin1, LOW);
  delay(5);
  digitalWrite(trigPin1, HIGH);
  delay(10);
  digitalWrite(trigPin1, LOW);
  dauer1 = pulseIn(echoPin1, HIGH);
  frontSensor = (dauer1/2) * 0.03432;
  Serial.print(frontSensor);
  Serial.print(" cm");
  delay(100);

   // Ultraschallsensor 2
  digitalWrite(trigPin2, LOW);
  delay(5);
  digitalWrite(trigPin2, HIGH);
  delay(10);
  digitalWrite(trigPin2, LOW);
  dauer2 = pulseIn(echoPin2, HIGH);
  rightSensor = (dauer2/2) * 0.03432;
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
  leftSensor = (dauer3/2) * 0.03432;
  //Serial.print(entfernung3);
  //Serial.print(" cm");
  delay(100);
  
  if(frontSensor <= 20)
  {
    if(leftSensor <= 20 && rightSensor > 20)
    {
      if(degree == 0)
      {
        degree -= 90;
        //Fahrzeug bleibt stehen
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        delay(2000);
   
        //drehen nach rechts um 90 grad
        analogWrite(ENA, SPEED); //speed 0 - 255
        analogWrite(ENB, SPEED); //speed 0 - 255
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        delay(150);
      }
      else if(degree == -90)
      {
        degree = 90;
        //Fahrzeug bleibt stehen
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        delay(2000);
   
        //drehen nach rechts um 180 grad
        analogWrite(ENA, SPEED); //speed 0 - 255
        analogWrite(ENB, SPEED); //speed 0 - 255
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        delay(300); //Doppeltes Delay
      }
      else if(degree == 90)
      {
        degree = 0;
        //Fahrzeug bleibt stehen
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        delay(2000);
   
        // drehen nach rechts um 90 grad
        analogWrite(ENA, SPEED); //speed 0 - 255
        analogWrite(ENB, SPEED); //speed 0 - 255
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        delay(150);
      }
    }
    else if(rightSensor <= 20 && leftSensor > 20)
    {
      if(degree == 0)
      {
        degree += 90; 
        //Fahrzeug bleibt stehen
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        delay(2000);
   
        // drehen nach links um 90 grad
        //analogWrite(ENA, SPEED); //speed 0 - 255
        //analogWrite(ENB, SPEED); //speed 0 - 255
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        delay(150);
      }
      else if(degree == 90)
      {
        degree = -90;
        //Fahrzeug bleibt stehen
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        delay(2000);
   
        //drehen nach rechts um 180 grad
        analogWrite(ENA, SPEED); //speed 0 - 255
        analogWrite(ENB, SPEED); //speed 0 - 255
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        delay(300); //Doppelter Delay
      }
      else if(degree == -90)
      {
        degree = 0;
        //Fahrzeug bleibt stehen 
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        delay(2000);
   
        // drehen nach links um 90 grad
        analogWrite(ENA, SPEED); //speed 0 - 255
        analogWrite(ENB, SPEED); //speed 0 - 255
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        delay(150);
      }
    }
  //else if(rightSensor <= 20 && leftSensor <= 20)
    else if(rightSensor <= 20 && leftSensor > 20)
    {
      if(degree = 90)
      {
        degree = -90;
        //Fahrzeug bleibt stehen 
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        delay(2000);

//---------------FEHLER-----------------------------------------------
   
        //drehen nach rechts um 180 grad
        analogWrite(ENA, SPEED); //speed 0 - 255
        analogWrite(ENB, SPEED); //speed 0 - 255
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        delay(300); //doppelt Delay
      }

//-------------------------------------------------------------------      
      else if(degree = -90)
      {
        degree = 90; 
        //Fahrzeug bleibt stehen
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        delay(2000);
   
        //drehen nach links um 180 grad
        //analogWrite(ENA, SPEED); //speed 0 - 255
        //analogWrite(ENB, SPEED); //speed 0 - 255
        //Fahrzeug bleibt stehen
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        delay(300); //Doppeltes Delay
      }
    }
      else if(rightSensor > 20 && leftSensor > 20)
      {
        if(degree == 90)
        {
          degree = 0;
          //Fahrzeug bleibt stehen
          digitalWrite(in1, LOW);
          digitalWrite(in2, LOW);
          digitalWrite(in3, LOW);
          digitalWrite(in4, LOW);
          delay(2000);
   
          //drehen nach rechts um 90 grad
          analogWrite(ENA, SPEED); //speed 0 - 255
          analogWrite(ENB, SPEED); //speed 0 - 255
          digitalWrite(in1, LOW);
          digitalWrite(in2, HIGH);
          digitalWrite(in3, HIGH);
          digitalWrite(in4, LOW);
          delay(150);
        }
      else if(degree == -90)
      {
        degree = 0;
        //Fahrzeug bleibt stehen 
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        delay(2000);
   
        //drehen nach links um 90 grad
        analogWrite(ENA, SPEED); //speed 0 - 255
        analogWrite(ENB, SPEED); //speed 0 - 255
        //Fahrzeug bleibt stehen
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        delay(150);
      }
    }
    else 
    {
      if(degree == 0)
      {
        randomTurn();
      }
    }
  }
  else if(frontSensor > 20 && leftSensor > 20 && rightSensor > 20)
  {
    if(degree == 90)
    {
      degree = 0;
      //Fahrzeug bleibt stehen
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      delay(2000);
   
      //drehen nach rechts um 90 grad
      analogWrite(ENA, SPEED); //speed 0 - 255
      analogWrite(ENB, SPEED); //speed 0 - 255
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      delay(150);
    }
    else if(degree == -90)
    {
      degree = 0;
      //Fahrzeug bleibt stehen
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      delay(2000);
   
    // drehen nach links um 90 grad
    analogWrite(ENA, SPEED); //speed 0 - 255
    analogWrite(ENB, SPEED); //speed 0 - 255
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(150);
    }
  }
  else {
    // vorwärts fahren
    analogWrite(ENA, SPEED); //speed 0 - 255
    analogWrite(ENB, SPEED); //speed 0 - 255
    // linke Seite
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // rechte Seite
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
}

void randomTurn()
{
  int rand = random(0,2);
  if(rand == 0)
  {
    degree += 90;
    //Fahrzeug bleibt stehen
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delay(2000);
   
    //drehen nach links um 90 grad
    analogWrite(ENA, SPEED); //speed 0 - 255
    analogWrite(ENB, SPEED); //speed 0 - 255
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(150);
  }
  else
  {
    degree -= 90;
    //Fahrzeug bleibt stehen
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delay(2000);
   
    // drehen nach rechts um 90 grad
    analogWrite(ENA, SPEED); //speed 0 - 255
    analogWrite(ENB, SPEED); //speed 0 - 255
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(150);
  }
}
