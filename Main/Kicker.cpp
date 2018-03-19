// Idividual Kicker related functions, ect.
// 
// 


/*-----( Import needed stuff )-----*/
#include "Kicker.h"
#include "Display.h"
#include "Buttons.h"


extern Display display;
extern Buttons buttons;

/*-----(       Settings         )-----*/
#define	KICKER_PIN 7		//set to pin (7) for kicker output
#define	KICKER_Duration 500	//duration of kick in Milliseconds

/*-----(       Definitions      )-----*/

/*-----(       Variables        )-----*/

/*-----(     Class Methods      )-----*/

//constructor
Kicker::Kicker() {
	pinMode(KICKER_PIN, OUTPUT);
}


void Kicker::diagnostics(void * _this)
{
	Kicker *  kicker = (Kicker *)(_this);

	display.print("Press ENTR/RIGHT", "To Fire SOL/LED");

	do {

		//process the key pressed
		buttons.waitForNextKey();

		switch (buttons.lastKeyPressed()) {

		case LEFT:
			//exit menu
			break;

		case RIGHT:
			//Fire LED test
			kicker->ledTestKicker();
			break;

		case UP:
		case DOWN:
			//Do nothng
			break;

		case ENTER:
			//Fire solienoid
			kicker->fireKicker();
			break;

		default:
			//when all else fails
			display.print(0, 1, "UNKNOWN KEY: ");
			display.print(13, 1, String(buttons.lastKeyPressed()));
			delay(1000);
			break;
		}//end switch
	
	} while (buttons.lastKeyPressed() != LEFT);
}


void Kicker::fireKicker() {
	digitalWrite(KICKER_PIN, HIGH);
	delay(KICKER_Duration); //TODO: remove for timer interupt (https://learn.adafruit.com/multi-tasking-the-arduino-part-2/timers)
	digitalWrite(KICKER_PIN, LOW);
}

void Kicker::ledTestKicker() {
	digitalWrite(LED_BUILTIN,HIGH);
	delay(KICKER_Duration);
	digitalWrite(LED_BUILTIN, LOW);
}