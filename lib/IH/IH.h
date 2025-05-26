#include <Arduino.h>

enum IH_BUTTON {
  POWER,
  HEAT,
  UP,
  DOWN,
  BOIL,
  SPEED
};

class IH {
  public:
    void init();

    void power();
    void heat();
    void up();
    void down();
    void boil();
    void speed();
  private:
    void push(uint8_t i);
    const uint8_t pins[6] = {8, 4, 2, 12, 6, 10};
};