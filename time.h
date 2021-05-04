#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <sys/time.h>

float totalTime;
clock_t start, end;
int i;

void TimeMeasurement();
void GameCountdown();

#endif // TIME_H_INCLUDED
