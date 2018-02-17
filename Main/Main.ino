
/*-----( Soccer 2018 )-----*/
//This is the Goro Robotics 2018 Main Code

//---Team Members---
//   Luka Borland Lye(lukabl@icloud.com)
//   Christopher Dirks (Christopher@dirksonline.net)
//   Alex Facer (alex.Facer@gmail.com)


/*-----( Import needed stuff )-----*/
#include "Motor.h"
#include "Display.h"
#include "Buttons.h"
#include "MenuItem.h"
#include "Menu.h"
#include <Wire.h>
#include <NewliquidCrystal\LiquidCrystal_I2C.h>


/*-----( Instantiate Global Objects )-----*/
Display display;
Menu rootMenu;
Buttons buttons;
Motor motorBack(MOTOR_BACK, 23, A1, 26, 24, 8);

void testing(void * _this) { //TODO remove this code

	display.print("Robotics", "is awesome");
	delay(1000);
	buttonInteruptEvent = false;
	do {
		delay(1);
	} while (!buttonInteruptEvent); //wait for left key press to go to menu*/

}

void setup() {
	display.begin();

	/*-----( Menu Init [TODO])-----*/
	//add inputs and outputs for menu system
	//rootMenu.addInput(buttons)
	//rootMenu.addInput(serialPort)
	//rootMenu.addOutput(lcd)
	//rootMenu.addOutput(serialPort)

	//Create Menu Items and add to root menu
	//rootMenu.add(new MenuItem("-Team Members- ", testing, (void *) NULL));
	//rootMenu.add(new MenuItem("Luka BorlandLye", testing, (void *) NULL));
	//rootMenu.add(new MenuItem("Chris Dirks    ", testing, (void *) NULL));
	//rootMenu.add(new MenuItem("Alex Facer     ", testing, (void *) NULL));
	//                         012345678901234
	rootMenu.add(new MenuItem("   Goro 2018   ",	testing,				(void *) NULL			));
	rootMenu.add(new MenuItem("Buttons diag   ",	Buttons::diagnostics,	(void *)(&buttons)		));
	rootMenu.add(new MenuItem("MotorBack diag ",	Motor::diagnostics,		(void *)(&motorBack)	));

	/*-----( Other Initializatons [TODO: to be added to classes...])-----*/
	Serial.begin(9600);			// initialize serial communication at 9600 bits per second:
		
	rootMenu.start();//start menu system
}//end setup


// the loop routine runs over and over again forever:
void loop() {
	buttonInteruptEvent = false;
	
	/*do {
		//playing game...
		delay(100);
	} while (!buttonInteruptEvent); //wait for left key press to go to menu*/
	
	rootMenu.process();

}//end loop
