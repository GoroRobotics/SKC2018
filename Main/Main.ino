
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
	//                         0123456789012345
	rootMenu.add(new MenuItem("   Goro 2018   ", testing, (void *) NULL));
	rootMenu.add(new MenuItem("-Team Members- ", testing, (void *) NULL));
	rootMenu.add(new MenuItem("Luka BorlandLye", testing, (void *) NULL));
	rootMenu.add(new MenuItem("Chris Dirks    ", testing, (void *) NULL));
	rootMenu.add(new MenuItem("Alex Facer     ", testing, (void *) NULL));

	rootMenu.add(new MenuItem("btn diagnostics", Buttons::diagnostics, (void *) (&buttons)));

	
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
