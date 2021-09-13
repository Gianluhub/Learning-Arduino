#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "Leds.h"


const unsigned long interval = 1000;
unsigned long previousTime = 0;




void loop() {
  
  unsigned long currentTime = millis();

  //PrenderLed();

  if (currentTime - previousTime >= interval)
  {
    led(1);

  }




}
