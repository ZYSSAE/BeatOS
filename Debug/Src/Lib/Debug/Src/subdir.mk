################################################################################
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Lib/Debug/Src/ITM.c 

OBJS += \
./Src/Lib/Debug/Src/ITM.o 

C_DEPS += \
./Src/Lib/Debug/Src/ITM.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Lib/Debug/Src/%.o: ../Src/Lib/Debug/Src/%.c
	@echo '���ڹ����ļ��� $<'
	@echo '���ڵ��ã� Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -DDEBUG -I../Src/Include -I../Src/Lib/CMSIS/Include -I../Src/Lib/StdPeriph/Include -I../Src/Lib/Debug/Include -I../Src/User/Config -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo '�ѽ��������� $<'
	@echo ' '


