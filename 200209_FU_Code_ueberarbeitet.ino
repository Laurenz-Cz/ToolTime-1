int degree = 0; //gibt an, in welcher Stellung sich das Fahrzeug befindet --> Start ist bei 0
int dist1 = 30;
int dist2 = 20;

//--------------Motoren---------------------------------------------------------------------------------------------------

//Motoren
int in1 = 8;                //rechte Seite
int in2 = 7;                //rechte Seite
int in3 = 4;                //linke Seite
int in4 = 2;                //linke Seite

//Drehzahlregulierung
int ENA = 3;                //Drehzahlregelung rechte Seite
int ENB = 9;                //Drehzahlregelung linke Seite
//int SPEED1 = 255;         //Analoge Werte geben die Geschwindigkeit zum geradeaus Fahren vor (0-255)
//int SpeedDrehen = 255;    //Analoge Werte geben die Geschwindigkeit für das Drehen des Fahrzeugs vor (0-255)

int DELAY = 700;
int DELAYdoppelt = 1400;
int DELAYstehen = 1000;
int DELAYultra = 60;

//--------------Ultraschallsensoren---------------------------------------------------------------------------------------

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
  //------------------MOTORSTEUERUNG---------------------------------------------------------------------------------------
  
  pinMode(in1, OUTPUT); //rechte Seite
  pinMode(in2, OUTPUT); //rechte Seite
  pinMode(in3, OUTPUT); //linke Seite
  pinMode(in4, OUTPUT); //linke Seite

  //------------------Ultraschallsensoren----------------------------------------------------------------------------------

  // Ultraschallsensor 1
  Serial.begin(9600);
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


//-----------------------------Funktionen--------------------------------------------------------------------------------

void UltraschallSensoren (){
  //Vorne
  digitalWrite(trigPin1, LOW);
  delay(5);
  digitalWrite(trigPin1, HIGH);
  delay(10);
  digitalWrite(trigPin1, LOW);
  dauer1 = pulseIn(echoPin1, HIGH);
  frontSensor = (dauer1/2) * 0.03432;
  //Serial.print(frontSensor);
  //Serial.print(" cm");
  delay(DELAYultra);
  
  //Rechts
  digitalWrite(trigPin2, LOW);
  delay(5);
  digitalWrite(trigPin2, HIGH);
  delay(10);
  digitalWrite(trigPin2, LOW);
  dauer2 = pulseIn(echoPin2, HIGH);
  rightSensor = (dauer2/2) * 0.03432;
  //Serial.print(rightSensor);
  //Serial.print(" cm");
  delay(DELAYultra);
  
  //Links
  digitalWrite(trigPin3, LOW);
  delay(5);
  digitalWrite(trigPin3, HIGH);
  delay(10);
  digitalWrite(trigPin3, LOW);
  dauer3 = pulseIn(echoPin3, HIGH);
  leftSensor = (dauer3/2) * 0.03432;
  //Serial.print(leftSensor);
  //Serial.print(" cm");
  delay(DELAYultra);
}

//---------------------------Funktionen für Fahren und Drehen-------------------------------------------------------------

void DrehungR90 (){
  //analogWrite(ENA, SpeedDrehen); //speed 0 - 255
  //analogWrite(ENB, SpeedDrehen); //speed 0 - 255
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(DELAY);
}

void DrehungL90 (){
  //analogWrite(ENA, SpeedDrehen); //speed 0 - 255
  //analogWrite(ENB, SpeedDrehen); //speed 0 - 255
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(DELAY);
}

void DrehungR180 (){
  //analogWrite(ENA, SpeedDrehen); //speed 0 - 255
  //analogWrite(ENB, SpeedDrehen); //speed 0 - 255
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(DELAYdoppelt);
}

void DrehungL180 (){
  //analogWrite(ENA, SpeedDrehen); //speed 0 - 255
  //analogWrite(ENB, SpeedDrehen); //speed 0 - 255
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(DELAYdoppelt);
}

void Stop (){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(DELAYstehen);
}

