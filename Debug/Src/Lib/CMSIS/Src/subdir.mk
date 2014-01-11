################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Lib/CMSIS/Src/core_cm3.c \
../Src/Lib/CMSIS/Src/startup_stm32f10x.c \
../Src/Lib/CMSIS/Src/system_stm32f10x.c 

OBJS += \
./Src/Lib/CMSIS/Src/core_cm3.o \
./Src/Lib/CMSIS/Src/startup_stm32f10x.o \
./Src/Lib/CMSIS/Src/system_stm32f10x.o 

C_DEPS += \
./Src/Lib/CMSIS/Src/core_cm3.d \
./Src/Lib/CMSIS/Src/startup_stm32f10x.d \
./Src/Lib/CMSIS/Src/system_stm32f10x.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Lib/CMSIS/Src/%.o: ../Src/Lib/CMSIS/Src/%.c
	@echo '正在构建文件： $<'
	@echo '正在调用： Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -DDEBUG -I../Src/Include -I../Src/Lib/CMSIS/Include -I../Src/Lib/StdPeriph/Include -I../Src/Lib/Debug/Include -I../Src/User/Config -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '


