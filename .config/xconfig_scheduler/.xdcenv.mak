#
_XDCBUILDCOUNT = 0
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/ti/bios_6_40_01_15/packages;C:/ti/mcsdk_2_01_02_06/demos;C:/ti/dsplib_c66x_3_1_0_0/packages;C:/ti/ccsv6/ccs_base;C:/ti/ipc_1_24_03_32/packages;Y:/CCS/workspace_v6_0/finna-be-wallhack/.config
override XDCROOT = c:/ti/xdctools_3_30_03_47_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/ti/bios_6_40_01_15/packages;C:/ti/mcsdk_2_01_02_06/demos;C:/ti/dsplib_c66x_3_1_0_0/packages;C:/ti/ccsv6/ccs_base;C:/ti/ipc_1_24_03_32/packages;Y:/CCS/workspace_v6_0/finna-be-wallhack/.config;c:/ti/xdctools_3_30_03_47_core/packages;..
HOSTOS = Windows
endif
