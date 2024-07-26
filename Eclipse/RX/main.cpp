#include "includes.h"


//function to directly print text on the OLED
void OledPrint(String text , int x, int y){
	display.clearDisplay();
	display.setCursor(x,y);
	display.print(text);
	display.display();
}


int main(void){
	//for using the Arduino framework calling these functions is needed
	init();
	initVariant();

	//pins mode setup
	pinMode(btStat, INPUT_PULLUP);

	for (int i = 0; i < 5; i++) {
		pinMode(MotorDriverPins[i], OUTPUT);
	}

	//init serial
	Serial.begin(38400);

	//init display
	display.begin(SSD1306_SWITCHCAPVCC, ADDRESS);

	//stop the car in case of random values on the output at startup
	stop();

	//Set the display sittings
	display.clearDisplay();
	display.setTextSize(2);
	display.setTextColor(SSD1306_WHITE);
	display.display();


	while(1) {

		//if bluetooth is connected
		if(digitalRead(btStat)){

			//if there's more 2 bytes of data in the UART receive buffer, Load those
			//bytes into the receive data array
			if (Serial.available() >= 2) {
				Serial.readBytes(dataArr, 2 );
			}else{ //else, empty the receive buffer
				int temp = Serial.read();
			}

			//set the PWM value as received from the receive data array
			analogWrite(enA, speed);

			//switch between the buttons state values from their respective byte from the
			//Receive data array
			switch (ButtonsState){

			case 0b00001110:
				forward();
				OledPrint("Forward", 20, 20);
				break;

			case 0b00001101:
				backward();
				OledPrint("Backward", 20, 20);
				break;

			case 0b00001011:
				right();
				OledPrint("Right", 20, 20);
				break;

			case 0b00000111:
				left();
				OledPrint("Left", 20, 20);
				break;

			default:
				stop();
				OledPrint("Stopped", 20, 20);
				break;
			}

			 //else if the bluetooth is not connected, show on
			 //display and stop the car and empty the receive buffer
		}else{
			stop();
			OledPrint("The remote\nis not\nconnected\n", 0, 0);
			int temp = Serial.read();
		}

		//a small delay for the serial to stabilize
		delay(10);

		//to check and load any data through serial (Required by the arduino core)
		if (serialEventRun) serialEventRun();
	}

	return 0;
}

