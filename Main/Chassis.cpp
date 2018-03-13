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
extern Motor motorBack;
extern Motor motorLeft;
extern Motor motorRight;


/*-----(       Settings         )-----*/
#define MIN_POWER 45 //the minimum power required to move the motor under the force of the robot

/*-----(       Definitions      )-----*/

/*-----(       Variables        )-----*/

/*-----(     Class Methods      )-----*/

//constructor
Chassis::Chassis(){

}


void Chassis::interactive(void * _this) {
	Chassis *  chassis = (Chassis *)(_this);

	motorBack.start();	//enable motorBack
	motorLeft.start();	//enable motorLeft
	motorRight.start();	//enable motorRight

	chassis->setPower(100);	//set power

	display.print("Press buttons ","to drive");

	do {
		
		//process the key pressed
		buttons.waitForNextKey();

		switch (buttons.lastKeyPressed()) {
		case RIGHT:
			//Drive Right
			chassis->_direction = 90;
			break;

		case LEFT:
			//Drive left
			chassis->_direction = -90;
			break;

		case UP:
			//Drive Forward
			chassis->_direction = 0;
			break;

		case DOWN:
			//Drive Backwards	
			chassis->_direction = 180;
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

		chassis->setDirection(chassis->_direction);

	} while (buttons.lastKeyPressed() != ENTER);
	
	motorBack.stop();
	motorLeft.stop();
	motorRight.stop();

}


void Chassis::setDirection(int direction) {//Sets the direction of the Chassis, range(-180, +180)

	_direction = direction;

	//Motor Position:
	//	30	- Motor Right
	//	150	- Motor Back
	//	270	- Motor Left



	switch (_direction) {
		case 0	://Straight Forward
			motorRight.setPower	(((_power - MIN_POWER)*0.87)  + MIN_POWER);	//Cos(270 - 0) = -87%
			motorBack.setPower	(0);										//Cos(150 - 0) = 0%
			motorLeft.setPower	(((_power - MIN_POWER)*-0.87) - MIN_POWER);	//Cos(30  - 0) = 87%
			break;

		case 90		:

			break;

		case 180	:
		case -180	:
			
			break;

		case -90:

			break;

		}

}


void Chassis::setPower(int power) {//Sets the power of the Chassis, range(0, +255)

	_power = power;
}