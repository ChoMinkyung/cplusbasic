#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	double x1, y1, x2, y2, x3, y3;

	cout << "(x1, y1)�� �Է��ϼ��� : ";
	cin >> x1 >>  y1;

	cout << "(x2, y2)�� �Է��ϼ��� : ";
	cin >> x2 >> y2;

	cout << "(x3, y3)�� �Է��ϼ��� : ";
	cin >> x3 >> y3;


	double s = abs((x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3)) / 2;
	
	cout << "�ﰢ���� ���� : " << s << endl;
}