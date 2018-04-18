
// Individual Motor related functions, ect.
// 
// 

/*-----( Import needed stuff )-----*/
#include "IR.h"

/*-----(       Settings         )-----*/
#define	RESET_TICKS	40	//<-Confirm TODO
#define FLASH_MS 150

/*-----(     Class Methods      )-----*/
IR::IR(
	const uint8_t  sensorPin,			//IR sensor pin conection
	const uint8_t  supplyPin,			//IR sensor vcc conection
	const uint8_t  LedOutputPin,		//LED pin conection
	const bool	   autoRestart,			//TRUE/FALSE restart required when reading
	const uint16_t counterLimit,		//
	const uint8_t  counterIncrement,	//
	const uint16_t DetectThreshold,		//
	const uint16_t NotDetectThreshold	//
) :
	SENSOR_PIN(sensorPin),
	SUPPLY_PIN(supplyPin),
	LED_OUTPUT_PIN(LedOutputPin),
	AUTO_RESTART(autoRestart),
	COUNTER_LIMIT(counterLimit),
	COUNTER_INCREMENT(counterIncrement),
	DETECT_THRESHOLD(DetectThreshold),
	NOT_DETECT_THRESHOLD(NotDetectThreshold)
{
	pinMode(SENSOR_PIN, INPUT);
	pinMode(SUPPLY_PIN, OUTPUT);
	pinMode(LED_OUTPUT_PIN, OUTPUT);
	digitalWrite(SUPPLY_PIN, HIGH);
	
	if (AUTO_RESTART)
	{
		status = RESET_ON;
	}
	else
	{
		status = OK;
	}
	
}

void IR::tick()
{
	switch (status)
	{

	case OK://Read sensor and update output/led
		
		prevBallDetected = ballDetected;

		// adjust high speed counter
		if (digitalRead(SENSOR_PIN) == LOW) //when the IR is receiving something
		{
			Counter += (Counter < COUNTER_LIMIT ? COUNTER_INCREMENT : 0);//add to counter up to limit
		}
		else //IR == HIGH ==> IR not seing anything
		{
			resetCounter++;
			Counter -= (Counter > 0);//If IR is off then -1 (if counter > than 0)
		}

		//Determine if we are realiably seeing, or not seeing the ball
		if (Counter > DETECT_THRESHOLD) {
			ballDetected = true;
		}
		if (Counter < NOT_DETECT_THRESHOLD) {
			ballDetected = false;
		}

		//update LED when ball detected changes
		if (ballDetected != prevBallDetected)//if ball detected has changed up date the LED
		{
			digitalWrite(LED_OUTPUT_PIN, ballDetected);//turn LED on/off
		}

		// Reset the IR Sensor periodicly
		if (resetCounter > (COUNTER_LIMIT + 100)) {
			resetCounter = 0;
			status = RESET_OFF;
		}break;


	case RESET_OFF:
		// Reset the IR Sensor by turning it off
		digitalWrite(SUPPLY_PIN, LOW);
		delayMicroseconds(1000);//TODO replace with tick counter
		status = RESET_ON;
		break;


	case RESET_ON:
		// Restart the IR Sensor by turning it on
		digitalWrite(SUPPLY_PIN, HIGH);
		delayMicroseconds(1000);//TODO replace with tick counter
		status = OK;
		break;
	
	
	case NOT_SET:
	default:
		digitalWrite(LED_OUTPUT_PIN, HIGH);
		Serial.println("ERROR: IR tick (case NOT_SET:)");
		delay(10000);
		digitalWrite(LED_OUTPUT_PIN, LOW);
		break;
	}
}

void IR::flash()
{
	digitalWrite(LED_OUTPUT_PIN, HIGH);
	delay(FLASH_MS);
	digitalWrite(LED_OUTPUT_PIN, LOW);
}
