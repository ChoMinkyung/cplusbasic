#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

struct POINT_2D
{
	double x;
	double y;
};

struct LinearEquation
{
	// ax + by = c
	double a;
	double b;
	double c;
};

void getLinear(POINT_2D* pp1, POINT_2D* pp2, LinearEquation* linear);
void Cramer(LinearEquation* linear_1, LinearEquation* linear_2);

int main()
{

	POINT_2D point_1;
	POINT_2D point_2;
	POINT_2D point_3;
	POINT_2D point_4;

	LinearEquation linear_1;
	LinearEquation linear_2;

	cout << "(x1, y1) : ";
	cin >> point_1.x >> point_1.y;

	cout << "(x2, y2) : ";
	cin >> point_2.x >> point_2.y;

	cout << "(x2, y2) : ";
	cin >> point_3.x >> point_3.y;

	cout << "(x2, y2) : ";
	cin >> point_4.x >> point_4.y;

	getLinear(&point_1, &point_2, &linear_1);
	getLinear(&point_3, &point_4, &linear_2);

	Cramer(&linear_1, &linear_2);

}

void getLinear(POINT_2D* pp1, POINT_2D* pp2, LinearEquation* linear)
{
	//ax + by = c;
	linear->a = pp2->y - pp1->y;
	linear->b = pp2->x - pp1->x;
	linear->c = pp2->x * pp1->y - pp1->x * pp2->y;
}

void Cramer(LinearEquation* linear_1, LinearEquation* linear_2)
{
	if (linear_1->a / linear_1->b == linear_2->a / linear_2->b) cout << "두 직선은 평행히다." << endl;
	else
	{
		double x = (linear_1->c * linear_2->b - linear_1->b * linear_2->c) / (linear_1->a * linear_2->b - linear_1->b * linear_2->a);
		double y = (linear_1->a * linear_2->c - linear_1->c * linear_2->a) / (linear_1->a * linear_2->b - linear_1->b * linear_2->a);
		cout << "두 직선의 교차점은 (" << x << ", " << y << ") 이다." << endl;
	}
}