
#include "displayFunctions.h"

#if 0

void displayMatrix(cmatrix_t *cMatrix)
{
	uint16_t iRow,iCol;

	printf("[\n\t");
	for (iRow = 0;iRow < cMatrix->_rows;iRow ++)
	{
		for (iCol = 0;iCol < cMatrix->_cols;iCol ++)
		{
			printf("%f + %fi \t",real(cMatrix->_data[iRow][iCol]),imag(cMatrix->_data[iRow][iCol]));
		}
		printf(";\n\t");
	}
	printf(" \n] \n");
}

void displayMatrix(cmatrix_t &cMatrix)
{
	uint16_t iRow,iCol;

	printf("[\n\t");
	for (iRow = 0;iRow < cMatrix._rows;iRow ++)
	{
		for (iCol = 0;iCol < cMatrix._cols;iCol ++)
		{
			printf("%f + %fi \t",real(cMatrix._data[iRow][iCol]),imag(cMatrix._data[iRow][iCol]));
		}
		printf(";\n\t");
	}
	printf(" \n] \n");
}

#else

void displayMatrix(cmatrix_t *cMatrix)
{
	uint16_t iRow,iCol;

	printf("[\n\t");
	for (iRow = 0;iRow < cMatrix->_rows;iRow ++)
	{
		for (iCol = 0;iCol < cMatrix->_cols;iCol ++)
		{
			printf("%f + %fi \t",real(cMatrix->_data[iRow][iCol]),imag(cMatrix->_data[iRow][iCol]));
		}
		printf(";\n\t");
	}
	printf(" \n] \n");
}

void displayMatrix(cmatrix_t &cMatrix)
{
	uint16_t iRow,iCol;

	printf("[\n\t");
	for (iRow = 0;iRow < cMatrix._rows;iRow ++)
	{
		for (iCol = 0;iCol < cMatrix._cols;iCol ++)
		{
			printf("%f + %fi \t",real(cMatrix._data[iRow][iCol]),imag(cMatrix._data[iRow][iCol]));
		}
		printf(";\n\t");
	}
	printf(" \n] \n");
}

#endif

void displayUserStructure(userConfig_t *cUser)
{
	uint16_t iCount;
	printf("Displaying user info - %d \n",cUser->userID);
	printf("Number of Rx Antennas - %d \n",cUser->nRxAntenna);
	printf("Number of Queued Pkts - %d \n",cUser->queuedPkts);
	printf("---------- End of basic user information --------- \n");
	printf("Displaying Channel Matrices - \n");
	for (iCount = 0;iCount < sysConfig.nSBs;iCount ++)
	{
		displayMatrix(&cUser->channelMatrix[iCount]);
	}
}

void displaySystemInfo()
{
	printf("Number of Tx Antenna - %d \n",sysConfig.nTXAntenna);
	printf("Number of PRBs - %d \n",sysConfig.nPRBs);
	printf("Number of Scheduling Blocks - %d \n",sysConfig.nSBs);
	printf("---------- End of system configuration information --------- \n");
}

void displayScheduledUsers(systemConfig_t *sysConfig,downlinkConfig_t *dlConfig)
{
	uint16_t iSB,iUser;
	for (iSB = 0;iSB < sysConfig->nSBs;iSB ++)
	{
		printf("[ ");
		for (iUser = 0;iUser < dlConfig->schedInfo.rUserIndex[iSB];iUser ++)
		{
			printf("(%d,%d)",dlConfig->schedInfo.schedulerTuple[iSB][iUser][0],dlConfig->schedInfo.schedulerTuple[iSB][iUser][1]);
		}
		printf(" ] \t");
	}
	printf("\n");
}

