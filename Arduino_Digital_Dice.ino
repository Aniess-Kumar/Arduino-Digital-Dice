#include <LedControl.h>

LedControl matrix(11, 13, 10, 1);
const int buttonPin = 2;

byte numbers[6][8] = {
 {B00011000,B00111000,B00011000,B00011000,B00011000,B00011000,B00111100,B00000000},
 {B00111100,B01100110,B00000110,B00001100,B00011000,B00110000,B01111110,B00000000},
 {B00111100,B01100110,B00000110,B00011100,B00000110,B01100110,B00111100,B00000000},
 {B00001100,B00011100,B00101100,B01001100,B01111110,B00001100,B00001100,B00000000},
 {B01111110,B01100000,B01100000,B01111100,B00000110,B01100110,B00111100,B00000000},
 {B00111100,B01100110,B01100000,B01111100,B01100110,B01100110,B00111100,B00000000}
};

void showNumber(int n){ for(int r=0;r<8;r++) matrix.setRow(0,r,numbers[n-1][r]); }

void startupAnimation(){
 matrix.clearDisplay(0);
 matrix.setLed(0,3,3,true); matrix.setLed(0,3,4,true); matrix.setLed(0,4,3,true); matrix.setLed(0,4,4,true); delay(150);
 matrix.setLed(0,2,2,true); matrix.setLed(0,2,5,true); matrix.setLed(0,5,2,true); matrix.setLed(0,5,5,true); delay(120);
 matrix.setLed(0,1,1,true); matrix.setLed(0,1,6,true); matrix.setLed(0,6,1,true); matrix.setLed(0,6,6,true); delay(120);
 for(int i=0;i<8;i++){ matrix.setLed(0,0,i,true); matrix.setLed(0,7,i,true); matrix.setLed(0,i,0,true); matrix.setLed(0,i,7,true); delay(30); }
 delay(150);
 for(int r=0;r<8;r++) matrix.setRow(0,r,B11111111); delay(100); matrix.clearDisplay(0); delay(80);
 for(int r=0;r<8;r++) matrix.setRow(0,r,B11111111); delay(80); matrix.clearDisplay(0); delay(200);
}

void setup(){
 pinMode(buttonPin,INPUT_PULLUP); matrix.shutdown(0,false); matrix.setIntensity(0,5); matrix.clearDisplay(0);
 randomSeed(analogRead(A0)^micros()); startupAnimation();
}

void loop(){
 if(digitalRead(buttonPin)==LOW){
  delay(30);
  if(digitalRead(buttonPin)==LOW){
   unsigned long start=millis(); int rollTime=random(700,1300);
   while(millis()-start<rollTime){ showNumber(random(1,7)); delay(random(60,140)); }
   showNumber(random(1,7));
   while(digitalRead(buttonPin)==LOW) delay(10);
   delay(random(100,300));
  }
 }
}
