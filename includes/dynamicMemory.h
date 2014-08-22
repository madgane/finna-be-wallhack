
#ifndef DYNAMICMEMORY_H_
#define DYNAMICMEMORY_H_

#include "structureDefines.h"

class DynamicMemory
{

private :

	uint32_t newMemChunks;
	list_t *headList;
	list_t *tailList;

	uint32_t tracePoint[3];
	static const unsigned int scratchBufferSize = 1024;
	short scratchpadBuffer[scratchBufferSize];

private :

	list_t* getEmptyList(uint32_t bufferSize);
	void clearLists();

public :

	DynamicMemory();
	~DynamicMemory();

	void freeMatrixMemory(cmatrix_t *fMatrix);
	cmatrix_t* getMatrix(uint16_t nRows,uint16_t nCols);
	cmatrix_t* getMatrixZ(uint16_t nRows,uint16_t nCols);
	cmatrix_t* getMatrixR(cmatrix_t *tMatrix,uint16_t nRows,uint16_t nCols);

	void updateMatrix(cmatrix_t *matrix2D,uint16_t nRows,uint16_t nCols);
	void updateMatrixZ(cmatrix_t *matrix2D,uint16_t nRows,uint16_t nCols);

	void reshapeMatrix(cmatrix_t *matrix2D,uint16_t nRows,uint16_t nCols);
	void reshapeMatrixAndCopy(cmatrix_t *matrix2D,uint16_t nRows,uint16_t nCols);

	void displayDMStatus();
	void displayDMCompleteStatus();

	void* obtainMemoryBuffer(uint32_t size_t);
	void freeMemoryBuffer(void *inBuffer,uint32_t size_t);

	void resetQInfo();
	void displayQInfo();

};

#endif /* DYNAMICMEMORY_H_ */
