/*
 * pinConfig.h
 *
 *  Created on: Jul 26, 2024
 *      Author: DELL
 */

#ifndef PINCONFIG_H_
#define PINCONFIG_H_

//bluetooth connection state pin
#define btStat 2


//Motor Driver pins array
const int MotorDriverPins[5] = {3, 7, 6, 5, 4};
#define enA  MotorDriverPins[0]
#define in1  MotorDriverPins[1]
#define in2  MotorDriverPins[2]
#define in3  MotorDriverPins[3]
#define in4  MotorDriverPins[4]

#endif /* PINCONFIG_H_ */
