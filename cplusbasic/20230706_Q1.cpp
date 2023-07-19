#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int arr[] = { 5, 7, 0, 2, 4, 10, 3, 1, 3 };
	int size = sizeof(arr) / sizeof(int);
	int max = arr[0];

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 1; i < size; i++)
	{
		if (max < arr[i]) max = arr[i];
	}

	vector<int> counting(max + 1, 0);

	for (int i = 0; i < size; i++)
	{
		counting[arr[i]]++;
		
	}

	int n = 0;
	for (int i = 0; i < size; i++)
	{
		if (counting[n]-- > 0)
		{
			arr[i] = n;

		}
		else
		{
			n++;
			i--;
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

}