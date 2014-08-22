################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := c:/ti/ccsv6/tools/compiler/c6000_7.4.8

ORDERED_OBJS += \
$(GEN_CMDS__FLAG) \
"./lteSystem.obj" \
"./sysMainLTE.obj" \
"./utilities/blasFunctions.obj" \
"./utilities/lapackFunctions.obj" \
"./sources/globalDeclarations.obj" \
"./sources/supportingFunctions.obj" \
"./schedulers/greedyScheduling.obj" \
"./schedulers/pipdScheduling.obj" \
"./schedulers/randomScheduling.obj" \
"./schedulers/succprojScheduling.obj" \
"./framework/displayFunctions.obj" \
"./framework/dynamicMemory.obj" \
"./framework/frameworkFunctions.obj" \
"./framework/memoryManagement.obj" \
"./framework/schedulingAlgorithms.obj" \
"../C6678.cmd" \
-l"libc.a" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include utilities/subdir_vars.mk
-include sources/subdir_vars.mk
-include schedulers/subdir_vars.mk
-include framework/subdir_vars.mk
-include subdir_rules.mk
-include utilities/subdir_rules.mk
-include sources/subdir_rules.mk
-include schedulers/subdir_rules.mk
-include framework/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
finna-be-wallhack.out \

EXE_OUTPUTS__QUOTED += \
"finna-be-wallhack.out" \

BIN_OUTPUTS += \
finna-be-wallhack.hex \

BIN_OUTPUTS__QUOTED += \
"finna-be-wallhack.hex" \


# All Target
all: finna-be-wallhack.out

# Tool invocations
finna-be-wallhack.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C6000 Linker'
	"c:/ti/ccsv6/tools/compiler/c6000_7.4.8/bin/cl6x" -mv6600 --abi=eabi -g --define=TEN_MHZ --display_error_number --diag_warning=225 --diag_wrap=off -z -m"finna-be-wallhack.map" -i"c:/ti/ccsv6/tools/compiler/c6000_7.4.8/lib" -i"c:/ti/ccsv6/tools/compiler/c6000_7.4.8/include" --reread_libs --define=CORE0 --warn_sections --display_error_number --diag_wrap=off --xml_link_info="finna-be-wallhack_linkInfo.xml" --rom_model -o "finna-be-wallhack.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

finna-be-wallhack.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: C6000 Hex Utility'
	"c:/ti/ccsv6/tools/compiler/c6000_7.4.8/bin/hex6x"  -o "finna-be-wallhack.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "lteSystem.pp" "sysMainLTE.pp" "utilities\blasFunctions.pp" "utilities\lapackFunctions.pp" "sources\globalDeclarations.pp" "sources\supportingFunctions.pp" "schedulers\greedyScheduling.pp" "schedulers\pipdScheduling.pp" "schedulers\randomScheduling.pp" "schedulers\succprojScheduling.pp" "framework\displayFunctions.pp" "framework\dynamicMemory.pp" "framework\frameworkFunctions.pp" "framework\memoryManagement.pp" "framework\schedulingAlgorithms.pp" 
	-$(RM) "lteSystem.obj" "sysMainLTE.obj" "utilities\blasFunctions.obj" "utilities\lapackFunctions.obj" "sources\globalDeclarations.obj" "sources\supportingFunctions.obj" "schedulers\greedyScheduling.obj" "schedulers\pipdScheduling.obj" "schedulers\randomScheduling.obj" "schedulers\succprojScheduling.obj" "framework\displayFunctions.obj" "framework\dynamicMemory.obj" "framework\frameworkFunctions.obj" "framework\memoryManagement.obj" "framework\schedulingAlgorithms.obj" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

