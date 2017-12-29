// All button related functions, ect.
// 
// 


/*-----( Import needed stuff )-----*/
#include "Buttons.h"


/*-----(       Settings       )-----*/
#define BUTTON_INTERUPT_PIN 2 // The digital pin the button board is connected to. (But only some of the buttons trigger the interupt)
#define BUTTON_ANALOG_PIN A0 // The analog pin the button board is connected to. (Each button generates a different analog voltage when pressed)


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



