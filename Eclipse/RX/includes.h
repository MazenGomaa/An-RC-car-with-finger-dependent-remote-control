/*
 * includes.h
 *
 *  Created on: Jul 26, 2024
 *      Author: DELL
 */

#ifndef INCLUDES_H_
#define INCLUDES_H_

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "movements.h"
#include "pinConfig.h"

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

#endif /* INCLUDES_H_ */
