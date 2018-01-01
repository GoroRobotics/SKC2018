// 
// 
// 

#include "Menu.h"
#include "MenuItem.h"
#include "Buttons.h"
#include "Global.h"

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
	do
	{
		show();

		lcd.setCursor(0, 1);//TO BE MOVED...

							//Fetch next keystroke.
		switch (buttons.waitForNextKey()) {
		default:
			lcd.print("ERR UNKNOWN KEY");
		}//end switch

	} while (!finished);
	
}

void Menu::show()
{
	//Display the current menu items.
	lcd.setCursor(0, 0);
	lcd.print(currentItem->displayText());
	lcd.setCursor(0, 1);
	lcd.print(currentItem->next()->displayText());
}

