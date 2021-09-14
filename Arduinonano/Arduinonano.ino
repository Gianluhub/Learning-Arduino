#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "Leds.h"


const unsigned long intervalo = 1000;
unsigned long tiempoprevio = 0;




void loop() {
  
  unsigned long currentTime = millis();

  //PrenderLed();
  delay(1000);
  if (currentTime - previousTime >= interval)
  {
    led(1);
    previousTime = currentTime;

  }

  if (timer(2000)) 
  {
    serial.println("True\n");
    led(2);
  }
  else serial.println('false\n');


}
