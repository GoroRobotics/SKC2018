// 
// 
// 

#include "Menu.h"
#include "MenuItem.h"

Menu::Menu(){//constructor
	currentItem = NULL;
}

void Menu::add(MenuItem * item) {
	if (currentItem != NULL) { item->insertAfter(currentItem); }
	currentItem = item;
}

void Menu::start(LiquidCrystal_I2C lcd)
{
	currentItem = currentItem->next(); //go back to first item added
	lcd.setCursor(0, 0);		// NOTE: Cursor Position: (CHAR, LINE) start at 0
	lcd.print(currentItem->displayText());

	lcd.setCursor(0, 1);		// NOTE: Cursor Position: (CHAR, LINE) start at 0
	lcd.print(currentItem->next()->displayText());
}

