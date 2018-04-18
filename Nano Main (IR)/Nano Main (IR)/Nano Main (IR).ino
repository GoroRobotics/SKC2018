/*
 Name:		Nano_Main_IR.ino
 Created:	April 2018 for RoboCup
 Author:	Christopher Dirks
*/

#include "IR.h"

//Characteristics
//#define COUNTER_MAX						700
//#define COUNTER_ADDITION				6
//#define COUNTER_SEEING_THRESHOLD		600
//#define COUNTER_NOT_SEEING_THRESHOLD	100

//#define LED				44	//testing
//#define IR				A0	//testing
//#define IR_SUPPLY		A1	//testing

//LEDs
//#define LED_FRONT_RIGHT 13
//#define LED_FRONT_LEFT	A1
//#define LED_LEFT		A0
//#define LED_LEFT_BACK	9 
//#define LED_BACK		10
//#define LED_RIGHT_BACK	11
//#define LED_RIGHT		12

//IRs 
//#define IR_FRONT_RIGHT	A3	
//#define IR_FRONT_LEFT	A2	
//#define IR_LEFT			5	
//#define IR_LEFT_BACK	6	
//#define IR_BACK			7	//intermitant
//#define IR_RIGHT_BACK	8	//intermitant
//#define IR_RIGHT		A4	//intermitant

//IR Supply
//#define IR_VCC_FRONT_RIGHT	2
//#define IR_VCC_FRONT_LEFT	1
//#define IR_VCC_LEFT			0
//#define IR_VCC_RIGHT		3
//#define IR_VCC_BACK			4

/*
//Counter		
unsigned int FrontRightCounter	= 0;

//not seen counter
long notSeenFrontRightCounter	= 0;

long notSeenCounter = 0;

//Booleans
bool FrontRightDetected	= false;	bool prevFrontRightDetected		= false;
*/

//create instaces of IR sensors
// Name,	 sensorPin, supplyPin, LedOutputPin, autoRestart, counterLimit, counterIncrement, DetectThreshold, NotDetectThreshold
IR frontRight(A3,       2,         13,           false,       700,          6,                600,             100               );
IR frontLeft (A2,       1,         A1,           false,       700,          6,                600,             100               );
IR left      (5,        0,         A0,           false,       700,          6,                600,             100               );
IR leftBack  (6,        4,         9 ,           false,       700,          6,                600,             100               );
IR back      (7,        4,         10,           true,        700,          6,                600,             100               );
IR rightBack (8,        4,         11,           true,        700,          6,                600,             100               );
IR right     (A4,       3,         12,           true,        700,          6,                600,             100               );

// the setup function runs once when you press reset or power the board
void setup() {
					
	//start Serial
	Serial.begin(57600);
	Serial.println("*** Begin ***");

	//startup cool thingy
	LEDCircleFlash();
	LEDCircleFlash();
	LEDCircleFlash();
	
	//Mega test
	/*pinMode(44, OUTPUT);
	digitalWrite(44, HIGH);
	delay(100);
	digitalWrite(44, LOW);
	delay(100);
	pinMode(A1, OUTPUT);
	digitalWrite(A1, HIGH);
	pinMode(A0, INPUT);*/
}

void loop() {
	back.tick();
	right.tick();
	rightBack.tick();
}


/*void loop2() {// the loop function runs over and over again until power down or reset

	prevFrontRightDetected = FrontRightDetected;
//	if (++loopcounter == 5) {
//		Serial.print(FrontRightCounter);
//		Serial.print(",");
//		Serial.println(notSeenCounter);
//		loopcounter = 0;
//	}

	// adjust high speed counter
	if (digitalRead(IR_RIGHT_BACK) == LOW) //if the IR is receiving something
	{
		FrontRightCounter += (FrontRightCounter < COUNTER_MAX ? COUNTER_ADDITION : 0);//if IR is on & if counter>250 then +2 t counter else +0
//		notSeenCounter = 0;
	}
	else //IR == HIGH ==> IR not seing anything
	{
		notSeenCounter++;
		FrontRightCounter -= (FrontRightCounter > 0);//If IR is off then -1 (if counter > than 0)
	}

	//Determine if we are realiably seeing, or not seeing the ball
	
	if (FrontRightCounter > COUNTER_SEEING_THRESHOLD) {
		FrontRightDetected = true;
	}
	if (FrontRightCounter < COUNTER_NOT_SEEING_THRESHOLD) {
		FrontRightDetected = false;
	}

	
	if (FrontRightDetected != prevFrontRightDetected)//if ball detected has changed up date the LED
	{
		digitalWrite(LED_RIGHT_BACK,FrontRightDetected);//turn LED on/off
	}
	
	// Reset the IR Sensor if nothing seen for a long while
	if (notSeenCounter > (COUNTER_MAX+100)) {
		digitalWrite(IR_VCC_BACK, LOW);
		delayMicroseconds(400);
		digitalWrite(IR_VCC_BACK, HIGH);
		notSeenCounter = 0;
		delayMicroseconds(400);
		//Serial.println("Reset");
	}
}*/

void LEDCircleFlash() {
	frontRight.flash();
	frontLeft.flash();
	left.flash();
	leftBack.flash();
	back.flash();
	rightBack.flash();
	right.flash();
}