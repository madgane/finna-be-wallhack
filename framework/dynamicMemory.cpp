
#include "dynamicMemory.h"

DynamicMemory::DynamicMemory()
{
	newMemChunks = 0;
	headList = (list_t *) obtainMemoryBuffer(sizeof(list_t));

	headList->id = newMemChunks;
	headList->isOccupied = false;
	headList->prev = NULL;
	headList->next = NULL;
	headList->memoryInBytes = 0;
	headList->memoryPointer = NULL;

	tailList = headList;
	tracePoint[0] = tracePoint[1] = tracePoint[2] = 0;

	heapMemoryHandle = bufferHeap;
	Error_init(&eBlock);
}

DynamicMemory::~DynamicMemory() {
	clearLists();
	printf("Total Lists without deletion ! - %d \n",newMemChunks);
}

void* DynamicMemory::obtainMemoryBuffer(uint32_t size_t)
{
	void *outBuffer;
	outBuffer = Memory_alloc(heapMemoryHandle,size_t,0,&eBlock);

	if (outBuffer != NULL)
		exit(EXIT_FAILURE);

	return outBuffer;
}

void DynamicMemory::freeMemoryBuffer(void *bufferPointer,uint32_t size_t)
{
	Memory_free(heapMemoryHandle,bufferPointer,size_t);
}

list_t* DynamicMemory::getEmptyList(uint32_t bufferSize)
{
	float minHeadRoom = 1e7,cHeadRoom;
	list_t *newList,*minList = NULL;
	list_t *currentList = tailList;

	if (!newMemChunks)
	{
		headList->isOccupied = true;
		headList->id = newMemChunks ++;
		headList->memoryInBytes = bufferSize;
		headList->memoryPointer = (void *) obtainMemoryBuffer(bufferSize);

		if (headList->memoryPointer == NULL)
		{
			printf("Unable to create new memory ! \n");
		}

		tracePoint[0] ++;
		return headList;
	}

	while (true)
	{
		if (!currentList->isOccupied)
		{
			if (bufferSize <= currentList->memoryInBytes)
			{
				cHeadRoom = (float) (currentList->memoryInBytes - bufferSize);
				if (cHeadRoom < minHeadRoom)
				{
					minList = currentList;
					minHeadRoom = cHeadRoom;
				}
			}
		}

		if (currentList->prev == NULL)
		{
			break;
		}
		else
		{
			if (currentList == currentList->prev->next)
			{
				currentList = currentList->prev;
			}
			else
			{
				printf("Memory corruption occured ! \n");fflush(stdout);
				break;
			}

		}
	}

	if (minList == NULL)
	{
		newList = (list_t *) obtainMemoryBuffer(sizeof(list_t));

		newList->id = newMemChunks++;
		newList->isOccupied = true;
		newList->prev = tailList;
		newList->next = NULL;
		newList->memoryInBytes = bufferSize;
		newList->memoryPointer = (void *) obtainMemoryBuffer(bufferSize);

		tailList->next = newList;
		tailList = newList;

		if (newList->memoryPointer == NULL)
		{
			cout << "buffer size requested - " << bufferSize << endl;
			printf("Unable to create new memory ! \n");
		}

		tracePoint[0] ++;
		return tailList;

	}
	else
	{
		tracePoint[2] ++;
		minList->isOccupied = true;
		return minList;
	}
}

cmatrix_t* DynamicMemory::getMatrix(uint16_t nRows,uint16_t nCols)
{
	list_t *tempList;
	cmatrix_t *matrix2D;
	uint32_t bufferSize,iRow;
	fcomplex_t **aArray,*bArray,*gArray;

	matrix2D = (cmatrix_t *) obtainMemoryBuffer(sizeof(cmatrix_t));

	matrix2D->_rows = nRows;
	matrix2D->_cols = nCols;
	bufferSize = nRows * (nCols + 1) * sizeof(fcomplex_t);
	tempList = getEmptyList(bufferSize);

	matrix2D->headList = tempList;
	gArray = (fcomplex_t *) tempList->memoryPointer;

	aArray = (fcomplex_t **) &gArray[0];
	bArray = (fcomplex_t *) &gArray[nRows];

	for (iRow = 0;iRow < nRows;iRow ++)
	{
		aArray[iRow] = (fcomplex_t *) &bArray[iRow * nCols];
	}

	matrix2D->_data = aArray;
	return matrix2D;
}

