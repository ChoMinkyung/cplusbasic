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

	cout << "r1의 중심 : (" << r1.getX() << ", " << r1.getY() << ") r1의 width, height : " << r1.getWidth() << ", " << r1.getHeight() << endl;
	cout << "r1의 면적과 둘레 : " << r1.getArea() << ", " << r1.getPerimeter() << endl;

	cout << endl;

	cout << "r2는 r1에 포함";
	if (r1.contains(r2)) cout << "됩니다." << endl;
	else cout << "되지 않습니다." << endl;

	cout << "r3는 r1과 ";
	if (r1.overlaps(r3)) cout << "겹칩니다." << endl;
	else cout << "겹치지 않습니다." << endl;
}