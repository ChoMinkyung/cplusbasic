#include <cmath>
#include "20230614_Q2_MyPoint.h"

MyPoint::MyPoint()
{
	x = y = 0;
}

MyPoint::MyPoint(double x, double y)
{
	this->x = x;
	this->y = y;
}

MyPoint::~MyPoint()
{
}

double MyPoint::getX() const
{
	return x;
}

double MyPoint::getY() const
{
	return y;
}

double MyPoint::Distane(const MyPoint& p)
{
	return 	sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}
