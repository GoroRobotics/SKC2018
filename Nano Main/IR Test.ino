
//Port C
#define LED_1 A2
#define LED_2 A1
#define LED_3 A0

//Port D
#define BTN_1 8
#define BTN_2 9
#define BTN_3 10
#define BTN_MASK B00000111

#define DELAY_MS 100

// the setup function runs once when you press reset or power the board
void setup() {
	
	// initialize digital pin LED_BUILTIN as an output.
	pinMode(LED_1, OUTPUT);
	pinMode(LED_2, OUTPUT);
	pinMode(LED_3, OUTPUT);
	pinMode(BTN_1, INPUT_PULLUP);
	pinMode(BTN_2, INPUT_PULLUP);
	pinMode(BTN_3, INPUT_PULLUP);

	Serial.begin(57600);
	Serial.println("*** Begin ***");
}

byte inputs_now = 0, inputs_prev = 0;

void loop() {
	//Serial.println("---------");
	
	do {
		//read inputs on POPRTB
		inputs_now = (~PINB & BTN_MASK);
	} while (inputs_now == inputs_prev); //loop untill input changes
	inputs_prev = inputs_now;

	Serial.println(inputs_now);// | B00000000, BIN);

	//set LEDs
	PORTC = inputs_now;

//	Serial.println("loop - End");
//	delay(DELAY_MS);
}