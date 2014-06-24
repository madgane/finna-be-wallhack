################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
utilities/blasFunctions.obj: ../utilities/blasFunctions.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/c6000_7.6.0/bin/cl6x" -mv6600 --abi=eabi -O2 --include_path="/opt/ti/c6000_7.6.0/include" --include_path="/home/ganesh/Documents/TI/finna-be-wallhack/includes" --define=_INLINE --define=TEN_MHZ --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="utilities/blasFunctions.pp" --obj_directory="utilities" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

utilities/lapackFunctions.obj: ../utilities/lapackFunctions.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/c6000_7.6.0/bin/cl6x" -mv6600 --abi=eabi -O2 --include_path="/opt/ti/c6000_7.6.0/include" --include_path="/home/ganesh/Documents/TI/finna-be-wallhack/includes" --define=_INLINE --define=TEN_MHZ --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="utilities/lapackFunctions.pp" --obj_directory="utilities" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


