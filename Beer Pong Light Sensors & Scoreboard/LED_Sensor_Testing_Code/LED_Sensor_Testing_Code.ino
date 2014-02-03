/* This code is for a 6 cup beer pong table, using photoresisitors underneath the cups to tell
when a cup has been hit or not. The outcome of this then determines the score on an LCD screen
and which LEDs will be turned on.

LED Pins: 30-41 inclusive (digital out)
Photocell Pins: A0-A11 inclusive (analog in)

*/


int timer = 100;           // The higher the number, the slower the timing.
int ledPins[] = {30, 31, 32, 33};       // an array of pin numbers to which LEDs are attached
int ledCount = 4;           // the number of pins (i.e. the length of the array)
int photoPins[] = {0, 1, 2, 3};
//int photoCount = 12;
int photocellReading[] = {0, 0, 0, 0};

void setup() {
  // the array elements are numbered from 0 to (pinCount - 1).
  // use a for loop to initialize each pin as an output:
  for (int thisPin = 0; thisPin < ledCount; thisPin++)  {
    pinMode(ledPins[thisPin], OUTPUT);      
  }
  
  for (int thisPin = 0; thisPin < ledCount; thisPin++)  {
    pinMode(photoPins[thisPin], INPUT);      
  }
  
}

void loop() {
  for (int thisPin = 0; thisPin < ledCount; thisPin++) {
  photocellReading[thisPin] = analogRead(photoPins[thisPin]);
  delay(timer);
  }  
  
  // loop from the lowest pin to the highest:
  for (int thisPin = 0; thisPin < ledCount; thisPin++) { 
    // turn the pin on:
    if (photocellReading[thisPin] > 500)
   { 
    digitalWrite(ledPins[thisPin], HIGH);   
    delay(timer);                  
    // turn the pin off:
   }
 else 
 {
    digitalWrite(ledPins[thisPin], LOW);    
 }

  }

}












//int photocellPin = 0;     // the cell and 10K pulldown are connected to a0
//int photocellReading;     // the analog reading from the sensor divider
//int LEDpin = 11;          // connect Red LED to pin 11 (PWM pin)
//int LEDbrightness;        // 
//void setup(void) {
//  // We'll send debugging information via the Serial monitor
//  Serial.begin(9600);   
//}
// 
//void loop(void) {
//  photocellReading = analogRead(photocellPin);  
// 
//  Serial.print("Analog reading = ");
//  Serial.println(photocellReading);     // the raw analog reading
// 
//  // LED gets brighter the darker it is at the sensor
//  // that means we have to -invert- the reading from 0-1023 back to 1023-0
//  photocellReading = 1023 - photocellReading;
//  //now we have to map 0-1023 to 0-255 since thats the range analogWrite uses
//  LEDbrightness = map(photocellReading, 0, 1023, 0, 255);
//  analogWrite(LEDpin, LEDbrightness);
// 
//  delay(100);
//}

