################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/admsLocal/Documents/stm/projects/en.stsw-stm32072/STM32L-Discovery_FW_Pack/Projects/AN3413-Current_consumption_touch_sensing/src/discover_functions.c \
C:/Users/admsLocal/Documents/stm/projects/en.stsw-stm32072/STM32L-Discovery_FW_Pack/Projects/AN3413-Current_consumption_touch_sensing/src/icc_measure.c \
C:/Users/admsLocal/Documents/stm/projects/en.stsw-stm32072/STM32L-Discovery_FW_Pack/Projects/AN3413-Current_consumption_touch_sensing/src/icc_measure_Ram.c \
C:/Users/admsLocal/Documents/stm/projects/en.stsw-stm32072/STM32L-Discovery_FW_Pack/Projects/AN3413-Current_consumption_touch_sensing/src/main.c \
C:/Users/admsLocal/Documents/stm/projects/en.stsw-stm32072/STM32L-Discovery_FW_Pack/Projects/AN3413-Current_consumption_touch_sensing/src/stm32l1xx_it.c \
C:/Users/admsLocal/Documents/stm/projects/en.stsw-stm32072/STM32L-Discovery_FW_Pack/Projects/AN3413-Current_consumption_touch_sensing/src/tsl_user.c 

OBJS += \
./User/discover_functions.o \
./User/icc_measure.o \
./User/icc_measure_Ram.o \
./User/main.o \
./User/stm32l1xx_it.o \
./User/tsl_user.o 

C_DEPS += \
./User/discover_functions.d \
./User/icc_measure.d \
./User/icc_measure_Ram.d \
./User/main.d \
./User/stm32l1xx_it.d \
./User/tsl_user.d 


# Each subdirectory must supply rules for building sources it contributes
User/discover_functions.o: C:/Users/admsLocal/Documents/stm/projects/en.stsw-stm32072/STM32L-Discovery_FW_Pack/Projects/AN3413-Current_consumption_touch_sensing/src/discover_functions.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32L1XX_MD -DUSE_STDPERIPH_DRIVER -c -I../../../inc -I../../../../../Libraries/STMTouch_Driver/inc -I../../../../../Libraries/CMSIS/Include -I../../../../../Libraries/STM32L1xx_StdPeriph_Driver/inc -I../../../../../Libraries/CMSIS/Device/ST/STM32L1xx/Include -I../../../../../Utilities/STM32L-DISCOVERY -Os -ffunction-sections -fdata-sections -Wall -mlong-calls -Wno-pointer-sign -Wno-missing-braces -Wformat=0 -fstack-usage -MMD -MP -MF"User/discover_functions.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
User/icc_measure.o: C:/Users/admsLocal/Documents/stm/projects/en.stsw-stm32072/STM32L-Discovery_FW_Pack/Projects/AN3413-Current_consumption_touch_sensing/src/icc_measure.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32L1XX_MD -DUSE_STDPERIPH_DRIVER -c -I../../../inc -I../../../../../Libraries/STMTouch_Driver/inc -I../../../../../Libraries/CMSIS/Include -I../../../../../Libraries/STM32L1xx_StdPeriph_Driver/inc -I../../../../../Libraries/CMSIS/Device/ST/STM32L1xx/Include -I../../../../../Utilities/STM32L-DISCOVERY -Os -ffunction-sections -fdata-sections -Wall -mlong-calls -Wno-pointer-sign -Wno-missing-braces -Wformat=0 -fstack-usage -MMD -MP -MF"User/icc_measure.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
User/icc_measure_Ram.o: C:/Users/admsLocal/Documents/stm/projects/en.stsw-stm32072/STM32L-Discovery_FW_Pack/Projects/AN3413-Current_consumption_touch_sensing/src/icc_measure_Ram.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32L1XX_MD -DUSE_STDPERIPH_DRIVER -c -I../../../inc -I../../../../../Libraries/STMTouch_Driver/inc -I../../../../../Libraries/CMSIS/Include -I../../../../../Libraries/STM32L1xx_StdPeriph_Driver/inc -I../../../../../Libraries/CMSIS/Device/ST/STM32L1xx/Include -I../../../../../Utilities/STM32L-DISCOVERY -Os -ffunction-sections -fdata-sections -Wall -mlong-calls -Wno-pointer-sign -Wno-missing-braces -Wformat=0 -fstack-usage -MMD -MP -MF"User/icc_measure_Ram.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
User/main.o: C:/Users/admsLocal/Documents/stm/projects/en.stsw-stm32072/STM32L-Discovery_FW_Pack/Projects/AN3413-Current_consumption_touch_sensing/src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32L1XX_MD -DUSE_STDPERIPH_DRIVER -c -I../../../inc -I../../../../../Libraries/STMTouch_Driver/inc -I../../../../../Libraries/CMSIS/Include -I../../../../../Libraries/STM32L1xx_StdPeriph_Driver/inc -I../../../../../Libraries/CMSIS/Device/ST/STM32L1xx/Include -I../../../../../Utilities/STM32L-DISCOVERY -Os -ffunction-sections -fdata-sections -Wall -mlong-calls -Wno-pointer-sign -Wno-missing-braces -Wformat=0 -fstack-usage -MMD -MP -MF"User/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
User/stm32l1xx_it.o: C:/Users/admsLocal/Documents/stm/projects/en.stsw-stm32072/STM32L-Discovery_FW_Pack/Projects/AN3413-Current_consumption_touch_sensing/src/stm32l1xx_it.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32L1XX_MD -DUSE_STDPERIPH_DRIVER -c -I../../../inc -I../../../../../Libraries/STMTouch_Driver/inc -I../../../../../Libraries/CMSIS/Include -I../../../../../Libraries/STM32L1xx_StdPeriph_Driver/inc -I../../../../../Libraries/CMSIS/Device/ST/STM32L1xx/Include -I../../../../../Utilities/STM32L-DISCOVERY -Os -ffunction-sections -fdata-sections -Wall -mlong-calls -Wno-pointer-sign -Wno-missing-braces -Wformat=0 -fstack-usage -MMD -MP -MF"User/stm32l1xx_it.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
User/tsl_user.o: C:/Users/admsLocal/Documents/stm/projects/en.stsw-stm32072/STM32L-Discovery_FW_Pack/Projects/AN3413-Current_consumption_touch_sensing/src/tsl_user.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32L1XX_MD -DUSE_STDPERIPH_DRIVER -c -I../../../inc -I../../../../../Libraries/STMTouch_Driver/inc -I../../../../../Libraries/CMSIS/Include -I../../../../../Libraries/STM32L1xx_StdPeriph_Driver/inc -I../../../../../Libraries/CMSIS/Device/ST/STM32L1xx/Include -I../../../../../Utilities/STM32L-DISCOVERY -Os -ffunction-sections -fdata-sections -Wall -mlong-calls -Wno-pointer-sign -Wno-missing-braces -Wformat=0 -fstack-usage -MMD -MP -MF"User/tsl_user.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

