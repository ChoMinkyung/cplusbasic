#include <ctime>

#include "20230619_Q1_StopWatch.h"

StopWatch::StopWatch()
{
    startTime = clock();
}

StopWatch::~StopWatch()
{

}

double StopWatch::getStart()
{
    return (double)startTime;
}

double StopWatch::getEnd()
{
    return (double)endTime;
}

void StopWatch::start()
{
    startTime = clock();
}

void StopWatch::stop()
{
    endTime = clock();

}

double StopWatch::getElapsedTime()
{
    return (double)(endTime - startTime)/CLOCKS_PER_SEC/1000;
}
