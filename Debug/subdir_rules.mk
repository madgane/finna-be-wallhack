################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
lteSystem.obj: ../lteSystem.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"c:/ti/ccsv6/tools/compiler/c6000_7.4.8/bin/cl6x" -mv6600 --abi=eabi -g --include_path="c:/ti/ccsv6/tools/compiler/c6000_7.4.8/include" --include_path="Y:/CCS/workspace_v6_0/finna-be-wallhack/includes" --define=TEN_MHZ --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="lteSystem.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/linker.cmd: ../scheduler.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"c:/ti/xdctools_3_30_03_47_core/xs" --xdcpath="C:/ti/omp_1_01_03_02/packages;C:/ti/mcsdk_2_01_02_06/demos;C:/ti/dsplib_c66x_3_1_0_0/packages;C:/ti/ipc_1_24_03_32/packages;c:/ti/ccsv6/ccs_base;C:/ti/bios_6_40_01_15/packages;" xdc.tools.configuro -o configPkg -t ti.targets.elf.C66 -p ti.sdo.ipc.examples.platforms.evm6670.core0 -r release -c "c:/ti/ccsv6/tools/compiler/c6000_7.4.8" --compileOptions "-g --optimize_with_debug" "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/compiler.opt: | configPkg/linker.cmd
configPkg/: | configPkg/linker.cmd

sysMainLTE.obj: ../sysMainLTE.cpp $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"c:/ti/ccsv6/tools/compiler/c6000_7.4.8/bin/cl6x" -mv6600 --abi=eabi -g --include_path="c:/ti/ccsv6/tools/compiler/c6000_7.4.8/include" --include_path="Y:/CCS/workspace_v6_0/finna-be-wallhack/includes" --define=TEN_MHZ --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="sysMainLTE.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


