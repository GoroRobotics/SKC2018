//#define NANO_PINS
#define ATTINY_PINS

#ifdef ATTINY_PINS
#define IRPin1 3		// the number of the IR1 pin
#define IRPin2 4		// the number of the IR2 pin
#define OutputPin 1     // the number of the LED pin
#endif

#ifdef NANO_PINS
#define IRPin1 1		// the number of the IR1 pin
#define IRPin2 2		// the number of the IR2 pin
#define OutputPin 13    // the number of the LED pin
#endif

// constants won't change.
#define IR2OFFSET 100

// variables will change:
int ir1Value = 0;
int ir2Value = 0;
int x = 0;

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
	ir2Value = analogRead(IRPin2);

	for (size_t i = 0; i < 10; i++)
	{
		x = i*10;
	}

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

