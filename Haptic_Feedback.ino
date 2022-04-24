/*
    Vibration Motor with Arduino
    For more details, visit: https://techzeero.com/arduino-tutorials/vibration-motor-with-arduino/
*/

// Setting Variables
const int answers[10] = {6, 9, 5, 5, 6, 6, 9, 9, 5, 6}; //test answers
int count = 0;  //question counter

//const int motorPin_1 = 5, motorPin_2 = 6, motorPin_3 = 9; //motor transistor pins


void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
    for (int count=0; count<10; ++count){
      Serial.print("Question ");
      Serial.print(count+1);
      delay(10000); //10 seconds
      analogWrite(answers[count], 255); //cool
      delay(5000); //5 seconds
      analogWrite(answers[count], 0); //stop
    }
    Serial.println("Test is Done");
    delay(120000); //2 minutes
}
