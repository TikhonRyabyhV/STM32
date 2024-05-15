################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GUI\ HAL\ library/stm32f7xx_hal_ltdc.c \
../GUI\ HAL\ library/stm32f7xx_hal_ltdc_ex.c \
../GUI\ HAL\ library/stm32f7xx_hal_sdram.c \
../GUI\ HAL\ library/stm32f7xx_hal_uart.c \
../GUI\ HAL\ library/stm32f7xx_ll_fmc.c 

OBJS += \
./GUI\ HAL\ library/stm32f7xx_hal_ltdc.o \
./GUI\ HAL\ library/stm32f7xx_hal_ltdc_ex.o \
./GUI\ HAL\ library/stm32f7xx_hal_sdram.o \
./GUI\ HAL\ library/stm32f7xx_hal_uart.o \
./GUI\ HAL\ library/stm32f7xx_ll_fmc.o 

C_DEPS += \
./GUI\ HAL\ library/stm32f7xx_hal_ltdc.d \
./GUI\ HAL\ library/stm32f7xx_hal_ltdc_ex.d \
./GUI\ HAL\ library/stm32f7xx_hal_sdram.d \
./GUI\ HAL\ library/stm32f7xx_hal_uart.d \
./GUI\ HAL\ library/stm32f7xx_ll_fmc.d 


# Each subdirectory must supply rules for building sources it contributes
GUI\ HAL\ library/stm32f7xx_hal_ltdc.o: ../GUI\ HAL\ library/stm32f7xx_hal_ltdc.c GUI\ HAL\ library/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"../GUI files" -I"../GUI HAL library" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"GUI HAL library/stm32f7xx_hal_ltdc.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
GUI\ HAL\ library/stm32f7xx_hal_ltdc_ex.o: ../GUI\ HAL\ library/stm32f7xx_hal_ltdc_ex.c GUI\ HAL\ library/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"../GUI files" -I"../GUI HAL library" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"GUI HAL library/stm32f7xx_hal_ltdc_ex.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
GUI\ HAL\ library/stm32f7xx_hal_sdram.o: ../GUI\ HAL\ library/stm32f7xx_hal_sdram.c GUI\ HAL\ library/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"../GUI files" -I"../GUI HAL library" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"GUI HAL library/stm32f7xx_hal_sdram.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
GUI\ HAL\ library/stm32f7xx_hal_uart.o: ../GUI\ HAL\ library/stm32f7xx_hal_uart.c GUI\ HAL\ library/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"../GUI files" -I"../GUI HAL library" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"GUI HAL library/stm32f7xx_hal_uart.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
GUI\ HAL\ library/stm32f7xx_ll_fmc.o: ../GUI\ HAL\ library/stm32f7xx_ll_fmc.c GUI\ HAL\ library/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F746xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"../GUI files" -I"../GUI HAL library" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"GUI HAL library/stm32f7xx_ll_fmc.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

