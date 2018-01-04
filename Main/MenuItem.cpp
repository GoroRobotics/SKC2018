// 
// 
// 

#include "MenuItem.h"

MenuItem::MenuItem(const char * displayText) //constructor
{
	_displayText = displayText;
	_next = this;
	_prev = this;
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

const char * MenuItem::displayText(){
	return _displayText;
}
