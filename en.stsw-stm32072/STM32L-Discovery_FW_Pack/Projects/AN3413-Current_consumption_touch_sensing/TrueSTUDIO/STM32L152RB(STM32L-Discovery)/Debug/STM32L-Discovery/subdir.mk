################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/admsLocal/Documents/stm/projects/en.stsw-stm32072/STM32L-Discovery_FW_Pack/Utilities/STM32L-DISCOVERY/stm32l_discovery_lcd.c 

OBJS += \
./STM32L-Discovery/stm32l_discovery_lcd.o 

C_DEPS += \
./STM32L-Discovery/stm32l_discovery_lcd.d 


# Each subdirectory must supply rules for building sources it contributes
STM32L-Discovery/stm32l_discovery_lcd.o: C:/Users/admsLocal/Documents/stm/projects/en.stsw-stm32072/STM32L-Discovery_FW_Pack/Utilities/STM32L-DISCOVERY/stm32l_discovery_lcd.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32L1XX_MD -DUSE_STDPERIPH_DRIVER -c -I../../../inc -I../../../../../Libraries/STMTouch_Driver/inc -I../../../../../Libraries/CMSIS/Include -I../../../../../Libraries/STM32L1xx_StdPeriph_Driver/inc -I../../../../../Libraries/CMSIS/Device/ST/STM32L1xx/Include -I../../../../../Utilities/STM32L-DISCOVERY -Os -ffunction-sections -fdata-sections -Wall -mlong-calls -Wno-pointer-sign -Wno-missing-braces -Wformat=0 -fstack-usage -MMD -MP -MF"STM32L-Discovery/stm32l_discovery_lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

