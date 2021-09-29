#ifndef Leds_h
#define Leds_h

#define LED1 2
#define LED2 4





void setup();
void PrenderLed();
int timer(unsigned long interval);
void led(int tipo);
void bOnCallback(void *ptr);
void bOffCallback(void *ptr);
void bnextCallback(void *ptr);
void b0Callback(void *ptr);


#endif
