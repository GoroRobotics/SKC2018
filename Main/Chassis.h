// Chassis.h

#ifndef _CHASSIS_h
#define _CHASSIS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class Chassis
{
private:
	int _direction;		//current Chassis digital direction value, range(-180, +180)
	int _power = 100;			//cureent Chassis digital power value, range(0, +255)

protected:


public:
	 Chassis();
	 static void interactive(void * _this);
	 void setDirection(int direction);
	 void setPower(int power);
};
#endif

