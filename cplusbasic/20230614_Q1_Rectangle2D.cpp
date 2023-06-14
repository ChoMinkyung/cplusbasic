#include <cmath>
#include "20230614_Q1_Rectangle2D.h"

Rectangle2D::Rectangle2D()
{
    x = y = 0;
    width = height = 1;
}

Rectangle2D::Rectangle2D(double x, double y, double width, double height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

Rectangle2D::~Rectangle2D()
{
}

double Rectangle2D::getX()
{
    return x;
}

double Rectangle2D::getY()
{
    return y;
}


void Rectangle2D::setXY(double x, double y)
{
    this->x = x;
    this->y = y;
}

double Rectangle2D::getWidth()
{
    return width;
}

double Rectangle2D::getHeight()
{
    return height;
}

void Rectangle2D::setWH(double width, double height)
{
    this->width = width;
    this->height = height;
}

double Rectangle2D::getArea()
{
    return width*height;
}

double Rectangle2D::getPerimeter()
{
    return 2*(width+height);
}

bool Rectangle2D::contains(double x, double y)
{
    double y_max = y + height / 2;
    double y_min = y - height / 2;
    double x_max = x + width / 2;
    double x_min = x - width / 2;

    if (y<y_max && y>y_min && x<x_max && x>x_min) return true;
    return false;
}

bool Rectangle2D::contains(const Rectangle2D& r)
{
    double width_max = width > r.width ? width : r.width;
    double height_max = height > r.height ? height : r.height;

    if (abs(x - r.x) < width_max / 2 && abs(y - r.y) < height_max / 2) return true;
    return false;
}

bool Rectangle2D::overlaps(const Rectangle2D& r)
{

    if (abs(x - r.x) < width / 2 + r.width / 2 && abs(y - r.y) < height / 2 + r.height / 2) return true;
    return false;
}
