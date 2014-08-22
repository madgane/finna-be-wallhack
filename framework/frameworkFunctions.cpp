
#include "frameworkFunctions.h"

void randomizeChannelMatrix(cmatrix_t *channelMatrix,bool createM)
{
	uint16_t iRow,iCol;
	float pathLoss,tempFloat_1,tempFloat_2;
	
	pathLoss = (float) rand()/(RAND_MAX - 1);
	if (createM)
	{
		createMatrix(channelMatrix,channelMatrix->_rows,channelMatrix->_cols);
	}

	for (iRow = 0;iRow < channelMatrix->_rows;iRow ++)
	{
		for (iCol = 0;iCol < channelMatrix->_cols;iCol ++)
		{
			tempFloat_1 = 2.0 * (((float) rand()) / (RAND_MAX - 1)) - 1;
			tempFloat_2 = 2.0 * (((float) rand()) / (RAND_MAX - 1)) - 1;
			channelMatrix->_data[iRow][iCol] = pathLoss * fcomplex_t(tempFloat_1,tempFloat_2);
			channelMatrix->_data[iRow][iCol] /= 2.0;
		}
	}
}

void initializeSystem(downlinkConfig_t *dConfig,systemConfig_t *sConfig,uint16_t cellID,uint16_t nTxAntenna,uint16_t nRxAntenna,uint16_t nSchBlks,uint16_t nUsers)
{
	uint32_t iUser;

	dConfig->cellID = cellID;
	dConfig->maxUsers = MAX_ACTIVE_USERS;
	for (iUser = 0;iUser < dConfig->maxUsers;iUser ++)
	{
		dConfig->activeUsers[iUser] = NULL;
	}

	dConfig->frameNumber = 0;
	dConfig->linkedUsers = 0;

	sConfig->nPRBs = 10;
	sConfig->nSBs = nSchBlks;
	sConfig->nTXAntenna = nTxAntenna;
	sConfig->maxRxAntenna = nRxAntenna;

	dynamicMemory = (DynamicMemory *) new DynamicMemory();
}

userConfig_t* createNewUserStructure(uint16_t uID,uint16_t nRxAntenna,uint16_t backloggedPkts)
{
	userConfig_t *cUser;
	uint16_t iSchBlk,iStream;
	extern systemConfig_t sysConfig;

	cUser = (userConfig_t *) allocateMemory(sizeof(userConfig_t));

	cUser->userID = uID;
	cUser->queuedPkts = backloggedPkts;
	cUser->nRxAntenna = nRxAntenna;

	for (iSchBlk = 0;iSchBlk < sysConfig.nSBs;iSchBlk ++)
	{
		cUser->channelMatrix[iSchBlk].headList = NULL;
		cUser->channelMatrix[iSchBlk]._rows = nRxAntenna;
		cUser->channelMatrix[iSchBlk]._cols = sysConfig.nTXAntenna;
		cUser->channelMatrix[iSchBlk]._data = (fcomplex_t **) allocateMemory(sizeof(fcomplex_t *) * nRxAntenna);

		for (iStream = 0;iStream < nRxAntenna;iStream ++)
		{
			cUser->channelMatrix[iSchBlk]._data[iStream] = (fcomplex_t *) &globalChannelMatrix[uID][iSchBlk][iStream];
		}

		for (iStream = 0;iStream < MAX_MUX_USERS;iStream ++)
		{
			cUser->vH[iSchBlk][iStream] = (fcomplex_t *) allocateMemory(sysConfig.nTXAntenna * sizeof(fcomplex_t));
		}
	}

	return cUser;
}

