################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
framework/displayFunctions.obj: ../framework/displayFunctions.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/c6000_7.6.0/bin/cl6x" -mv6600 --abi=eabi --include_path="/opt/ti/c6000_7.6.0/include" --include_path="/home/ganesh/ti/schedulerTIKernel/includes" -g --define=TEN_MHZ --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="framework/displayFunctions.pp" --obj_directory="framework" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

framework/dynamicMemory.obj: ../framework/dynamicMemory.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/c6000_7.6.0/bin/cl6x" -mv6600 --abi=eabi --include_path="/opt/ti/c6000_7.6.0/include" --include_path="/home/ganesh/ti/schedulerTIKernel/includes" -g --define=TEN_MHZ --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="framework/dynamicMemory.pp" --obj_directory="framework" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

framework/frameworkFunctions.obj: ../framework/frameworkFunctions.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/c6000_7.6.0/bin/cl6x" -mv6600 --abi=eabi --include_path="/opt/ti/c6000_7.6.0/include" --include_path="/home/ganesh/ti/schedulerTIKernel/includes" -g --define=TEN_MHZ --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="framework/frameworkFunctions.pp" --obj_directory="framework" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

framework/memoryManagement.obj: ../framework/memoryManagement.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/c6000_7.6.0/bin/cl6x" -mv6600 --abi=eabi --include_path="/opt/ti/c6000_7.6.0/include" --include_path="/home/ganesh/ti/schedulerTIKernel/includes" -g --define=TEN_MHZ --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="framework/memoryManagement.pp" --obj_directory="framework" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

framework/schedulingAlgorithms.obj: ../framework/schedulingAlgorithms.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/c6000_7.6.0/bin/cl6x" -mv6600 --abi=eabi --include_path="/opt/ti/c6000_7.6.0/include" --include_path="/home/ganesh/ti/schedulerTIKernel/includes" -g --define=TEN_MHZ --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="framework/schedulingAlgorithms.pp" --obj_directory="framework" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


