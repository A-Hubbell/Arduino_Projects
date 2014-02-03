
//This code currently works for the black photodiode, one channel only.

int photoDiode = 7;
int LED = 2;

void setup ()

{
  
  pinMode (photoDiode, INPUT);
  pinMode (LED, OUTPUT);
  digitalWrite(LED, HIGH);
  digitalWrite(photoDiode, LOW);
  delay(3000);
  
}

void loop ()

{ 
  if (digitalRead(photoDiode) == HIGH)
  {
    digitalWrite(LED, LOW);
  }
  
//  if (digitalRead(photoDiode)==HIGH)
//  {
//    digitalWrite(LED, LOW);
//  }
}


