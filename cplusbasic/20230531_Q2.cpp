#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	double x1, y1, x2, y2;

	cout << "(x1, y1)을 입력하세요 : ";
	cin >> x1 >> y1;
	cout << "(x2, y2)을 입력하세요 : ";
	cin >> x2 >> y2;
	double len = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

	cout << "두 점 사이의 거리는 " << len << "입니다." << endl;
}