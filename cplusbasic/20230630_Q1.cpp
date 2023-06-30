#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/* merge sort */

int main()
{
	int arr[10] = { 4, 1, 9, 6, 3, 0, 2, 8, 5, 7 };
	int arr_copy[10];
}

void MergeSort(int * arr, int left, int right)
{
	if (right / 2 > 0)
	{
		MergeSort(arr, left, right / 2);

		MergeSort(arr, right / 2 + 1, left);


	}

	return;
}