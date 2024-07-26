################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
..\main.cpp \
..\movements.cpp 

LINK_OBJ += \
.\main.cpp.o \
.\movements.cpp.o 

CPP_DEPS += \
.\main.cpp.d \
.\movements.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
main.cpp.o: ..\main.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\DELL\Desktop\eclipse\eclipse24emb\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\Users\DELL\Desktop\eclipse\eclipse24emb\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\variants\eightanaloginputs" -I"C:\Users\DELL\Desktop\eclipse\eclipse24emb\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\cores\arduino" -I"C:\Users\DELL\Documents\Arduino\libraries\Adafruit_BusIO" -I"C:\Users\DELL\Documents\Arduino\libraries\Adafruit_GFX_Library" -I"C:\Users\DELL\Documents\Arduino\libraries\Adafruit_SSD1306" -I"C:\Users\DELL\Desktop\eclipse\eclipse24emb\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\Wire\src" -I"C:\Users\DELL\Desktop\eclipse\eclipse24emb\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SPI\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<" -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

movements.cpp.o: ..\movements.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Users\DELL\Desktop\eclipse\eclipse24emb\arduinoPlugin\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-g++" -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_NANO -DARDUINO_ARCH_AVR   -I"C:\Users\DELL\Desktop\eclipse\eclipse24emb\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\variants\eightanaloginputs" -I"C:\Users\DELL\Desktop\eclipse\eclipse24emb\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\cores\arduino" -I"C:\Users\DELL\Documents\Arduino\libraries\Adafruit_BusIO" -I"C:\Users\DELL\Documents\Arduino\libraries\Adafruit_GFX_Library" -I"C:\Users\DELL\Documents\Arduino\libraries\Adafruit_SSD1306" -I"C:\Users\DELL\Desktop\eclipse\eclipse24emb\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\Wire\src" -I"C:\Users\DELL\Desktop\eclipse\eclipse24emb\arduinoPlugin\packages\arduino\hardware\avr\1.8.6\libraries\SPI\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<" -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


