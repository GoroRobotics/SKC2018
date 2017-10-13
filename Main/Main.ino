/*
This example shows how to fade the built in LED using the analogWrite() function.

The analogWrite() function uses PWM, so if you want to change the pin you're 
using, be sure to use another PWM capable pin. (denoted by ~) 
*/

#define LED LED_BUILTIN		// LED is the built in LED pin
int brightness = 0;			// how bright the LED is
int fadeAmount = 5;			// how many points to fade the LED by
int fadespeed  = 15;		//the speed of the fade (in ms)
	

void setup() {
	pinMode(LED, OUTPUT);	// declare LED to be an output:
}//end setup


// the loop routine runs over and over again forever:
void loop() {
	
	analogWrite(LED, brightness);				// set the brightness of the led:

	brightness = brightness + fadeAmount;		// change the brightness for next time through the loop:
	
	if (brightness <= 0 || brightness >= 255){	// reverse the direction of the fading at the ends of the fade:
		fadeAmount = -fadeAmount;
	}//end if
	
	delay(fadespeed);								// wait for (speed) milliseconds to see the dimming effect
}//end loop