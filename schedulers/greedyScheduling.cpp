
#include "mainIncludes.h"
#include "blasFunctions.h"
#include "lapackFunctions.h"

void performGreedyScheduling(systemConfig_t *sysConfig,downlinkConfig_t *dlConfig)
{
	float *normVector;
	uint16_t iUser,iSB,muxUsers,jUser,maxIndex,maxElements,iStream,cUser,maxRank;

	muxUsers = MIN(MIN(sysConfig->nTXAntenna,dlConfig->linkedUsers * dlConfig->activeUsers[0]->nRxAntenna),MAX_MUX_USERS);

	maxElements = dlConfig->linkedUsers * muxUsers;
	normVector = (float *) calloc(maxElements,sizeof(float));
	
	for (iSB = 0;iSB < sysConfig->nSBs;iSB ++)
	{
		for (jUser = 0;jUser < dlConfig->linkedUsers;jUser ++)
		{
			maxRank = MIN(sysConfig->nTXAntenna,dlConfig->activeUsers[jUser]->nRxAntenna);
			for (iStream = 0;iStream < maxRank;iStream ++)
			{
				cUser = jUser * muxUsers + iStream;
				normVector[cUser] = cblas_scnrm2(sysConfig->nTXAntenna,dlConfig->activeUsers[jUser]->vH[iSB][iStream],1);
			}
		}

		for (iUser = 0;iUser < muxUsers;iUser ++)
		{
			maxIndex = cblas_isamax(maxElements,normVector,1);
			dlConfig->schedInfo.schedulerTuple[iSB][dlConfig->schedInfo.rUserIndex[iSB]][0] = (uint16_t)(maxIndex / muxUsers);
			dlConfig->schedInfo.schedulerTuple[iSB][dlConfig->schedInfo.rUserIndex[iSB]][1] = (maxIndex % muxUsers);
			dlConfig->schedInfo.rUserIndex[iSB] ++;
			normVector[maxIndex] = 0.0;
		}
	}

	free(normVector);
}

