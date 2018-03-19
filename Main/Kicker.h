// Kicker.h

#ifndef _KICKER_h
#define _KICKER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class Kicker
{
private: 

protected:

public:
	Kicker();
	static void diagnostics(void * _this);
	void fireKicker();
	void ledTestKicker();
};
#endif

