#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	double v,a;

	cout << "Speed and Accelation : ";
	cin >> v >> a;

	cout << "Minimum runaway length : " << v * v / (2 * a);
}