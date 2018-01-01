
/*-----( Soccer 2018 )-----*/
//This is the Goro Robotics 2018 Main Code

//---Team Members---
//   Luka Borland Lye(lukabl@icloud.com)
//   Christopher Dirks (Christopher@dirksonline.net)
//   Alex Facer (alex.Facer@gmail.com)


/*-----( Import needed stuff )-----*/
#include "Buttons.h"
#include "MenuItem.h"
#include "Menu.h"
#include <Wire.h>
#include <NewliquidCrystal\LiquidCrystal_I2C.h>

/*-----(       Settings       )-----*/
#define LED LED_BUILTIN		// LED is the built in LED pin
#define LCD_I2C_Adress 0x3F //lcd adress on the I2C network
#define Scroll_Speed 15 //the speed of scroll text function (ms per charactor)
#define LED LED_BUILTIN		// LED is the built in LED pin

/*-----(    Button Settings       )-----*/
#define BUTTON_UP_MAX 150
#define BUTTON_UP_MIN 138
#define BUTTON_DOWN_MAX 335
#define BUTTON_DOWN_MIN	325
#define BUTTON_LEFT_MAX 0 
#define BUTTON_LEFT_MIN	0
#define BUTTON_RIGHT_MAX 513
#define BUTTON_RIGHT_MIN 501
#define BUTTON_ENTER_MAX 747
#define BUTTON_ENTER_MIN 735
#define NO_BUTTOM_MAX 1024
#define NO_BUTTON_MIN 800

/* We may want to shift settings to SD card and be abe to be changed using the menu.  */

/*-----(       Variables        )-----*/


/*-----(       Setup I2C        )-----*/
LiquidCrystal_I2C lcd(LCD_I2C_Adress, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  //Set the LCD I2C address


void setup() {
	
	/*-----( Instantiate Required Objects )-----*/
	Menu rootMenu;
	Buttons buttons;
	

	/*-----( Menu Init [TODO])-----*/
	//add inputs and outputs for menu system
	//rootMenu.addInput(buttons)
	//rootMenu.addInput(serialPort)
	//rootMenu.addOutput(lcd)
	//rootMenu.addOutput(serialPort)
	
	//Create Menu Items and add to root menu
	rootMenu.add(new MenuItem("1 Item 1"));
	rootMenu.add(new MenuItem("2 Item 2"));
	rootMenu.add(new MenuItem("3 Item 3"));
	rootMenu.add(new MenuItem("4 Item 4"));
		

	/*-----( Other Initializatons [to be added to classes...])-----*/
	Serial.begin(9600);	// initialize serial communication at 9600 bits per second:
	lcd.begin(16, 2);			// initialize the lcd for 16 chars 2 lines
	

	/*-----( Splash Screen [To be moved])-----*/
	
	//---   Title Screen   ---
	lcd.setCursor(2, 0);		// NOTE: Cursor Position: (CHAR, LINE) start at 0
	lcd.print("GORO PHEONIX");
	delay(500);
	scroll_Away_Text();

	//- Subtitle)-
	lcd.setCursor(2, 0);
	lcd.print("Rising from");
	lcd.setCursor(3, 1);
	lcd.print("the ashes");
	delay(500);
	scroll_Away_Text();


	//rootMenu.start(lcd);//start menu system

}//end setup


// the loop routine runs over and over again forever:
void loop() {

	lcd.setCursor(1, 1);
	lcd.print("Press Left Key");
	buttonInteruptEvent = false;

	while (!buttonInteruptEvent) {
		//Print the button state while no buttom is pressed
		lcd.setCursor(0, 0);
		lcd.print("Button:");
		lcd.setCursor(7, 0);
		lcd.print(buttonInteruptEvent);
	}//wait for key press
	
	delay(1000);
		
	int buttonValue;

	do     
	{//read buttons (analog) and display until key is released
		buttonValue = analogRead(A0);
		lcd.setCursor(7, 0);
		lcd.print(buttonValue);
	} while (buttonValue<NO_BUTTON_MIN);
	
	buttonInteruptEvent = false;
	lcd.setCursor(7, 0);
	lcd.print("Release");
	delay(500);
	lcd.clear();
}//end loop


//To be moved...
void scroll_Away_Text(){//---Scroll away text to the left of the screen---

	for (int i = 0; i<16; i++) {
		lcd.scrollDisplayLeft();
		delay(Scroll_Speed);
	}//end for

	lcd.clear();

}//end function