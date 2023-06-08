#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct circle
{
	double x;
	double y;
	double r;
};

int overlap(circle* c1, circle* c2);

int main()
{
	circle C1;
	circle* pC1 = &C1;
	circle C2;
	circle* pC2 = &C2;

	cout << "ù ��° �� x, y, r : ";
	cin >> C1.x >> C1.y >> C1.r;

	cout << "�� ��° �� x, y, r : ";
	cin >> C2.x >> C2.y >> C2.r;

	switch (overlap(pC1, pC2))
	{
	case 0:
		cout << "�� ���� ��ġ�� �ʽ��ϴ�.";
		break;
	case 1:
		cout << "�� ��° ���� ù ��° ���� ���ο� �ֽ��ϴ�.";
		break;
	case 2:
		cout << "ù ��° ���� �� ��° ���� ���ο� �ֽ��ϴ�.";
		break;
	case 3:
		cout << "�� ���� ��Ĩ�ϴ�.";
		break;
	case 4:
		cout << "�� ���� �����ϴ�.";
		break;
	case 5:
		cout << "�� ���� �����մϴ�.";
		break;
	case 6:
		cout << "�� ���� �����մϴ�.";
		break;
	default:
		break;
	}
}

int overlap(circle* c1, circle* c2)
{
	double distance = sqrt(pow(c1->x - c2->x, 2) + pow(c1->y - c2->y, 2));

	circle* temp;
	int n = 1;

	if (c1->r < c2->r)
	{
		temp = c1;
		c1 = c2;
		c2 = temp;
		n = 2;
	}

	if (distance < c1->r - c2->r) return n;
	else if (distance > c1->r + c2->r && distance > c1->r - c2->r) return 0;
	else if (distance == 0 && c1->r == c2->r) return 4;
	else if (distance == c1->r + c2->r) return 5;
	else if (distance == c1->r - c2->r) return 6;

	return 3;
}