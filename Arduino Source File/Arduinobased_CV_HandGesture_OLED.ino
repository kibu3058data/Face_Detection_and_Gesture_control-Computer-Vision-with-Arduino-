#include <cvzone.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

SerialData serialData(5, 1); //(numOfValsRec,digitsPerValRec)
int valsRec[5]; // array of int with size numOfValsRec 
void setup(){
  display.begin(SSD1306_SWITCHCAPVCC,SCREEN_ADDRESS);
  display.clearDisplay();
  serialData.begin(9600);
}

void loop(){
  serialData.Get(valsRec);
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(52,2);
  display.clearDisplay();
  if(valsRec[0]==0 && valsRec[1]==1 && valsRec[2]==0 && valsRec[3]==0 && valsRec[4]==0)
    display.println("1");
  else if(valsRec[0]==0 && valsRec[1]==1 && valsRec[2]==1 && valsRec[3]==0 && valsRec[4]==0)
    display.println("2");
  else if(valsRec[0]==0 && valsRec[1]==1 && valsRec[2]==1 && valsRec[3]==1 && valsRec[4]==0)
    display.println("3");
  else if(valsRec[0]==0 && valsRec[1]==1 && valsRec[2]==1 && valsRec[3]==1 && valsRec[4]==1)
    display.println("4");
  else if(valsRec[0]==1 && valsRec[1]==1 && valsRec[2]==1 && valsRec[3]==1 && valsRec[4]==1)
    display.println("5");
  else if(valsRec[0]==0 && valsRec[1]==0 && valsRec[2]==0 && valsRec[3]==0 && valsRec[4]==0)
    display.println("0");
  else 
    display.println(" ");
  display.display();
}
