/* This code is for a 6-cup beer pong table, using photoresisitors underneath the cups to tell
when a cup has been hit or not. The outcome of this then determines the score on LCD screens 
for each team and which LEDs will be turned on.

LED Pins: 30-41 inclusive (digital out)
Photocell Pins: A0-A11 inclusive (analog in)

*/


int timer = 300;   // The higher the number, the slower the timing.
int LightThresh = 600;  // Voltage threshold (mV) for the photoresistors

// Initialize LED and Photoresistor pins on the arduino board
int BledPins[] = {30, 31, 32, 33, 34, 35};       
int RledPins[] = {36, 37, 38, 39, 40, 41};
int ledCount = 6;       
int BphotoPins[] = {0, 1, 2, 3, 4, 5};
int RphotoPins[] = {6, 7, 8, 9, 10, 11};
int BphotocellReading[] = {0, 0, 0, 0, 0, 0};
int RphotocellReading[] = {0, 0, 0, 0, 0, 0};
int Bscore[] = {0,0,0,0,0,0};  // Score set to zero
int Rscore[] = {0,0,0,0,0,0};


#include <LiquidCrystal.h>      // include the library code
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd1(44, 45, 46, 47, 48, 49);  
LiquidCrystal lcd2(44, 50, 46, 47, 48, 49); 


void setup() {
  // the array elements are numbered from 0 to (pinCount - 1).
  // use a for loop to initialize each pin as an output or an input:
  lcd1.begin(16, 2);
  lcd2.begin(16, 2);
 
  lcd1.print("Blue Team");
  lcd2.print("Red Team");
  
  
  for (int thisPin = 0; thisPin < ledCount; thisPin++)  {
    pinMode(BledPins[thisPin], OUTPUT);
    pinMode(RledPins[thisPin], OUTPUT);
  }
  
  for (int thisPin = 0; thisPin < ledCount; thisPin++)  {
    pinMode(BphotoPins[thisPin], INPUT);
    pinMode(RphotoPins[thisPin], INPUT);    
  }
  
}



void loop() {
  delay(timer);
  
  // Read the analog voltage values from the photoresistors (proportional to the amount of light)
  for (int thisPin = 0; thisPin < ledCount; thisPin++) {
  BphotocellReading[thisPin] = analogRead(BphotoPins[thisPin]);
  RphotocellReading[thisPin] = analogRead(RphotoPins[thisPin]);
  }  
  
  // loop from the lowest pin to the highest:
  for (int thisPin = 0; thisPin < ledCount; thisPin++) { 
    // turn the pin on:
   Bscore[thisPin]=0;
   Rscore[thisPin]=0;
    if (BphotocellReading[thisPin] > LightThresh)
   { 
    Rscore[thisPin]=Rscore[thisPin]+1;
    digitalWrite(BledPins[thisPin], LOW);               
    // turn the pin off:
   }
 else 
 {
    digitalWrite(BledPins[thisPin], HIGH);    
 }


if (RphotocellReading[thisPin] > LightThresh)
   { 
    Bscore[thisPin]=Bscore[thisPin]+1;
    digitalWrite(RledPins[thisPin], LOW);                  
    // turn the pin off:
   }
 else 
 {
    digitalWrite(RledPins[thisPin], HIGH);    
 }

  }

lcd1.setCursor(0, 1);
lcd2.setCursor(0,1);

lcd1.print(Bscore[0]+Bscore[1]+Bscore[2]+Bscore[3]+Bscore[4]+Bscore[5]);
lcd2.print(Rscore[0]+Rscore[1]+Rscore[2]+Rscore[3]+Rscore[4]+Rscore[5]);


}