void DynamicMemory::updateMatrix(cmatrix_t *matrix2D,uint16_t nRows,uint16_t nCols)
{
	list_t *tempList;
	uint32_t bufferSize,iRow;
	fcomplex_t **aArray,*bArray,*gArray;

	matrix2D->_rows = nRows;
	matrix2D->_cols = nCols;
	bufferSize = nRows * (nCols + 1) * sizeof(fcomplex_t);
	tempList = getEmptyList(bufferSize);

	matrix2D->headList = tempList;
	gArray = (fcomplex_t *) tempList->memoryPointer;

	aArray = (fcomplex_t **) &gArray[0];
	bArray = (fcomplex_t *) &gArray[nRows];

	for (iRow = 0;iRow < nRows;iRow ++)
	{
		aArray[iRow] = (fcomplex_t *) &bArray[iRow * nCols];
	}

	matrix2D->_data = aArray;
}

cmatrix_t* DynamicMemory::getMatrixZ(uint16_t nRows,uint16_t nCols)
{
	list_t *tempList;
	cmatrix_t *matrix2D;
	uint32_t bufferSize,iRow,iCol;
	fcomplex_t **aArray,*bArray,*gArray;

	matrix2D = (cmatrix_t *) obtainMemoryBuffer(sizeof(cmatrix_t));

	matrix2D->_rows = nRows;
	matrix2D->_cols = nCols;
	bufferSize = nRows * (nCols + 1) * sizeof(fcomplex_t);
	tempList = getEmptyList(bufferSize);

	matrix2D->headList = tempList;
	gArray = (fcomplex_t *) tempList->memoryPointer;

	aArray = (fcomplex_t **) &gArray[0];
	bArray = (fcomplex_t *) &gArray[nRows];

	for (iRow = 0;iRow < nRows;iRow ++)
	{
		aArray[iRow] = (fcomplex_t *) &bArray[iRow * nCols];
	}

	for (iRow = 0;iRow < nRows;iRow ++)
	{
		for (iCol = 0;iCol < nCols;iCol ++)
		{
			aArray[iRow][iCol] = fcomplex_t(0.0,0.0);
		}
	}

	matrix2D->_data = aArray;
	return matrix2D;
}

void DynamicMemory::updateMatrixZ(cmatrix_t *matrix2D,uint16_t nRows,uint16_t nCols)
{
	list_t *tempList;
	uint32_t bufferSize,iRow,iCol;
	fcomplex_t **aArray,*bArray,*gArray;

	matrix2D->_rows = nRows;
	matrix2D->_cols = nCols;
	bufferSize = nRows * (nCols + 1) * sizeof(fcomplex_t);
	tempList = getEmptyList(bufferSize);

	matrix2D->headList = tempList;
	gArray = (fcomplex_t *) tempList->memoryPointer;

	aArray = (fcomplex_t **) &gArray[0];
	bArray = (fcomplex_t *) &gArray[nRows];

	for (iRow = 0;iRow < nRows;iRow ++)
	{
		aArray[iRow] = (fcomplex_t *) &bArray[iRow * nCols];
	}

	for (iRow = 0;iRow < nRows;iRow ++)
	{
		for (iCol = 0;iCol < nCols;iCol ++)
		{
			aArray[iRow][iCol] = fcomplex_t(0.0,0.0);
		}
	}

	matrix2D->_data = aArray;
}

