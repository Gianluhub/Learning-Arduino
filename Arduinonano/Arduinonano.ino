#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <Nextion.h>
#include "Leds.h"

char buffer[100] = {0};

const unsigned long intervalo = 1000;
unsigned long tiempoprevio = 0;

NexButton b0=NexButton(2,10,"b0");
NexButton bNext=NexButton(2,7,"bNext");

NexButton bOn= NexButton(0,5,"bOn");
NexButton bOff= NexButton(0,6,"bOff");
NexText tState= NexText(0,4,"tState");
NexTouch *nex_listen_list[] = {
  &bOn,
  &bOff,
  &b0,
  &bNext,
  NULL
};


void bOnCallback(void *ptr){
  tState.setText ("Led on");
  digitalWrite(LED1,HIGH);
  Serial.print("Led on");
}

void bOffCallback(void *ptr){
  tState.setText ("Led off");
  digitalWrite(LED1,LOW);
  Serial.print("Led off");
}

void bnextCallback(void *ptr){
  String data;
  memset(buffer, 0, sizeof(buffer));  // Clear the buffer, so we can start using it
 data= bNext.getText(buffer, sizeof(buffer));
  Serial.println(data);
  
}


void b0Callback(void *ptr){
  String data;
  memset(buffer, 0, sizeof(buffer));  // Clear the buffer, so we can start using it
  data = b0.getText(buffer, sizeof(buffer));
  Serial.println(data);
  
}




void loop() {
  
//  unsigned long currentTime = millis();
//
//  //PrenderLed();
//  //delay(1000);
//  if (currentTime - tiempoprevio >= intervalo)
//  {
//    led(1);
//    tiempoprevio = currentTime;
//
//  }
//
//  if (timer(1000)) 
//  {
//    //Serial.println("True\n");
//    led(2);
//  }

nexLoop(nex_listen_list);
}
