#pragma once
class Rectangle2D
{
private:
	double x, y, width, height;

	
public:
	Rectangle2D();
	Rectangle2D(double x, double y, double width, double height);
	~Rectangle2D();

	double getX();
	double getY();
	void setXY(double x, double y);

	double getWidth();
	double getHeight();
	void setWH(double width, double height);

	double getArea();
	double getPerimeter();

	bool contains(double x, double y);
	bool contains(const Rectangle2D& r);
	bool overlaps(const Rectangle2D& r);

};