cmatrix_t* DynamicMemory::getMatrixR(cmatrix_t *inMatrix,uint16_t nRows,uint16_t nCols)
{
	list_t *tempList;
	cmatrix_t *matrix2D;
	uint32_t bufferSize,iRow,iCol;
	fcomplex_t **aArray,*bArray,*gArray;

	matrix2D = (cmatrix_t *) obtainMemoryBuffer(sizeof(cmatrix_t));

	matrix2D->_rows = nRows;
	matrix2D->_cols = nCols;
	bufferSize = nRows * (nCols + 1) * sizeof(fcomplex_t);
	tempList = getEmptyList(bufferSize);

	matrix2D->headList = tempList;
	gArray = (fcomplex_t *) tempList->memoryPointer;

	aArray = (fcomplex_t **) &gArray[0];
	bArray = (fcomplex_t *) &gArray[nRows];

	for (iRow = 0;iRow < nRows;iRow ++)
	{
		aArray[iRow] = (fcomplex_t *) &bArray[iRow * nCols];
	}

	for (iRow = 0;iRow < nRows;iRow ++)
	{
		for (iCol = 0;iCol < nCols;iCol ++)
		{
			aArray[iRow][iCol] = fcomplex_t(0.0,0.0);
		}
	}

	matrix2D->_data = aArray;
	for (iRow = 0;iRow < inMatrix->_rows;iRow ++)
	{
		for (iCol = 0;iCol < inMatrix->_cols;iCol ++)
		{
			aArray[iRow][iCol] = inMatrix->_data[iRow][iCol];
		}
	}

	freeMatrixMemory(inMatrix);
	return matrix2D;
}

void DynamicMemory::freeMatrixMemory(cmatrix_t *fMatrix)
{
	list_t *tempList;
	tempList = fMatrix->headList;
	if (tempList->id < newMemChunks)
	{
		tracePoint[1] ++;
		tempList->isOccupied = false;
		fMatrix->headList = NULL;
		fMatrix->_cols = fMatrix->_rows = 0;
	}
}

void DynamicMemory::clearLists()
{
	list_t *currentList = tailList;

	while (true)
	{
		newMemChunks --;
		freeMemoryBuffer(currentList->memoryPointer,currentList->memoryInBytes);
		if (currentList->prev != NULL)
		{
			currentList = currentList->prev;
		}
		else
		{
			break;
		}
	}
}

void DynamicMemory::displayDMCompleteStatus()
{
	list_t *currentList = headList;
	uint16_t freeBlocks = 0,usedBlocks = 0;
	printf("Total memory chunks allocated - %d \n",newMemChunks);
	printf("Displaying the existing blocks \n");
	printf("------------------------------------- \n");

	while (true)
	{
		printf("Block ID - %d \n",currentList->id);
		cout << "is occupied - " << currentList->isOccupied << endl;
		printf("Total bytes contained - %d \n",currentList->memoryInBytes);
		printf("Pointer to memory block - %x \n",currentList->memoryPointer);
		printf("Pointer to previous list - %x \n",currentList->prev);
		printf("Pointer to next list - %x \n",currentList->next);

		if (currentList->isOccupied)
		{
			usedBlocks ++;
		}
		else
		{
			freeBlocks ++;
		}

		printf("Total memory chunks unused - %d \n",freeBlocks);
		printf("Total memory chunks in use - %d \n",usedBlocks);
		printf("------------------------------------- \n");

		if (currentList->next != NULL)
		{
			currentList = currentList->next;
		}
		else
		{
			break;
		}
	}
}

void DynamicMemory::displayDMStatus()
{
	list_t *currentList = headList;
	uint16_t freeBlocks = 0,usedBlocks = 0;
	printf("Total memory chunks created - %d \n",newMemChunks);

	while (true)
	{
		if (currentList->isOccupied)
		{
			usedBlocks ++;
		}
		else
		{
			freeBlocks ++;
		}

		if (currentList->next != NULL)
		{
			currentList = currentList->next;
		}
		else
		{
			break;
		}
	}

	printf("Total memory chunks unused - %d \n",freeBlocks);
	printf("Total memory chunks in use - %d \n",usedBlocks);

}

void DynamicMemory::displayQInfo()
{
	cout << "Creations - " << tracePoint[0] << endl;
	cout << "Deletions - " << tracePoint[1] << endl;
	cout << "ReUses - " << tracePoint[2] << endl;
	cout << "---------------------------------" << endl;
}

void DynamicMemory::resetQInfo()
{
	tracePoint[0] = tracePoint[1] = tracePoint[2] = 0;
}

