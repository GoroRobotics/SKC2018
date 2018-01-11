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
		/*Propeties*/
		const char * _text;
		MenuItem * _next;
		MenuItem * _prev;

	protected:


	public:
		/*Methods*/
		MenuItem(const char * menuText, void(*command)(void *), void * context);//constructor
		void insertAfter(MenuItem * insertAfter);
		MenuItem * next();
		MenuItem * prev();
		const char * text();
		
		/*Properties*/
		void * context;
		void(*go) (void *);
};

#endif