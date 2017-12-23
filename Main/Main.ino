
/*-----( Soccer 2018 )-----*/
//This is the Goro Robotics 2018 Main Code

//---Team Members---
//   Luka Borland Lye(lukabl@icloud.com)
//   Christopher Dirks (Christopher@dirksonline.net)
//   Alex Facer (alex.Facer@gmail.com)


/*-----( Import needed libraries )-----*/
#include "MenuItem.h"
#include "Menu.h"
#include <Wire.h>
#include <NewliquidCrystal\LiquidCrystal_I2C.h>

/*-----(       Definitions       )-----*/
#define LED LED_BUILTIN		// LED is the built in LED pin
#define LCD_I2C_Adress 0x3F //lcd adress on the I2C network
#define Scroll_Speed 50 //the speed of scroll text function (ms per charictor)


#define LED LED_BUILTIN		// LED is the built in LED pin

/*-----(       Setup I2C        )-----*/
LiquidCrystal_I2C lcd(LCD_I2C_Adress, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  //Set the LCD I2C address


void setup() {
	//Instantiate Root Menu Object
	Menu rootMenu;
	//Create Menu Items and add to root menu
	rootMenu.add(new MenuItem("1 Item 1"));
	rootMenu.add(new MenuItem("2 Item 2"));
	rootMenu.add(new MenuItem("3 Item 3"));
	rootMenu.add(new MenuItem("4 Item 4"));

	//===============(Original Code)===================================================
	
	//---   Setup (Pins, LCD, ect)    ---
	lcd.begin(16, 2);			// initialize the lcd for 16 chars 2 lines

	//---   Title Screen   ---
	lcd.setCursor(2, 0);		// NOTE: Cursor Position: (CHAR, LINE) start at 0
	lcd.print("GORO PHEONIX");
	delay(800);
	scroll_Away_Text();

	//- Subtitle)-
	lcd.setCursor(2, 0);
	lcd.print("Rising from");
	lcd.setCursor(3, 1);
	lcd.print("the ashes");
	delay(800);
	scroll_Away_Text();
	//===============(Original Code)===================================================

	rootMenu.start(lcd);

}//end setup


// the loop routine runs over and over again forever:
void loop() {
}//end loop


void scroll_Away_Text(){//---Scroll away text to the left of the screen---

	for (int i = 0; i<16; i++) {
		lcd.scrollDisplayLeft();
		delay(Scroll_Speed);
	}//end for

	lcd.clear();

}//end function

