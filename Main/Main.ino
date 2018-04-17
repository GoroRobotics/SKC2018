
/*-----( Soccer 2018 )-----*/
//This is the Goro Robotics 2018 Main Code

//---Team Members---
//   Luka Borland Lye(lukabl@icloud.com)
//   Christopher Dirks (Christopher@dirksonline.net)
//   Alex Facer (alex.Facer@gmail.com)
//	 Liam Twentyman (liam@aacl.co.nz)
// Unnoticed, Previously Hidden, Behind The Scenes Genius
// Supreme Overall Contributor, Major Design Advisor, Key Robot Component Sourcer, Significant Motivator,
// Foremost Unbiased View Provider, Ultimate Design Critic, Supreme 3D Printer Builder,
// Master 3D Printer Firmware Configurer, Outstanding 3D Printer Advisor, 
// Chief 3D Printing Process Advisor, Vital CAD Design Advisor,
// Excellent Alternative Solutions Provider, and a whole load more. Also, is starting to assist with the programming,
// when the workload of Yr 12 Permits.


/*-----( Import needed stuff )-----*/
#include "Kicker.h"
#include "Chassis.h"
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
Motor motorLeft(MOTOR_LEFT, 22, A3, 27, 25, 10);
Motor motorRight(MOTOR_RIGHT, 29, A2, 30, 31, 9);
Chassis chassis;
Kicker kicker;

void contributors(void * _this) { //TODO remove this code

	display.print("Made by Chris,", "Alex and Luka");
	buttonInteruptEvent = false;
	do {
		delay(1);
	} while (!buttonInteruptEvent); //wait for left key press to go to menu*/

}


void setup() {

	display.begin();

	//Create Menu Items and add to root menu
	//                         012345678901234
	rootMenu.add(new MenuItem(" Goro Robotics ",	contributors,			(void *) NULL			));
	rootMenu.add(new MenuItem("Chassis Drive  ",	Chassis::interactive,	(void *)(&chassis)		));
	rootMenu.add(new MenuItem("Kicker diag    ",	Kicker::diagnostics,	(void *)(&kicker)		));
	rootMenu.add(new MenuItem("Buttons diag   ",	Buttons::diagnostics,	(void *)(&buttons)		));
	rootMenu.add(new MenuItem("Motor Back diag",	Motor::diagnostics,		(void *)(&motorBack)	));
	rootMenu.add(new MenuItem("Motor Left diag",	Motor::diagnostics,		(void *)(&motorLeft)	));
	rootMenu.add(new MenuItem("MotorRight diag",	Motor::diagnostics,		(void *)(&motorRight)	));
	
	
	/*-----( Other Initializatons [TODO: to be added to classes...])-----*/
	Serial.begin(9600);	// initialize serial communication at 9600 bits per second:
	rootMenu.start();	//start menu system

}//end setup


void loop() {// the loop routine runs over and over again forever:
	
	buttonInteruptEvent = false;	//button event handler
	
	rootMenu.process();				//run the menu system

	/*do {
		//Controller.aquire_ball();
		//Controller.goto(center_pitch_right);
		//Controller.goto(goal_box);
		//Kicker.Kick():
	} while (!buttonInteruptEvent); //wait for left key press to go to menu*/

}//end loop
