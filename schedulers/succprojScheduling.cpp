
#include "mainIncludes.h"
#include "blasFunctions.h"
#include "lapackFunctions.h"

#if 0

void performSuccessiveProjections(systemConfig_t *sysConfig,downlinkConfig_t *dlConfig)
{
	cvector_t cVector;
	fvector_t normVector;
	fcomplex_t alpha,beta;
	boostCMatrix_t tempMatrix,nMatrix;
	uint16_t iUser,iSB,muxUsers,jUser,maxIndex,maxElements,iStream,cUser,maxRank;

	muxUsers = MIN(MIN(sysConfig->nTXAntenna,dlConfig->linkedUsers * dlConfig->activeUsers[0]->nRxAntenna),MAX_MUX_USERS);
	maxElements = dlConfig->linkedUsers * muxUsers;
	
	beta = fcomplex_t(0,0);
	alpha = fcomplex_t(1,0);
	normVector.resize(maxElements,false);

	for (iSB = 0;iSB < sysConfig->nSBs;iSB ++)
	{
		normVector.clear();
		for (jUser = 0;jUser < dlConfig->linkedUsers;jUser ++)
		{
			maxRank = MIN(sysConfig->nTXAntenna,dlConfig->activeUsers[jUser]->nRxAntenna);
			for (iStream = 0;iStream < maxRank;iStream ++)
			{
				cUser = jUser * muxUsers + iStream;
				normVector(cUser) = cblas_scnrm2(sysConfig->nTXAntenna,&dlConfig->activeUsers[jUser]->vH[iSB][iStream](0),1);
			}
		}

		maxIndex = cblas_isamax(maxElements,&normVector(0),1);
		dlConfig->schedInfo.schedulerTuple[iSB][dlConfig->schedInfo.rUserIndex[iSB]][0] = (uint16_t)(maxIndex / muxUsers);
		dlConfig->schedInfo.schedulerTuple[iSB][dlConfig->schedInfo.rUserIndex[iSB]][1] = (uint16_t)(maxIndex % muxUsers);
		dlConfig->schedInfo.rUserIndex[iSB] ++;
		
		for (iUser = 1;iUser < muxUsers;iUser ++)
		{
			tempMatrix.resize(sysConfig->nTXAntenna,iUser,true);
			for (iStream = 0;iStream < sysConfig->nTXAntenna;iStream ++)
			{
				tempMatrix(iStream,(iUser - 1)) = dlConfig->activeUsers[(uint16_t)(maxIndex / muxUsers)]->vH[iSB][(maxIndex % muxUsers)](iStream);
			}

			getNullMatrix(tempMatrix,nMatrix);
			for (jUser = 0;jUser < dlConfig->linkedUsers;jUser ++)
			{
				maxRank = MIN(sysConfig->nTXAntenna,dlConfig->activeUsers[jUser]->nRxAntenna);
				for (iStream = 0;iStream < maxRank;iStream ++)
				{
					cUser = jUser * muxUsers + iStream;					
					#if !defined(MKL_ENABLED) && !defined(BLAS_ENABLED)
					cVector = prod(nMatrix,dlConfig->activeUsers[jUser]->vH[iSB][iStream]);
					#else
					cVector.resize(sysConfig->nTXAntenna,false);
					cblas_chemv(CblasRowMajor,CblasUpper,nMatrix.size1(),&alpha,&nMatrix(0,0),nMatrix.size2(),&dlConfig->activeUsers[jUser]->vH[iSB][iStream](0),1,&beta,&cVector(0),1);
					#endif
					
					normVector(cUser) = cblas_scnrm2(sysConfig->nTXAntenna,&cVector(0),1);
				}
			}

			maxIndex = cblas_isamax(maxElements,&normVector(0),1);
			dlConfig->schedInfo.schedulerTuple[iSB][dlConfig->schedInfo.rUserIndex[iSB]][0] = (uint16_t)(maxIndex / muxUsers);
			dlConfig->schedInfo.schedulerTuple[iSB][dlConfig->schedInfo.rUserIndex[iSB]][1] = (uint16_t)(maxIndex % muxUsers);
			dlConfig->schedInfo.rUserIndex[iSB] ++;
		}
	}
}

