// IR.h

#ifndef _IR_h
#define _IR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

enum SENSOR_LOCATION
{
	LOCATION_NOT_SET,
	FRONT_RIGHT,
	FRONT_LEFT,
	LEFT,
	LEFT_BACK,
	BACK,
	RIGHT_BACK,
	RIGHT,
};

class IR {

private:
	const uint8_t _SENSOR_PIN;			//IR sensor pin conection
	const uint8_t _SUPPLY_PIN;			//IR sensor vcc conection
	const uint8_t _LED_PIN;				//LED pin conection
	const uint8_t _RESTART;				//TRUE/FALSE restart required when reading
	const SENSOR_LOCATION _LOCATION;	//Location of sensor on robot
	
	unsigned int Counter = 0;			//todo
	long notSeenCounter = 0;			//todo
	bool ballDetected = false;			//todo
	bool prevballDetected = false;		//todo

protected:

public:
	IR(const uint8_t _SENSOR_PIN, const uint8_t _SUPPLY_PIN, const uint8_t _LED_PIN, const uint8_t _RESTART, SENSOR_LOCATION _LOCATION);//constructor
	void reStart();
	void read();
};
#endif