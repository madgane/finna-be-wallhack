

#include "lapackFunctions.h"

void eyeMatrix(cmatrix_t *iMatrix)
{
	uint16_t iRow;
	for (iRow = 0;iRow < iMatrix->_rows * iMatrix->_rows;iRow ++)
	{
		*(&iMatrix->_data[0][0] + iRow) = fcomplex_t(0.0,0.0);
	}
	for (iRow = 0;iRow < iMatrix->_rows;iRow ++)
	{
		iMatrix->_data[iRow][iRow] = fcomplex_t(1.0,0.0);
	}
}

void getMatrixInverse(cmatrix_t *aMatrix,cmatrix_t *bMatrix,fcomplex_t scalingF)
{
	cmatrix_t xMatrix;
	uint16_t xRow,xCol,iCol;
	fcomplex_t tempComplex;

	if (bMatrix == NULL)
	{
		bMatrix = aMatrix;
	}
	createZeroMatrix(&xMatrix,aMatrix->_rows,aMatrix->_cols * 2);

	for (xRow = 0;xRow < xMatrix._rows;xRow ++)
	{
		for (xCol = 0;xCol < aMatrix->_cols;xCol ++)
		{
			xMatrix._data[xRow][xCol] = aMatrix->_data[xRow][xCol];
			xMatrix._data[xRow][xCol + aMatrix->_cols] = 0.0;
			if (xCol == xRow)
				xMatrix._data[xRow][xCol + aMatrix->_cols] = 1.0;
		}
	}

	for (xCol = 0;xCol < aMatrix->_cols;xCol ++)
	{
		tempComplex = xMatrix._data[xCol][xCol];
		for (iCol = 0;iCol < xMatrix._cols;iCol ++)
		{
			xMatrix._data[xCol][iCol] = xMatrix._data[xCol][iCol] / tempComplex;
		}
		for (xRow = 0;xRow < xMatrix._rows;xRow ++)
		{
			if (xRow == xCol) continue;
			tempComplex = xMatrix._data[xRow][xCol];
			for (iCol = xCol;iCol < xMatrix._cols;iCol ++)
			{
				xMatrix._data[xRow][iCol] = xMatrix._data[xRow][iCol] - tempComplex * xMatrix._data[xCol][iCol];
			}
		}
	}

	for (xRow = 0;xRow < bMatrix->_rows;xRow ++)
	{
		for (xCol = 0;xCol < bMatrix->_cols;xCol ++)
		{
			bMatrix->_data[xRow][xCol] = xMatrix._data[xRow][xCol + bMatrix->_cols] * scalingF;
		}
	}

	freeMatrix(&xMatrix);
}

void getNullMatrix(cmatrix_t *aMatrix,cmatrix_t *nMatrix)
{
	cmatrix_t tMatrixA,tMatrixB;
	createMatrix(&tMatrixA,aMatrix->_cols,aMatrix->_cols);
	createMatrix(&tMatrixB,aMatrix->_cols,aMatrix->_rows);

	matrixMult(aMatrix,aMatrix,&tMatrixA,CblasConjTrans,CblasNoTrans,false);
	
	getMatrixInverse(&tMatrixA,NULL,fcomplex_t(-1.0,0.0));
	matrixMult(&tMatrixA,aMatrix,&tMatrixB,CblasNoTrans,CblasConjTrans,false);
	matrixMult(aMatrix,&tMatrixB,nMatrix,CblasNoTrans,CblasNoTrans,false);
	
	for (uint16_t iRow = 0;iRow < nMatrix->_rows;iRow ++)
		nMatrix->_data[iRow][iRow] = nMatrix->_data[iRow][iRow] + fcomplex_t(1.0,0.0);

	freeMatrix(&tMatrixA);freeMatrix(&tMatrixB);
}

