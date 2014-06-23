
#include "mainIncludes.h"
#include "blasFunctions.h"
#include "lapackFunctions.h"

void performRandomScheduling(systemConfig_t *sysConfig,downlinkConfig_t *dlConfig)
{
	uint16_t iSB,muxUsers,jUser,maxIndex,maxElements;

	maxElements = dlConfig->linkedUsers * MAX_MUX_USERS;
	muxUsers = MIN(MIN(sysConfig->nTXAntenna,dlConfig->linkedUsers * dlConfig->activeUsers[0]->nRxAntenna),MAX_MUX_USERS);

	for (iSB = 0;iSB < sysConfig->nSBs;iSB ++)
	{
		for (jUser = 0;jUser < muxUsers;jUser ++)
		{
			maxIndex = (uint16_t) ((float) (rand() / RAND_MAX) * maxElements);
			dlConfig->schedInfo.schedulerTuple[iSB][dlConfig->schedInfo.rUserIndex[iSB]][0] = (uint16_t)(maxIndex / MAX_MUX_USERS);
			dlConfig->schedInfo.schedulerTuple[iSB][dlConfig->schedInfo.rUserIndex[iSB]][1] = (maxIndex % MAX_MUX_USERS);
			dlConfig->schedInfo.rUserIndex[iSB] ++;
		}
	}
}

