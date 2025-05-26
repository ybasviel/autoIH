#include <Arduino.h>

#define RCV_BUFF_LEN 1

uint8_t button;

const uint8_t pins[6] = {8, 4, 2, 12, 6, 10};

enum BUTTON_CONF {
  POWER,
  HEAT,
  UP,
  DOWN,
  BOIL,
  SPEED
};

void push(uint8_t i){
  digitalWrite(pins[i], HIGH);
  delay(500);
  digitalWrite(pins[i], LOW);
}

void buttonCtrl(){
  switch(button){
    case '0':
      push(BUTTON_CONF::POWER);
      break;
    case '1':
      push(BUTTON_CONF::HEAT);
      break;
    case '2':
      push(BUTTON_CONF::UP); 
      break;
    case '3':
      push(BUTTON_CONF::DOWN); 
      break;
    case '4':
      push(BUTTON_CONF::BOIL);
      break;
    case '5':
      push(BUTTON_CONF::SPEED);
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

  for(uint8_t i = 0; i < 6; i++){
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], LOW);
  }

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


