################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:\Users\DELL\Desktop\eclipse\eclipse24emb\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\Wire\src\utility\twi.c 

C_DEPS += \
.\libraries\Wire\src\utility\twi.c.d 

LINK_OBJ += \
.\libraries\Wire\src\utility\twi.c.o 


# Each subdirectory must supply rules for building sources it contributes
libraries\Wire\src\utility\twi.c.o: C:\Users\DELL\Desktop\eclipse\eclipse24emb\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\Wire\src\utility\twi.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"C:\Users\DELL\Desktop\eclipse\eclipse24emb\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\Users\DELL\Desktop\eclipse\eclipse24emb\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\variants\eightanaloginputs" -I"C:\Users\DELL\Desktop\eclipse\eclipse24emb\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\cores\arduino" -I"C:\Users\DELL\Documents\Arduino\libraries\Adafruit_BusIO" -I"C:\Users\DELL\Documents\Arduino\libraries\Adafruit_GFX_Library" -I"C:\Users\DELL\Documents\Arduino\libraries\Adafruit_SSD1306" -I"C:\Users\DELL\Desktop\eclipse\eclipse24emb\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\Wire\src" -I"C:\Users\DELL\Desktop\eclipse\eclipse24emb\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SPI\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<" -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


