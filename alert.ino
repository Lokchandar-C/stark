void setup() {

}

void loop() {

}#include <Esplora.h>

void setup()
{
  Serial.begin(9600);  
  pinMode(A4,INPUT);
  pinMode(A3,INPUT);
  pinMode(A1,INPUT);      
}

void loop()
{
  long int xa = analogRead(A4);   
  long int ya = analogRead(A3);  
  long int za = analogRead(A1);
  float at = sqrt(xa*xa + ya*ya + za*za);      
  Serial.print(xa);
  Serial.print('\t');
  Serial.print(ya);
  Serial.print('\t');
  Serial.print(za);
  Serial.print('\t');
  Serial.print(at);
  Serial.println();  
    
    if (at < 50) {
        digitalWrite(2,HIGH);
    }
    else {
        digitalWrite(2,LOW);
    }


  delay(10);         
}
