#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int n;

	cout << "n을 입력하세요 : ";
	cin >> n;

	for (int i = 0; i <= n; i++)
	{
		int l = 0;
		int count = 0;
		for (int j = 0; j < 2 * n + 1; j++)
		{

			if (i + j >= n && count < 2 * i + 1)
			{
				
				cout << setw(3)<< pow(2, l);
				count++;
				if (j >= n) l--;
				else l++;
			}
			else cout << "   ";

		}
		cout << endl;
	}
}