
#ifndef STRUCTUREDEFINES_H_
#define STRUCTUREDEFINES_H_

#include "mainIncludes.h"

typedef std::complex<float> fcomplex_t;

typedef enum {CblasRowMajor=101, CblasColMajor=102} CBLAS_LAYOUT;
typedef enum {CblasNoTrans=111, CblasTrans=112, CblasConjTrans=113} CBLAS_TRANSPOSE;
typedef enum {CblasUpper=121, CblasLower=122} CBLAS_UPLO;
typedef enum {CblasNonUnit=131, CblasUnit=132} CBLAS_DIAG;
typedef enum {CblasLeft=141, CblasRight=142} CBLAS_SIDE;

typedef enum {ROUNDROBIN, GREEDY, SUCCPROJ, PIPD} SCHED_TYPE;

typedef struct list_t{

	uint16_t id;
	list_t *prev;
	list_t *next;
	uint32_t memoryInBytes;
	void *memoryPointer;
	bool isOccupied;

}list_t;

typedef struct {
	uint16_t _cols;
	uint16_t _rows;
	fcomplex_t **_data;
	list_t *headList;
}cmatrix_t;

typedef struct {
	uint16_t nTXAntenna;
	uint16_t maxRxAntenna;

	uint16_t nPRBs;
	uint16_t nSBs;
	SCHED_TYPE schedType;

}systemConfig_t;

typedef struct {

	uint16_t userID;

	cmatrix_t precMatrices[MAX_SCHBLK_OVER_SF];
	cmatrix_t channelMatrix[MAX_SCHBLK_OVER_SF];
	fcomplex_t *vH[MAX_SCHBLK_OVER_SF][MAX_MUX_USERS];

	uint32_t queuedPkts;
	uint8_t *userBits;
	uint16_t nRxAntenna;

	uint16_t totalStreams[MAX_SCHBLK_OVER_SF];
	uint16_t streamIndices[MAX_SCHBLK_OVER_SF][MAX_MUX_USERS];

}userConfig_t;

typedef struct {

	uint16_t rUserIndex[MAX_SCHBLK_OVER_SF];
	uint16_t schedulerTuple[MAX_SCHBLK_OVER_SF][MAX_MUX_USERS][2];

}scheduler_info_t;

typedef struct {

	uint16_t cellID;
	uint16_t frameNumber;
	userConfig_t *activeUsers[MAX_ACTIVE_USERS];

	uint16_t linkedUsers;
	uint16_t maxUsers;
	
	scheduler_info_t schedInfo;

}downlinkConfig_t;

#endif /* STRUCTUREDEFINES_H_ */

