
/* 
This program drives a stepper motor with a small photoresistor attached to it. The stepper motor rotates the photoresistor
around, while readings of light intensity are averaged and sent to the serial port.
 
 */

#include <Stepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution for the motor
const int sensorPin = 0 ;                                     

// initialize the stepper library 
Stepper myStepper(stepsPerRevolution, 4,5,6,7);            

int stepCount = 0;         // number of steps the motor has taken
float lightVal[3];
float avglightVal = 0;


void setup() {
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one step forward
  myStepper.step(1);
  delay(50);
  
  // Calculate average of 3 light readings 25 milliseconds apart
  lightVal[1] = analogRead(sensorPin);
    delay(25);
    lightVal[2] = analogRead(sensorPin);
    delay(25);
    lightVal[3] = analogRead(sensorPin);
    avglightVal = ((lightVal[1]+lightVal[2]+lightVal[3])/3);
  
  
 // Serial.print("steps:" );
  Serial.print(stepCount);
  Serial.print("      ");
  Serial.println(avglightVal);
 
  stepCount++;
}

