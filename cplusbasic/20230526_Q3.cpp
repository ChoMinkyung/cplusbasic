#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

int sumof(int a, int b);

int main()
{
	int a, b;

	cin >> a >> b;

	if (a > b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	cout << sumof(a, b) << endl;

}

int sumof(int a, int b)
{
	return (1 + b) * b / 2 - a * (a - 1) / 2;
}