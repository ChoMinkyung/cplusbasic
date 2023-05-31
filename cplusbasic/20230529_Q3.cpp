#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int line = 2 * n - 1;

	for (int i = 1; i < n + 1; i++)
	{
		int number = n;
		for (int j = 1; j < line + 1; j++)
		{
			if (number <= i)
			{
				cout.width(3);
				cout << number;
			}
			else cout << "   ";

			if (j < line / 2.0) number--;
			else number++;
		}
		cout << endl;
	}
}