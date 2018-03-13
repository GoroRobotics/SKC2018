
/*-----( Soccer 2018 )-----*/
//This is the Goro Robotics 2018 Main Code

//---Team Members---
//   Luka Borland Lye(lukabl@icloud.com)
//   Christopher Dirks (Christopher@dirksonline.net)
//   Alex Facer (alex.Facer@gmail.com)

//---Unnoticed, Previously Hidden, Behind The Scenes Genius
//
// Liam Twentyman (liam@aacl.co.nz)
// 
// Supreme Overall Contributor, Major Design Advisor, Key Robot Component Sourcer, Significant Motivator,
// Foremost Unbiased View Provider, Ultimate Design Critic, Supreme 3D Printer Builder,
// Master 3D Printer Firmware Configurer, Outstanding 3D Printer Advisor, 
// Chief 3D Printing Process Advisor, Vital CAD Design Advisor,
// Excellent Alternative Solutions Provider, and a whole load more. Also, is starting to assist with the programming,
// when the workload of Yr 12 Permits.


/*-----( Import needed stuff )-----*/
#include "Chassis.h"
#include "Motor.h"
#include "Display.h"
#include "Buttons.h"
#include "MenuItem.h"
#include "Menu.h"
#include <Wire.h>
#include <NewliquidCrystal\LiquidCrystal_I2C.h>



/* 
Now I know this is not where this code will live, but I was unable to find where it needs to go in the current code,
so I put it here to be moved to where it is needed.

This code is what will set the B set of pins as digital inputs (https://www.arduino.cc/en/Reference/PortManipulation)
I am unable to currently tell you what the pins in the B port are on the Arduino Mega 2560, but the code can be easily changed
for other ports.

To decode the data, bitmath will need to be used to extract the single bit values from the variable holding the values that
have been read in from the sensor. There are a few ways this could be done, but until I know more about
the specifics of how the data from the sensors is going to be used for robot control, the best I can do is
to point you to this link: (http://playground.arduino.cc/Code/BitMath)

However the code for reading in data from multiple pins, is below:

// Sets the B port pins to all be digital inputs. 0 = input, 1 = output
DDRB = B00000000

// random int variable
int foobar

// Sets foobar to have the value of the current input values of the pins in the port B block
foobar = PINB

// Its that simple, and PINB afaik, will automatically give the current value of the sensor when read.



*/






/*-----( Instantiate Global Objects )-----*/
Display display;
Menu rootMenu;
Buttons buttons;
Motor motorBack(MOTOR_BACK, 23, A1, 26, 24, 8);
Motor motorLeft(MOTOR_LEFT, 22, A3, 27, 25, 10);
Motor motorRight(MOTOR_RIGHT, 29, A2, 30, 31, 9);
Chassis chassis;

void contributors(void * _this) { //TODO remove this code

	display.print("Made by Alex,", "Luka and Chris");
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

	//rootMenu.add(new MenuItem("-Team Members- ", testing, (void *) NULL));
	//rootMenu.add(new MenuItem("Luka BorlandLye", testing, (void *) NULL));
	//rootMenu.add(new MenuItem("Chris Dirks    ", testing, (void *) NULL));
	//rootMenu.add(new MenuItem("Alex Facer     ", testing, (void *) NULL));
	
	//Create Menu Items and add to root menu
	//                         012345678901234
	rootMenu.add(new MenuItem(" Goro Robotics ",	contributors,			(void *) NULL			));
	rootMenu.add(new MenuItem("Chassis Drive  ",	Chassis::interactive,	(void *)(&chassis)		));
	rootMenu.add(new MenuItem("Buttons diag   ",	Buttons::diagnostics,	(void *)(&buttons)		));
	rootMenu.add(new MenuItem("Motor Back diag",	Motor::diagnostics,		(void *)(&motorBack)	));
	rootMenu.add(new MenuItem("Motor Left diag",	Motor::diagnostics,		(void *)(&motorLeft)	));
	rootMenu.add(new MenuItem("MotorRight diag",	Motor::diagnostics,		(void *)(&motorRight)	));
	
	
	/*-----( Other Initializatons [TODO: to be added to classes...])-----*/
	Serial.begin(9600);			// initialize serial communication at 9600 bits per second:
		
	rootMenu.start();//start menu system
}//end setup


// the loop routine runs over and over again forever:
void loop() {
	
	buttonInteruptEvent = false;	//button event handler
	
	rootMenu.process();				//run the menu system

	/*do {
		//Controller.aquire_ball();
		//Controller.goto(center_pitch_right);
		//Controller.goto(goal_box);
		//Kicker.Kick():
	} while (!buttonInteruptEvent); //wait for left key press to go to menu*/

}//end loop
