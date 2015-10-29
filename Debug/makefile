################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: TPFinal_DigitalesIII.axf

# Tool invocations
TPFinal_DigitalesIII.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"E:\LPCXpresso_7.9.0_455\workspace\CMSISv2p00_LPC17xx\Debug" -Xlinker -Map="TPFinal_DigitalesIII.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "TPFinal_DigitalesIII_Debug.ld" -o "TPFinal_DigitalesIII.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) TPFinal_DigitalesIII.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "TPFinal_DigitalesIII.axf"; # arm-none-eabi-objcopy -v -O binary "TPFinal_DigitalesIII.axf" "TPFinal_DigitalesIII.bin" ; # checksum -p LPC1769 -d "TPFinal_DigitalesIII.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
