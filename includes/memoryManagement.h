
#ifndef MEMORYMANAGEMENT_H_
#define MEMORYMANAGEMENT_H_

#include "mainIncludes.h"
#include "globalDeclarations.h"

void freeMatrix(cmatrix_t *fMatrix);

#pragma FUNC_ALWAYS_INLINE
void createMatrix(cmatrix_t *aMatrix,uint16_t nRows,uint16_t nCols);
#pragma FUNC_ALWAYS_INLINE
void reshapeMatrix(cmatrix_t *aMatrix,uint16_t nRows,uint16_t nCols);
#pragma FUNC_ALWAYS_INLINE
void createZeroMatrix(cmatrix_t *aMatrix,uint16_t nRows,uint16_t nCols);
#pragma FUNC_ALWAYS_INLINE
void reshapeAndCopyMatrix(cmatrix_t *inPointer,uint16_t nRows,uint16_t nCols);

void* allocateMemory(uint32_t size_t);
void freeMemory(void *bufferPointer,uint32_t size_t);


#endif /* MEMORYMANAGEMENT_H_ */