void DynamicMemory::reshapeMatrix(cmatrix_t *matrix2D,uint16_t nRows,uint16_t nCols)
{
	list_t *tempList;
	uint32_t bufferSize,iRow;
	fcomplex_t **aArray,*bArray,*gArray;

	bufferSize = nRows * (nCols + 1) * sizeof(fcomplex_t);
	if (bufferSize > matrix2D->headList->memoryInBytes)
	{
		freeMatrixMemory(matrix2D);
		tempList = getEmptyList(bufferSize);
		matrix2D->headList = tempList;
		cout << "creating new matrix array" << endl;
	}

	matrix2D->_rows = nRows;
	matrix2D->_cols = nCols;
	tempList = matrix2D->headList;
	gArray = (fcomplex_t *) tempList->memoryPointer;

	aArray = (fcomplex_t **) &gArray[0];
	bArray = (fcomplex_t *) &gArray[nRows];

	for (iRow = 0;iRow < nRows;iRow ++)
	{
		aArray[iRow] = (fcomplex_t *) &bArray[iRow * nCols];
	}

	matrix2D->_data = aArray;
}

void DynamicMemory::reshapeMatrixAndCopy(cmatrix_t *matrix2D,uint16_t nRows,uint16_t nCols)
{
	list_t *tempList;
	bool createdNewBuffer = false;
	uint32_t bufferSize,iRow,oRows,oCols,iCol;
	fcomplex_t **aArray,*bArray,*gArray,*tempBuffer;


	bufferSize = nRows * (nCols + 1) * sizeof(fcomplex_t);
	if (bufferSize > matrix2D->headList->memoryInBytes)
	{
		freeMatrixMemory(matrix2D);
		tempList = getEmptyList(bufferSize);
		matrix2D->headList = tempList;
		cout << "creating new matrix array" << endl;
	}

	oRows = matrix2D->_rows;oCols = matrix2D->_cols;
	if (DynamicMemory::scratchBufferSize > (sizeof(fcomplex_t) * oRows * oCols))
	{
		tempBuffer = (fcomplex_t *) scratchpadBuffer;
	}
	else
	{
		createdNewBuffer = true;
		tempBuffer = (fcomplex_t *) obtainMemoryBuffer(sizeof(fcomplex_t) * oRows * oCols);
	}


	if (nCols == oCols)
	{
		for (iRow = 0;iRow < oRows;iRow ++)
			for (iCol = 0;iCol < oCols;iCol ++)
				tempBuffer[iRow * oCols + iCol] = matrix2D->_data[iRow][iCol];

		matrix2D->_rows = nRows;
		matrix2D->_cols = nCols;
		tempList = matrix2D->headList;
		gArray = (fcomplex_t *) tempList->memoryPointer;

		aArray = (fcomplex_t **) &gArray[0];
		bArray = (fcomplex_t *) &gArray[nRows];

		for (iRow = 0;iRow < nRows;iRow ++)
		{
			aArray[iRow] = (fcomplex_t *) &bArray[iRow * nCols];
		}

		matrix2D->_data = aArray;

		for (iRow = 0;iRow < oRows;iRow ++)
			for (iCol = 0;iCol < oCols;iCol ++)
				matrix2D->_data[iRow][iCol] = tempBuffer[iRow * oCols + iCol];
	}

	if (nRows == oRows)
	{
		for (iCol = 0;iCol < oCols;iCol ++)
			for (iRow = 0;iRow < oRows;iRow ++)
				tempBuffer[iRow + iCol * oRows] = matrix2D->_data[iRow][iCol];

		matrix2D->_rows = nRows;
		matrix2D->_cols = nCols;
		tempList = matrix2D->headList;
		gArray = (fcomplex_t *) tempList->memoryPointer;

		aArray = (fcomplex_t **) &gArray[0];
		bArray = (fcomplex_t *) &gArray[nRows];

		for (iRow = 0;iRow < nRows;iRow ++)
		{
			aArray[iRow] = (fcomplex_t *) &bArray[iRow * nCols];
		}

		matrix2D->_data = aArray;
		for (iCol = 0;iCol < oCols;iCol ++)
			for (iRow = 0;iRow < oRows;iRow ++)
				matrix2D->_data[iRow][iCol] = tempBuffer[iRow + iCol * oRows];

	}

	if (createdNewBuffer)
		freeMemoryBuffer(tempBuffer,sizeof(fcomplex_t) * oRows * oCols);
}


