#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <sys/time.h>

float totalTime;
clock_t start, end;
long i;

void TimeMeasurement();
void GameCountdown();
long TimeLeft();

#endif // TIME_H_INCLUDED
