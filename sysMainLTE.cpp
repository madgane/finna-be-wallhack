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

xdc_Void lteSystemInit(xdc_UArg a0, xdc_UArg a1);
xdc_Void displaySchedulerInfo(xdc_UArg a0, xdc_UArg a1);

xdc_Void channelUpdate(xdc_UArg a0, xdc_UArg a1);
xdc_Void schedulingForCurrentSF(xdc_UArg a0, xdc_UArg a1);

}

extern Swi_Handle swiHandleA,swiHandleB;

Int main()
{ 
	System_printf("Program Started ! \n");
	System_flush();

	lteSystemInit(0,0);
	channelUpdate(0,0);
	schedulingForCurrentSF(0,0);
	displaySchedulerInfo(0,0);

	exit(1);




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



