
#include "blasFunctions.h"

float cblas_scnrm2(uint32_t length,void *ptr,uint32_t incX)
{
	uint16_t iIndex;
	fcomplex_t *cPointer;

	float scnrm_val = 0.0;
	cPointer = (fcomplex_t *) ptr;

	for (iIndex = 0;iIndex < length;iIndex += incX)
	{
		scnrm_val += std::pow((float)abs(cPointer[iIndex]),2.0f);
	}

	return sqrt(scnrm_val);
}

uint32_t cblas_isamax(uint32_t length,void *ptr,uint32_t incX)
{
	uint16_t iIndex,maxIndex = length;
	float *fPointer,maxVal = 0.0;
	fPointer = (float *) ptr;

	for (iIndex = 0;iIndex < length;iIndex += incX)
	{
		if (fPointer[iIndex] > maxVal)
		{
			maxIndex = iIndex;
			maxVal = fPointer[iIndex];
		}
	}

	return maxIndex;
}

void matrixCopy(cmatrix_t *bMatrix,cmatrix_t *aMatrix,CBLAS_TRANSPOSE cblasTR1,bool createM)
{
	uint16_t iRow,iCol;

	switch (cblasTR1)
	{
		case (CblasNoTrans) :
		{
			if (createM)
				createMatrix(aMatrix,bMatrix->_rows,bMatrix->_cols);
			for (iRow = 0;iRow < bMatrix->_rows;iRow ++)
			{
				for (iCol = 0;iCol < bMatrix->_cols;iCol ++)
				{
					aMatrix->_data[iRow][iCol] = bMatrix->_data[iRow][iCol];
				}
			}
			break;
		}
		case (CblasConjTrans) :
		{
			if (createM)
				createMatrix(aMatrix,bMatrix->_cols,bMatrix->_rows);
			for (iRow = 0;iRow < bMatrix->_cols;iRow ++)
			{
				for (iCol = 0;iCol < bMatrix->_rows;iCol ++)
				{
					aMatrix->_data[iRow][iCol] = conj(bMatrix->_data[iCol][iRow]);
				}
			}
			break;
		}
		case (CblasTrans) :
		{
			if (createM)
				createMatrix(aMatrix,bMatrix->_cols,bMatrix->_rows);
			for (iRow = 0;iRow < bMatrix->_cols;iRow ++)
			{
				for (iCol = 0;iCol < bMatrix->_rows;iCol ++)
				{
					aMatrix->_data[iRow][iCol] = bMatrix->_data[iCol][iRow];
				}
			}
			break;
		}
		default :
			cout << "Unknown Type !" << endl;
			break;
	}
}

void matrixMult(cmatrix_t *pMatrix, cmatrix_t *qMatrix, cmatrix_t *rMatrix,CBLAS_TRANSPOSE cblasTR1,CBLAS_TRANSPOSE cblasTR2,bool createM)
{
	fcomplex_t cValue;
	uint16_t iRow,iCol,iIndex;

	if ((cblasTR1 == CblasNoTrans) && (cblasTR2 == CblasNoTrans))
	{
		if (createM)
		{
			createMatrix(rMatrix,pMatrix->_rows,qMatrix->_cols);
		}
		for (iRow = 0;iRow < rMatrix->_rows;iRow ++)
		{
			for (iCol = 0;iCol < rMatrix->_cols;iCol ++)
			{
				cValue = 0.0;
				for (iIndex = 0;iIndex < qMatrix->_rows;iIndex ++)
				{
					cValue += pMatrix->_data[iRow][iIndex] * qMatrix->_data[iIndex][iCol];
				}
				rMatrix->_data[iRow][iCol] = cValue;
			}
		}
	}
	else if ((cblasTR1 == CblasNoTrans) && (cblasTR2 == CblasConjTrans))
	{
		if (createM)
		{
			createMatrix(rMatrix,pMatrix->_rows,qMatrix->_rows);
		}
		for (iRow = 0;iRow < rMatrix->_rows;iRow ++)
		{
			for (iCol = 0;iCol < rMatrix->_cols;iCol ++)
			{
				cValue = 0.0;
				for (iIndex = 0;iIndex < pMatrix->_cols;iIndex ++)
				{
					cValue += pMatrix->_data[iRow][iIndex] * conj(qMatrix->_data[iCol][iIndex]);
				}
				rMatrix->_data[iRow][iCol] = cValue;
			}
		}
	}
	else if ((cblasTR1 == CblasConjTrans) && (cblasTR2 == CblasNoTrans))
	{
		if (createM)
		{
			createMatrix(rMatrix,pMatrix->_cols,qMatrix->_cols);
		}
		for (iRow = 0;iRow < rMatrix->_rows;iRow ++)
		{
			for (iCol = 0;iCol < rMatrix->_cols;iCol ++)
			{
				cValue = 0.0;
				for (iIndex = 0;iIndex < qMatrix->_rows;iIndex ++)
				{
					cValue += conj(pMatrix->_data[iIndex][iRow]) * qMatrix->_data[iIndex][iCol];
				}
				rMatrix->_data[iRow][iCol] = cValue;
			}
		}
	}
}

