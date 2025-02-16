#include "pumps.h"

const int pump1_pin = 21;  // H2O2
const int pump2_pin = 22;  // Acetone
const int pump3_pin = 23;  // BCA
const int pump4_pin = 39;  // Buffer
const int pump5_pin = 38;  // Distilled water

// Total delay: 33 seconds
const int pump1_delay = 6600;
const int pump2_delay = 3300;
const int pump3_delay = 9800;
const int pump4_delay = 10'000;
const int pump5_delay = 3300;

void Pumps::setup() {
  pinMode(pump1_pin, OUTPUT);
  pinMode(pump2_pin, OUTPUT);
  pinMode(pump3_pin, OUTPUT);
  pinMode(pump4_pin, OUTPUT);
  pinMode(pump5_pin, OUTPUT);
  turnOff();
}

void Pumps::turnOn() {
  digitalWrite(pump1_pin, HIGH);
  digitalWrite(pump2_pin, HIGH);
  digitalWrite(pump3_pin, HIGH);
  digitalWrite(pump4_pin, HIGH);
  digitalWrite(pump5_pin, HIGH);
}

void Pumps::turnOff() {
  digitalWrite(pump1_pin, LOW);
  digitalWrite(pump2_pin, LOW);
  digitalWrite(pump3_pin, LOW);
  digitalWrite(pump4_pin, LOW);
  digitalWrite(pump5_pin, LOW);
}

void Pumps::handleCommand(ScienceCommand command) { 
  if (command.pumps == PumpState_PUMP_ON) {
    turnOn();
  } else if (command.pumps == PumpState_PUMP_OFF) {
    turnOff();
  } else if (command.pumps == PumpState_FILL) {
    fillTubes();
  }
}

void Pumps::fillTubes() {
  Serial.println("Pouring pump 1");
  digitalWrite(pump1_pin, HIGH);
  delay(pump1_delay);
  digitalWrite(pump1_pin, LOW);

  Serial.println("Pouring pump 2");
  digitalWrite(pump2_pin, HIGH);
  delay(pump2_delay);
  digitalWrite(pump2_pin, LOW);

  Serial.println("Pouring pump 3");
  digitalWrite(pump3_pin, HIGH);
  delay(pump3_delay);
  digitalWrite(pump3_pin, LOW);

  Serial.println("Pouring pump 4");
  digitalWrite(pump4_pin, HIGH);
  delay(pump4_delay);
  digitalWrite(pump4_pin, LOW);

  Serial.println("Pouring pump 5");
  digitalWrite(pump5_pin, HIGH);
  delay(pump5_delay);
  digitalWrite(pump5_pin, LOW);

  turnOff();
}
