
#include "supportingFunctions.h"
#include "blasFunctions.h"
#include "lapackFunctions.h"

void decomposeChannelMatrices(systemConfig_t *sysConfig,downlinkConfig_t *dlConfig)
{
	uint16_t iSB,iUser,iStream,iAntenna,nMax;
	cmatrix_t uMatrix,dMatrix,vMatrix,tempMatrix;

	nMax = MAX(sysConfig->nTXAntenna,sysConfig->maxRxAntenna);

	createMatrix(&uMatrix,nMax,nMax);
	createMatrix(&dMatrix,nMax,sysConfig->nTXAntenna);
	createMatrix(&vMatrix,sysConfig->nTXAntenna,sysConfig->nTXAntenna);
	createMatrix(&tempMatrix,nMax,nMax);

	for (iUser = 0;iUser < dlConfig->linkedUsers;iUser ++)
	{
		if (dlConfig->activeUsers[iUser]->nRxAntenna != 1)
		{
			for (iSB = 0;iSB < sysConfig->nSBs;iSB ++)
			{
				dlConfig->activeUsers[iUser]->totalStreams[iSB] = 0;

				dynamicMemory->reshapeMatrix(&uMatrix,dlConfig->activeUsers[iUser]->nRxAntenna,dlConfig->activeUsers[iUser]->nRxAntenna);
				dynamicMemory->reshapeMatrix(&dMatrix,dlConfig->activeUsers[iUser]->nRxAntenna,sysConfig->nTXAntenna);
				getSVD(&dlConfig->activeUsers[iUser]->channelMatrix[iSB],&uMatrix,&dMatrix,&vMatrix,'N');

				dynamicMemory->reshapeMatrix(&tempMatrix,uMatrix._rows,sysConfig->nTXAntenna);
				matrixMult(&uMatrix,&dlConfig->activeUsers[iUser]->channelMatrix[iSB],&tempMatrix,CblasConjTrans,CblasNoTrans,false);

				for (iStream = 0;iStream < tempMatrix._rows;iStream ++)
				{
					for (iAntenna = 0;iAntenna < sysConfig->nTXAntenna;iAntenna ++)
					{
						dlConfig->activeUsers[iUser]->vH[iSB][iStream][iAntenna] = tempMatrix._data[iStream][iAntenna];
					}
				}
			}
		}
		else
		{
			iStream = 0;
			for (iSB = 0;iSB < sysConfig->nSBs;iSB ++)
			{
				for (iAntenna = 0;iAntenna < sysConfig->nTXAntenna;iAntenna ++)
				{
					dlConfig->activeUsers[iUser]->vH[iSB][iStream][iAntenna] = dlConfig->activeUsers[iUser]->channelMatrix[iSB]._data[iStream][iAntenna];
				}
			}
		}
	}

	freeMatrix(&uMatrix);freeMatrix(&dMatrix);freeMatrix(&vMatrix);freeMatrix(&tempMatrix);
}

void clearSchedulerConfigurations(systemConfig_t *sysConfig,downlinkConfig_t *dlConfig)
{
	for (uint16_t iSB = 0;iSB < sysConfig->nSBs;iSB ++)
	{
		dlConfig->schedInfo.rUserIndex[iSB] = 0;
	}
}

