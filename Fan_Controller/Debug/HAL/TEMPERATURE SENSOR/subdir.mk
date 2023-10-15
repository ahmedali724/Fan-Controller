################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/TEMPERATURE\ SENSOR/lm35_sensor.c 

OBJS += \
./HAL/TEMPERATURE\ SENSOR/lm35_sensor.o 

C_DEPS += \
./HAL/TEMPERATURE\ SENSOR/lm35_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/TEMPERATURE\ SENSOR/lm35_sensor.o: ../HAL/TEMPERATURE\ SENSOR/lm35_sensor.c HAL/TEMPERATURE\ SENSOR/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"HAL/TEMPERATURE SENSOR/lm35_sensor.d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


