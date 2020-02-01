int degree = 0;         //gibt an, in welcher Stellung sich das Fahrzeug befindet - Start ist bei 0

//--------------Motoren-----------------------------------

//Motoren
int in1 = 8;            //rechte Seite
int in2 = 7;            //rechte Seite
int in3 = 4;            //linke Seite
int in4 = 2;            //linke Seite

//Drehzahlregulierung
int ENA = 3;            //Drehzahlregelung rechte Seite
int ENB = 9;            //Drehzahlregelung linke Seite
int SPEED = 150;        //Analoge Werte geben die Geschwindigkeit zum geradeaus Fahren vor (0-255)
int SpeedDrehen = 200;  //Analoge Werte geben die Geschwindigkeit für das Drehen des Fahrzeugs vor (0-255)

//--------------Ultraschallsensoren---------------------------

// Ultraschallsensor vorne
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


void setup()  
{
  //------------------MOTORSTEUERUNG--------------------------
  
  pinMode(in1, OUTPUT); //rechte Seite
  pinMode(in2, OUTPUT); //rechte Seite
  pinMode(in3, OUTPUT); //linke Seite
  pinMode(in4, OUTPUT); //linke Seite

  //------------------Ultraschallsensoren-----------------------

  // Ultraschallsensor 1
  //Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  // Ultraschallsensor 2
  //Serial.begin(9600);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  // Ultraschallsensor 3
  //Serial.begin(9600);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
}


