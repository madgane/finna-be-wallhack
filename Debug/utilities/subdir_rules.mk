################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
utilities/blasFunctions.obj: ../utilities/blasFunctions.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"c:/ti/ccsv6/tools/compiler/c6000_7.4.8/bin/cl6x" -mv6600 --abi=eabi -g --include_path="c:/ti/ccsv6/tools/compiler/c6000_7.4.8/include" --include_path="Y:/CCS/workspace_v6_0/finna-be-wallhack/includes" --define=TEN_MHZ --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="utilities/blasFunctions.pp" --obj_directory="utilities" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

utilities/lapackFunctions.obj: ../utilities/lapackFunctions.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"c:/ti/ccsv6/tools/compiler/c6000_7.4.8/bin/cl6x" -mv6600 --abi=eabi -g --include_path="c:/ti/ccsv6/tools/compiler/c6000_7.4.8/include" --include_path="Y:/CCS/workspace_v6_0/finna-be-wallhack/includes" --define=TEN_MHZ --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="utilities/lapackFunctions.pp" --obj_directory="utilities" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


