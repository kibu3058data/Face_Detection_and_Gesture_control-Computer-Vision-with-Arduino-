#include <cvzone.h>

SerialData serialData(1, 1); //(numOfValsRec,digitsPerValRec)
int valsRec[1]; // array of int with size numOfValsRec 

const int ledPin=2;
const int buzzPin=7;
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzPin,OUTPUT);
  serialData.begin(9600);
}

void loop() {

  serialData.Get(valsRec);
  digitalWrite(ledPin, valsRec[0]);
  delay(10);
}
