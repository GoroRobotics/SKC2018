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
	KEY_NONE,	//no keys pressed
	LEFT,
	RIGHT,
	UP,
	DOWN,
	ENTER	//Far right button
};

class Buttons{
 
private:
	KEY buttonValue = KEY_NONE;
	KEY _lastKeyPressed = KEY_NONE;
	int buttonAnalogValue = 0;
	void print(KEY button);

protected:

 public:
	Buttons(); //constructor
	boolean allKeysReleased();
	KEY lastKeyPressed(void);
	KEY waitForNextKey(void);
	void waitForAnyKeyPress();
	void waitForAllKeysReleased();
	static String KEY2String(KEY button);
	static void diagnostics(void * _this);
};

#endif