void VorwaertsFahren (){
  //analogWrite(ENA, SPEED1); //speed 0 - 255
  //analogWrite(ENB, SPEED1); //speed 0 - 255
  digitalWrite(in1, LOW);     // Linkeseite
  digitalWrite(in2, HIGH);    // Linkeseite
  digitalWrite(in3, LOW);     // Rechteseite
  digitalWrite(in4, HIGH);    // Rechteseite
  
}

//-------------------Funktionen für Logik--------------------------------------------------------------------------------


void Front(){

  if (degree == 0)
  {
    //Rechtsdrehung  
    degree = -90;
    DrehungR90();

  }

  else if (degree == 90)
  {
    //Rechtsdrehung    
    degree = 0;
    DrehungR90();
        
  }

  else if (degree == -90)
  {
    //Linksdrehung
    degree = 0;
    DrehungL90();
        
  }

  else if (degree == 180)
  {
    //Rechtsdrehung um 180°
    degree = 0;
    DrehungR180;
  }
        
}

//-----------------------------------------------------------------------------------------------------------------------

void FrontRight(){

  if (degree == 0)
  {
    //Linksdrehung
    degree = 90;
    DrehungL90();   
  }

  else if (degree == 90)
  {
    //Linksdrehung um 180°
    degree = -90;
    DrehungL180();
  }

  else if (degree == -90)
  {
    //Linksdrehung
    degree = 0;
    DrehungL90();
  }

  else if (degree == 180)
  {
    //Linksdrehung um 180°
    degree = 0;
    DrehungL180();    
  }
}

//-----------------------------------------------------------------------------------------------------------------------


void FrontLeft (){
  
  if (degree == 0)
  {
    //Rechtsdrehung
    degree = -90;
    DrehungR90();
  }

  else if (degree == 90)
  {
    //Rechtsdrehung
    degree = 0;
    DrehungR90();
  }

  else if (degree == -90)
  {
    //Rechtsdrehung um 180°
    degree = 90;
    DrehungR180();
  }

  else if (degree == 180)
  {
    //Rechtsdrehung um 180°
    degree = 0;
    DrehungR180();    
  }
}


//-----------------------------------------------------------------------------------------------------------------------


void FrontRightLeft (){
  
  if (degree == 180)
  {
    //Linksdrehung um 180°
    degree = 0;
    DrehungL180;
  }

  else if (degree == 90)
  {
    //Rechtsdrehung um 180°
    degree = -90;
    DrehungR180;
  }

  else if (degree == -90)
  {
    //Linksdrehung um 180°
    degree  = 90;
    DrehungL180;
  }

  else if (degree == 0)
  {
    //Rechtsdrehung um 180°
    degree = 180;
    DrehungR180;    
  }
}


void DrehungNachVorne(){

  if (frontSensor > dist1 && rightSensor > dist2 && leftSensor > dist2)
  {
    if (degree == 90)
    {
      degree = 0;
      DrehungR90;
    }

    else if (degree == -90)
    {
      degree = 0;
      DrehungL90;
    }
  }
}


void loop(){
 

  Serial.println(degree);

  
//--------------------Ultraschallsensoren---------------------------------------------------------------------------------
  
  
  UltraschallSensoren();
  

//--------------------BEGINN DER LOGIK------------------------------------------------------------------------------------


  if (frontSensor <=dist1)
  {
    Stop();

       
//--------------------Folgender Abschnitt: Wenn frontSensor alleine auslöst-----------------------------------------------

    Front();
    
//--------------------Folgender Abschnitt: Wenn frontSensor && rightSensor auslöst----------------------------------------
    

    if (frontSensor <= dist1 && rightSensor <= dist2)
    {
      FrontRight();
    }


//--------------------Folgender Abschnitt: Wenn frontSensor && leftSensor------------------------------------------------


    else if (frontSensor <= dist1 && leftSensor <= dist2)
    {
      FrontLeft();
    }
    

//--------------------Folgender Abschnitt: Wenn frontSensor && leftSensor && rightSensor---------------------------------


    else if (frontSensor <= dist1 && leftSensor <= dist2 && rightSensor <= dist2)
    {
      FrontRightLeft();
    }


//--------------------Wenn keine Bedingung erfüllt ist, dreht sich das Fahrzeug auf 0° und fährt weiter-----------------   
      
    
  }

  else
  
  DrehungNachVorne();
  VorwaertsFahren();
  
}
