#pragma once

#include "src/tmc/BURT_TMC.h"
#include "src/scooper/scooper.h"

// -------------------- Pinouts --------------------

// Pump 1: <LABEL WITH CHEMICAL>
// HIGH = ON, LOW = OFF
#define PUMP1 21  // NOT PWM
#define PUMP2 22
#define PUMP3 23
#define PUMP4 0  // Avoid? On Serial1
#define PUMP5 25
#define PUMP6 27  // Avoid? On SPI 1
#define PUMP7 1  // Avoid? On Serial1

// Temp/Humidity: SDA 18, SCL 19, I2C 1
#define CO2_PIN  17 // On I2C 1

#define SERVO1 38  // Methane sensor connector, on SPI 1
#define SCOOP_SERVO 39  // pH sensor connector, SPI 1

#define LIMIT1 34
#define LIMIT2 35
#define LIMIT3 29
#define LIMIT4 28

// CS: 3, 4, 5, 6
// EN: 8, 9, 10, 7

//Stepper Motor Constants (taken from arm code, double check)
#define ACCEL 0x00030d4d //200013 (unclear what units but this is the decimal version)
#define SPEED 0x000327e7 //206823 (unclear what units but this is the decimal version)

// --------------- Motor definitions ---------------

///Stepper1 on PCB (IC3)
StepperMotorPins vacuumLinearPins = {
	chipSelect: 6, 
	enable: 7, 
};
StepperMotorConfig vacuumLinearConfig = {
	name: "vacuumLinear", 
	unitName: "Steps",
	current: 250, 
	speed: SPEED / 25,
	accel: ACCEL, 
	isPositive: true, 
	toUnits: 1.0,
	toSteps: 1.0,
};

LimitSwitch vacuumLimit;
// 	pin: 24, 
// 	triggeredValue: HIGH,
// 	direction: 1,
// 	position: 0,
// };

StepperMotor vacuumLinear(vacuumLinearPins, vacuumLinearConfig, vacuumLimit);

///Stepper2 on PCB (IC5)
StepperMotorPins dirtLinearPins = {
	chipSelect: 5, 
	enable: 10, 
};
StepperMotorConfig dirtLinearConfig = {
	name: "dirtLinear", 
	unitName: "Steps",
	current: 250, 
	speed: SPEED / 2, 
	accel: ACCEL, 
	isPositive: true, 
	toUnits: 1.0,
	toSteps: 1.0,
};

LimitSwitch dirtLinearLimit;
// 	pin: 2, 
// 	triggeredValue: HIGH,
// 	direction: 1,
// 	position: 0,
// };

StepperMotor dirtLinear(dirtLinearPins, dirtLinearConfig, dirtLinearLimit);

///Stepper3 on PCB (IC4) -- dirt-carousel
StepperMotorPins scoopArmPins = {
	chipSelect: 4, 
	enable: 9, 
};
StepperMotorConfig scoopArmConfig = {
	name: "scienceLinear", 
	unitName: "Steps",
	current: 400,
	speed: SPEED / 5, 
	accel: ACCEL,
	isPositive: true, 
	toUnits: 1.0,
	toSteps: 1.0,
};

LimitSwitch scoopArmLimit;
// 	pin: 32, 
// 	triggeredValue: HIGH,
// 	direction: -1,
// 	position: 0,
// };

StepperMotor scoopArmMotor(scoopArmPins, scoopArmConfig, scoopArmLimit);

///Stepper4 on PCB (IC2) -- Scooper
StepperMotorPins dirtCarouselPins = {
	chipSelect: 3, 
	enable: 8, 
};
StepperMotorConfig dirtCarouselConfig = {
	name: "dirtCarousel", 
	unitName: "Steps",
	current: 250, 
	speed: SPEED / 20, //changed values came from testing
	accel: ACCEL, 
	isPositive: true, 
	toUnits: 1.0,
	toSteps: 1.0,
};

LimitSwitch dirtCarouselLimit;
// 	pin: 0, 
// 	triggeredValue: HIGH,
// 	direction: 1,
// 	position: 0,
// };

StepperMotor dirtCarousel(dirtCarouselPins, dirtCarouselConfig, dirtCarouselLimit);

Scooper scooper(scoopArmMotor, SCOOP_SERVO);
