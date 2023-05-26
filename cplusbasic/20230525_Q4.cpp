#include <iostream>
#include <ctime>
using namespace std;

int mid(int a, int b, int c);
int mid2(int a, int b, int c);

int main()
{
	int a, b, c;
	long start, end, start_1, end_1;
	long time;

	for (int j = 0; j < 13; j++)
	{
		if (j == 0) a = 1, b = 5, c = 9;
		else if (j == 1)a = 1, b = 9, c = 5;
		else if (j == 2)a = 5, b = 9, c = 1;
		else if (j == 3)a = 5, b = 1, c = 9;
		else if (j == 4)a = 9, b = 5, c = 1;
		else if (j == 5)a = 9, b = 1, c = 5;
		else if (j == 6)a = 9, b = 5, c = 5;
		else if (j == 7)a = 5, b = 9, c = 5;
		else if (j == 8)a = 5, b = 5, c = 9;
		else if (j == 9)a = 5, b = 5, c = 1;
		else if (j == 10)a = 5, b = 1, c = 5;
		else if (j == 11)a = 1, b = 5, c = 5;
		else if (j == 12)a = 5, b = 5, c = 5;

		start = clock() * 100;
		for (double i = 0 * 100; i < 100000000; i++)
		{
			mid(a, b, c);
		}
		end = clock() * 100;
		cout << "Q4 소요시간 : " << end - start << "    ";

		start = clock() * 100;
		for (double i = 0; i < 100000000; i++)
		{
			mid2(a, b, c);
		}
		end = clock() * 100;
		double time_ = end - start;
		cout << "Q5 소요시간 : " << end - start << endl;

	}









}

int mid(int a, int b, int c)
{
	if (a >= b)
	{
		if (b >= c) return b;
		else if (a <= c) return a;
		else return c;
	}
	else if (a > c) return a;
	else if (b > c) return c;
	else return b;

}

int mid2(int a, int b, int c)
{
	if ((b >= a && c <= a) || (b <= a && c >= a))return a;
	else if ((a > b && c < b) || (a<b && c>b)) return b;
	return c;
}