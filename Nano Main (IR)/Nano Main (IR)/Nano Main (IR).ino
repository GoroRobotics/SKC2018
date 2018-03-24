/*
 Name:		Nano_Main__IR_.ino
 Created:	3/23/2018 9:19:52 PM
 Author:	CD_FER
*/

//LEDs
#define LED_1 A0
#define LED_2 A1
#define LED_3 A2
#define LED_4 A3
#define LED_5 A4
#define LED_6 A5
#define LED_7 A6
#define LED_8 A7


//IRs
#define IR_1 2
#define IR_2 3
#define IR_3 4
#define IR_4 5
#define IR_5 6
#define IR_6 7
#define IR_7 8
#define IR_8 9


int	ir1Counter = 0;
boolean	ballDetected = false;

// the setup function runs once when you press reset or power the board
void setup() {

	// initialize digital pins as an output/INPUTS.
	pinMode(LED_1, OUTPUT);
	pinMode(LED_2, OUTPUT);
	pinMode(LED_3, OUTPUT);
	pinMode(LED_4, OUTPUT);
	pinMode(LED_5, OUTPUT);
	pinMode(LED_6, OUTPUT);
	pinMode(LED_7, OUTPUT);
	pinMode(LED_8, OUTPUT);
	
	pinMode(IR_1, INPUT_PULLUP);
	pinMode(IR_2, INPUT_PULLUP);
	pinMode(IR_3, INPUT_PULLUP);
	pinMode(IR_4, INPUT_PULLUP);
	pinMode(IR_5, INPUT_PULLUP);
	pinMode(IR_6, INPUT_PULLUP);
	pinMode(IR_7, INPUT_PULLUP);
	pinMode(IR_8, INPUT_PULLUP);

	Serial.begin(57600);
	Serial.println("*** Begin ***");

}

// the loop function runs over and over again until power down or reset
void loop() {



	if (digitalRead(IR_8) == LOW)
	{
		ir1Counter += (ir1Counter < 250 ? 2 : 0);
	}
	else
	{
		ir1Counter -= (ir1Counter > 0);
	}

	
	if (ballDetected != (ir1Counter > 200))
	{
		ballDetected = (ir1Counter > 200);
		digitalWrite(LED_1, ballDetected);
	}
	
}