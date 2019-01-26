// Idividual Chassis related functions, ect.
// 
// 


/*-----( Import needed stuff )-----*/
#include "Chassis.h"
#include "Display.h"
#include "Buttons.h"
#include "Motor.h"

extern Display display;
extern Buttons buttons;
extern Motor motorLeft;
extern Motor motorRight;


/*-----(       Settings         )-----*/
#define MIN_POWER 45 //the minimum power required to move the motor under the force of the robot

/*-----(       Definitions      )-----*/

/*-----(       Variables        )-----*/

/*-----(     Class Methods      )-----*/

//constructor
Chassis::Chassis(){
	display.print("Chassis()","Constructor");
}


void Chassis::interactive(void * _this) {
	Chassis *  chassis = (Chassis *)(_this);

	motorLeft.start();	//enable motorLeft
	motorRight.start();	//enable motorRight

	chassis->_power = MIN_POWER;

	display.print("Press buttons ","to drive");

	do {
		
		//process the key pressed
		buttons.waitForNextKey();

		switch (buttons.lastKeyPressed()) {
		case RIGHT:
			//Drive Right
			//TODO
			break;

		case LEFT:
			//Drive left
			//TODO
			break;

		case UP:
			//Drive Forward
			chassis->forward(chassis->_power);
			break;

		case DOWN:
			//Drive Backwards	
			chassis->backward(chassis->_power);
			break;

		case ENTER:
			//exit menu
			break;

		default:
			//when all else fails
			display.print(0, 1, "UNKNOWN KEY: ");
			display.print(13, 1, String(buttons.lastKeyPressed()));
			delay(1000);
			break;
		}//end switch


	} while (buttons.lastKeyPressed() != ENTER);
	
	motorLeft.disableMotor();
	motorRight.disableMotor();

}


void Chassis::pointAt(int direction) {//Sets the direction of the Chassis, range(-180, +180)

	_direction = direction;


	if (_direction>180)
	{
		_direction = -_direction - 180;
	}



	switch (_direction) {
		case 0	://Straight Forward
			//motorRight.setPower	(_power);
			//motorLeft.setPower	(_power);
			break;

		case 30:
			
			break;

		case 60:

			break;

		case 90		://Right

			break;

		case 120:

			break;

		case 150:

			break;

		case 180	:
		case -180	://Backwards
			
			break;

		case -150:

			break;

		case -120:

			break;

		case -90://Left

			break;

		case -60:

			break;

		case -30:

			break;

		}

}


void Chassis::forward(int power) {//Sets the Chassis in the forawrd direction, range(0, 255)

	_power = power;

	motorRight.setPower	(_power);
	motorLeft.setPower	(-_power);

}

void Chassis::backward(int power) {//Sets the Chassis in the backward direction, range(0, 255)

	_power = power;

	motorRight.setPower	(-_power);
	motorLeft.setPower	(_power);

}