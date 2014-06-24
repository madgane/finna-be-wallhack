################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../lteSystem.cpp \
../sysMainLTE.cpp 

CFG_SRCS += \
../scheduler.cfg 

OBJS += \
./lteSystem.obj \
./sysMainLTE.obj 

CPP_DEPS += \
./lteSystem.pp \
./sysMainLTE.pp 

GEN_MISC_DIRS += \
./configPkg/ 

GEN_CMDS += \
./configPkg/linker.cmd 

GEN_OPTS += \
./configPkg/compiler.opt 

GEN_FILES += \
./configPkg/linker.cmd \
./configPkg/compiler.opt 

CPP_DEPS__QUOTED += \
"lteSystem.pp" \
"sysMainLTE.pp" 

GEN_FILES__QUOTED += \
"configPkg/linker.cmd" \
"configPkg/compiler.opt" 

GEN_MISC_DIRS__QUOTED += \
"configPkg/" 

OBJS__QUOTED += \
"lteSystem.obj" \
"sysMainLTE.obj" 

CPP_SRCS__QUOTED += \
"../lteSystem.cpp" \
"../sysMainLTE.cpp" 

GEN_CMDS__FLAG += \
-l"./configPkg/linker.cmd" 

GEN_OPTS__FLAG += \
--cmd_file="./configPkg/compiler.opt" 


