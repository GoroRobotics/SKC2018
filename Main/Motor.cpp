// Idividual Motor related functions, ect.
// 
// 


/*-----( Import needed stuff )-----*/
#include "Motor.h"
#include "Display.h"
#include "Buttons.h"

extern Display display;
extern Buttons buttons;


/*-----(       Settings         )-----*/
#define DIAGNOSTICS_INCREMENT  10//the amount it increases by each time you press the button

/*-----(       Definitions      )-----*/

/*-----(       Variables        )-----*/

/*-----(     Class Methods      )-----*/

//constructor
Motor::Motor(//Refer to motor board pin annottions
	MOTOR_UNIT unit,		//MOTOR_LEFT, MOTOR_RIGHT, MOTOR_BACK
	const uint8_t EN_PIN,	//Enables board
	const uint8_t CS_PIN,	//Current Sensor
	const uint8_t INA_PIN,	//Direction Pin A
	const uint8_t INB_PIN,	//Direction Pin B
	const uint8_t PWM_PIN	//PWM Pin sets power
	) : 
	_EN_PIN(EN_PIN),
	_CS_PIN(CS_PIN),
	_INA_PIN(INA_PIN),
	_INB_PIN(INB_PIN),
	_PWM_PIN(PWM_PIN),
	_unit(unit)
{	
	pinMode(EN_PIN	, OUTPUT);
	pinMode(CS_PIN	, INPUT	);
	pinMode(INA_PIN	, OUTPUT);
	pinMode(INB_PIN	, OUTPUT);
	pinMode(PWM_PIN	, OUTPUT);
}

void Motor::diagnostics(void * _this) {
	Motor *  motor = (Motor *)(_this);
	
	motor->start();//enable motor

	display.print("Current:000", "Pwr:0");

	do {
		do{ //update the current on the display whilst waiting for the key to be pressed
			motor->_current = 0;
			for (int i = 0; i < 20; i++)
			{
				(motor->_current) += analogRead(motor->_CS_PIN);
			}

			//Update the display
			char currentChr[4]; sprintf(currentChr, "%03d", motor->_current);
			char powerChr[4]; sprintf(powerChr, "%04d", motor->_power);
			display.print(8,0,String(currentChr)); 
			display.print(4,1,String(powerChr));
			delay(300);
		} while (buttons.allKeysReleased());
		
		//process the key pressed
		buttons.waitForNextKey();

		switch (buttons.lastKeyPressed()) {
		case RIGHT:
			//Increase by 1
			if (motor->_power<255)
			{
				motor->_power = motor->_power + 1;
			}
			break;

		case LEFT:
			//Exit current menuitem
			break;

		case UP:
			//Increase power
			if (motor->_power<255)
			{
				motor->_power = motor->_power + DIAGNOSTICS_INCREMENT;
			}
			break;

		case DOWN:
			//Decrease power {TODO}	
			if (motor->_power>-255)
			{
				motor->_power = motor->_power - DIAGNOSTICS_INCREMENT;
			}
			break;

		case ENTER:
			motor->_power = -motor->_power;
			break;

		default:
			//when all else fails
			display.print(0, 1, "UNKNOWN KEY: ");
			display.print(13, 1, String(buttons.lastKeyPressed()));
			delay(1000);
			break;
		}//end switch

		motor->setPower(motor->_power);

	} while (buttons.lastKeyPressed() != LEFT);
	motor->stop();
}

void Motor::start() {//Enables the Motor Pin, and sets power to 0 CLOCKWISE
	digitalWrite(_EN_PIN, HIGH);
	setPower(0);
}

void Motor::stop() {//Disables the Motor Pin
	digitalWrite(_EN_PIN, LOW);
}

void Motor::setPower(int power) {//Sets the power and direction of the Motor, range(-255, +255)

	//validation {TODO}
	_power = power;
	
	DIRECTION newDirection = (power > 0) ? COUNTER_CLOCKWISE : CLOCKWISE;

	if (newDirection != direction) {
		switch(newDirection) {
		case CLOCKWISE:
			digitalWrite(_INA_PIN, HIGH);
			digitalWrite(_INB_PIN, LOW);
			break;

		case COUNTER_CLOCKWISE:
			digitalWrite(_INA_PIN, LOW);
			digitalWrite(_INB_PIN, HIGH);
			break;

		case DIRECTION_NOT_SET:
			//ignore
			break;
		}
	} //end if
	analogWrite(_PWM_PIN, abs(power));
}