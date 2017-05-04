#include <Keyboard.h>


const int rowsPins[] = {A0};
const int rowsPinsSize = 1;
const int columnsPins[] = {5,6,7,8,9};
const int columnsPinsSize = 5;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Keyboard.begin();

  //set the row pins in the correct mode
  for (int i = 0; i < rowsPinsSize; ++i) {
    pinMode(rowsPins[i], INPUT);
  }

  //set the column pins in the correct mode
  for (int i = 0; i < columnsPinsSize; ++i) {
    pinMode(columnsPins[i], OUTPUT);
  }

}

void loop() {
  //check the rows against the columns
  for (int i = 0; i < columnsPinsSize; ++i) {
    //turn on the column
    digitalWrite(columnsPins[i], HIGH);
    delay(20);
    //check for the rows
    for(int j = 0; j < rowsPinsSize; ++j){

      //check if the row got power
      int result = digitalRead(rowsPins[j]);
      if(result == HIGH){
        HandleKey(j,i);
      }
    }
    delay(20);
    //turn of the collumn
    digitalWrite(columnsPins[i], LOW);
  }
 delay(50);
}

void HandleKey(int row, int column) {
  if(row == 0 && column == 0){
    Keyboard.write(131);//GUI
    delay(1000);
    Keyboard.println("Text Editor");//Name of the program
    delay(200);
    Keyboard.write(179);//tab to go to the program
    delay(200);
    Keyboard.write(176);//enter to start the program  
  }
  else if(row == 0 && column == 1){
    Serial.println("2");
  }
  else if(row == 0 && column == 2){
    Serial.println("3");
  }
  else if(row == 0 && column == 3){
    Serial.println("4");
  }
  else if(row == 0 && column == 4){
    Serial.println("5");
  }
}




