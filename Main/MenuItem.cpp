// MenuItem.cpp
// 
// 

#include "MenuItem.h"

//Create a menu item (Menu item text, command, context (object on which to execute the command))
MenuItem::MenuItem(const char * menuText, void(*command) (void *), void * context) //constructor
{
	_text = menuText;
	_next = this;
	_prev = this;
	go = command;
	this->context = context;
}

void MenuItem::insertAfter(MenuItem * insertAfter){
	_next = insertAfter->_next;
	_prev = insertAfter;
	insertAfter->_next = this;
	_next->_prev = this;
}

MenuItem * MenuItem::next(){
	return _next;
}

MenuItem * MenuItem::prev(){
	return _prev;
}

const char * MenuItem::text(){
	return _text;
}
