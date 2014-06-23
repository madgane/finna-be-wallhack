
#ifndef _DISPLAFUNCTIONS_H_
#define _DISPLAFUNCTIONS_H_

#include "mainIncludes.h"
#include "globalDeclarations.h"

void displaySystemInfo();
void displayMatrix(cmatrix_t &cMatrix);
void displayMatrix(cmatrix_t *cMatrix);
void displayUserStructure(userConfig_t *cUser);
void displayScheduledUsers(systemConfig_t *sysConfig,downlinkConfig_t *dlConfig);

#endif /* _DISPLAYFUNCTIONS_H_ */
