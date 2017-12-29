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

class Buttons{
 
private:
	
protected:

 public:
	Buttons(); //constructor
	
};

#endif