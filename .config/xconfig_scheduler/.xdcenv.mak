#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = /opt/ti/bios_6_40_01_15/packages;/opt/ti/uia_1_03_02_10/packages;/opt/ti/ccsv6/ccs_base;/home/ganesh/ti/schedulerTIKernel/.config
override XDCROOT = /opt/ti/xdctools_3_30_02_44_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = /opt/ti/bios_6_40_01_15/packages;/opt/ti/uia_1_03_02_10/packages;/opt/ti/ccsv6/ccs_base;/home/ganesh/ti/schedulerTIKernel/.config;/opt/ti/xdctools_3_30_02_44_core/packages;..
HOSTOS = Linux
endif