void matrixMultV(cmatrix_t *pMatrix, fcomplex_t *qVector, fcomplex_t *outVector,bool createM)
{
	fcomplex_t cValue;
	uint16_t iRow,iIndex;

	if (createM == true)
		outVector = (fcomplex_t *) malloc(sizeof(fcomplex_t) * pMatrix->_rows);

	for (iRow = 0;iRow < pMatrix->_rows;iRow ++)
	{
		cValue = 0.0;
		for (iIndex = 0;iIndex < pMatrix->_cols;iIndex ++)
		{
			cValue += pMatrix->_data[iRow][iIndex] * qVector[iIndex];
		}
		outVector[iRow] = cValue;
	}
}

fcomplex_t dotProductV(fcomplex_t *aVector,fcomplex_t *bVector,uint16_t size)
{
	uint16_t iIndex;
	fcomplex_t runValue = fcomplex_t(0.0,0.0);
	for (iIndex = 0;iIndex < size;iIndex ++)
		runValue += conj(aVector[iIndex]) * bVector[iIndex];

	return runValue;
}

void outerProductV(fcomplex_t *aVector,fcomplex_t *bVector,cmatrix_t *cMatrix,fcomplex_t scaling)
{
	uint16_t iRow,iCol;
	for (iRow = 0;iRow < cMatrix->_rows;iRow ++)
	{
		for (iCol = 0;iCol < cMatrix->_cols;iCol ++)
		{
			cMatrix->_data[iRow][iCol] = scaling * aVector[iRow] * conj(bVector[iCol]);
		}
	}
}

void matrixMultSafeB(cmatrix_t *aMatrix,cmatrix_t *bMatrix)
{
	fcomplex_t *tempComplex;
	uint16_t iRow,iCol,iiCol;

	tempComplex = (fcomplex_t *) malloc(sizeof(fcomplex_t) * bMatrix->_rows);

	for (iCol = 0;iCol < bMatrix->_cols;iCol ++)
	{
		for (iRow = 0;iRow < aMatrix->_rows;iRow ++)
		{
			tempComplex[iRow] = 0.0;
			for (iiCol = 0;iiCol < bMatrix->_rows;iiCol ++)
			{
				tempComplex[iRow] += aMatrix->_data[iRow][iiCol] * bMatrix->_data[iiCol][iCol];
			}
		}
		for (iRow = 0;iRow < bMatrix->_rows;iRow ++)
		{
			bMatrix->_data[iRow][iCol] = tempComplex[iRow];
		}
	}

	free(tempComplex);
}

void matrixMultSafeA(cmatrix_t *aMatrix,cmatrix_t *bMatrix)
{
	fcomplex_t *tempComplex;
	uint16_t iRow,iCol,iiCol;

	tempComplex = (fcomplex_t *) malloc(sizeof(fcomplex_t) * bMatrix->_cols);

	for (iRow = 0;iRow < aMatrix->_rows;iRow ++)
	{
		for (iCol = 0;iCol < bMatrix->_cols;iCol ++)
		{
			tempComplex[iCol] = 0.0;
			for (iiCol = 0;iiCol < bMatrix->_rows;iiCol ++)
			{
				tempComplex[iCol] += aMatrix->_data[iRow][iiCol] * bMatrix->_data[iiCol][iCol];
			}
		}
		for (iCol = 0;iCol < bMatrix->_cols;iCol ++)
		{
			aMatrix->_data[iRow][iCol] = tempComplex[iCol];
		}
	}

	free(tempComplex);
}

void matrixHermitian(cmatrix_t *qMatrix)
{
	uint16_t iIndex,xRow,xCol;
	fcomplex_t *tempComplex;

	tempComplex = (fcomplex_t *) malloc(sizeof(fcomplex_t) * qMatrix->_rows * qMatrix->_cols);

	for (xRow = 0;xRow < qMatrix->_rows;xRow ++)
	{
		for (xCol = 0;xCol < qMatrix->_cols;xCol ++)
		{
			iIndex = xCol * qMatrix->_rows + xRow;
			tempComplex[iIndex] = conj(qMatrix->_data[xRow][xCol]);
		}
	}

	iIndex = 0;
	reshapeMatrix(qMatrix,qMatrix->_cols,qMatrix->_rows);
	for (xRow = 0;xRow < qMatrix->_rows;xRow ++)
	{
		for (xCol = 0;xCol < qMatrix->_cols;xCol ++)
		{
			qMatrix->_data[xRow][xCol] = tempComplex[iIndex ++];
		}
	}

	free(tempComplex);
}

void matrixTranspose(cmatrix_t *qMatrix)
{
	uint16_t iIndex,xRow,xCol;
	fcomplex_t *tempComplex;

	tempComplex = (fcomplex_t *) malloc(sizeof(fcomplex_t) * qMatrix->_rows * qMatrix->_cols);

	for (xRow = 0;xRow < qMatrix->_rows;xRow ++)
	{
		for (xCol = 0;xCol < qMatrix->_cols;xCol ++)
		{
			iIndex = xCol * qMatrix->_rows + xRow;
			tempComplex[iIndex] = qMatrix->_data[xRow][xCol];
		}
	}

	iIndex = 0;
	reshapeMatrix(qMatrix,qMatrix->_cols,qMatrix->_rows);
	for (xRow = 0;xRow < qMatrix->_rows;xRow ++)
	{
		for (xCol = 0;xCol < qMatrix->_cols;xCol ++)
		{
			qMatrix->_data[xRow][xCol] = tempComplex[iIndex ++];
		}
	}

	free(tempComplex);
}
