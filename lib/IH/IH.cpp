#include "IH.h"

void IH::init(){
  for(uint8_t i = 0; i < 6; i++){
    pinMode(this->pins[i], OUTPUT);
    digitalWrite(this->pins[i], LOW);
  }
}

void IH::power(){
  push(IH_BUTTON::POWER);
}

void IH::heat(){
  push(IH_BUTTON::HEAT);
}

void IH::up(){
  push(IH_BUTTON::UP);
}

void IH::down(){
  push(IH_BUTTON::DOWN);
}

void IH::boil(){
  push(IH_BUTTON::BOIL);
}

void IH::speed(){
  push(IH_BUTTON::SPEED);
}

void IH::push(uint8_t i){
  digitalWrite(this->pins[i], HIGH);
  delay(500);
  digitalWrite(this->pins[i], LOW);
}
