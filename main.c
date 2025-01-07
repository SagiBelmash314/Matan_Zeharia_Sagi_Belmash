#include <stdio.h>
#include "superMarket.h"
#define ERR_MSG "An error has accured"

void main()
{
	SuperMarket sm;
	if (!initSuperMarket(&sm))
		puts(ERR_MSG);
	else
	{
		printSuperMarket(&sm);
		if(!addProduct(&sm))
			puts(ERR_MSG);
		if (!addProduct(&sm))
			puts(ERR_MSG);
		else
		{
			printSuperMarket(&sm);
			freeSuperMarket(&sm);
		}
	}
}