/* Set serial monitor to "No line ending"
 * wedxszaq for 10m
 * WEDXSZAQ for 5m
 * r to reset*/

#include <neotimer.h>
Neotimer timer5 = Neotimer(5000);
Neotimer timer10 = Neotimer(10000);

//http://embed.plnkr.co/3VUsekP3jC5xwSIQDVHx/preview
//update from Krszyszztof rogoza
String directions;
#define ROW_1 2
#define ROW_2 3
#define ROW_3 4
#define ROW_4 5
#define ROW_5 6
#define ROW_6 7
#define ROW_7 9
#define ROW_8 8

#define COL_8 10
#define COL_7 11
#define COL_6 12
#define COL_5 13
#define COL_4 A5
#define COL_3 A4
#define COL_2 A3
#define COL_1 A2

const byte row[] = {
  ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8
};
const byte col[] = {
  COL_1,COL_2, COL_3, COL_4, COL_5, COL_6, COL_7, COL_8
};

//Directional Images
byte player[] = {B00000000,B00000000,B00000000,B00011000,B00011000,B00000000,B00000000,B00000000};
byte E1[] = {B00011000,B00000000,B00000000,B00011000,B00011000,B00000000,B00000000,B00000000};
byte SE1[] = {B00000011,B00000001,B00000000,B00011000,B00011000,B00000000,B00000000,B00000000};
byte S1[] = {B00000000,B00000000,B00000000,B00011001,B00011001,B00000000,B00000000,B00000000};
byte SW1[] = {B00000000,B00000000,B00000000,B00011000,B00011000,B00000000,B00000001,B00000011};
byte W1[] = {B00000000,B00000000,B00000000,B00011000,B00011000,B00000000,B00000000,B00011000};
byte NW1[] = {B00000000,B00000000,B00000000,B00011000,B00011000,B00000000,B10000000,B11000000};
byte N1[] = {B00000000,B00000000,B00000000,B10011000,B10011000,B00000000,B00000000,B00000000};
byte NE1[] = {B11000000,B10000000,B00000000,B00011000,B00011000,B00000000,B00000000,B00000000};
byte E[] = {B00000000,B00011000,B00000000,B00011000,B00011000,B00000000,B00000000,B00000000};
byte SEE[] = {B00000000,B00000110,B00000010,B00011000,B00011000,B00000000,B00000000,B00000000};
byte S[] = {B00000000,B00000000,B00000000,B00011010,B00011010,B00000000,B00000000,B00000000};
byte SW[] = {B00000000,B00000000,B00000000,B00011000,B00011000,B00000010,B00000110,B00000000};
byte W[] = {B00000000,B00000000,B00000000,B00011000,B00011000,B00000000,B00011000,B00000000};
byte NW[] = {B00000000,B00000000,B00000000,B00011000,B00011000,B01000000,B01100000,B00000000};
byte N[] = {B00000000,B00000000,B00000000,B01011000,B01011000,B00000000,B00000000,B00000000};
byte NE[] = {B00000000,B01100000,B01000000,B00011000,B00011000,B00000000,B00000000,B00000000};

void setup() {
    // Open serial port
    Serial.begin(9600);
    
    // Set all used pins to OUTPUT
    // This is very important! If the pins are set to input
    // the display will be very dim.
    for (byte i = 2; i <= 13; i++)  {
        pinMode(i, OUTPUT);
    }
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
    pinMode(A4, OUTPUT);
    pinMode(A5, OUTPUT);
    timer10.start();   
}

// Setting Variables
const char *answers[] = {"NE", "NE1", "W", "E", "SE", "W1", "NW1", "N1", "N", "S"};
int count = 0;

void loop() {
    if (count < 10){
            
      if (timer10.done()){
        directions = answers[count];
        timer5.start();
        timer10.reset();
        Serial.println("here");
      }
      if (timer5.done()){
        Serial.println("there");
        directions = 'X';
        count += 1;
        timer10.start();
        timer5.reset();
      }
      drawDirection();
    }
    else {
    Serial.println("Test is Done");
    delay(120000); //2 minutes
    }
}

void drawDirection()  {
  if (directions == "N") {
    drawScreen(N);
  }
  else if (directions == "NE") {
    drawScreen(NE);
  }
  else if (directions == "E") {
    drawScreen(E);
  }
  else if (directions == "SE") {
    drawScreen(SEE);
  }
  else if (directions == "S") {
    drawScreen(S);
  }
  else if (directions == "SW") {
    drawScreen(SW);
  }
  else if (directions == "W") {
    drawScreen(W);
  }
  else if (directions == "NW") {
    drawScreen(NW);
  }
  else if (directions == "N1") {
    drawScreen(N1);
  }
  else if (directions == "NE1") {
    drawScreen(NE1);
  }
  else if (directions == "E1") {
    drawScreen(E1);
  }
  else if (directions == "SE1") {
    drawScreen(SE1);
  }
  else if (directions == "S1") {
    drawScreen(S1);
  }
  else if (directions == "SW1") {
    drawScreen(SW1);
  }
  else if (directions == "W1") {
    drawScreen(W1);
  }
  else if (directions == "NW1") {
    drawScreen(NW1);
  }
  else {
    drawScreen(player);
  } 
}
  
void drawScreen(byte buffer2[])
 { 
   // Turn on each row in series
    for (byte i = 0; i < 8; i++)        // count next row
     {
        digitalWrite(row[i], LOW);    //initiate whole row
        for (byte a = 0; a < 8; a++)    // count next row
        {
          // if You set (~buffer2[i] >> a) then You will have positive
          digitalWrite(col[a], (buffer2[i] >> a) & 0x01); // initiate whole column
          
          delayMicroseconds(100);       // uncoment deley for diferent speed of display
          //delayMicroseconds(1000);
          //delay(10);
          //delay(100);
          
          digitalWrite(col[a], LOW);      // reset whole column
        }
        digitalWrite(row[i], HIGH);     // reset whole row
        // otherwise last row will intersect with next row
        
    }
 }  

  /* this is siplest resemplation how for loop is working with each row.
    digitalWrite(COL_1, (~b >> 0) & 0x01); // Get the 1st bit: 10000000
    digitalWrite(COL_2, (~b >> 1) & 0x01); // Get the 2nd bit: 01000000
    digitalWrite(COL_3, (~b >> 2) & 0x01); // Get the 3rd bit: 00100000
    digitalWrite(COL_4, (~b >> 3) & 0x01); // Get the 4th bit: 00010000
    digitalWrite(COL_5, (~b >> 4) & 0x01); // Get the 5th bit: 00001000
    digitalWrite(COL_6, (~b >> 5) & 0x01); // Get the 6th bit: 00000100
    digitalWrite(COL_7, (~b >> 6) & 0x01); // Get the 7th bit: 00000010
    digitalWrite(COL_8, (~b >> 7) & 0x01); // Get the 8th bit: 00000001
}*/
