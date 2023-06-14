#include "20230609_Q2_vector.h"

cVector3::cVector3()
{
	x = y = z = 0;
}

cVector3::cVector3(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

cVector3::~cVector3()
{
}

void cVector3::Reset(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;

}

bool cVector3::operator==(cVector3& vec)
{
	if (x == vec.x && y == vec.y && z == vec.z) return true;

	return false;
}

bool cVector3::operator!=(cVector3& vec)
{
	if (x == vec.x && y == vec.y && z == vec.z) return false;
	return true;
}

cVector3 cVector3::operator+(cVector3& vec)
{

	return cVector3(x + vec.x, y + vec.y, z + vec.z);
}

cVector3 cVector3::operator-(cVector3& vec)
{
	return cVector3(x - vec.x, y - vec.y, z - vec.z);
}

cVector3 cVector3::operator*(double d)
{
	return cVector3(x * d, y * d, z * d);
}

cVector3 cVector3::operator/(double d)
{

	return cVector3(x / d, y / d, z / d);
}

double cVector3::length()
{
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

cVector3 cVector3::Normalize()
{

	return cVector3(x / length(), y / length(), z / length());
}

double cVector3::Dot(cVector3& v1)
{
	return v1.x * x + v1.y * y + v1.z * z;
}

cVector3 cVector3::Cross(cVector3& v1)
{
	return cVector3(y * v1.z - z * v1.y, z * v1.x - x * v1.z, x * v1.y - y * v1.x);
}

double cVector3::Angle(cVector3& v1)
{
	return (acos(Dot(v1) / (v1.length() * length())) * 180) / 3.141592;
}



cVector3 operator*(double n, cVector3& vec)
{
	return cVector3(n * vec.x, n * vec.y, n * vec.z);
}

std::ostream& operator<<(std::ostream& os, const cVector3& v)
{
	os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
	return os;
}
