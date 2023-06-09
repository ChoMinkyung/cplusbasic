#pragma once
#include "20230614_Q2_MyPoint.h"

class Circle2D
{
private:
	double x, y, radius;
public:
	Circle2D();
	Circle2D(double x, double y, double radius);
	~Circle2D();

	double getX();
	double getY();
	double getRadius();


	double getArea();
	double getPerimeter();
	bool contains(double x, double y);
	bool contains(const Circle2D& circle);
	bool overlaps(const Circle2D& circle);

	friend bool contains(const Circle2D& circle, const MyPoint& point);

};

