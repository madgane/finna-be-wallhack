/*
 *  ======== main.c ========
 */

#include "stdlib.h"
#include <xdc/std.h>
#include <xdc/runtime/System.h>

#include "globalDeclarations.h"

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <xdc/runtime/Error.h>

#include <ti/sysbios/knl/Clock.h>
#include <xdc/runtime/Types.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Swi.h>
#include <ti/sysbios/family/c66/Cache.h>

extern "C" {

Uint32 getTicks();
xdc_Void clockISRA(xdc_UArg a0, xdc_UArg a1);
xdc_Void clockISRB(xdc_UArg a0, xdc_UArg a1);
xdc_Void clockISRC(xdc_UArg a0, xdc_UArg a1);
xdc_Void idleFunction(xdc_UArg arg0,xdc_UArg arg1);
}

clock_t clockHandle;
extern Swi_Handle swiHandleA,swiHandleB,swiHandleC;

Int main()
{ 
	System_printf("Program Started ! \n");

	Cache_Size cacheConfig;
	cacheConfig.l1pSize = Cache_L1Size_32K;
	cacheConfig.l1dSize = Cache_L1Size_32K;
	cacheConfig.l2Size = Cache_L2Size_512K;

	Cache_enable(Cache_Type_ALL);
	Cache_setSize(&cacheConfig);
	Cache_setMar(&globalChannelMatrix,sizeof(globalChannelMatrix),0xFFFFFFFF);

	System_flush();
	BIOS_start();

	return(EXIT_SUCCESS);
}

xdc_Void idleFunction(xdc_UArg arg0,xdc_UArg arg1)
{
	System_printf("SWI_POST A at clock ISR at %u \n",getTicks());
	clockISRA(0,0);
	System_printf("SWI_POST B at clock ISR at %u \n",getTicks());
	clockISRB(0,0);
	System_printf("SWI_POST C at clock ISR at %u \n",getTicks());
	clockISRC(0,0);
}

xdc_Void clockISRA(xdc_UArg arg0,xdc_UArg arg1)
{
	Swi_post(swiHandleA);
	System_printf("Clock ISR running at %u \n",getTicks());
}

xdc_Void clockISRB(xdc_UArg arg0,xdc_UArg arg1)
{
	Swi_post(swiHandleB);
	System_printf("Clock ISR running at %u \n",getTicks());
}

xdc_Void clockISRC(xdc_UArg arg0,xdc_UArg arg1)
{
	Swi_post(swiHandleC);
	System_printf("Terminating ISR running at %u \n",getTicks());
}

Uint32 getTicks()
{
	return Clock_getTicks();
}
