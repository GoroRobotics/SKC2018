
// Idividual Motor related functions, ect.
// 
// 


/*-----( Import needed stuff )-----*/
#include "IR.h"

/*-----(       Settings         )-----*/
#define COUNTER_MAX			700
#define COUNTER_ADDITION	6
//#define COUNTER_THRESHOLD	200
#define COUNTER_SEEING_THRESHOLD	600
#define COUNTER_NOT_SEEING_THRESHOLD	100

/*-----(     Class Methods      )-----*/
IR::IR(
	const uint8_t SENSOR_PIN,			//IR sensor pin conection
	const uint8_t SUPPLY_PIN,			//IR sensor vcc conection
	const uint8_t LED_PIN,				//LED pin conection
	const uint8_t RESTART,				//TRUE/FALSE restart required when reading
	const SENSOR_LOCATION LOCATION		//Location of sensor on robot
) :
	_SENSOR_PIN(SENSOR_PIN),
	_SUPPLY_PIN(SUPPLY_PIN),
	_LED_PIN(LED_PIN),
	_RESTART(RESTART),
	_LOCATION(LOCATION)
{
	pinMode(SENSOR_PIN, INPUT);
	pinMode(SUPPLY_PIN, INPUT);
	pinMode(LED_PIN, OUTPUT);
}


void IR::reStart()
{
}

void IR::read()
{
}
