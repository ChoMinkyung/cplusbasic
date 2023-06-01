#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

void Q1()
{
	int n, base;
	int base_arr[10];

	cout << "값을 입력하시오 : ";
	cin >> n;
	cout << "몇 진수로 변환할까요? ";
	cin >> base;

	int i = 0;

	cout << "10진수 " << n << "은 " << base << "진수로 ";

	while (n >= base)
	{
		if (n % base > 9) base_arr[i] = n % base + 55;
		else base_arr[i] = n % base;
		n = n / base;

		i++;
	}

	if (n > 9) base_arr[i] = n + 55;
	else base_arr[i] = n;

	for (int j = i; j >= 0; j--)
	{
		if (base_arr[j] >= 65)
		{
			char ch = base_arr[j];
			cout << ch;
		}
		else cout << base_arr[j];
	}

	cout << "입니다." << endl;
}


int main()
{
	char input[10];
	int n = 0;
	int before_base, after_base;
	int before_base_arr[10];
	int after_base_arr[10];

	cout << "입력 데이터는 몇 진수입니까? : ";
	cin >> before_base;
	cout << "값을 입력하시오 : ";
	cin >> input;
	cout << "몇 진수로 변환할까요? ";
	cin >> after_base;

	for (int i = strlen(input)-1; i >= 0; i--)
	{
		if (input[i] >= 65) n += input[i] - 55;
		else n += (input[i] - '0') * before_base * i;
	}

	cout << n;
}