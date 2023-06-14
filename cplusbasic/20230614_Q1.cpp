#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#include "20230614_Q1_Rectangle2D.h"

int main()
{
	Rectangle2D r1(2, 2, 5.5, 4.9);
	Rectangle2D r2(4, 5, 10.5, 3.2);
	Rectangle2D r3(3, 5, 2.3, 5.2);

	cout << "r1�� �߽� : (" << r1.getX() << ", " << r1.getY() << ") r1�� width, height : " << r1.getWidth() << ", " << r1.getHeight() << endl;
	cout << "r1�� ������ �ѷ� : " << r1.getArea() << ", " << r1.getPerimeter() << endl;

	cout << endl;

	cout << "r2�� r1�� ����";
	if (r1.contains(r2)) cout << "�˴ϴ�." << endl;
	else cout << "���� �ʽ��ϴ�." << endl;

	cout << "r3�� r1�� ";
	if (r1.overlaps(r3)) cout << "��Ĩ�ϴ�." << endl;
	else cout << "��ġ�� �ʽ��ϴ�." << endl;
}