#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

struct CENTER
{
	int r;
	double x0;
	double y0;
};

struct POINT_2D
{
	double x;
	double y;
};

void inside(CENTER* pc, POINT_2D* pp);

int main()
{
	CENTER center;
	CENTER* pc = &center;

	POINT_2D point;
	POINT_2D* pp = &point;

	cout << "반지름 r : ";
	cin >> pc->r;
	cout << "(x0, y0) : ";
	cin >> pc->x0 >> pc->y0;
	
	cout << "(x, y) : ";
	cin >> pp->x >> pp->y;

	inside(pc, pp);

}

void inside(CENTER * pc, POINT_2D *pp)
{
	double distance = sqrt(pow(pc->x0 - pp->x, 2) + pow(pc->y0 - pp->y, 2));

	cout << "점(" << pp->x << ", " << pp->y << ")는 중점이 (" << pc->x0 << ", " << pc->y0 << ")이고 반지름이 " << pc->r;

	if (distance <= pc->r) cout << "인 원 안에 있습니다." << endl;
	else cout << "인 원 밖에 있습니다." << endl;

}