################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/lucifer/github/STM32F4/Drivers/I2C/i2c_driver.c 

OBJS += \
./Drivers/I2C/i2c_driver.o 

C_DEPS += \
./Drivers/I2C/i2c_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/I2C/i2c_driver.o: /home/lucifer/github/STM32F4/Drivers/I2C/i2c_driver.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F411VETx -DSTM32F411E_DISCO -DDEBUG -DSTM32F411xE -I"/home/lucifer/github/STM32F4/Examples/UART/inc" -I"/home/lucifer/github/STM32F4/Drivers" -I"/home/lucifer/github/STM32F4/Drivers/uart" -I"/home/lucifer/github/STM32F4/Examples/UART/CMSIS/device" -I"/home/lucifer/github/STM32F4/Examples/UART/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


