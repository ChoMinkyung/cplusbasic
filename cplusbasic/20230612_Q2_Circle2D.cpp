#include "20230612_Q2_Circle2D.h"

#include <cmath>
#define PI 3.141592

Circle2D::Circle2D()
{
    x = y = 0;
    radius = 1;
}

Circle2D::Circle2D(double x, double y, double radius)
{
    this->x = x;
    this->y = y;
    this->radius = radius;
}

Circle2D::~Circle2D()
{
}

double Circle2D::getX()
{
    return x;
}

double Circle2D::getY()
{
    return y;
}

double Circle2D::getRadius()
{
    return radius;
}


double Circle2D::getArea()
{
    return radius * radius * PI;
}

double Circle2D::getPerimeter()
{
    return 2 * radius * PI;
}

bool Circle2D::contains(double x, double y)
{
    double distance = sqrt(pow(this->x - x, 2) + pow(this->y - y, 2));

    if (distance > radius) return false;
    return true;
}

bool Circle2D::contains(const Circle2D& circle)
{
    double distance = sqrt(pow(x - circle.x, 2) + pow(y - circle.y, 2));

    if (distance <= abs(radius - circle.radius)) return true;

    return false;
}

bool Circle2D::overlaps(const Circle2D& circle)
{
    double distance = sqrt(pow(x - circle.x, 2) + pow(y - circle.y, 2));

    if (distance > abs(radius - circle.radius) || distance < radius + circle.radius) return true;

    return false;
}
