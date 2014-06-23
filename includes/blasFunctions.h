
#ifndef BLASFUNCTIONS_H_
#define BLASFUNCTIONS_H_

#include "memoryManagement.h"

uint32_t cblas_isamax(uint32_t,void *ptr,uint32_t incX);
float cblas_scnrm2(uint32_t length,void *ptr,uint32_t incX);

fcomplex_t dotProductV(fcomplex_t *aVector,fcomplex_t *bVector,uint16_t size);
void outerProductV(fcomplex_t *aVector,fcomplex_t *bVector,cmatrix_t *cMatrix,fcomplex_t scaling = fcomplex_t(1.0,0.0));

void matrixTranspose(cmatrix_t *qMatrix);
void matrixHermitian(cmatrix_t *qMatrix);

void matrixMultV(cmatrix_t *pMatrix, fcomplex_t *qVector, fcomplex_t *outVector,bool createM = true);

void matrixMultSafeA(cmatrix_t *aMatrix,cmatrix_t *bMatrix);
void matrixMultSafeB(cmatrix_t *aMatrix,cmatrix_t *bMatrix);

void matrixCopy(cmatrix_t *aMatrix,cmatrix_t *bMatrix,CBLAS_TRANSPOSE cblasTR1 = CblasNoTrans,bool createM=true);

void matrixMult(cmatrix_t *pMatrix, cmatrix_t *qMatrix, cmatrix_t *rMatrix,CBLAS_TRANSPOSE cblasTR1=CblasNoTrans,CBLAS_TRANSPOSE cblasTR2=CblasNoTrans,bool createM = true);

#endif /* BLASFUNCTIONS_H_ */
