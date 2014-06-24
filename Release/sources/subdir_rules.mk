################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
sources/globalDeclarations.obj: ../sources/globalDeclarations.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/c6000_7.6.0/bin/cl6x" -mv6600 --abi=eabi -O2 --include_path="/opt/ti/c6000_7.6.0/include" --include_path="/home/ganesh/ti/schedulerTIKernel/includes" --define=_INLINE --define=TEN_MHZ --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="sources/globalDeclarations.pp" --obj_directory="sources" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

sources/supportingFunctions.obj: ../sources/supportingFunctions.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/c6000_7.6.0/bin/cl6x" -mv6600 --abi=eabi -O2 --include_path="/opt/ti/c6000_7.6.0/include" --include_path="/home/ganesh/ti/schedulerTIKernel/includes" --define=_INLINE --define=TEN_MHZ --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="sources/supportingFunctions.pp" --obj_directory="sources" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


