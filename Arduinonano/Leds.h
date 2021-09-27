#ifndef Leds_h
#define Leds_h

void setup();
void PrenderLed();
int timer(unsigned long interval);
void led(int tipo);
void bOnCallback(void *ptr);
void bOffCallback(void *ptr);

#endif
