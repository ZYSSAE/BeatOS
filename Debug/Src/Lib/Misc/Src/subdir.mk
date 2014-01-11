################################################################################
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Lib/Misc/Src/_sbrk.c \
../Src/Lib/Misc/Src/syscalls.c 

OBJS += \
./Src/Lib/Misc/Src/_sbrk.o \
./Src/Lib/Misc/Src/syscalls.o 

C_DEPS += \
./Src/Lib/Misc/Src/_sbrk.d \
./Src/Lib/Misc/Src/syscalls.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Lib/Misc/Src/%.o: ../Src/Lib/Misc/Src/%.c
	@echo '���ڹ����ļ��� $<'
	@echo '���ڵ��ã� Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -DDEBUG -I../Src/Include -I../Src/Lib/CMSIS/Include -I../Src/Lib/Misc/Include -I../Src/Lib/StdPeriph/Include -I../Src/IO/Config -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo '�ѽ��������� $<'
	@echo ' '


