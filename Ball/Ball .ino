#define PinIR 8 //IR carrier output


void setup() {
	pinMode(PinIR, OUTPUT);
}


void loop() {
	
	for (int i = 0; i<32; i++) {
		digitalWrite(PinIR, HIGH);
		delayMicroseconds(11);
		digitalWrite(PinIR, LOW);
		delayMicroseconds(10);
	}

	for (int i = 0; i<32; i++) {
		digitalWrite(PinIR, LOW);
		delayMicroseconds(10);
		digitalWrite(PinIR, LOW);
		delayMicroseconds(10);
	}
}