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

		//Fetch next keystroke.
		button = buttons.waitForNextKey();

		switch (button) {
		case LEFT:	
			//Exit current menu [TODO]
			break;
		case UP:
			//Scroll menu up
			currentItem = currentItem->prev();
			break;
		case DOWN:
			//Scroll menu down
			currentItem = currentItem->next();
			break;
		case RIGHT:
		case ENTER:	
			//right and enter: execute selected menu item
			break;
		default:
			//when all else fails
			lcd.setCursor(0,1); lcd.print("UNKNOWN KEY: "); lcd.print(button); delay(1000);
			break;
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