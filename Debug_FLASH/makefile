################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/Peripherals/subdir.mk
-include src/subdir.mk
-include generate/src/subdir.mk
-include board/subdir.mk
-include RTD/src/subdir.mk
-include Project_Settings/Startup_Code/subdir.mk
-include FreeMASTER/src/drivers/dreg/S32/subdir.mk
-include FreeMASTER/src/common/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_SIZE += \
FRDM_A_S32M276_PMSM_FOC_1Sh.siz \


# All Target
all: FRDM_A_S32M276_PMSM_FOC_1Sh.elf secondary-outputs

# Tool invocations
FRDM_A_S32M276_PMSM_FOC_1Sh.elf: $(OBJS) C:/Users/alovi/OneDrive/Documents/Remmen_Brakes/F108/NXP/BLDC_Control/Project_Settings/Linker_Files/linker_flash_s32m276.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Standard S32DS C Linker'
	arm-none-eabi-gcc -o "FRDM_A_S32M276_PMSM_FOC_1Sh.elf" "@FRDM_A_S32M276_PMSM_FOC_1Sh.args"  $(USER_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

FRDM_A_S32M276_PMSM_FOC_1Sh.siz: FRDM_A_S32M276_PMSM_FOC_1Sh.elf
	@echo 'Invoking: Standard S32DS Print Size'
	arm-none-eabi-size --format=berkeley FRDM_A_S32M276_PMSM_FOC_1Sh.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ./*
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
