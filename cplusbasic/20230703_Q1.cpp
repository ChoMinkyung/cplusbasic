#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

/* heap sort */
void HeapSort(int* arr, int size);
void Print(int* arr, int size);

int main()
{
	int arr[] = { 6,4,8,3,1,9,7 };
	int size = sizeof(arr) / sizeof(int);

	HeapSort(arr, size);
	
	Print(arr, size);

	
}

void HeapSort(int* arr, int size)
{
	// 부모 : i  왼쪽 i * 2 + 1  오른쪽 i * 2 + 2
	int i = 0;
	size--;

	while (size > 0)
	{
		for(int i=size; i>=0; i--)
		{
			if (i * 2 + 1 > size) continue;
			
			int temp = i * 2 + 1;

			if(i * 2 + 2 < size) arr[temp] < arr[i * 2 + 2] ? temp = i * 2 + 2 : temp;

			if (arr[i] < arr[temp]) swap(arr[i], arr[temp]);
		}

		swap(arr[size], arr[0]);
		size--;
	}
}

void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}