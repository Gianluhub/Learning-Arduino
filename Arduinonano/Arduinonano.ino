#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "Leds.h"


void setup();

void loop() {
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,LOW);
  delay(1000);
  digitalWrite(LED2,HIGH);
  digitalWrite(LED1,LOW);
  delay(1000);

}
