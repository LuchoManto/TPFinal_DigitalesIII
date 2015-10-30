################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/TP_Final.c \
../src/control_motor.c \
../src/control_velocidad.c \
../src/conversor.c \
../src/cr_startup_lpc175x_6x.c \
../src/crp.c \
../src/serial.c 

OBJS += \
./src/TP_Final.o \
./src/control_motor.o \
./src/control_velocidad.o \
./src/conversor.o \
./src/cr_startup_lpc175x_6x.o \
./src/crp.o \
./src/serial.o 

C_DEPS += \
./src/TP_Final.d \
./src/control_motor.d \
./src/control_velocidad.d \
./src/conversor.d \
./src/cr_startup_lpc175x_6x.d \
./src/crp.d \
./src/serial.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__USE_CMSIS=CMSISv2p00_LPC17xx -D__LPC17XX__ -D__REDLIB__ -I"F:\LUCHO\Facu\Cuartoo\ElectronicaDigital\Workspace\CMSISv2p00_LPC17xx\inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


