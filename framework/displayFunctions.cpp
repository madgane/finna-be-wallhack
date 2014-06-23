
#include "displayFunctions.h"
#include <xdc/runtime/System.h>

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

	System_printf("[\n\t");
	for (iRow = 0;iRow < cMatrix->_rows;iRow ++)
	{
		for (iCol = 0;iCol < cMatrix->_cols;iCol ++)
		{
			System_printf("%f + %fi \t",real(cMatrix->_data[iRow][iCol]),imag(cMatrix->_data[iRow][iCol]));
		}
		System_printf(";\n\t");
	}
	System_printf(" \n] \n");
}

void displayMatrix(cmatrix_t &cMatrix)
{
	uint16_t iRow,iCol;

	System_printf("[\n\t");
	for (iRow = 0;iRow < cMatrix._rows;iRow ++)
	{
		for (iCol = 0;iCol < cMatrix._cols;iCol ++)
		{
			System_printf("%f + %fi \t",real(cMatrix._data[iRow][iCol]),imag(cMatrix._data[iRow][iCol]));
		}
		System_printf(";\n\t");
	}
	System_printf(" \n] \n");
}

#endif

void displayUserStructure(userConfig_t *cUser)
{
	uint16_t iCount;
	System_printf("Displaying user info - %d \n",cUser->userID);
	System_printf("Number of Rx Antennas - %d \n",cUser->nRxAntenna);
	System_printf("Number of Queued Pkts - %d \n",cUser->queuedPkts);
	System_printf("---------- End of basic user information --------- \n");
	System_printf("Displaying Channel Matrices - \n");
	for (iCount = 0;iCount < sysConfig.nSBs;iCount ++)
	{
		displayMatrix(&cUser->channelMatrix[iCount]);
	}
}

void displaySystemInfo()
{
	System_printf("Number of Tx Antenna - %d \n",sysConfig.nTXAntenna);
	System_printf("Number of PRBs - %d \n",sysConfig.nPRBs);
	System_printf("Number of Scheduling Blocks - %d \n",sysConfig.nSBs);
	System_printf("---------- End of system configuration information --------- \n");
}

void displayScheduledUsers(systemConfig_t *sysConfig,downlinkConfig_t *dlConfig)
{
	uint16_t iSB,iUser;
	for (iSB = 0;iSB < sysConfig->nSBs;iSB ++)
	{
		System_printf("[ ");
		for (iUser = 0;iUser < dlConfig->schedInfo.rUserIndex[iSB];iUser ++)
		{
			System_printf("(%d,%d)",dlConfig->schedInfo.schedulerTuple[iSB][iUser][0],dlConfig->schedInfo.schedulerTuple[iSB][iUser][1]);
		}
		System_printf(" ] \t");
	}
	System_printf("\n");
}

