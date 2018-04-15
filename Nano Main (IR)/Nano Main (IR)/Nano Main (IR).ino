/*
 Name:		Nano_Main__IR_.ino
 Created:	3/23/2018 9:19:52 PM
 Author:	CD_FER
*/

//LEDs
#define LED_FRONT_RIGHT 13
#define LED_FRONT_LEFT	A1
#define LED_LEFT		A0
#define LED_LEFT_BACK	9 
#define LED_BACK		10
#define LED_RIGHT_BACK	11
#define LED_RIGHT		12

                                                                                                                                                                                                                   

//IRs TODO to be confirmed
#define IR_FRONT_RIGHT	2
#define IR_FRONT_LEFT	3
#define IR_LEFT			4
#define IR_LEFT_BACK	5
#define IR_BACK			6
#define IR_RIGHT_BACK	7
#define IR_RIGHT		8



int	ir1Counter = 0;
boolean	ballDetected = false;

// the setup function runs once when you press reset or power the board
void setup() {

	// initialize digital pins as an output/INPUTS.
	pinMode(LED_FRONT_RIGHT	, OUTPUT);
	pinMode(LED_FRONT_LEFT	, OUTPUT);
	pinMode(LED_LEFT		, OUTPUT);
	pinMode(LED_LEFT_BACK	, OUTPUT);
	pinMode(LED_BACK		, OUTPUT);
	pinMode(LED_RIGHT_BACK	, OUTPUT);
	pinMode(LED_RIGHT		, OUTPUT);
	
	pinMode(IR_FRONT_RIGHT	, INPUT_PULLUP);
	pinMode(IR_FRONT_LEFT	, INPUT_PULLUP);
	pinMode(IR_LEFT			, INPUT_PULLUP);
	pinMode(IR_LEFT_BACK	, INPUT_PULLUP);
	pinMode(IR_BACK			, INPUT_PULLUP);
	pinMode(IR_RIGHT_BACK	, INPUT_PULLUP);
	pinMode(IR_RIGHT		, INPUT_PULLUP);
	

	Serial.begin(57600);
	Serial.println("*** Begin ***");

	LEDCircleFlash();
	LEDCircleFlash();

}

// the loop function runs over and over again until power down or reset
void loop() {
	
	
	LEDCircleFlash();
	
	/*
	if (digitalRead(IR_8) == LOW)
	{
		ir1Counter += (ir1Counter < 250 ? 2 : 0);//if IR is on & if counter>250 then +2 t counter else +0
	}
	else
	{
		ir1Counter -= (ir1Counter > 0);//If IR is off then -1 (if counter > than 0)
	}

	
	if (ballDetected != (ir1Counter > 200))//if ir counter si inconsitant with ball detected
	{
		ballDetected = (ir1Counter > 200);//Set ball detected
		digitalWrite(LED_1, ballDetected);//turn LED on
	}*/
	
}

void LEDCircleFlash(void) {
	digitalWrite(LED_FRONT_RIGHT, HIGH);
	delay(100);
	digitalWrite(LED_FRONT_LEFT, HIGH);
	delay(100);
	digitalWrite(LED_LEFT, HIGH);
	delay(100);
	digitalWrite(LED_LEFT_BACK, HIGH);
	delay(100);
	digitalWrite(LED_BACK, HIGH);
	delay(100);
	digitalWrite(LED_RIGHT_BACK, HIGH);
	delay(100);
	digitalWrite(LED_RIGHT, HIGH);
	delay(100);
	digitalWrite(LED_FRONT_RIGHT, LOW);
	delay(100);
	digitalWrite(LED_FRONT_LEFT, LOW);
	delay(100);
	digitalWrite(LED_LEFT, LOW);
	delay(100);
	digitalWrite(LED_LEFT_BACK, LOW);
	delay(100);
	digitalWrite(LED_BACK, LOW);
	delay(100);
	digitalWrite(LED_RIGHT_BACK, LOW);
	delay(100);
	digitalWrite(LED_RIGHT, LOW);
	delay(100);
}