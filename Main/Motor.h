// Motor.h

#ifndef _MOTOR_h
#define _MOTOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
enum DIRECTION
{
	DIRECTION_NOT_SET,
	CLOCKWISE,
	COUNTER_CLOCKWISE
};

enum MOTOR_UNIT
{
	MOTOR_NOT_SET,
	MOTOR_LEFT,
	MOTOR_RIGHT,
	MOTOR_BACK
};


class Motor {

private:
	const uint8_t _EN_PIN;	//Enables board
	const uint8_t _CS_PIN;	//Current Sensor
	const uint8_t _INA_PIN;	//Direction Pin A
	const uint8_t _INB_PIN;	//Direction Pin B
	const uint8_t _PWM_PIN;	//PWM Pin sets power
	const MOTOR_UNIT _unit; 
	
	DIRECTION direction = DIRECTION_NOT_SET;
	int _power;		//current motor digital power value, range -128 - 127
	int _current;	//current motor current

protected:

public:
	Motor(MOTOR_UNIT _unit, const uint8_t EN_PIN, const uint8_t CS_PIN, const uint8_t INA_PIN, const uint8_t INB_PIN, const uint8_t PWM_PIN);//constructor
	static void diagnostics(void * _this);
	void start();
	void stop();
	void disableMotor();
	void setPower(int power);
};

#endif