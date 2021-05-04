#include "time.h"
#include <sys/time.h>
float totalTime;
clock_t start, end;
int i;

/*This function measures the game time in seconds*/
void TimeMeasurement()
{
    /*time measurement*/
    for(i=0; i<200000000; i++);

    /*stop gets the current CPU time*/
    end = clock();

    /*Result of the Runtime measuring in seconds*/
    totalTime = (float)(end-start) / (float)CLOCKS_PER_SEC;

    printf("The Game was running %.2f seconds\n",totalTime);
}

void GameCountdown()
{
    clock_t currTime;
    clock_t endTime;

    int countdownSec = 30;

    /**
    printf("Bitte Sekunden eingeben ");
    scanf("%d",&countdownSec);
    **/

    while(countdownSec!=0)
    {
        // Ausgabe
        printf("Nur noch %d\n",countdownSec);
        // Ende_Zeit berechnen
        endTime=clock()+CLOCKS_PER_SEC;
        do
        {
            // Aktuelle_Zeit auslesen
            currTime=clock();
        }
        while(currTime<endTime);
        // eine Sekunde ist um
        countdownSec--;
    }
}
