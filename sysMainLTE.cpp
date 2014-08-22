/*
 *  ======== main.c ========
 */

#include "stdlib.h"
#include "globalDeclarations.h"

void lteSystemInit();
void channelUpdate();
void lteSystemTerminate();
void schedulingForCurrentSF();

int main()
{ 
	lteSystemInit();
	channelUpdate();
	schedulingForCurrentSF();
	lteSystemTerminate();

    return(EXIT_SUCCESS);
}