void getQRDecomposition(cmatrix_t *aMatrix,cmatrix_t *qMatrix,cmatrix_t *rMatrix)
{
	cmatrix_t Pmatrix;
	uint16_t iRow,iCol,nSize,xRow;
	fcomplex_t *wVec,innerProduct;

	nSize = MIN(aMatrix->_rows,aMatrix->_cols);

	if (rMatrix != NULL)
		matrixCopy(aMatrix,rMatrix,CblasNoTrans,false);
	else
		rMatrix = aMatrix;

	createMatrix(&Pmatrix,aMatrix->_rows,aMatrix->_rows);
	wVec = (fcomplex_t *) malloc((aMatrix->_rows) * sizeof(fcomplex_t));

	for (iCol = 0;iCol < nSize;iCol ++)
	{
		for (iRow = 0;iRow < iCol;iRow ++)
		{
			wVec[iRow] = 0.0;
		}

		innerProduct = rMatrix->_data[iCol][iCol] * conj(rMatrix->_data[iCol][iCol]);

		for (iRow = iCol+1;iRow < aMatrix->_rows;iRow ++)
		{
			wVec[iRow] = rMatrix->_data[iRow][iCol];
			innerProduct += rMatrix->_data[iRow][iCol] * conj(rMatrix->_data[iRow][iCol]);
		}

		wVec[iCol] = rMatrix->_data[iCol][iCol] - fcomplex_t(sqrt(innerProduct.real()),0.0);

		innerProduct = 0.0;
		for (xRow = iCol;xRow < aMatrix->_rows;xRow ++)
		{
			innerProduct += conj(wVec[xRow]) * rMatrix->_data[xRow][iCol];
		}

		innerProduct = -1.0f / innerProduct;
		outerProductV(wVec,wVec,&Pmatrix,innerProduct);

		for (xRow = 0;xRow < aMatrix->_rows;xRow ++)
		{
			Pmatrix._data[xRow][xRow] = fcomplex_t(1.0,0.0) + Pmatrix._data[xRow][xRow];
		}

		matrixMultSafeB(&Pmatrix,rMatrix);

		if (iCol == 0)
			matrixCopy(&Pmatrix,qMatrix,CblasNoTrans,false);
		else
			matrixMultSafeB(&Pmatrix,qMatrix);

	}

	free(wVec);
	freeMatrix(&Pmatrix);
	matrixHermitian(qMatrix);
}

void getSVD(cmatrix_t *xcMatrix,cmatrix_t *ucMatrix,cmatrix_t *dcMatrix,cmatrix_t *vcMatrix,char jobV)
{
	cmatrix_t tQ,hR;
	uint16_t iIter = 0,maxSize;
	const uint16_t maxIterations = 8;

	maxSize = MAX(xcMatrix->_cols,xcMatrix->_rows);

	createMatrix(&tQ,maxSize,maxSize);
	createMatrix(&hR,maxSize,maxSize);
	reshapeMatrix(&hR,xcMatrix->_cols,xcMatrix->_rows);

	matrixCopy(xcMatrix,&hR,CblasConjTrans,false);
	reshapeMatrix(&tQ,hR._rows,hR._rows);
	getQRDecomposition(&hR,&tQ);

	matrixCopy(&tQ,vcMatrix,CblasNoTrans,false);

	matrixHermitian(&hR);
	reshapeMatrix(&tQ,hR._rows,hR._rows);
	getQRDecomposition(&hR,&tQ);

	matrixCopy(&tQ,ucMatrix,CblasNoTrans,false);

	while (iIter < maxIterations)
	{
		matrixHermitian(&hR);
		reshapeMatrix(&tQ,hR._rows,hR._rows);
		getQRDecomposition(&hR,&tQ);

		if (iIter % 2)
		{
			matrixMultSafeA(ucMatrix,&tQ);
		}
		else
		{
			matrixMultSafeA(vcMatrix,&tQ);
		}

		iIter ++;
	}

	matrixCopy(&hR,dcMatrix,CblasNoTrans,false);
	freeMatrix(&tQ);
	freeMatrix(&hR);
}
