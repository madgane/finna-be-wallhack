
#include "mainIncludes.h"
#include "globalDeclarations.h"
#include "frameworkFunctions.h"
#include "schedulingAlgorithms.h"
#include "displayFunctions.h"


uint16_t g_nUsers = 1;
uint16_t g_nTransmit = 8,g_nReceive = 8,g_nSchedBlocks = 1;

void lteSystemInit();
void channelUpdate();
void lteSystemTerminate();
void schedulingForCurrentSF();

void lteSystemInit()
{
	uint16_t cellID = 0;
	#if defined(FILE_INPUT)
	uint16_t leadIndex;
	char channelFileName[] = "channelDumpFile.h";
	#endif

	sysConfig.schedType = SUCCPROJ;
	initializeSystem(&dlConfig,&sysConfig,cellID,g_nTransmit,g_nReceive,g_nSchedBlocks,g_nUsers);
	printf("Initialized System Parameters ! \n");
}

void channelUpdate()
{
	uint16_t iUser;
	userConfig_t *cUser;

	printf("Running Channel Updates ! \n");
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
	printf("Completed Channel Updates ! \n");
}

void schedulingForCurrentSF()
{
	printf("Performing Scheduling at SF level ! \n");
	performUserScheduling(&sysConfig,&dlConfig);
	printf("Completed Scheduling at SF level ! \n");
}

void lteSystemTerminate()
{
	printf("Displaying the final scheduler info ! \n");
	displayScheduledUsers(&sysConfig,&dlConfig);

	cleanupUsers(&dlConfig);
	exit(EXIT_SUCCESS);
}
