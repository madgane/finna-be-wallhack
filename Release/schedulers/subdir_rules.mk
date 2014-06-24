################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
schedulers/greedyScheduling.obj: ../schedulers/greedyScheduling.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/c6000_7.6.0/bin/cl6x" -mv6600 --abi=eabi -O2 --include_path="/opt/ti/c6000_7.6.0/include" --include_path="/home/ganesh/Documents/TI/finna-be-wallhack/includes" --define=_INLINE --define=TEN_MHZ --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="schedulers/greedyScheduling.pp" --obj_directory="schedulers" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

schedulers/pipdScheduling.obj: ../schedulers/pipdScheduling.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/c6000_7.6.0/bin/cl6x" -mv6600 --abi=eabi -O2 --include_path="/opt/ti/c6000_7.6.0/include" --include_path="/home/ganesh/Documents/TI/finna-be-wallhack/includes" --define=_INLINE --define=TEN_MHZ --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="schedulers/pipdScheduling.pp" --obj_directory="schedulers" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

schedulers/randomScheduling.obj: ../schedulers/randomScheduling.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/c6000_7.6.0/bin/cl6x" -mv6600 --abi=eabi -O2 --include_path="/opt/ti/c6000_7.6.0/include" --include_path="/home/ganesh/Documents/TI/finna-be-wallhack/includes" --define=_INLINE --define=TEN_MHZ --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="schedulers/randomScheduling.pp" --obj_directory="schedulers" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

schedulers/succprojScheduling.obj: ../schedulers/succprojScheduling.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/c6000_7.6.0/bin/cl6x" -mv6600 --abi=eabi -O2 --include_path="/opt/ti/c6000_7.6.0/include" --include_path="/home/ganesh/Documents/TI/finna-be-wallhack/includes" --define=_INLINE --define=TEN_MHZ --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="schedulers/succprojScheduling.pp" --obj_directory="schedulers" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


