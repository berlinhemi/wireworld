#include <stdlib.h>
#include <time.h>

#include "include/utils.h"


int random_between(int low, int high)
{
    srand(time(NULL));
    int number = -1;

    if(low <= high)
    {
        number = (rand() % (high-low+1)) + low;
    }

    return number;
}

void custom_sleep(double sec)
{
	struct timespec ts;
	ts.tv_sec = (int) sec;
	ts.tv_nsec = (sec - ((int) sec)) * 1000000000;
	nanosleep(&ts, NULL);
}

void clear_console()
{
    system("clear -x");
}