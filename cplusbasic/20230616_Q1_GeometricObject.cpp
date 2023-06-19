#include <iostream>
using namespace std;

#include "20230616_Q1_GeometricObject.h"
#define PI 3.141592

GeometricObject::GeometricObject()
{
	x = y = 0;
}

GeometricObject::GeometricObject(double x, double y)
{
	this->x = x;
	this->y = y;
}

GeometricObject::~GeometricObject()
{
	cout << "GeometricObject ¼Ò¸ê" << endl;
}

double GeometricObject::getX() const
{
	return x;
}

double GeometricObject::getY() const
{
	return y;
}

void GeometricObject::setXY(double x, double y)
{
	this->x = x;
	this->y = y;
}

NewCircle2D::NewCircle2D(): GeometricObject()
{
	radius = 1;
}

NewCircle2D::NewCircle2D(double x, double y, double radius) : GeometricObject(x, y)
{
	this->radius = radius;
}

NewCircle2D::~NewCircle2D()
{
	cout << "NewCircle2D ¼Ò¸ê" << endl;

}

double NewCircle2D::getRadius()
{
	return radius;
}

bool NewCircle2D::contains(const NewCircle2D& circle)
{
	
	double distance = sqrt(pow(getX() - circle.getX(), 2) + pow(getY() - circle.getY(), 2));

	if (distance <= abs(radius - circle.radius)) return true;

	return false;
}

bool NewCircle2D::overlaps(const NewCircle2D& circle)
{
	return false;
}

double NewCircle2D::getArea()
{
	return 0.0;
}

double NewCircle2D::getPerimeter()
{
	return 0.0;
}

bool NewCircle2D::contains(double x, double y)
{
	return false;
}

bool contains(const NewCircle2D& circle, const NewMyPoint& point)
{
	return false;
}

bool contains(const NewRectangle2D& rect, const NewMyPoint& point)
{
	return false;
}

NewRectangle2D::NewRectangle2D()
{
}

NewRectangle2D::NewRectangle2D(double x, double y, double width, double height)
{
}

NewRectangle2D::~NewRectangle2D()
{
}

double NewRectangle2D::getWidth()
{
	return 0.0;
}

double NewRectangle2D::getHeight()
{
	return 0.0;
}

void NewRectangle2D::setWH(double width, double height)
{
}

bool NewRectangle2D::contains(const NewRectangle2D& rect)
{
	return false;
}

bool NewRectangle2D::overlaps(const NewRectangle2D& rect)
{
	return false;
}

double NewRectangle2D::getArea()
{
	return 0.0;
}

double NewRectangle2D::getPerimeter()
{
	return 0.0;
}

bool NewRectangle2D::contains(double x, double y)
{
	return false;
}

NewMyPoint::NewMyPoint()
{
}

NewMyPoint::NewMyPoint(double x, double y)
{
}

NewMyPoint::~NewMyPoint()
{
}

double NewMyPoint::Distane(const NewMyPoint& point)
{
	return 0.0;
}
