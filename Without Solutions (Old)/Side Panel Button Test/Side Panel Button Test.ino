/*
Button

Turns on and off a light emitting diode(LED) connected to digital
pin, when pressing a pushbutton attached to pin.


The circuit:
* LED attached from pin 13 to ground
* pushbutton attached to pin 2 from +5V
* 10K resistor attached to pin 2 from ground

* Note: on most Arduinos there is already an LED on the board
attached to pin 13.


created 2005
by DojoDave <http://www.0j0.org>
modified 30 Aug 2011
by Tom Igoe

This example code is in the public domain.

http://www.arduino.cc/en/Tutorial/Button
*/

// constants won't change. They're used here to
// set pin numbers:
#define buttonPin1 = 0;		// the number of the pushbutton pin
//#define buttonPin2 = 0;		// the number of the pushbutton pin
#define ledPin1 = 1;			// the number of the LED pin
#define ledPin2 = 2;			// the number of the LED pin

							// variables will change:
int buttonState1 = 0;        // variable for reading the pushbutton status
int buttonState2 = 0;        // variable for reading the pushbutton status

void setup() {
	// initialize the LED pin as an output:
	pinMode(ledPin1, OUTPUT);
	pinMode(ledPin2, OUTPUT);
	// initialize the pushbutton pin as an input:
	pinMode(buttonPin1, INPUT_PULLUP);
	//pinMode(buttonPin2, INPUT_PULLUP);
}

void loop() {
	// read the state of the pushbutton value:
	buttonState1 = digitalRead(buttonPin1);
	//buttonState2 = digitalRead(buttonPin2);

	// check if the pushbutton is pressed.
	// if it is, the buttonState is HIGH:
	if (buttonState1 == LOW) {
		// turn LED on:
		digitalWrite(ledPin1, HIGH);
		digitalWrite(ledPin2, HIGH);
	}
	else {
		// turn LED off:
		digitalWrite(ledPin1, LOW);
		digitalWrite(ledPin2, LOW);
	}
	
}