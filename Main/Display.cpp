// 
// 
// 

/*-----( Import needed stuff )-----*/
#include "Display.h"
#include <Wire.h>
#include <NewliquidCrystal\LiquidCrystal_I2C.h>


/*-----(       Settings       )-----*/
#define LCD_I2C_Adress 0x3F //lcd adress on the I2C network
#define Scroll_Speed 15 //the speed of scroll text function (ms per charactor)

Display::Display() :
	lcd(LCD_I2C_Adress, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE)
{	
	//for some reason this needs to be empty
}

void Display::begin() {
	lcd.begin(16, 2);			// initialize the lcd for 16 chars 2 lines
	spashScreen();
}

void Display::spashScreen() {//display goro robotics on lcd with animation 
	/*-----( Splash Screen )-----*/
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
}

void Display::scroll_Away_Text() {//---Scroll away text to the left of the screen---

	for (int i = 0; i<16; i++) {
		lcd.scrollDisplayLeft();
		delay(Scroll_Speed);
	}//end for

	lcd.clear();

}//end function

//Print at a location
//int position (0-15), int line (0-1), String text
void Display::print(int position, int line, String text)
{
	lcd.setCursor(position, line);
	lcd.print(text);
}

//Print at 0,0
//String text 
void Display::print(String text)
{
	print(0, 0, text);
}

//Clear & Print two lines
//String line1, String line2 (Optional)
void Display::print(String line1, String line2 = "")
{
	print(0, line1, line2);
}

//Clear & Print two lines indented
//int position(indent) (0-15), String line1, String line2 (Optional)
void Display::print(int position, String line1, String line2 = "")
{
	lcd.clear();
	print(position, 0, line1);
	print(position, 1, line2);
}
