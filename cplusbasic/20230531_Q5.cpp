#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

void one()
{
	int PNary[500];
	int n = 0, count = 0;
	for (int i = 2; i <= 1000; i++)
	{
		int prime_number = 1;
		for (int j = 2; j < i; j++)
		{
			count++;
			if (i % j == 0)
			{
				prime_number = 0;
				break;
			}
		}

		if (prime_number == 1)
		{
			PNary[n] = i;
			n++;
		}
	}

	cout << count;
}

void two()
{
	int PNary[500];
	PNary[0] = 2;
	int n = 1, count = 0;
	for (int i = 3; i <= 1000; i += 2)
	{
		int prime_number = 1;
		for (int j = 3; j < i; j+=2)
		{
			count++;
			if (i % j == 0)
			{
				prime_number = 0;
				break;
			}
		}

		if (prime_number == 1)
		{
			PNary[n] = i;
			n++;
		}
	}
	cout << count;
}

void three()
{
	int PNary[500];
	PNary[0] = 2;
	int n = 1, count = 0;
	for (int i = 3; i <= 1000; i += 2)
	{
		int prime_number = 1;
		for (int j = 1; j < n; j++)
		{
			count++;
			if (i % PNary[j] == 0)
			{
				prime_number = 0;
				break;
			}
		}

		if (prime_number == 1)
		{
			PNary[n] = i;
			n++;
		}
	}
	cout << count;
}

void four()
{
	int PNary[500];
	PNary[0] = 2;
	int n = 1, count = 0;
	for (int i = 3; i <= 1000; i += 2)
	{
		int prime_number = 1;
		int PNsqrt = sqrt(i);
		int j = 0;
		while (PNary[j] <= PNsqrt)
		{
			count++;
			if (i % PNary[j] == 0)
			{
				prime_number = 0;
				break;
			}
			j++;
		}

		if (prime_number == 1)
		{
			PNary[n] = i;
			n++;
		}
	}
	cout << count;
}

int main()
{
	//1번
	cout << "1. 1씩 증가하면서 소수 판단 : ";
	one();
	cout << endl;

	//2번
	cout << "2. 홀수만 소수 판단 : ";
	two();
	cout << endl;

	//3번
	cout << "3. 이전 계산된 소수로 소수 판단 : ";
	three();
	cout << endl;

	//4번
	cout << "4. 제곱근 n 이하의 소수로 소수 판단 : ";
	four();
	cout << endl;

}