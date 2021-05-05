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
/*This function will start the timer */
void StartClock()
{
    startTime=clock();
}
/*This function will end the started timer from the StartClock() function */
void EndClock()
{
    endTime=clock();
}
