#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Line
{
	double x0, y0, x1, y1;
	//y = ax+b
	double a, b;
};

struct point_2D
{
	double x, y;
};

void getLine(Line* line);
int getPointLoc(Line* line, point_2D* point);

int main()
{
	Line line;
	Line* pLine = &line;

	point_2D point;
	point_2D* pPoint = &point;

	cout << "p0(x0, y0)를 입력하세요 : ";
	cin >> line.x0 >> line.y0;
	cout << "p1(x1, y1)을 입력하세요 : ";
	cin >> line.x1 >> line.y1;

	cout << "p2(x2, y2)를 입력하세요 : ";
	cin >> point.x >> point.y;
	
	getLine(pLine);
	switch (getPointLoc(pLine, pPoint))
	{
	case 0:
		cout << "점 p2는 직선 위에 있습니다." << endl;
		break;
	case 1:
		cout << "점 p2는 직선 오른쪽에 있습니다." << endl;
		break;
	case -1:
		cout << "점 p2는 직선 왼쪽에 있습니다." << endl;
		break;
	case 2:
		cout << "점 p2는 직선 위쪽에 있습니다." << endl;
		break;
	case -2:
		cout << "점 p2는 직선 아래쪽에 있습니다." << endl;
		break;
	}

}

void getLine(Line* line)
{
	line->a = (line->y1 - line->y0) / (line->x1 - line->x0);
	line->b = line->y0 - line->a * line->x0;
}

int getPointLoc(Line* line, point_2D* point)
{
	if (line->a > 0)
	{
		if (line->a * point->x + line->b > point->y) return 1;
		else if (line->a * point->x + line->b < point->y) return -1;
		else return 0;
	}
	else if (line->a < 0)
	{
		if (line->a * point->x + line->b > point->y) return -1;
		else if (line->a * point->x + line->b < point->y) return 1;
		else return 0;
	}
	else
	{
		if (line->a * point->x + line->b > point->y) return -2;
		else if (line->a * point->x + line->b < point->y) return 2;
		else return 0;
	}
}