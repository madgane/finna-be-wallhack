

#ifndef SCHEDULINGALGORITHMS_H_
#define SCHEDULINGALGORITHMS_H_

#include "globalDeclarations.h"
#include "supportingFunctions.h"

void performUserScheduling(systemConfig_t *sysConfig,downlinkConfig_t *dlConfig);
void performRandomScheduling(systemConfig_t *sysConfig,downlinkConfig_t *dlConfig);
void performGreedyScheduling(systemConfig_t *sysConfig,downlinkConfig_t *dlConfig);
void performSuccessiveProjections(systemConfig_t *sysConfig,downlinkConfig_t *dlConfig);
void performPIPDScheduling(systemConfig_t *sysConfig,downlinkConfig_t *dlConfig);

#endif /* SCHEDULINGALGORITHMS_H_ */
