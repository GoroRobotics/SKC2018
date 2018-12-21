/*
Blink
Turns on an LED on for one second, then off for one second, repeatedly.

Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
it is attached to digital pin 12, on MKR1000 on pin 6. 12 is set to
the correct LED pin independent of which board is used.
If you want to know what pin the on-board LED is connected to on your Arduino model, check
the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products

1	RESET (or if disabled, D5, A0)
8	VCC
2	D3, A3
7	D2, A1 (SCK)
3	D4, A2
6	D1 (MISO)
4	GND
5	D0 (MOSI)

*/


// the setup function runs once when you press reset or power the board
void setup() {
	// initialize digital pin 12 as an output.
	pinMode(1, OUTPUT);
	pinMode(2, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
	digitalWrite(1, HIGH);		// turn the LED on (HIGH is the voltage level)
	digitalWrite(2, LOW);		// turn the LED on (HIGH is the voltage level)
	delay(1000);                // wait for a second
	digitalWrite(1, LOW);		// turn the LED off by making the voltage LOW
	digitalWrite(2, HIGH);		// turn the LED off by making the voltage LOW
	delay(1000);                // wait for a second
}