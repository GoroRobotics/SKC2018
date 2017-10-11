/*
This example shows how to fade the built in LED using the analogWrite() function.

The analogWrite() function uses PWM, so if you want to change the pin you're 
using, be sure to use another PWM capable pin. (denoted by ~) 
*/

/*-----( Import needed libraries )-----*/
#include <Wire.h>
#include <NewliquidCrystal\LiquidCrystal_I2C.h>

#define LED LED_BUILTIN		// LED is the built in LED pin
int brightness = 0;			// how bright the LED is
int fadeAmount = 5;			// how many points to fade the LED by
int fadespeed  = 15;		//the speed of the fade (in ms)
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  //TODO: Find and Set the LCD I2C address


void setup() {
	pinMode(LED, OUTPUT);	// declare LED to be an output:
	lcd.begin(16, 2);   // initialize the lcd for 16 chars 2 lines, turn on backlight
						// ------- Quick 3 blinks of backlight  -------------
	for (int i = 0; i< 3; i++)
	{
		lcd.backlight();
		delay(250);
		lcd.noBacklight();
		delay(250);
	}
	lcd.backlight(); // finish with backlight on  

	//-------- Write characters on the display ------------------
	// NOTE: Cursor Position: (CHAR, LINE) start at 0  
	lcd.setCursor(0, 0); //Start at character 4 on line 0
	lcd.print("GORO PHEONIX");
	delay(1000);
	lcd.setCursor(0, 1);
	lcd.print("Hello, world!");
	delay(8000);
	lcd.setCursor(0, 1);
	lcd.print("Risng frm ashes");
	delay(8000);

}//end setup



void loop() {// the loop routine runs over and over again forever
	
	analogWrite(LED, brightness);				// set the brightness of the led:

	brightness = brightness + fadeAmount;		// change the brightness for next time through the loop:
	
	if (brightness <= 0 || brightness >= 255){	// reverse the direction of the fading at the ends of the fade:
		fadeAmount = -fadeAmount;
	}//end if
	
	delay(fadespeed);								// wait for (speed) milliseconds to see the dimming effect
}//end loop