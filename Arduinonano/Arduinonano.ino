#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <Nextion.h>
#include "Leds.h"

char buffer[20] = {0};
char trama[18] = {0};
int temperatura[2] = {0};

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
  //String data;
  memset(buffer, 0, sizeof(buffer));  // Clear the buffer, so we can start using it
  bNext.getText(buffer, sizeof(buffer));
  Serial.println(buffer);
  desentramado(trama,temperatura);
  Serial.println(trama);
  Serial.println(temperatura[0]);
  Serial.println(temperatura[1]);
  
}


void b0Callback(void *ptr){
  //String data;
  memset(buffer, 0, sizeof(buffer));  // Clear the buffer, so we can start using it
  b0.getText(buffer, sizeof(buffer));
  Serial.println(buffer);
  desentramado(trama,temperatura);
  Serial.println(trama);
  Serial.println(temperatura[0]);
  Serial.println(temperatura[1]);
}

void desentramado(char trama[],int temperatura[]){
  int i = 0;
  int j = 0;
  int k = 0;
  //char trama[18] = {0};
  char aux[4] = {0};
  //int temperatura[2] = {0};
  
  // Extrae los datos hasta que se lea el caracter de fin 'X'
  do
  {
    // Revisa si hay un dato nuevo que tomar
    if(buffer[i] == '+')
    {
      trama[j] = buffer[i+1]; // Toma el dato siguiente
      i+=2;                   // Incrementa en dos para saltar al siguiente dato a extraer


      // Verifica si es necesario extraer un valor de temperatura
      if (buffer[i] == '-')
      {
        i++;                  // Incrementa al siguiente dato a extraer

        // Guarda los valores hasta que se lea el caracter de fin '-'
        do
        {
          aux[k] = buffer[i];
          k++;
          i++;
        }while(buffer[i]!='-');

        // Si la temperatura pertenece a la del poliester guarda ese valor en la posicion 0 del array
        if(trama[j] == 'D') temperatura[0] = String(aux).toInt();  // Convierte los caracteres a un entero y se guarda

        // Si la temperatura pertenece a la del algodon guarda ese valor en la posicion 1 del array
        if(trama[j] == 'E') temperatura[1] = String(aux).toInt();  // Convierte los caracteres a un entero y se guarda

        memset(aux, 0, sizeof(aux));  // Limpia el auxiliar para la siguiente interacion
        k = 0;                        // Reinicia el indice del auxiliar
        i++;                          // Incrementa la trama al siguiente dato a leer
      }

      j++;                          // Incrementa la posicion del array trama

    }
    
  }while(buffer[i]!='X');
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
