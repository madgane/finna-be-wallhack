/*
 *  ======== main.c ========
 */

#include "stdlib.h"
#include <xdc/std.h>
#include <xdc/runtime/System.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <xdc/runtime/Error.h>

#include <ti/sysbios/hal/Cache.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Swi.h>
#include <ti/sysbios/knl/Clock.h>

extern "C" {

xdc_Void clockISRA(xdc_UArg a0, xdc_UArg a1);
xdc_Void clockISRB(xdc_UArg a0, xdc_UArg a1);
xdc_Void clockISRC(xdc_UArg a0, xdc_UArg a1);

}

extern Swi_Handle swiHandleA,swiHandleB,swiHandleC;

Int main()
{ 
	System_printf("Program Started ! \n");
	System_flush();

	BIOS_start();
    return(EXIT_SUCCESS);
}

xdc_Void clockISRA(xdc_UArg arg0,xdc_UArg arg1)
{
	Swi_post(swiHandleA);
	System_printf("Clock ISR running at %u \n",Clock_getTicks());
}

xdc_Void clockISRB(xdc_UArg arg0,xdc_UArg arg1)
{
	Swi_post(swiHandleB);
	System_printf("Clock ISR running at %u \n",Clock_getTicks());
}

xdc_Void clockISRC(xdc_UArg arg0,xdc_UArg arg1)
{
	Swi_post(swiHandleC);
	System_printf("Terminating ISR running at %u \n",Clock_getTicks());
}


