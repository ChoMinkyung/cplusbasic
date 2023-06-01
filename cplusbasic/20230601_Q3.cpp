#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


double add(double x, double y);
double sub(double x, double y);

double calculate(double x, double y, double (*func)(double, double));


int main()
{
	double (*func)(double, double) = NULL;
	double x, y;
	int menu = 100;
	while (1)
	{
		cout << "menu를 입력하세요 (1=더하기, 2=뺴기, 0=종료): ";
		cin >> menu;
		switch (menu)
		{
		case 0:
			cout << "프로그램을 종료합니다." << endl;
			exit(1);
		case 1:
			func = add;
			break;
		case 2:
			func = sub;
			break;
		default:
			break;
		}

		cout << "x, y를 입력하세요 : ";
		cin >> x >> y;
		double q = calculate(x, y, func);
		cout << "결과=" << q << endl;

	}

}

double calculate(double x, double y, double(*func)(double, double))
{
	return func(x, y);
}

double add(double x, double y)
{
	return x + y;
}

double sub(double x, double y)
{
	return x - y;
}