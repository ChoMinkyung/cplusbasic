#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

int plusItem(int count, int* item, int* per, int index);
int perSum(int n, int* per, int index);

int main()
{
	int random;
	int item[11] = { 0 };
	int sum = 0;
	int per[11] = { 1, 3, 3, 5, 5, 5, 10, 10, 10, 10, 38 };
	srand(time(0));

	int n;
	cout << "È½¼ö ? ";
	cin >> n;

	int count = 0;
	while (count < n)
	{
		random = rand() % n;

		if (random < perSum(n, per, 0) && item[0] < per[0] * n / 100) 
			count = plusItem(count, item, per, 0);
		else if (random >= perSum(n,per, 0) && random < perSum(n, per, 1) && item[1] < per[1] * n / 100) 
			count = plusItem(count, item, per, 1);
		else if (random >= perSum(n,per, 1) && random < perSum(n, per, 2) && item[2] < per[2] * n / 100)
			count = plusItem(count, item, per, 2);
		else if (random >= perSum(n,per, 2) && random < perSum(n, per, 3) && item[3] < per[3] * n / 100)
			count = plusItem(count, item, per, 3);
		else if (random >= perSum(n, per, 3) && random < perSum(n, per, 4) && item[4] < per[4] * n / 100)
			count = plusItem(count, item, per, 4);
		else if (random >= perSum(n, per, 4) && random < perSum(n, per, 5) && item[5] < per[5] * n / 100)
			count = plusItem(count, item, per, 5);
		else if (random >= perSum(n, per, 5) && random < perSum(n, per, 6) && item[6] < per[6] * n / 100)
			count = plusItem(count, item, per, 6);
		else if (random >= perSum(n, per, 6) && random < perSum(n, per, 7) && item[7] < per[7] * n / 100)
			count = plusItem(count, item, per, 7);
		else if (random >= perSum(n, per, 7) && random < perSum(n, per, 8) && item[8] < per[8] * n / 100)
			count = plusItem(count, item, per, 8);
		else if (random >= perSum(n, per, 8) && random < perSum(n, per, 9) && item[9] < per[9] * n / 100)
			count = plusItem(count, item, per, 9);
		else if (random >= perSum(n, per, 9) && random < perSum(n, per, 10) && item[10] < per[10] * n / 100)
			count = plusItem(count, item, per, 10);

	}

	for (int i = 0; i < 11; i++)
	{
		cout << (char)('A' + i) << " : " << item[i] << "  ";
		if (i == 5) cout << endl;
	}

	cout << endl;
}

int plusItem(int count, int* item, int* per, int index)
{
	item[index] += 1;
	return ++count;
}

int perSum(int n, int* per, int index)
{
	int sum = 0;
	for (int i = 0; i <= index;i++)
	{
		sum += per[i] * n / 100;
	}

	return sum;
}