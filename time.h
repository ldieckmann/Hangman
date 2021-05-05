#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <sys/time.h>

float totalTime, startTime, endTime, currTime;

void TimeMeasurement();
void StartClock();
void EndClock();
#endif // TIME_H_INCLUDED
