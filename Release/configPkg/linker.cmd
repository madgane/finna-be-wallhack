/*
 * Do not modify this file; it is automatically generated from the template
 * linkcmd.xdt in the ti.targets.elf package and will be overwritten.
 */

/*
 * put '"'s around paths because, without this, the linker
 * considers '-' as minus operator, not a file name character.
 */


-l"/home/ganesh/Templates/workspace_ti/schedulerTIKernel/Release/configPkg/package/cfg/app_pe66.oe66"
-l"/opt/ti/mcsdk/uia_1_03_02_10/packages/ti/uia/services/lib/release/ti.uia.services.ae66"
-l"/opt/ti/mcsdk/uia_1_03_02_10/packages/ti/uia/sysbios/lib/release/ti.uia.sysbios.ae66"
-l"/opt/ti/mcsdk/uia_1_03_02_10/packages/ti/uia/family/c66/lib/release/ti.uia.family.c66.ae66"
-l"/opt/ti/mcsdk/uia_1_03_02_10/packages/ti/uia/runtime/lib/release/ti.uia.runtime.ae66"
-l"/home/ganesh/Templates/workspace_ti/schedulerTIKernel/src/sysbios/sysbios.ae66"
-l"/opt/ti/mcsdk/uia_1_03_02_10/packages/ti/uia/events/lib/release/ti.uia.events.ae66"
-l"/opt/ti/bios_6_40_01_15/packages/ti/targets/rts6000/lib/ti.targets.rts6000.ae66"
-l"/opt/ti/bios_6_40_01_15/packages/ti/targets/rts6000/lib/boot.ae66"

--retain="*(xdc.meta)"


--args 0x200
-heap  0x0
-stack 0x200

MEMORY
{
    L2SRAM (RWX) : org = 0x800000, len = 0x100000
    MSMCSRAM (RWX) : org = 0xc000000, len = 0x200000
    DDR3 : org = 0x80000000, len = 0x20000000
}

/*
 * Linker command file contributions from all loaded packages:
 */

/* Content from xdc.services.global (null): */

/* Content from xdc (null): */

/* Content from xdc.corevers (null): */

/* Content from xdc.shelf (null): */

/* Content from xdc.services.spec (null): */

/* Content from xdc.services.intern.xsr (null): */

/* Content from xdc.services.intern.gen (null): */

/* Content from xdc.services.intern.cmd (null): */

/* Content from xdc.bld (null): */

/* Content from ti.targets (null): */

/* Content from ti.targets.elf (null): */

/* Content from xdc.rov (null): */

/* Content from xdc.runtime (null): */

/* Content from ti.targets.rts6000 (null): */

/* Content from ti.sysbios.interfaces (null): */

/* Content from ti.sysbios.family (null): */

/* Content from xdc.services.getset (null): */

/* Content from ti.sysbios.hal (null): */

/* Content from xdc.rta (null): */

/* Content from ti.uia.events (null): */

/* Content from xdc.runtime.knl (null): */

/* Content from ti.sysbios.family.c66 (ti/sysbios/family/c66/linkcmd.xdt): */

/* Content from ti.sysbios.rts (ti/sysbios/rts/linkcmd.xdt): */

/* Content from ti.sysbios.family.c62 (null): */

/* Content from ti.sysbios.family.c64p.tci6488 (null): */

/* Content from ti.catalog.c6000 (null): */

/* Content from ti.catalog (null): */

/* Content from ti.catalog.peripherals.hdvicp2 (null): */

/* Content from xdc.platform (null): */

/* Content from xdc.cfg (null): */

/* Content from ti.platforms.evm6670 (null): */

/* Content from ti.sysbios (null): */

/* Content from ti.sysbios.knl (null): */

/* Content from ti.sysbios.family.c64p (ti/sysbios/family/c64p/linkcmd.xdt): */

/* Content from ti.sysbios.utils (null): */

/* Content from ti.sysbios.syncs (null): */

/* Content from ti.sysbios.gates (null): */

/* Content from ti.sysbios.heaps (null): */

/* Content from ti.sysbios.xdcruntime (null): */

/* Content from ti.sysbios.timers.timer64 (null): */

/* Content from ti.uia.runtime (null): */

/* Content from ti.uia.family.c66 (null): */

/* Content from ti.uia.sysbios (null): */

/* Content from ti.uia.services (null): */

/* Content from configPkg (null): */

/* Content from xdc.services.io (null): */


/*
 * symbolic aliases for static instance objects
 */
xdc_runtime_Startup__EXECFXN__C = 1;
xdc_runtime_Startup__RESETFXN__C = 1;
TSK_idle = ti_sysbios_knl_Task_Object__table__V + 80;

SECTIONS
{
    .text: load >> L2SRAM
    .ti.decompress: load > L2SRAM
    .stack: load > L2SRAM
    GROUP: load > L2SRAM
    {
        .bss:
        .neardata:
        .rodata:
    }
    .cinit: load > L2SRAM
    .pinit: load >> L2SRAM
    .init_array: load > L2SRAM
    .const: load >> L2SRAM
    .data: load >> L2SRAM
    .fardata: load >> L2SRAM
    .switch: load >> L2SRAM
    .sysmem: load > L2SRAM
    .far: load >> L2SRAM
    .args: load > L2SRAM align = 0x4, fill = 0 {_argsize = 0x200; }
    .cio: load >> L2SRAM
    .ti.handler_table: load > L2SRAM
    .c6xabi.exidx: load > L2SRAM
    .c6xabi.extab: load >> L2SRAM
    .bigmem: load > MSMCSRAM
    .ddrMem: load > DDR3
    .memHeap: load > MSMCSRAM
    .vecs: load > L2SRAM
    xdc.meta: load > L2SRAM, type = COPY
    xdc.noload: load > L2SRAM, type = COPY

}
