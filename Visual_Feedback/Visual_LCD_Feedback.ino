/*
* Arduino LCD Tutorial
*
* Crated by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/

#include <LiquidCrystal.h> // includes the LiquidCrystal Library 
LiquidCrystal lcd(1, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7) 

// Setting Variables
const char *answers[] = {"S, 5m", "NE, 10m", "W, 5m", "SE, 10m", "W, 10m", "E, 5m", "NE, 5m", "SW, 5m", "N, 10m", "S, 5m"};

void setup() 
{ 
  lcd.begin(8,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display } 
}

void loop() 
{ 
  for (int count=0; count<10; ++count){
    Serial.print("Question ");
    Serial.print(count+1);
    delay(10000); //10 seconds
    lcd.print(answers[count]);
    delay(5000); //5 seconds
    lcd.clear(); 
    }
    Serial.println("Test is Done");
    delay(120000); //2 minutes
}
