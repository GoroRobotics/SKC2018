// Display.h

#ifndef _DISPLAY_h
#define _DISPLAY_h
#include <wire.h>
#include <NewliquidCrystal\LiquidCrystal_I2C.h>

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class Display {

private:
	LiquidCrystal_I2C lcd;

	void scroll_Away_Text();

protected:


public:
	Display();//constructor
	void print( int line, int , String text);
	void print(String line1, String line2);
	void print(int position, String line1, String line2);
	void print(String text);
	void begin();
	void spashScreen();
};

#endif