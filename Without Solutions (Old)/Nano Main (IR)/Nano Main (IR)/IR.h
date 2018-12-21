// IR.h

#ifndef _IR_h
#define _IR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

//enum SENSOR_LOCATION
//{
//	LOCATION_NOT_SET,
//	FRONT_RIGHT,
//	FRONT_LEFT,
//	LEFT,
//	LEFT_BACK,
//	BACK,
//	RIGHT_BACK,
//	RIGHT,
//};

enum IR_STATUS
{
	NOT_SET,
	OK,
	RESET_OFF,
	RESET_ON
};

class IR {

private:
	
	const uint8_t SENSOR_PIN;			//IR sensor pin conection
	const uint8_t SUPPLY_PIN;			//IR sensor vcc conection
	const uint8_t LED_OUTPUT_PIN;		//LED pin/output to mega pin conection
	const bool    AUTO_RESTART;			//TRUE/FALSE restart required when reading
	const uint8_t COUNTER_LIMIT;		//
	const uint8_t COUNTER_INCREMENT;	//
	const uint8_t DETECT_THRESHOLD;		//
	const uint8_t NOT_DETECT_THRESHOLD;	//
	
	unsigned int resetTickCounter = 0;
	unsigned int Counter = 0;
	long resetCounter = 0;
	bool prevBallDetected = false;
	
	IR_STATUS status;

protected:

public:
	
	bool ballDetected = false;
	
	IR( const uint8_t  sensorPin,			//IR sensor pin conection
		const uint8_t  supplyPin,			//IR sensor vcc conection
		const uint8_t  LedOutputPin,		//LED pin conection
		const bool	   autoRestart,			//TRUE/FALSE restart required when reading
		const uint16_t counterLimit,		//
		const uint8_t  counterIncrement,	//
		const uint16_t DetectThreshold,		//
		const uint16_t NotDetectThreshold	//
		);

	void tick();
	IR_STATUS tick(IR_STATUS sharedStatus);
	void flash();

};
#endif