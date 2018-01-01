// 
// 
// 

#include "Menu.h"
#include "MenuItem.h"
#include "Buttons.h"
#include <NewliquidCrystal\LiquidCrystal_I2C.h>

extern LiquidCrystal_I2C lcd;
extern Buttons buttons;

Menu::Menu(){//constructor
	currentItem = NULL;
}

void Menu::add(MenuItem * item) {
	if (currentItem != NULL) { item->insertAfter(currentItem); }
	currentItem = item;
}

void Menu::start()
{
	currentItem = currentItem->next(); //go back to first item added
	show();
}

void Menu::process()
{
	boolean finished = false;
	KEY button;
	do
	{
		show();

		lcd.setCursor(0, 1);//TO BE MOVED...

		//Fetch next keystroke.
		button = buttons.waitForNextKey();
		switch (button) {
		default:
			lcd.print("UNKNOWN KEY: "); lcd.print(button); delay(1000);
		}//end switch

	} while (!finished);
	
}

void Menu::show()
{
	lcd.clear();
	//Display the current menu items.
	lcd.setCursor(0, 0);
	lcd.print(currentItem->displayText());
	lcd.setCursor(0, 1);
	lcd.print(currentItem->next()->displayText());
}

