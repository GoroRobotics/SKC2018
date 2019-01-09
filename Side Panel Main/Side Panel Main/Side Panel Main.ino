// Idividual Side Panel related functions, ect.
// 
// 


/*-----(       Settings         )-----*/
// set pin numbers:
#define IRPin1 0		// the number of the IR1 pin
#define IRPin2 0		// the number of the IR2 pin
#define OutputPin 1     // the number of the LED pin

/*-----(       Definitions      )-----*/
#define IROFFSET 100

/*-----(       Variables        )-----*/
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
	ir2Value = analogRead(IRPin2);

	// check if the IR is detected.
	// if it is, the Outputpin is HIGH:
	if (ir1Value >= ir2Value + IROFFSET) {
		digitalWrite(OutputPin, HIGH);
	}
	else {
		digitalWrite(OutputPin, LOW);
	}
}