void performSuccessiveProjections(systemConfig_t *sysConfig,downlinkConfig_t *dlConfig)
{
	float *normVector;
	fcomplex_t *cVector;

	fcomplex_t alpha,beta;
	cmatrix_t tempMatrix,nMatrix;
	uint16_t iUser,iSB,muxUsers,jUser,maxIndex,maxElements,iStream,cUser,maxRank;

	muxUsers = MIN(MIN(sysConfig->nTXAntenna,dlConfig->linkedUsers * dlConfig->activeUsers[0]->nRxAntenna),MAX_MUX_USERS);
	maxElements = dlConfig->linkedUsers * muxUsers;

	beta = fcomplex_t(0,0);
	alpha = fcomplex_t(1,0);

	normVector = (float *) calloc(maxElements,sizeof(float));
	cVector = (fcomplex_t *) calloc(sysConfig->nTXAntenna,sizeof(fcomplex_t));

	for (iSB = 0;iSB < sysConfig->nSBs;iSB ++)
	{
		tempMatrix._data = NULL;
		tempMatrix._rows = tempMatrix._cols = 0;
		for (jUser = 0;jUser < dlConfig->linkedUsers;jUser ++)
		{
			maxRank = MIN(sysConfig->nTXAntenna,dlConfig->activeUsers[jUser]->nRxAntenna);
			for (iStream = 0;iStream < maxRank;iStream ++)
			{
				cUser = jUser * muxUsers + iStream;
				normVector[cUser] = cblas_scnrm2(sysConfig->nTXAntenna,dlConfig->activeUsers[jUser]->vH[iSB][iStream],1);
			}
		}

        maxIndex = cblas_isamax(maxElements,normVector,1);
        dlConfig->schedInfo.schedulerTuple[iSB][dlConfig->schedInfo.rUserIndex[iSB]][0] = (uint16_t)(maxIndex / muxUsers);
        dlConfig->schedInfo.schedulerTuple[iSB][dlConfig->schedInfo.rUserIndex[iSB]][1] = (uint16_t)(maxIndex % muxUsers);
        dlConfig->schedInfo.rUserIndex[iSB] ++;

        for (iUser = 1; iUser < muxUsers; iUser ++)
        {
			memalloc_2DR(&tempMatrix,sysConfig->nTXAntenna,iUser);
            for (iStream = 0; iStream < sysConfig->nTXAntenna; iStream ++)
            {
				tempMatrix._data[iStream][iUser - 1] = dlConfig->activeUsers[(uint16_t)(maxIndex / muxUsers)]->vH[iSB][(maxIndex % muxUsers)][iStream];
            }

            getNullMatrix(&tempMatrix,&nMatrix);
            for (jUser = 0; jUser < dlConfig->linkedUsers; jUser ++)
            {
                maxRank = MIN(sysConfig->nTXAntenna,dlConfig->activeUsers[jUser]->nRxAntenna);
                for (iStream = 0; iStream < maxRank; iStream ++)
                {
                    cUser = jUser * muxUsers + iStream;
					#if !defined(MKL_ENABLED) && !defined(BLAS_ENABLED)
                    matrixMult(&nMatrix,dlConfig->activeUsers[jUser]->vH[iSB][iStream],cVector,false);
					#else
					cblas_cgemv(CblasRowMajor,CblasNoTrans,nMatrix._rows,nMatrix._cols,&alpha,nMatrix._data[0],nMatrix._cols,&dlConfig->activeUsers[jUser]->vH[iSB][iStream](0),1,&beta,&cVector(0),1);
					#endif

					normVector[cUser] = cblas_scnrm2(sysConfig->nTXAntenna,cVector,1);
                }
            }

            maxIndex = cblas_isamax(maxElements,normVector,1);
            dlConfig->schedInfo.schedulerTuple[iSB][dlConfig->schedInfo.rUserIndex[iSB]][0] = (uint16_t)(maxIndex / muxUsers);
            dlConfig->schedInfo.schedulerTuple[iSB][dlConfig->schedInfo.rUserIndex[iSB]][1] = (uint16_t)(maxIndex % muxUsers);
            dlConfig->schedInfo.rUserIndex[iSB] ++;
        }

        freeMatrix(&tempMatrix);
    }

	free(normVector);free(cVector);
}

