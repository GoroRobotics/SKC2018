// 
// 
// 

#include "Menu.h"
#include "MenuItem.h"
#include "Buttons.h"
#include "Display.h"

extern Display display;
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
			//right and enter: execute selected menu item's command.
			currentItem->go(currentItem->context);
			break;
		default:
			//when all else fails
			display.print(0,1,"UNKNOWN KEY: "); 
			display.print(13,1,String(button)); 
			delay(1000);
			break;
		}//end switch

	} while (!finished);
	
}

void Menu::show()
{
	//Display the current menu items.
	display.print(1,currentItem->text(), currentItem->next()->text());
	//overlay cursor
	display.print(0, 0, String(">"));
}