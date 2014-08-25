/****************************************************************************/
/*  C6678.cmd                                                               */
/*  Copyright (c) 2011 Texas Instruments Incorporated                       */
/*  Author: Rafael de Souza                                                 */
/*                                                                          */
/*    Description: This file is a sample linker command file that can be    */
/*                 used for linking programs built with the C compiler and  */
/*                 running the resulting .out file on an C6678              */
/*                 device.  Use it as a guideline.  You will want to        */
/*                 change the memory layout to match your specific C6xxx    */
/*                 target system.  You may want to change the allocation    */
/*                 scheme according to the size of your program.            */
/*                                                                          */
/*    Usage:       The map below divides the external memory in segments    */
/*                 Use the linker option --define=COREn=1                   */
/*                 Where n is the core number.                              */
/*                                                                          */
/****************************************************************************/

MEMORY
{
    CORE0_L2_SRAM:   o = 0x10800000 l = 0x00100000   /* 1024kB CORE0 L2/SRAM */
    CORE0_L1P_SRAM:  o = 0x10E00000 l = 0x00008000   /* 32kB CORE0 L1P/SRAM */
    CORE0_L1D_SRAM:  o = 0x10F00000 l = 0x00008000   /* 32kB CORE0 L1D/SRAM */
  
    CORE1_L2_SRAM:   o = 0x11800000 l = 0x00100000   /* 1024kB CORE1 L2/SRAM */
    CORE1_L1P_SRAM:  o = 0x11E00000 l = 0x00008000   /* 32kB CORE1 L1P/SRAM */
    CORE1_L1D_SRAM:  o = 0x11F00000 l = 0x00008000   /* 32kB CORE1 L1D/SRAM */
  
    CORE2_L2_SRAM:   o = 0x12800000 l = 0x00100000   /* 1024kB CORE2 L2/SRAM */
    CORE2_L1P_SRAM:  o = 0x12E00000 l = 0x00008000   /* 32kB CORE2 L1P/SRAM */
    CORE2_L1D_SRAM:  o = 0x12F00000 l = 0x00008000   /* 32kB CORE2 L1D/SRAM */
  
    CORE3_L2_SRAM:   o = 0x13800000 l = 0x00100000   /* 1024kB CORE3 L2/SRAM */
    CORE3_L1P_SRAM:  o = 0x13E00000 l = 0x00008000   /* 32kB CORE3 L1P/SRAM */
    CORE3_L1D_SRAM:  o = 0x13F00000 l = 0x00008000   /* 32kB CORE3 L1D/SRAM */
  }
 
//--stack_size=0x10000 /*64KB*/
//--heap_size=0x100000 /*1MB*/

SECTIONS
{

    .bigMem		   >  DDR3
    .memHeap	   >  MSMCSRAM

#ifdef CORE0

    .text          >  CORE0_L2_SRAM
    .stack         >  MSMCSRAM
    .bss           >  CORE0_L2_SRAM
    .cio           >  CORE0_L2_SRAM
    .const         >  CORE0_L2_SRAM
    .data          >  CORE0_L2_SRAM
    .switch        >  CORE0_L2_SRAM
    .sysmem        >  MSMCSRAM
    .far           >  MSMCSRAM
    .args          >  CORE0_L2_SRAM
    .ppinfo        >  CORE0_L2_SRAM
    .ppdata        >  CORE0_L2_SRAM
  
    /* COFF sections */
    .pinit         >  CORE0_L2_SRAM
    .cinit         >  CORE0_L2_SRAM
  
    /* EABI sections */
    .binit         >  CORE0_L2_SRAM
    .init_array    >  CORE0_L2_SRAM
    .neardata      >  CORE0_L2_SRAM
    .fardata       >  CORE0_L2_SRAM
    .rodata        >  CORE0_L2_SRAM
    .c6xabi.exidx  >  CORE0_L2_SRAM
    .c6xabi.extab  >  CORE0_L2_SRAM

#endif

#ifdef CORE1
    .text          >  CORE1_L2_SRAM
    .stack         >  MSMCSRAM
    .bss           >  CORE1_L2_SRAM
    .cio           >  CORE1_L2_SRAM
    .const         >  CORE1_L2_SRAM
    .data          >  CORE1_L2_SRAM
    .switch        >  CORE1_L2_SRAM
    .sysmem        >  MSMCSRAM
    .far           >  CORE1_L2_SRAM
    .args          >  CORE1_L2_SRAM
    .ppinfo        >  CORE1_L2_SRAM
    .ppdata        >  CORE1_L2_SRAM
  
    /* COFF sections */
    .pinit         >  CORE1_L2_SRAM
    .cinit         >  CORE1_L2_SRAM
  
    /* EABI sections */
    .binit         >  CORE1_L2_SRAM
    .init_array    >  CORE1_L2_SRAM
    .neardata      >  CORE1_L2_SRAM
    .fardata       >  CORE1_L2_SRAM
    .rodata        >  CORE1_L2_SRAM
    .c6xabi.exidx  >  CORE1_L2_SRAM
    .c6xabi.extab  >  CORE1_L2_SRAM
#endif

#ifdef CORE2
    .text          >  CORE2_L2_SRAM
    .stack         >  MSMCSRAM
    .bss           >  CORE2_L2_SRAM
    .cio           >  CORE2_L2_SRAM
    .const         >  CORE2_L2_SRAM
    .data          >  CORE2_L2_SRAM
    .switch        >  CORE2_L2_SRAM
    .sysmem        >  MSMCSRAM
    .far           >  CORE2_L2_SRAM
    .args          >  CORE2_L2_SRAM
    .ppinfo        >  CORE2_L2_SRAM
    .ppdata        >  CORE2_L2_SRAM
  
    /* COFF sections */
    .pinit         >  CORE2_L2_SRAM
    .cinit         >  CORE2_L2_SRAM
  
    /* EABI sections */
    .binit         >  CORE2_L2_SRAM
    .init_array    >  CORE2_L2_SRAM
    .neardata      >  CORE2_L2_SRAM
    .fardata       >  CORE2_L2_SRAM
    .rodata        >  CORE2_L2_SRAM
    .c6xabi.exidx  >  CORE2_L2_SRAM
    .c6xabi.extab  >  CORE2_L2_SRAM
#endif

#ifdef CORE3
    .text          >  CORE3_L2_SRAM
    .stack         >  MSMCSRAM
    .bss           >  CORE3_L2_SRAM
    .cio           >  CORE3_L2_SRAM
    .const         >  CORE3_L2_SRAM
    .data          >  CORE3_L2_SRAM
    .switch        >  CORE3_L2_SRAM
    .sysmem        >  MSMCSRAM
    .far           >  CORE3_L2_SRAM
    .args          >  CORE3_L2_SRAM
    .ppinfo        >  CORE3_L2_SRAM
    .ppdata        >  CORE3_L2_SRAM
  
    /* COFF sections */
    .pinit         >  CORE3_L2_SRAM
    .cinit         >  CORE3_L2_SRAM
  
    /* EABI sections */
    .binit         >  CORE3_L2_SRAM
    .init_array    >  CORE3_L2_SRAM
    .neardata      >  CORE3_L2_SRAM
    .fardata       >  CORE3_L2_SRAM
    .rodata        >  CORE3_L2_SRAM
    .c6xabi.exidx  >  CORE3_L2_SRAM
    .c6xabi.extab  >  CORE3_L2_SRAM
#endif

}
