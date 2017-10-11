/*-----( Import needed libraries )-----*/
#include <Wire.h>
#include <NewliquidCrystal\LiquidCrystal_I2C.h>

/*-----(       Definitions       )-----*/
#define LED LED_BUILTIN		// LED is the built in LED pin

/*-----(       Variables         )-----*/
int brightness = 0;			// how bright the LED is
int fadeAmount = 5;			// how many points to fade the LED by
int fadespeed  = 15;		//the speed of the fade (in ms)

/*-----(    Set I2C adresses     )-----*/
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  //Set the LCD I2C address


void setup() {
	pinMode(LED, OUTPUT);		// declare LED to be an output:
	lcd.begin(16, 2);			// initialize the lcd for 16 chars 2 lines
	lcd.noBacklight();			//Blink backlight
	lcd.backlight();		
	

	//--- Write on the display (Title)---
	lcd.setCursor(2, 0);		// NOTE: Cursor Position: (CHAR, LINE) start at 0
	lcd.print("GORO PHEONIX");
	delay(1000);
	lcd.setCursor(2, 1);
	lcd.print("Hello, world");
	delay(1000);

	//---Scroll away text---
	for (int i = 0; i< 16; i++){
		lcd.scrollDisplayLeft();
		delay(150);
	}//end for loop
	lcd.clear();

	//--- Write on the display (Subtitle)---
	lcd.setCursor(2, 0);
	lcd.print("Rising from");
	delay(500);
	lcd.setCursor(3, 1);
	lcd.print("the ashes");

}//end setup



void loop() {// the loop routine runs over and over again forever
	
	analogWrite(LED, brightness);				// set the brightness of the led:

	brightness = brightness + fadeAmount;		// change the brightness for next time through the loop:
	
	if (brightness <= 0 || brightness >= 255){	// reverse the direction of the fading at the ends of the fade:
		fadeAmount = -fadeAmount;
	}//end if
	
	delay(fadespeed);								// wait for (speed) milliseconds to see the dimming effect
}//end loop