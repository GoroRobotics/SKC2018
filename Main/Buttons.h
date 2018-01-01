// Buttons.h

#ifndef _BUTTONS_h
#define _BUTTONS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

void buttonInteruptServiceRoutine(); 
extern volatile byte buttonInteruptEvent;

enum KEY
{
	NONE,	//no keys pressed
	LEFT,
	RIGHT,
	UP,
	DOWN,
	ENTER	//Far right button
};

class Buttons{
 
private:
	
protected:

 public:
	Buttons(); //constructor
	KEY waitForNextKey(void);
};

#endif