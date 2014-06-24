################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
lteSystem.obj: ../lteSystem.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/c6000_7.6.0/bin/cl6x" -mv6600 --abi=eabi -O2 --include_path="/opt/ti/c6000_7.6.0/include" --include_path="/home/ganesh/Documents/TI/finna-be-wallhack/includes" --define=_INLINE --define=TEN_MHZ --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="lteSystem.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/linker.cmd: ../scheduler.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"/opt/ti/xdctools_3_30_01_25_core/xs" --xdcpath="/opt/ti/bios_6_40_01_15/packages;/opt/ti/mcsdk/uia_1_03_02_10/packages;/opt/ti/ccsv6/ccs_base;" xdc.tools.configuro -o configPkg -t ti.targets.elf.C66 -p ti.platforms.evm6670 -r release -c "/opt/ti/c6000_7.6.0" --compileOptions "-g --optimize_with_debug" "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/compiler.opt: | configPkg/linker.cmd
configPkg/: | configPkg/linker.cmd

sysMainLTE.obj: ../sysMainLTE.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"/opt/ti/c6000_7.6.0/bin/cl6x" -mv6600 --abi=eabi -O2 --include_path="/opt/ti/c6000_7.6.0/include" --include_path="/home/ganesh/Documents/TI/finna-be-wallhack/includes" --define=_INLINE --define=TEN_MHZ --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="sysMainLTE.pp" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: $<'
	@echo ' '


