// Idividual Side Panel related functions, ect.
// 
// 


/*-----(       Settings         )-----*/
#define NANO_PINS
//#define ATTINY_PINS

#ifdef ATTINY_PINS
#define IRPin1 3		// the number of the IR1 pin
#define IRPin2 4		// the number of the IR2 pin
#define OutputPin 1     // the number of the LED pin
#endif

#ifdef NANO_PINS
//#define IRPin1 1		// the number of the IR1 pin
#define IRPin1 A1		// the number of the IR1 pin (D3 on Shield)
#define IRPin2 A2		// the number of the IR2 pin
#define OutputPin 13    // the number of the LED pin
#endif

/*-----(       Definitions      )-----*/
//#define IROFFSET 100
#define SAMPLE_LENGTH 150

/*-----(       Variables        )-----*/
int ir1Values[SAMPLE_LENGTH];
int ir2Values[SAMPLE_LENGTH];
//int ir1Value = 0;
//int ir2Value = 0;


void setup() {
	// initialize the LED pin as an output:
	//pinMode(OutputPin, OUTPUT);
	// initialize the pushbutton pin as an input:
	pinMode(IRPin1, INPUT);
	pinMode(IRPin2, INPUT);

	Serial.begin(9600);
	Serial.println("Starting Up");
}

void loop() {
	for (int i = 0; i < SAMPLE_LENGTH; i++)
	{
		ir1Values[i] = analogRead(IRPin1);
		ir2Values[i] = analogRead(IRPin2);
		
		// read the state of the pushbutton value:
		//ir1Value = analogRead(IRPin1);
		//ir2Value = analogRead(IRPin2);

		// check if the IR is detected.
		// if it is, the Outputpin is HIGH:
		/*if (ir1Value >= ir2Value + IROFFSET) {
			digitalWrite(OutputPin, HIGH);
		}
		else {
			digitalWrite(OutputPin, LOW);
		}*/
	}
	
	for (int i = 0; i < SAMPLE_LENGTH; i++) {
		Serial.print(ir1Values[i]);
		Serial.print(",");
		Serial.println(ir2Values[i]);
	}
	//Serial.print(700);
	//Serial.print(",");
	//Serial.println(700);
	Serial.println("---xxx---");
	
}