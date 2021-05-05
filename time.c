#include "time.h"
#include <sys/time.h>
float totalTime, startTime, endTime, currTime;

/*This function measures the game time in seconds*/
void TimeMeasurement()
{
    /*Result of the Runtime measuring in seconds*/
    totalTime = (endTime-startTime) / (float)CLOCKS_PER_SEC;
    printf("You have needed %.2f sec\n",totalTime);

}
void StartClock()
{
    startTime=clock();
}
void EndClock()
{
    endTime=clock();
}
