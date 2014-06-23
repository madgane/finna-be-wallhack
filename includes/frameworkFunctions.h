
#ifndef FRAMEWORKFUNCTIONS_H_
#define FRAMEWORKFUNCTIONS_H_

#include "mainIncludes.h"
#include "memoryManagement.h"
#include "globalDeclarations.h"

void cleanupUsers(downlinkConfig_t *dlConfig);
void randomizeChannelMatrix(cmatrix_t *channelMatrix,bool createM = true);
void initializeSystem(downlinkConfig_t *dConfig,systemConfig_t *sConfig,uint16_t cellID,uint16_t nTxAntenna,uint16_t nRxAntenna,uint16_t nSchBlks,uint16_t nUsers);
userConfig_t* createNewUserStructure(uint16_t uID,uint16_t nRxAntenna,uint16_t backloggedPkts);
void updateDLConfig_User(downlinkConfig_t *dConfig,userConfig_t *cUser);
void clearDLConfig_User(downlinkConfig_t *dConfig,uint16_t userID);
void updateUserChannel(userConfig_t *cUser);
void updateUserChannel(userConfig_t *cUser,uint16_t leadIndex);
void freeUser(userConfig_t *cUser);
void updateChannelDumps(float *channelVector, char *fileString);

#endif /* FRAMEWORKFUNCTIONS_H_ */
