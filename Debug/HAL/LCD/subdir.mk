################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LCD/LCD.c 

OBJS += \
./HAL/LCD/LCD.o 

C_DEPS += \
./HAL/LCD/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LCD/%.o: ../HAL/LCD/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\#ITI\#16_Interfacing\ITI_Embedded\APP" -I"D:\#ITI\#16_Interfacing\ITI_Embedded\MCAL\GI" -I"D:\#ITI\#16_Interfacing\ITI_Embedded\MCAL\EXI" -I"D:\#ITI\#16_Interfacing\ITI_Embedded\HAL\KEYPAD" -I"D:\#ITI\#16_Interfacing\ITI_Embedded\HAL\LCD" -I"D:\#ITI\#16_Interfacing\ITI_Embedded\HAL" -I"D:\#ITI\#16_Interfacing\ITI_Embedded\LIB" -I"D:\#ITI\#16_Interfacing\ITI_Embedded\MCAL" -I"D:\#ITI\#16_Interfacing\ITI_Embedded\MCAL\DIO" -I"D:\#ITI\#16_Interfacing\ITI_Embedded\SERVICES" -Wall -g3 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


