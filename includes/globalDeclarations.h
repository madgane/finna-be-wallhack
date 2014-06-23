
#ifndef _GLOBALDECL_H_
#define _GLOBALDECL_H_

#include "mainIncludes.h"
#include "dynamicMemory.h"

extern downlinkConfig_t dlConfig;
extern systemConfig_t sysConfig;
extern DynamicMemory *dynamicMemory;

extern fcomplex_t globalChannelMatrix[MAX_ACTIVE_USERS][MAX_SCHBLK_OVER_SF][MAX_MUX_USERS][MAX_MUX_USERS];

#endif /* GLOBALDECL_H_ */
