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

  Serial.println("Activado\n")
  switch (tipo)
  {
    case 1:
      digitalWrite(LED1,!digitalRead(LED1));
      Serial.println("Estado Led 1: %d \n",digitalRead(LED1));
    break;

    case 2:
      digitalWrite(LED2,!digitalRead(LED2));
      Serial.println("Estado Led 2 : %d \n",digitalRead(LED2));
    break;  
  }
}

int timer(unsigned long interval){
  static unsigned long previousTime = millis();
  unsigned long currentTime = millis();

  if (currentTime - previousTime >= interval)
  {
    previousTime = currentTime;
    return true;
  }
  else return false;


}