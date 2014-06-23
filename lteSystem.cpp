
#include "mainIncludes.h"
#include "globalDeclarations.h"
#include "frameworkFunctions.h"
#include "schedulingAlgorithms.h"
#include "displayFunctions.h"

#include <xdc/std.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Swi.h>
#include <xdc/runtime/System.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Semaphore.h>

uint16_t g_nUsers = 1;
uint16_t g_nTransmit = 8,g_nReceive = 8,g_nSchedBlocks = 1;

extern Semaphore_Handle reInitSystem;
extern Swi_Handle swiHandleA,swiHandleB;

extern "C" {

xdc_Void lteSystemInit(xdc_UArg a0, xdc_UArg a1);
xdc_Void displaySchedulerInfo(xdc_UArg a0, xdc_UArg a1);

xdc_Void channelUpdate(xdc_UArg a0, xdc_UArg a1);
xdc_Void schedulingForCurrentSF(xdc_UArg a0, xdc_UArg a1);

}

xdc_Void lteSystemInit(xdc_UArg a0, xdc_UArg a1)
{
	uint16_t cellID = 0;
	#if defined(FILE_INPUT)
	uint16_t leadIndex;
	char channelFileName[] = "channelDumpFile.h";
	#endif

	//while (1)
	{
		//if (Semaphore_pend(reInitSystem,BIOS_WAIT_FOREVER))
		{
			sysConfig.schedType = SUCCPROJ;
			initializeSystem(&dlConfig,&sysConfig,cellID,g_nTransmit,g_nReceive,g_nSchedBlocks,g_nUsers);
			System_printf("Initialized System Parameters ! \n");
		}
	}
}

xdc_Void channelUpdate(xdc_UArg a0,xdc_UArg a1)
{
	uint16_t iUser;
	userConfig_t *cUser;

	System_printf("Running Channel Updates ! \n");
	for (iUser = 0;iUser < g_nUsers;iUser ++)
	{
		cUser = createNewUserStructure(iUser,g_nReceive,10);
		updateDLConfig_User(&dlConfig,cUser);
	}

	#if defined(FILE_INPUT)
	uint16_t leadIndex = 0;
	#endif

	for (iUser = 0;iUser < g_nUsers;iUser ++)
	{
		#if !defined(FILE_INPUT)
		updateUserChannel(dlConfig.activeUsers[iUser]);
		#else
		updateUserChannel(dlConfig.activeUsers[iUser]),leadIndex++);
		#endif
	}
}

xdc_Void schedulingForCurrentSF(xdc_UArg a0,xdc_UArg a1)
{
	System_printf("Performing Scheduling at SF level ! \n");
	performUserScheduling(&sysConfig,&dlConfig);
}

xdc_Void lteSystemTerminate(xdc_UArg a0, xdc_UArg a1)
{
	cleanupUsers(&dlConfig);
}

xdc_Void displaySchedulerInfo(xdc_UArg a0,xdc_UArg a1)
{
	displayScheduledUsers(&sysConfig,&dlConfig);
}
