#include <Arduino.h>
#include <Nextion.h>
#include "Leds.h"


extern NexButton bOn;
extern NexButton bOff;
extern NexText tState;
extern NexButton b0;
extern NexButton bNext;
extern NexTouch *nex_listen_list[];
extern char buffer[100];

void setup() {
Serial2.begin(9600);
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);
nexInit();

bOn.attachPop(bOnCallback, &bOn);
bOff.attachPop(bOffCallback, &bOff);
bNext.attachPop(bnextCallback,&bNext);
b0.attachPop(b0Callback,&b0);

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

void LED (int estado){

 
  switch (estado)
  {
    case 1:
      digitalWrite(LED1,HIGH);
      Serial.println("\nEncendido");
    break;

    case 2:
      digitalWrite(LED1,LOW);
      Serial.println("\nApagado");

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
