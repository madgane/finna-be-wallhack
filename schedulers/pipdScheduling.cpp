
#include "mainIncludes.h"
#include "blasFunctions.h"
#include "lapackFunctions.h"

void performPIPDScheduling(systemConfig_t *sysConfig,downlinkConfig_t *dlConfig)
{
	fcomplex_t *cVector,cValue;
	float *normVector,*prodVector;
	uint16_t iUser,iSB,muxUsers,jUser,maxIndex,maxElements,iStream,cUser,maxRank,xUser,xStream;
	
	muxUsers = MIN(MIN(sysConfig->nTXAntenna,dlConfig->linkedUsers * dlConfig->activeUsers[0]->nRxAntenna),MAX_MUX_USERS);
	maxElements = dlConfig->linkedUsers * muxUsers;
	
	normVector = (float *) new float[maxElements];
	prodVector = (float *) new float[maxElements];
	cVector = (fcomplex_t *) new fcomplex_t[sysConfig->nTXAntenna];
	
	for (iSB = 0;iSB < sysConfig->nSBs;iSB ++)
	{
		for (jUser = 0;jUser < dlConfig->linkedUsers;jUser ++)
		{
			maxRank = MIN(sysConfig->nTXAntenna,dlConfig->activeUsers[jUser]->nRxAntenna);
			for (iStream = 0;iStream < maxRank;iStream ++)
			{
				cUser = jUser * muxUsers + iStream;
				prodVector[cUser] = 1.0;
				normVector[cUser] = cblas_scnrm2(sysConfig->nTXAntenna,dlConfig->activeUsers[jUser]->vH[iSB][iStream],1);
			}
		}
		
		maxIndex = cblas_isamax(maxElements,normVector,1);
		dlConfig->schedInfo.schedulerTuple[iSB][dlConfig->schedInfo.rUserIndex[iSB]][0] = (uint16_t)(maxIndex / muxUsers);
		dlConfig->schedInfo.schedulerTuple[iSB][dlConfig->schedInfo.rUserIndex[iSB]][1] = (uint16_t)(maxIndex % muxUsers);
		dlConfig->schedInfo.rUserIndex[iSB] ++;
		
		for (iUser = 1;iUser < muxUsers;iUser ++)
		{
			xUser = dlConfig->schedInfo.schedulerTuple[iSB][iUser - 1][0];
			xStream = dlConfig->schedInfo.schedulerTuple[iSB][iUser - 1][1];
			
			for (iStream = 0;iStream < sysConfig->nTXAntenna;iStream ++)
			{
				cVector[iStream] = conj(dlConfig->activeUsers[xUser]->vH[iSB][xStream][iStream]) / normVector[maxIndex];
			}
			
			for (jUser = 0;jUser < dlConfig->linkedUsers;jUser ++)
			{
				maxRank = MIN(sysConfig->nTXAntenna,dlConfig->activeUsers[jUser]->nRxAntenna);
				for (iStream = 0;iStream < maxRank;iStream ++)
				{
					cUser = jUser * muxUsers + iStream;					
					#if !defined(MKL_ENABLED) && !defined(BLAS_ENABLED)
					cValue = dotProductV(cVector,dlConfig->activeUsers[jUser]->vH[iSB][iStream],sysConfig->nTXAntenna);
					#else
					cblas_cdotu_sub(sysConfig->nTXAntenna,cVector,1,dlConfig->activeUsers[jUser]->vH[iSB][iStream],1,&cValue);
					#endif
					prodVector[cUser] = abs(normVector[cUser] - abs(cValue)) * prodVector[cUser];
				}
			}
			
			maxIndex = cblas_isamax(maxElements,prodVector,1);
			dlConfig->schedInfo.schedulerTuple[iSB][dlConfig->schedInfo.rUserIndex[iSB]][0] = (uint16_t)(maxIndex / muxUsers);
			dlConfig->schedInfo.schedulerTuple[iSB][dlConfig->schedInfo.rUserIndex[iSB]][1] = (uint16_t)(maxIndex % muxUsers);
			dlConfig->schedInfo.rUserIndex[iSB] ++;
		}
	}
}
