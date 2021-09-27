#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <Nextion.h>
#include "Leds.h"

const unsigned long intervalo = 1000;
unsigned long tiempoprevio = 0;




void loop() {
  
  unsigned long currentTime = millis();

  //PrenderLed();
  //delay(1000);
  if (currentTime - tiempoprevio >= intervalo)
  {
    led(1);
    tiempoprevio = currentTime;

  }

  if (timer(1000)) 
  {
    //Serial.println("True\n");
    led(2);
  }


}
