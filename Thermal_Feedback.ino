
// Setting Variables
const int answers[10] = {9, 5, 6, 5, 5, 5, 9, 6, 9, 5}; //test answers
int count = 0;  //question counter

//const int peltier_1 = 5, peltier_2 = 6, peltier_3 = 9; //peltier modules pins


void setup()
{
  Serial.begin(9600);
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
