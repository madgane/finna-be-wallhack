#
_XDCBUILDCOUNT = 0
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /opt/ti/bios_6_40_01_15/packages;/opt/ti/mcsdk/uia_1_03_02_10/packages;/opt/ti/ccsv6/ccs_base;/home/ganesh/Documents/TI/finna-be-wallhack/.config
override XDCROOT = /opt/ti/xdctools_3_30_01_25_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /opt/ti/bios_6_40_01_15/packages;/opt/ti/mcsdk/uia_1_03_02_10/packages;/opt/ti/ccsv6/ccs_base;/home/ganesh/Documents/TI/finna-be-wallhack/.config;/opt/ti/xdctools_3_30_01_25_core/packages;..
HOSTOS = Linux
endif
