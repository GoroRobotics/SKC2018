
//Port C
#define LED_1 A0
#define LED_2 A1
#define LED_3 A2
#define LED_4 A3
#define LED_5 A4
#define LED_6 A5


//Port D
#define IR_1 1
#define IR_2 2
#define IR_3 3
#define IR_4 4
#define IR_5 5
#define IR_6 6
#define IR_7 7
#define IR_8 8

#define IR_MASK B00000111

#define DELAY_MS 100

// the setup function runs once when you press reset or power the board
void setup() {
	
	// initialize digital pin LED_BUILTIN as an output.
	pinMode(LED_1, OUTPUT);
	pinMode(LED_2, OUTPUT);
	pinMode(LED_3, OUTPUT);
	pinMode(LED_4, OUTPUT);
	pinMode(LED_5, OUTPUT);
	pinMode(LED_6, OUTPUT);
	pinMode(IR_1, INPUT_PULLUP);
	pinMode(IR_2, INPUT_PULLUP);
	pinMode(IR_3, INPUT_PULLUP);
	pinMode(IR_4, INPUT_PULLUP);
	pinMode(IR_5, INPUT_PULLUP);
	pinMode(IR_6, INPUT_PULLUP);
	pinMode(IR_7, INPUT_PULLUP);
	pinMode(IR_8, INPUT_PULLUP);

	//Serial.begin(57600);
	//Serial.println("*** Begin ***");
}

byte inputs_now = 0, inputs_prev = 0;

void loop() {
	//Serial.println("---------");
	
	do {
		//read inputs on POPRTB
		inputs_now = (~PINB & IR_MASK);
	} while (inputs_now == inputs_prev); //loop untill input changes
	inputs_prev = inputs_now;

	//Serial.println(inputs_now);// | B00000000, BIN);

	//set LEDs
	PORTC = inputs_now;

//	Serial.println("loop - End");
//	delay(DELAY_MS);
}