#include  <Arduino.h>

#include "../science.pb.h"

class Pumps {
  public:
    void setup();
    void turnOn();
    void turnOff();
    void handleCommand(ScienceCommand command);
    void fillTubes();
};
