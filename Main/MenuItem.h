// MenuItem.h

#ifndef _MENUITEM_h
#define _MENUITEM_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class MenuItem{

	private:
		const char * _displayText;
		MenuItem * _next;
		MenuItem * _prev;

	protected:


	public:
		MenuItem(const char * displayText);//constructor
		void insertAfter(MenuItem * insertAfter);
		MenuItem * next();
		MenuItem * prev();
		const char * displayText();
};

#endif

