#include "20230614_Q1_Rectangle2D.h"
#include "20230612_Q2_Circle2D.h"

#include <iostream>
using namespace std;

int main()
{
	MyPoint p1;
	MyPoint p2(10, 30.5);

	cout << "p1(" << p1.getX() << ", " << p1.getY() << ")" << endl;
	cout << "p2(" << p2.getX() << ", " << p2.getY() << ")" << endl;
	cout << "p1�� p2 ������ �Ÿ� : " << p1.Distane(p2) << endl;

	cout << endl;

	Circle2D c(2, 2, 5.5);
	Rectangle2D r(3, 5, 2.3, 5.2);

	cout << "p1�� c ���ο� ";
	if (contains(c, p1)) cout << "�ֽ��ϴ�." << endl;
	else cout << "�����ϴ�." << endl;

	cout << "p2�� c ���ο� ";
	if (contains(c, p2)) cout << "�ֽ��ϴ�." << endl;
	else cout << "�����ϴ�." << endl;

	cout << "p1�� r ���ο� ";
	if (contains(r, p1)) cout << "�ֽ��ϴ�." << endl;
	else cout << "�����ϴ�." << endl;

	cout << "p2�� r ���ο� ";
	if (contains(r, p2)) cout << "�ֽ��ϴ�." << endl;
	else cout << "�����ϴ�." << endl;
}