void updateDLConfig_User(downlinkConfig_t *dConfig,userConfig_t *cUser)
{
	bool foundUser = false;
	int16_t iUser = 0,emptyLoc = -1;

	while (!foundUser)
	{
		if (dConfig->activeUsers[iUser] != NULL)
		{
			if (dConfig->activeUsers[iUser]->userID == cUser->userID)
			{
				foundUser = true;
				clearDLConfig_User(dConfig,cUser->userID);
				dConfig->activeUsers[iUser] = cUser;
			}
		}
		else
		{
			if ((emptyLoc == -1) || foundUser)
			{
				emptyLoc = iUser;
			}
		}

		iUser ++;
		if (iUser == dConfig->maxUsers)
		{
			break;
		}
	}

	if (foundUser)
	{
		freeUser(dConfig->activeUsers[emptyLoc]);
	}
	else
	{
		if (emptyLoc == -1)
		{
			cout << "User index exceeds the Array Limit !" << endl;
			exit(EXIT_FAILURE);
		}
	}

	dConfig->linkedUsers ++;
	dConfig->activeUsers[emptyLoc] = cUser;
}

void clearDLConfig_User(downlinkConfig_t *dConfig,uint16_t userID)
{
	uint16_t iUser;
	for (iUser = 0;iUser < dConfig->maxUsers;iUser ++)
	{
		if (dConfig->activeUsers[iUser] != NULL)
		{
			if (dConfig->activeUsers[iUser]->userID == userID)
			{
				dConfig->linkedUsers --;
				freeUser(dConfig->activeUsers[iUser]);
				dConfig->activeUsers[iUser] = NULL;
				break;
			}
		}
	}
}

void freeUser(userConfig_t *cUser)
{
	uint32_t size_t;
	uint16_t iSB,iStream;
	for (iSB = 0;iSB < MAX_SCHBLK_OVER_SF;iSB ++)
	{
		//freeMatrix(&cUser->channelMatrix[iSB]);
		//freeMatrix(&cUser->precMatrices[iSB]);
		size_t = sysConfig.nTXAntenna * sizeof(fcomplex_t);
		for (iStream = 0;iStream < MAX_MUX_USERS;iStream ++)
		{
			if (cUser->vH[iSB][iStream] != NULL)
			{
				freeMemory(cUser->vH[iSB][iStream],size_t);
			}
		}

		size_t = sizeof(fcomplex_t *) * cUser->nRxAntenna;
		freeMemory(cUser->channelMatrix[iSB]._data,size_t);
	}
	
	freeMemory(cUser,sizeof(userConfig_t));
}

void updateUserChannel(userConfig_t *cUser)
{
	uint16_t iSchBlk;
	extern systemConfig_t sysConfig;
	for (iSchBlk = 0;iSchBlk < sysConfig.nSBs;iSchBlk ++)
	{
		randomizeChannelMatrix(&cUser->channelMatrix[iSchBlk],false);
	}
}

#if defined(FILE_INPUT)

void updateUserChannel(userConfig_t *cUser,uint16_t leadIndex)
{
	uint32_t startIndex;
	extern systemConfig_t sysConfig;
	uint16_t iSchBlk,iRow,iCol,iIndex;
		
	float channelDumps[] = {
		#include "channelDumpFile.h"
	};
	
	for (iSchBlk = 0;iSchBlk < sysConfig.nSBs;iSchBlk ++)
	{
		startIndex = leadIndex * sysConfig.nSBs * cUser->nRxAntenna * sysConfig.nTXAntenna \
						+ iSchBlk * cUser->nRxAntenna * sysConfig.nTXAntenna;
		for (iRow = 0;iRow < cUser->channelMatrix[iSchBlk]._rows;iRow ++)
		{
			for (iCol = 0;iCol < cUser->channelMatrix[iSchBlk]._cols;iCol ++)
			{
				iIndex = startIndex + iRow * sysConfig.nTXAntenna + iCol;
				cUser->channelMatrix[iSchBlk]._data[iRow][iCol] = fcomplex_t(channelDumps[iIndex * CPLX],channelDumps[iIndex * CPLX + 1]);
			}
		}
	}
}

#endif

void cleanupUsers(downlinkConfig_t *dlConfig)
{
	for (uint16_t iUser = 0;iUser < MAX_ACTIVE_USERS;iUser ++)
	{
		clearDLConfig_User(dlConfig,iUser);
	}

	dynamicMemory->~DynamicMemory();

	dynamicMemory->displayQInfo();
	dynamicMemory->displayDMStatus();
}