void loop() 
{
    //---------------Ultraschallsensoren-----------------------
  
  //Ultraschallsensor vorne
  digitalWrite(trigPin1, LOW);
  delay(5);
  digitalWrite(trigPin1, HIGH);
  delay(10);
  digitalWrite(trigPin1, LOW);
  dauer1 = pulseIn(echoPin1, HIGH);
  frontSensor = (dauer1/2) * 0.03432;
  //Serial.print(frontSensor);
  //Serial.print(" cm");
  delay(100);

   // Ultraschallsensor rechts
  digitalWrite(trigPin2, LOW);
  delay(5);
  digitalWrite(trigPin2, HIGH);
  delay(10);
  digitalWrite(trigPin2, LOW);
  dauer2 = pulseIn(echoPin2, HIGH);
  rightSensor = (dauer2/2) * 0.03432;
  //Serial.print(rightSensor);
  //Serial.print(" cm");
  delay(100);

  // Ultraschallsensor links
  digitalWrite(trigPin3, LOW);
  delay(5);
  digitalWrite(trigPin3, HIGH);
  delay(10);
  digitalWrite(trigPin3, LOW);
  dauer3 = pulseIn(echoPin3, HIGH);
  leftSensor = (dauer3/2) * 0.03432;
  //Serial.print(leftSensor);
  //Serial.print(" cm");
  delay(100);
  
  if(frontSensor <= 30) //war vorher auf Wert 20 eingestellet (Reaktion zu langsam)
  {
     //Fahrzeug bleibt stehen
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        delay(2000);
    
    if(leftSensor <= 20 && rightSensor > 20)
    {
      if(degree == 0)
      {
        degree -= 90;
        //drehen nach rechts um 90 grad
        analogWrite(ENA, SpeedDrehen); //speed 0 - 255
        analogWrite(ENB, SpeedDrehen); //speed 0 - 255
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        delay(650);
      }
      else if(degree == -90)
      {
        degree = 90;
        //drehen nach rechts um 180 grad
        analogWrite(ENA, SpeedDrehen); //speed 0 - 255
        analogWrite(ENB, SpeedDrehen); //speed 0 - 255
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        delay(1300); //Doppeltes Delay
      }
      else if(degree == 90)
      {
        degree = 0;
        // drehen nach rechts um 90 grad
        analogWrite(ENA, SpeedDrehen); //speed 0 - 255
        analogWrite(ENB, SpeedDrehen); //speed 0 - 255
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        delay(650);
      }
    }
    else if(rightSensor <= 20 && leftSensor > 20)
    {
      if(degree == 0)
      {
        degree += 90;
        // drehen nach links um 90 grad
        analogWrite(ENA, SpeedDrehen); //speed 0 - 255
        analogWrite(ENB, SpeedDrehen); //speed 0 - 255
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        delay(650);
      }
      else if(degree == 90)
      {
        degree -= 90;
        //drehen nach links um 180 grad
        analogWrite(ENA, SpeedDrehen); //speed 0 - 255
        analogWrite(ENB, SpeedDrehen); //speed 0 - 255
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        delay(1300); //Doppelter Delay
      }
      else if(degree == -90)
      {
        degree = 0;   
        // drehen nach links um 90 grad
        analogWrite(ENA, SpeedDrehen); //speed 0 - 255
        analogWrite(ENB, SpeedDrehen); //speed 0 - 255
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        delay(650);
      }
    }
    else if(rightSensor <= 20 && leftSensor <= 20)
    {
      if(degree == 90)
      {
        degree -= 90;
        //drehen nach rechts um 180 grad
        analogWrite(ENA, SpeedDrehen); //speed 0 - 255
        analogWrite(ENB, SpeedDrehen); //speed 0 - 255
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        delay(1300); //doppelt Delay
      }

      else if(degree = -90)
      {
        degree = 90;   
        //drehen nach links um 180 grad
        analogWrite(ENA, SpeedDrehen); //speed 0 - 255
        analogWrite(ENB, SpeedDrehen); //speed 0 - 255
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        delay(1300); //Doppeltes Delay
      }
    }
    else if(rightSensor > 20 && leftSensor > 20)
    {
      if(degree == 90)
      {
        degree = 0;   
        //drehen nach rechts um 90 grad
        analogWrite(ENA, SpeedDrehen); //speed 0 - 255
        analogWrite(ENB, SpeedDrehen); //speed 0 - 255
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        delay(650);
      }
      else if(degree == -90)
      {
        degree = 0;   
        //drehen nach links um 90 grad
        analogWrite(ENA, SpeedDrehen); //speed 0 - 255
        analogWrite(ENB, SpeedDrehen); //speed 0 - 255
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        delay(650);
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
  
  //Folgender Abschnitt: Wenn der Abstand zu allen Sensoren größer als der definierte Wert ist, dann dreht das Fahrzeug wieder auf 0°
  //und fährt anschließend wieder gerade aus. (Wenn es auf -90° steht --> Drehung nach links, bei +90° --> Drehung nach rechts)
  
  else if(frontSensor > 20 && leftSensor > 20 && rightSensor > 20)
  {
    if(degree == 90)
    {
      degree = 0;   
      //drehen nach rechts um 90 grad
      analogWrite(ENA, SpeedDrehen); //speed 0 - 255
      analogWrite(ENB, SpeedDrehen); //speed 0 - 255
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      delay(650);
      
      //-------------TESTBLOCK----------------------
      
      // vorwärts fahren
      analogWrite(ENA, SPEED);  //speed 0 - 255
      analogWrite(ENB, SPEED);  //speed 0 - 255
      digitalWrite(in1, LOW);   //linke Seite
      digitalWrite(in2, HIGH);  //linke Seite
      digitalWrite(in3, LOW);   //rechte Seite
      digitalWrite(in4, HIGH);  //rechte Seite
      
      //--------------------------------------------
      
    }
    else if(degree == -90)
    {
      degree = 0;   
      //drehen nach links um 90 grad
      analogWrite(ENA, SpeedDrehen); //speed 0 - 255
      analogWrite(ENB, SpeedDrehen); //speed 0 - 255
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      delay(650);
      
      //-------------TESTBLOCK----------------------
      
      // vorwärts fahren
      analogWrite(ENA, SPEED);  //speed 0 - 255
      analogWrite(ENB, SPEED);  //speed 0 - 255
      digitalWrite(in1, LOW);   //linke Seite
      digitalWrite(in2, HIGH);  //linke Seite
      digitalWrite(in3, LOW);   //rechte Seite
      digitalWrite(in4, HIGH);  //rechte Seite
      
      //--------------------------------------------
     
    }
    else
    {
      //-------------TESTBLOCK----------------------
      
      // vorwärts fahren
      analogWrite(ENA, SPEED);  //speed 0 - 255
      analogWrite(ENB, SPEED);  //speed 0 - 255
      digitalWrite(in1, LOW);   //linke Seite
      digitalWrite(in2, HIGH);  //linke Seite
      digitalWrite(in3, LOW);   //rechte Seite
      digitalWrite(in4, HIGH);  //rechte Seite
      
      //--------------------------------------------
    }
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
    analogWrite(ENA, SpeedDrehen); //speed 0 - 255
    analogWrite(ENB, SpeedDrehen); //speed 0 - 255
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(650);
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
    analogWrite(ENA, SpeedDrehen); //speed 0 - 255
    analogWrite(ENB, SpeedDrehen); //speed 0 - 255
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(650);
  }
}
