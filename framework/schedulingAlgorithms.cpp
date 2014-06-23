
#include "schedulingAlgorithms.h"

void performUserScheduling(systemConfig_t *sysConfig,downlinkConfig_t *dlConfig)
{
	decomposeChannelMatrices(sysConfig,dlConfig);
	clearSchedulerConfigurations(sysConfig,dlConfig);

	switch (sysConfig->schedType)
	{
		case (ROUNDROBIN) :
		{
			performRandomScheduling(sysConfig,dlConfig);
			break;
		}
		case (GREEDY) :
		{
			performGreedyScheduling(sysConfig,dlConfig);
			break;
		}
		case (SUCCPROJ) :
		{
			performSuccessiveProjections(sysConfig,dlConfig);
			break;
		}
		case (PIPD) :
		{
			performPIPDScheduling(sysConfig,dlConfig);
			break;
		}
		default :
		{
			printf("Unknown Scheduler Algorithm ! \n");
			exit(false);
		}
	}
}

