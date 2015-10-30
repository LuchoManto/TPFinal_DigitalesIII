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
all: TP_Final.axf

# Tool invocations
TP_Final.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"F:\LUCHO\Facu\Cuartoo\ElectronicaDigital\Workspace\CMSISv2p00_LPC17xx\Debug" -Xlinker -Map="TP_Final.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "TP_Final_Debug.ld" -o "TP_Final.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) TP_Final.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "TP_Final.axf"; # arm-none-eabi-objcopy -v -O binary "TP_Final.axf" "TP_Final.bin" ; # checksum -p LPC1769 -d "TP_Final.bin";
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
