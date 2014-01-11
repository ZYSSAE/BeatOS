################################################################################
# 自动生成的文件。不要编辑！
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Src/User/subdir.mk
-include Src/Lib/StdPeriph/Src/subdir.mk
-include Src/Lib/Debug/Src/subdir.mk
-include Src/Lib/CMSIS/Src/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
BeatOS-STM32.bin \


# 所有目标
all: BeatOS-STM32.elf secondary-outputs

# 工具调用
BeatOS-STM32.elf: $(OBJS) $(USER_OBJS)
	@echo '正在构建目标： $@'
	@echo '正在调用： Cross ARM C Linker'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -T STM32.ld -nostartfiles -Xlinker --gc-sections -L../Src/LinkScript -Wl,-Map,"BeatOS-STM32.map" -o "BeatOS-STM32.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo '已结束构建目标： $@'
	@echo ' '

BeatOS-STM32.bin: BeatOS-STM32.elf
	@echo '正在调用： Cross ARM GNU Create Flash Image'
	arm-none-eabi-objcopy "BeatOS-STM32.elf" -O binary  "BeatOS-STM32.bin"
	@echo '已结束构建： $@'
	@echo ' '

# 其他目标
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(SECONDARY_FLASH)$(S_UPPER_DEPS) BeatOS-STM32.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
