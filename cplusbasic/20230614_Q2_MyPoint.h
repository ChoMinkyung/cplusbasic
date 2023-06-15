#pragma once
#include "20230614_Q2_MyPoint.h"

class MyPoint
{
private:
	double x, y;
public:
	MyPoint();
	MyPoint(double x, double y);
	~MyPoint();

	double getX() const;
	double getY() const;

	double Distane(const MyPoint&);
	
};

