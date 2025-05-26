#include <Arduino.h>
#include "IH.h"

#define RCV_BUFF_LEN 1

uint8_t button;

IH ih;

void buttonCtrl(){
  switch(button){
    case '0':
      ih.power();
      break;
    case '1':
      ih.heat();
      break;
    case '2':
      ih.up(); 
      break;
    case '3':
      ih.down(); 
      break;
    case '4':
      ih.boil();
      break;
    case '5':
      ih.speed();
      break;
    default:
      break;
  }
}

void showPrompt(){
  Serial.println("0:power, 1:heat, 2:up, 3:down, 4:boil, 5:speed");
  Serial.print(">");
}

void setup() {
  Serial.begin(115200);
  ih.init();
  
  showPrompt();
}

void loop() {
  if (Serial.available()) {
    button = Serial.read();

    Serial.println(button-48);

    buttonCtrl();

    showPrompt();
  }
}


