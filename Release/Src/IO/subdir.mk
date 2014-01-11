################################################################################
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/IO/Interrupt.c 

S_UPPER_SRCS += \
../Src/IO/startup_stm32f10x_hd.S 

OBJS += \
./Src/IO/Interrupt.o \
./Src/IO/startup_stm32f10x_hd.o 

C_DEPS += \
./Src/IO/Interrupt.d 

S_UPPER_DEPS += \
./Src/IO/startup_stm32f10x_hd.d 


# Each subdirectory must supply rules for building sources it contributes
Src/IO/%.o: ../Src/IO/%.c
	@echo '���ڹ����ļ��� $<'
	@echo '���ڵ��ã� Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O3 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g -I../Src/Include -I../Src/Lib/CMSIS/Include -I../Src/Lib/StdPeriph/Include -I../Src/IO/Config -I../Src/Lib/Debug/Include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo '�ѽ��������� $<'
	@echo ' '

Src/IO/%.o: ../Src/IO/%.S
	@echo '���ڹ����ļ��� $<'
	@echo '���ڵ��ã� Cross ARM GNU Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O3 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g -x assembler-with-cpp -I../Src/Include -I../Src/Lib/CMSIS/Include -I../Src/Lib/StdPeriph/Include -I../Src/IO/Config -I../Src/Lib/Debug/Include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo '�ѽ��������� $<'
	@echo ' '


