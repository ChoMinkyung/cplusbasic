#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

/*
	p.42 연습문제 18 응용
	n단의 숫자 모래시계를 출력하는 프로그램을 작성

	예)

*/

int main()
{
	int n;
	cin >> n;

	int line = 1 + (n - 1) * 2;
	int number = 1;
	int count = line;

	for (int i = 1; i < line + 1; i++)
	{
		for (int j = 0; j < number - 1; j++)
		{
			cout << " ";
		}

		for (int k = 0; k < count; k++)
		{
			cout << number;

		}

		if (i < n)
		{
			number++;
			count -= 2;
		}
		else
		{
			number--;
			count += 2;
		}
		cout << endl;
	}
}