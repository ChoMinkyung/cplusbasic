#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

void PrintS(int k);
void Print(int k);

int main()
{
	int k;
	cout << "홀수를 입력해주세요 : ";
	cin >> k;
	while (k % 2 == 0 || k > 99 || k < 3)
	{
		cout << "3<=k<=99인 홀수를 입력해주세요 : ";
		cin >> k;
	}

	PrintS(k);
	//cout << endl;
	//Print(k);

}

void PrintS(int k)
{
	int m = (k + 1) / 2 - 1;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (j >= (k + 1) / 2 -1)
			{
				int jj = j - (k + 1) / 2 + 1 ;
				if (jj< m) cout << "  ";
				else if (jj - m > 0 && jj - m < (k + 1) / 2 - m -1 ) cout << "+ ";
				else cout << "* ";
			}
			else cout << "  ";

		}
		if (i < k / 2) m--;
		else m++;
		cout << endl;
	}
}

void Print(int k)
{
	int m = (k + 1) / 2 - 1;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < (k + 1) / 2; j++)
		{
			if (j < m) cout << "  ";
			else if (j - m > 0 && j - m < (k + 1) / 2 - m - 1) cout << "+ ";
			else cout << "* ";
		}
		if (i < k / 2) m--;
		else m++;
		cout << endl;
	}
}