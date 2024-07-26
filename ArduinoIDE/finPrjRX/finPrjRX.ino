#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


//Oled display object with its parameters, width, height, TWI object, reset
#define WIDTH 128     // OLED display width, in pixels
#define HEIGHT 64     // OLED display height, in pixels
#define RESET     -1  // Reset pin (-1 since its not used)
#define ADDRESS 0x3C  //OLED i2c address
Adafruit_SSD1306 display(WIDTH,HEIGHT, &Wire, RESET);

//Receive data array
byte dataArr[2] = {0,0};
#define speed dataArr[1]
#define ButtonsState dataArr[0]

//Motor Driver pins array
const byte MotorDriverPins[5] = {3, 7, 6, 5, 4};
#define enA  MotorDriverPins[0]
#define in1  MotorDriverPins[1]
#define in2  MotorDriverPins[2]
#define in3  MotorDriverPins[3]
#define in4  MotorDriverPins[4]

//bluetooth connection state pin
#define btStat 2


void setup() {

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
}

void loop() {

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
}




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


//function to directly print text on the OLED
void OledPrint(String text , int x, int y){
	display.clearDisplay();
	display.setCursor(x,y);
	display.print(text);
	display.display();
}

