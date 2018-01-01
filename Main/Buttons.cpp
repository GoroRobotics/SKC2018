// All button related functions, ect.
// 
// 


/*-----( Import needed stuff )-----*/
#include "Buttons.h"


/*-----(       Settings       )-----*/
#define BUTTON_INTERUPT_PIN 2 // The digital pin the button board is connected to. (But only some of the buttons trigger the interupt)
#define BUTTON_ANALOG_PIN A0 // The analog pin the button board is connected to. (Each button generates a different analog voltage when pressed)

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

KEY Buttons::waitForNextKey()
{
	KEY buttonValue = NONE;

//	do {//read buttons (analog) and display until key is released
//		buttonValue = analogRead(A0);
//	} while (buttonValue<NO_BUTTON_MIN);

	return buttonValue;
}

