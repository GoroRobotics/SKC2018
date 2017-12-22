// 
// 
// 

#include "Menu.h"
#include "MenuItem.h"

#define MAX_MENU_LENGTH 12

MenuItem items[MAX_MENU_LENGTH];
int numberOfItems;

void Menu::init(){
	numberOfItems = 0;
}

void Menu::add(MenuItem item) {
	if (numberOfItems >= MAX_MENU_LENGTH){ return; } //Don't add too many items to array

	items[numberOfItems] = item;
	numberOfItems++;
}//end add()
