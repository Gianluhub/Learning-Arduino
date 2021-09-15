#include <Arduino.h>
#include "Leds.h"

#define LED1 6
#define LED2 4

void setup() {
Serial.begin(9600);
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);

}


void PrenderLed(){

  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,LOW);
  delay(1000);
  digitalWrite(LED2,HIGH);
  digitalWrite(LED1,LOW);
  delay(1000);
  digitalWrite(LED2,HIGH);
  digitalWrite(LED1,HIGH);
}


void led (int tipo){

 
  switch (tipo)
  {
    case 1:
      digitalWrite(LED1,!digitalRead(LED1));
      Serial.println("\nEstado Led 1:");
      Serial.println(digitalRead(LED1));
    break;

    case 2:
      digitalWrite(LED2,!digitalRead(LED2));
      Serial.println("\nEstado Led 2:");
      Serial.println(digitalRead(LED2));
    break;  
  }
}

int timer(unsigned long interval){

  unsigned long currentTime = millis();
  static unsigned long previousTime = millis();
  static int flag = 0;

  if (flag == 1)
  { 
    previousTime = millis();
    flag = 0;
  }


  if (currentTime - previousTime >= interval)
  {
    flag = 1;
    return true;
  }
  else return false;


}
