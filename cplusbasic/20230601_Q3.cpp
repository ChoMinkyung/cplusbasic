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
		cout << "menu�� �Է��ϼ��� (1=���ϱ�, 2=����, 0=����): ";
		cin >> menu;
		switch (menu)
		{
		case 0:
			cout << "���α׷��� �����մϴ�." << endl;
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

		cout << "x, y�� �Է��ϼ��� : ";
		cin >> x >> y;
		double q = calculate(x, y, func);
		cout << "���=" << q << endl;

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