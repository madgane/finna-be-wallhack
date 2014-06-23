
#include "memoryManagement.h"

void freeMatrix(cmatrix_t *fMatrix)
{
	dynamicMemory->freeMatrixMemory(fMatrix);
}

void createMatrix(cmatrix_t *aMatrix,uint16_t nRows,uint16_t nCols)
{
	dynamicMemory->updateMatrix(aMatrix,nRows,nCols);
}

void createZeroMatrix(cmatrix_t *aMatrix,uint16_t nRows,uint16_t nCols)
{
	dynamicMemory->updateMatrixZ(aMatrix,nRows,nCols);
}

void reshapeMatrix(cmatrix_t *aMatrix,uint16_t nRows,uint16_t nCols)
{
	dynamicMemory->reshapeMatrix(aMatrix,nRows,nCols);
}

void reshapeAndCopyMatrix(cmatrix_t *inPointer,uint16_t nRows,uint16_t nCols)
{
	dynamicMemory->reshapeMatrixAndCopy(inPointer,nRows,nCols);
}

void* allocateMemory(uint32_t size_t)
{
	return dynamicMemory->obtainMemoryBuffer(size_t);
}

void freeMemory(void *bufferPointer,uint32_t size_t)
{
	dynamicMemory->freeMemoryBuffer(bufferPointer,size_t);
}
