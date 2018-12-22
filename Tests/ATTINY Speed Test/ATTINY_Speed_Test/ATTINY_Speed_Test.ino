/*
Name:		Side_Panel_Speed_Test.ino
Created:	12/21/2018 7:36:31 PM
Author:	CD_FER
*/

// constants won't change. They're used here to
#define IR2OFFSET 100
// set pin numbers:
#define IRPin1 0     // the number of the IR1 pin
#define IRPin2 0     // the number of the IR1 pin
#define OutputPin 1      // the number of the LED pin

// variables will change:
int ir1Value = 0;
int ir2Value = 0;

void setup() {
	// initialize the LED pin as an output:
	pinMode(OutputPin, OUTPUT);
	// initialize the pushbutton pin as an input:
	pinMode(IRPin1, INPUT);
	pinMode(IRPin2, INPUT);
}

void loop() {
	// read the state of the pushbutton value:
	ir1Value = analogRead(IRPin1);
	//ir2Value = analogRead(IRPin2);

	// check if the pushbutton is pressed.
	// if it is, the buttonState is HIGH:
	if (ir1Value >= ir2Value + IR2OFFSET) {
		dip();
	}
	else {
		dip();
	}
}

void dip() {
	digitalWrite(OutputPin, !digitalRead(OutputPin));
}

