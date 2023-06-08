#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
	int coin;
	double front = 0, back = 0;
	srand(time(0));
	for (int i = 1; i <= 1000000; i++)
	{
		coin = rand() % 2;
		if (coin == 0) front++;
		else back++;

		cout.precision(4);
		cout << i << "번째 앞면 : " << (front / i)* 100 << "% 뒷면 : " << (back / i) * 100 << "%" << endl;
	}
}