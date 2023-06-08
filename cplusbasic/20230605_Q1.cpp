#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct rectangle
{
	double x;
	double y;
	double width;
	double height;

	double min_x;
	double min_y;
	double max_x;
	double max_y;
};

void getRectangle(rectangle* rect);

int Overlap(rectangle* rect1, rectangle* rect2);

int main()
{
	rectangle rect1;
	rectangle* pRect1 = &rect1;
	rectangle rect2;
	rectangle* pRect2 = &rect2;

	cout << "ù ��° �簢�� x, y, width, height : ";
	cin >> rect1.x >> rect1.y >> rect1.width >> rect1.height;

	getRectangle(pRect1);

	cout << "�� ��° �簢�� x, y, width, height : ";
	cin >> rect2.x >> rect2.y >> rect2.width >> rect2.height;

	getRectangle(pRect2);

	switch (Overlap(pRect1, pRect2))
	{
	case 0:
		cout << "�� ���簢���� ��ġ�� ����" << endl;
		break;
	case 1:
		cout << "�� ��° ���簢���� ù ��° ���簢�� ���ο� ����" << endl;
		break;
	case 2:
		cout << "ù ��° ���簢���� �� ��° ���簢�� ���ο� ����" << endl;
		break;
	case 3:
		cout << "�� ���簢���� ��������" << endl;
		break;
	case 4:
		cout << "�� ���簢���� ����" << endl;
		break;
	default:
		break;
	}
}

void getRectangle(rectangle* rect)
{
	rect->max_x = rect->x + rect->width / 2.0;
	rect->min_x = rect->x - rect->width / 2.0;
	rect->max_y = rect->y + rect->height / 2.0;
	rect->min_y = rect->y - rect->height / 2.0;
}

int Overlap(rectangle* rect1, rectangle* rect2)
{

	if (rect1->min_x >= rect2->max_x || rect2->min_x >= rect1->max_x 
		|| rect1->min_y >= rect2->max_y || rect2->min_y >= rect1->max_y ) return 0;

	if (rect1->min_x <= rect2->min_x && rect1->max_x >= rect2->max_x)
	{
		if (rect1->min_y <= rect2->min_y)
		{
			if (rect1->width == rect2->width && rect1->height == rect2->height) return 4;
			if (rect1->max_y > rect2->max_y)  return 1;
		}
	}

	if (rect1->min_x >= rect2->min_x && rect1->max_x <= rect2->max_x)
	{
		if (rect2->min_y <= rect1->min_y && rect2->max_y  > rect1->max_y)  return 2;
	}

	return 3;


}
