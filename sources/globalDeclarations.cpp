
#include "globalDeclarations.h"

downlinkConfig_t dlConfig;
systemConfig_t sysConfig;
DynamicMemory *dynamicMemory;

#pragma DATA_SECTION(".bigMem")
fcomplex_t globalChannelMatrix[MAX_ACTIVE_USERS][MAX_SCHBLK_OVER_SF][MAX_MUX_USERS][MAX_MUX_USERS];