#else

void performSuccessiveProjections(systemConfig_t *sysConfig,downlinkConfig_t *dlConfig)
{
	float *normVector;
	fcomplex_t *cVector;

	fcomplex_t alpha,beta;
	cmatrix_t tempMatrix,nMatrix;
	uint16_t iUser,iSB,muxUsers,jUser,maxIndex,maxElements,iStream,cUser,maxRank;
	
	muxUsers = MIN(MIN(sysConfig->nTXAntenna,dlConfig->linkedUsers * dlConfig->activeUsers[0]->nRxAntenna),MAX_MUX_USERS);
	maxElements = dlConfig->linkedUsers * muxUsers;
	
	beta = fcomplex_t(0,0);
	alpha = fcomplex_t(1,0);

	createMatrix(&tempMatrix,muxUsers,muxUsers);
	createMatrix(&nMatrix,sysConfig->nTXAntenna,sysConfig->nTXAntenna);

	normVector = (float *) calloc(maxElements,sizeof(float));
	cVector = (fcomplex_t *) calloc(sysConfig->nTXAntenna,sizeof(fcomplex_t));

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
		
        maxIndex = cblas_isamax(maxElements,normVector,1);
        dlConfig->schedInfo.schedulerTuple[iSB][dlConfig->schedInfo.rUserIndex[iSB]][0] = (uint16_t)(maxIndex / muxUsers);
        dlConfig->schedInfo.schedulerTuple[iSB][dlConfig->schedInfo.rUserIndex[iSB]][1] = (uint16_t)(maxIndex % muxUsers);
        dlConfig->schedInfo.rUserIndex[iSB] ++;
		
        for (iUser = 1; iUser < muxUsers; iUser ++)
        {
        	reshapeAndCopyMatrix(&tempMatrix,sysConfig->nTXAntenna,iUser);
            for (iStream = 0; iStream < sysConfig->nTXAntenna; iStream ++)
            {
				tempMatrix._data[iStream][iUser - 1] = dlConfig->activeUsers[(uint16_t)(maxIndex / muxUsers)]->vH[iSB][(maxIndex % muxUsers)][iStream];
            }
          
            getNullMatrix(&tempMatrix,&nMatrix);
            for (jUser = 0; jUser < dlConfig->linkedUsers; jUser ++)
            {
                maxRank = MIN(sysConfig->nTXAntenna,dlConfig->activeUsers[jUser]->nRxAntenna);
                for (iStream = 0; iStream < maxRank; iStream ++)
                {
                    cUser = jUser * muxUsers + iStream;
                    matrixMultV(&nMatrix,dlConfig->activeUsers[jUser]->vH[iSB][iStream],cVector,false);
					normVector[cUser] = cblas_scnrm2(sysConfig->nTXAntenna,cVector,1);
                }
            }
            
            maxIndex = cblas_isamax(maxElements,normVector,1);
            dlConfig->schedInfo.schedulerTuple[iSB][dlConfig->schedInfo.rUserIndex[iSB]][0] = (uint16_t)(maxIndex / muxUsers);
            dlConfig->schedInfo.schedulerTuple[iSB][dlConfig->schedInfo.rUserIndex[iSB]][1] = (uint16_t)(maxIndex % muxUsers);
            dlConfig->schedInfo.rUserIndex[iSB] ++;
        }
	}

	free(normVector);free(cVector);
	freeMatrix(&tempMatrix);freeMatrix(&nMatrix);
}


#endif
