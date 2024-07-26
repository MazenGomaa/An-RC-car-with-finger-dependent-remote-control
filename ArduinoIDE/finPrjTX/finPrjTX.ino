#include <movingAvg.h>

//Moving average object
#define NoOfSampels 5
movingAvg avg(NoOfSampels);

//Some definitions used for mapping and averaging
#define ADCmax 1024
#define ADCmin 0
#define SenseOffset 183
#define PWMmin 0
#define PWMmax 255

#define analogPin A3 //Pressure sensor analog pin

//Pins array for the 4 buttons, Forward, backward, right, left, in order
const uint8_t buttonPins[] = {9, 10, 11, 12};

//The data array to hold the Buttons state, VAL val for the pressure sensor
#define dataArrSize 2
uint8_t dataArr[dataArrSize] = {0,0};
#define RXButtonsStates dataArr[0] //index 0 is for buttons data
#define TXPadelVal dataArr[1]      //index 1 is for PWM val


void setup() {
	Serial.begin(38400); //init serial communication

	//Set pin modes of the used buttons and the analog pin
	for (int i = 0; i < 4; i++) {
		pinMode(buttonPins[i], INPUT);
	}
	pinMode(analogPin, INPUT);

	//init the moving average object
	avg.begin();

}

void loop() {
		//loop through Each button's state and store that in the Data array byte by sitting
		//the first 4 bits of the buttons state byte within the array respectively
		for (int i = 0; i < 4; i++) {
			if (digitalRead(buttonPins[i])) { //if a button is pressed, then set its respective bit
				bitSet(RXButtonsStates, i);
			}else{							  //if it's not, then clear its respective bit
				bitClear(RXButtonsStates, i);
			}
		}


		//Read the ADC value of the pressure sensor, then map it into a PWM value
		//then get a moving average value of the PWM value, then store that into the
		//PWM byte within the data array to be sent
		TXPadelVal  = avg.reading(map(analogRead(analogPin),ADCmin ,ADCmax - SenseOffset ,PWMmin ,PWMmax  ));

		//Send the Array through the serial as a set of bytes
		Serial.write(dataArr , dataArrSize);

		//wait for the serial transmit buffer to finish
		Serial.flush();

		//wait for the data to be received and processed
		delay(100);
}
