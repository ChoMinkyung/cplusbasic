#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	double x1, y1, x2, y2;

	cout << "(x1, y1)�� �Է��ϼ��� : ";
	cin >> x1 >> y1;
	cout << "(x2, y2)�� �Է��ϼ��� : ";
	cin >> x2 >> y2;
	double len = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

	cout << "�� �� ������ �Ÿ��� " << len << "�Դϴ�." << endl;
}