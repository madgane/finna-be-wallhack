
#ifndef LAPACKFUNCTIONS_H_
#define LAPACKFUNCTIONS_H_

#include "blasFunctions.h"
#include "displayFunctions.h"

void getNullMatrix(cmatrix_t *aMatrix,cmatrix_t *nMatrix);
void getSVD(cmatrix_t *aMatrix,cmatrix_t *uMatrix,cmatrix_t *dMatrix,cmatrix_t *vMatrix,char jobV = 'A');

void eyeMatrix(cmatrix_t *iMatrix);
void getQRDecomposition(cmatrix_t *aMatrix,cmatrix_t *qMatrix,cmatrix_t *rMatrix = NULL);

void getMatrixInverse(cmatrix_t *aMatrix,cmatrix_t *iMatrix = NULL,fcomplex_t scalingF = fcomplex_t(1.0,0.0));
void getNullMatrix(cmatrix_t *aMatrix,cmatrix_t *nMatrix);

#endif /* LAPACKFUNCTIONS_H_ */
