#pragma once
class GeometricObject
{
private:
	double x, y;
public:
	GeometricObject();
	GeometricObject(double x, double y);
	~GeometricObject();

	double getX() const;
	double getY() const ;
	void setXY(double x, double y);

	virtual double getArea() = 0;
	virtual double getPerimeter() = 0;

	virtual bool contains(double x, double y) = 0;
};

class NewCircle2D : public GeometricObject
{
private:
	double radius;
public:
	NewCircle2D();
	NewCircle2D(double x, double y, double radius);
	~NewCircle2D();

	double getRadius();

	bool contains(const NewCircle2D& circle);
	bool overlaps(const NewCircle2D& circle);

	friend bool contains(const NewCircle2D& circle, const NewMyPoint& point);

	double getArea() override;
	double getPerimeter() override;
	bool contains(double x, double y) override;
};

class NewRectangle2D : public GeometricObject
{
private:
	double width, height;

public:
	NewRectangle2D();
	NewRectangle2D(double x, double y, double width, double height);
	~NewRectangle2D();

	double getWidth();
	double getHeight();
	void setWH(double width, double height);

	bool contains(const NewRectangle2D& rect);
	bool overlaps(const NewRectangle2D& rect);

	friend bool contains(const NewRectangle2D& rect, const NewMyPoint& point);

	double getArea() override;
	double getPerimeter() override;

	bool contains(double x, double y) override;
};

class NewMyPoint : public GeometricObject
{
public:
	NewMyPoint();
	NewMyPoint(double x, double y);
	~NewMyPoint();

	double Distane(const NewMyPoint& point);
};