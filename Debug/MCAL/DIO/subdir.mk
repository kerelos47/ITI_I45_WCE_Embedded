################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/DIO/DIO.c \
../MCAL/DIO/DIO_cfg.c 

OBJS += \
./MCAL/DIO/DIO.o \
./MCAL/DIO/DIO_cfg.o 

C_DEPS += \
./MCAL/DIO/DIO.d \
./MCAL/DIO/DIO_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/DIO/%.o: ../MCAL/DIO/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\#ITI\#16_Interfacing\ITI_Embedded\APP" -I"D:\#ITI\#16_Interfacing\ITI_Embedded\MCAL\EXI" -I"D:\#ITI\#16_Interfacing\ITI_Embedded\HAL\KEYPAD" -I"D:\#ITI\#16_Interfacing\ITI_Embedded\HAL\LCD" -I"D:\#ITI\#16_Interfacing\ITI_Embedded\HAL" -I"D:\#ITI\#16_Interfacing\ITI_Embedded\LIB" -I"D:\#ITI\#16_Interfacing\ITI_Embedded\MCAL" -I"D:\#ITI\#16_Interfacing\ITI_Embedded\MCAL\DIO" -I"D:\#ITI\#16_Interfacing\ITI_Embedded\SERVICES" -Wall -g3 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


