#pragma once
class StopWatch
{
private:
	clock_t startTime, endTime;

public:
	StopWatch();
	~StopWatch();

	double getStart();
	double getEnd();
	void start();
	void stop();
	double getElapsedTime();

};

