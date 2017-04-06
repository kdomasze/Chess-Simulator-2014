#include "Time.h"

/* Get the time, Call this function before play makes a move and call after player maked a move, require a varible type time_t which is in Time.h lib */ 
int TimeStart(time_t x)
{
	time(&x);
	return (int)x;
	
}

/* compare two time's different and compare with the time limit */
int TimeCompare(int x,int y)
{
	double i;
	int j,k;

	i = ((double)(y-x))/60.00;
        j = (int)(((i*100.00) - ((int)(i)*100)));
        k = j*60/100;

	
	printf("Time limit is 3 minutes\n");
	printf("this move takes %d minutes and %d seconds\n",(int)i,k);

	/* time limit is 360 seconds */
	if((y-x) > 360)
	{
		printf("Time out, You Lose!!!\n");
		return 1;
	}

	else
	{
		return 0;
	}
	
}



