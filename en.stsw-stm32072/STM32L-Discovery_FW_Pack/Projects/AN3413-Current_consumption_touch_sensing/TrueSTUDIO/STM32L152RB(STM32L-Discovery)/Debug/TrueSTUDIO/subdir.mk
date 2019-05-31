################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
C:/Users/admsLocal/Documents/stm/projects/en.stsw-stm32072/STM32L-Discovery_FW_Pack/Libraries/CMSIS/Device/ST/STM32L1xx/Source/Templates/TrueSTUDIO/startup_stm32l1xx_md.s 

OBJS += \
./TrueSTUDIO/startup_stm32l1xx_md.o 


# Each subdirectory must supply rules for building sources it contributes
TrueSTUDIO/startup_stm32l1xx_md.o: C:/Users/admsLocal/Documents/stm/projects/en.stsw-stm32072/STM32L-Discovery_FW_Pack/Libraries/CMSIS/Device/ST/STM32L1xx/Source/Templates/TrueSTUDIO/startup_stm32l1xx_md.s
	arm-none-eabi-gcc -mcpu=cortex-m3 -g3 -c -x assembler-with-cpp --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

