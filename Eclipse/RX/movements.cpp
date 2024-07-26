#include <Arduino.h>
#include "movements.h"
#include "pinConfig.h"

void forward(){
	// Set Motor A reverse
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);

	// Set Motor B reverse
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);

}

void backward(){
	// Set Motor A forward
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);

	// Set Motor B forward
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
}

void right(){
	// Set Motor A reverse
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);

	// Set Motor B forward
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
}

void left(){
	// Set Motor A forward
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);

	// Set Motor B reverse
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
}

void stop(){
	// Set Motor A forward
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);

	// Set Motor B reverse
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}
