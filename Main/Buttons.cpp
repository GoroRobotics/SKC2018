// All button related functions, ect.
// 
// 


/*-----( Import needed stuff )-----*/
#include "Buttons.h"
#include <NewliquidCrystal\LiquidCrystal_I2C.h>

extern LiquidCrystal_I2C lcd;

/*-----(       Settings       )-----*/
#define BUTTON_INTERUPT_PIN 2	// The digital pin the button board is connected to. (But only some of the buttons trigger the interupt)
#define BUTTON_ANALOG_PIN A0	// The analog pin the button board is connected to. (Each button generates a different analog voltage when pressed)
#define DEBOUNCE_DELAY 5		//milliseconds delay for analog value to settle

//Analog range of values   (min,max)
#define BUTTON_LEFT		MID(0,0)
#define BUTTON_UP		MID(138,150)
#define BUTTON_DOWN		MID(325,335)
#define BUTTON_RIGHT	MID(501,513)
#define BUTTON_ENTER	MID(735,747)
#define BUTTON_NONE 	MID(1020,1024)

/*-----(       Definitions       )-----*/
#define MID(A,B) ((A+B)/2)
//Midway boundaries between key press analaog values to use with less than evaluations.
#define BUTTON_LEFT_LTBOUNDARY	MID(BUTTON_LEFT ,BUTTON_UP)
#define BUTTON_UP_LTBOUNDARY	MID(BUTTON_UP	,BUTTON_DOWN)
#define BUTTON_DOWN_LTBOUNDARY	MID(BUTTON_DOWN	,BUTTON_RIGHT)
#define BUTTON_RIGHT_LTBOUNDARY	MID(BUTTON_RIGHT,BUTTON_ENTER)
#define BUTTON_ENTER_LTBOUNDARY	MID(BUTTON_ENTER,BUTTON_NONE)
//need a greater than boundary for all keys released (aka NONE)
#define BUTTON_NONE_GTBOUNDARY	BUTTON_ENTER_LTBOUNDARY+1 // to the top of the analogue input range

/*-----(       Variables        )-----*/
volatile byte buttonInteruptEvent = false;//The flag set to true when the button Interupt Service Routine has been triggered.

/*-----( Interupt Service Routine  )-----*/
//Runs each time the Left button is pressed. It is triggered by a change in voltage on a digital pin.
void buttonInteruptServiceRoutine(void)
{
	buttonInteruptEvent = true;
}//end function


/*-----( Class Methods  )-----*/
//TODO


Buttons::Buttons()//constructor
{
	pinMode(BUTTON_INTERUPT_PIN, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(BUTTON_INTERUPT_PIN), buttonInteruptServiceRoutine, FALLING);
}

//Waits for next key to be pressed and released. Will not return KEY=NONE. Will initially wait for all keys to be released. 
KEY Buttons::waitForNextKey()
{
	waitForAllKeysReleased();

	waitForAnyKeyPress();

	lcd.setCursor(0, 1);	lcd.print("Key =           ");    lcd.setCursor(0, 4);
	
	//Button has been pressed, determine which button was pressed	
		 if	(buttonAnalogValue <= BUTTON_LEFT_LTBOUNDARY)	{ buttonValue = LEFT;  lcd.print("LEFT  "); }
	else if (buttonAnalogValue <= BUTTON_UP_LTBOUNDARY)		{ buttonValue = UP;	   lcd.print("UP    "); }
	else if (buttonAnalogValue <= BUTTON_DOWN_LTBOUNDARY)	{ buttonValue = DOWN;  lcd.print("DOWN  "); }
	else if (buttonAnalogValue <= BUTTON_RIGHT_LTBOUNDARY)	{ buttonValue = RIGHT; lcd.print("RIGHT "); }
	else if (buttonAnalogValue <= BUTTON_ENTER_LTBOUNDARY)	{ buttonValue = ENTER; lcd.print("ENTER "); }
	
	lcd.print(buttonAnalogValue);

	//wait for key to be released before continuing
	waitForAllKeysReleased();

	return lastKeyPressed;
}

//sets buttonValue to KEY value when done
void Buttons::waitForAnyKeyPress()
{
	do { //wait until a button is pressed
		buttonAnalogValue = analogRead(BUTTON_ANALOG_PIN);
	} while (buttonAnalogValue > BUTTON_NONE_GTBOUNDARY);

	delay(DEBOUNCE_DELAY);
	buttonAnalogValue = analogRead(BUTTON_ANALOG_PIN);
}

//sets buttonValue = NONE and updates lastKeyPressed when done
void Buttons::waitForAllKeysReleased()
{
	do { //wait until button is released (aka KEYS=NONE)
		buttonAnalogValue = analogRead(BUTTON_ANALOG_PIN);
	} while (!(buttonAnalogValue > BUTTON_NONE_GTBOUNDARY));

	lastKeyPressed = buttonValue;
	buttonValue = NONE;
}

