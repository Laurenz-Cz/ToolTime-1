//www.elegoo.com
//2016.12.9

//We always have to include the library
#include "LedControl.h"

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to LOAD(CS)
 pin 10 is connected to the CLK 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,10,11,1);

/* we always wait a bit between updates of the display */
unsigned long delaytime1=1000;
unsigned long delaytime2=1500;
void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
}

/*
 This method will display the characters for the
 word "Arduino" one after the other on the matrix. 
 (you need at least 5x7 leds to see the whole chars)
 */
void writeArduinoOnMatrix() {
  /* here is the data for the characters */
  byte W[5]={B00111111, B01000000, B00111000, B01000000, B00111111};
  byte e[5]={B00111000, B01010100, B01010100, B00011000, B00000000};
  byte s[5]={B01001000, B01010100, B01010100, B00100100, B00000000};
  byte n[5]={B01111100, B00000100, B00000100, B01111000, B00000000};
  byte d[5]={B00111000, B01000100, B01000100, B01111111, B00000000};
  byte H[5]={B01111111, B00001000, B00001000, B01111111, B00000000};
  byte l[5]={B01000001, B01111111, B01000000, B00000000, B00000000};
  byte p[5]={B11111100, B00100100, B00100100, B00011000, B00000000};

  /* now display them one by one with a small delay */
  lc.setRow(0,0,W[0]);
  lc.setRow(0,1,W[1]);
  lc.setRow(0,2,W[2]);
  lc.setRow(0,3,W[3]);
  lc.setRow(0,4,W[4]);
  delay(delaytime1);
  lc.setRow(0,0,e[0]);
  lc.setRow(0,1,e[1]);
  lc.setRow(0,2,e[2]);
  lc.setRow(0,3,e[3]);
  lc.setRow(0,4,e[4]);
  delay(delaytime2);
  lc.setRow(0,0,s[0]);
  lc.setRow(0,1,s[1]);
  lc.setRow(0,2,s[2]);
  lc.setRow(0,3,s[3]);
  lc.setRow(0,4,s[4]);
  delay(delaytime1);
  lc.setRow(0,0,e[0]);
  lc.setRow(0,1,e[1]);
  lc.setRow(0,2,e[2]);
  lc.setRow(0,3,e[3]);
  lc.setRow(0,4,e[4]);
  delay(delaytime1);
  lc.setRow(0,0,n[0]);
  lc.setRow(0,1,n[1]);
  lc.setRow(0,2,n[2]);
  lc.setRow(0,3,n[3]);
  lc.setRow(0,4,n[4]);
  delay(delaytime1);
  lc.setRow(0,0,d[0]);
  lc.setRow(0,1,d[1]);
  lc.setRow(0,2,d[2]);
  lc.setRow(0,3,d[3]);
  lc.setRow(0,4,d[4]);
  delay(delaytime2);
  lc.setRow(0,0,H[0]);
  lc.setRow(0,1,H[1]);
  lc.setRow(0,2,H[2]);
  lc.setRow(0,3,H[3]);
  lc.setRow(0,4,H[4]);
  delay(delaytime1);
  lc.setRow(0,0,e[0]);
  lc.setRow(0,1,e[1]);
  lc.setRow(0,2,e[2]);
  lc.setRow(0,3,e[3]);
  lc.setRow(0,4,e[4]);
  delay(delaytime1);
  lc.setRow(0,0,l[0]);
  lc.setRow(0,1,l[1]);
  lc.setRow(0,2,l[2]);
  lc.setRow(0,3,l[3]);
  lc.setRow(0,4,l[4]);
  delay(delaytime1);
  lc.setRow(0,0,p[0]);
  lc.setRow(0,1,p[1]);
  lc.setRow(0,2,p[2]);
  lc.setRow(0,3,p[3]);
  lc.setRow(0,4,p[4]);
  delay(delaytime1);
}

/*
  This function lights up a some Leds in a row.
 The pattern will be repeated on every row.
 The pattern will blink along with the row-number.
 row number 4 (index==3) will blink 4 times etc.
/*
  
/*
  This function lights up a some Leds in a column.
 The pattern will be repeated on every column.
 The pattern will blink along with the column-number.
 column number 4 (index==3) will blink 4 times etc.
 */

/* 
 This function will light up every Led on the matrix.
 The led will blink along with the row-number.
 row number 4 (index==3) will blink 4 times etc.
 */
void loop() { 
  writeArduinoOnMatrix(); 
}
