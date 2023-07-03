#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <new>
#include <iomanip>

using namespace std;

#include "20230619_Q1_StopWatch.h"

int n_swap = 0, n_compare = 0;

void SelectionSort1(int len, int* arr);
void SelectionSort2(int len, int* arr);
void BubbleSortVersion(int* arr, int size);
void QuickSort(int* arr, int left, int right);
void HeapSort(int* arr, int size);

void Print(int* arr, int len);

int main()
{
	StopWatch sw;

	double n = 10000000;

	cout << fixed << setprecision(0) << n << "번 반복했을 때" << endl;
	cout << fixed << setprecision(6);

	int arr[] = { 3,1,7,9,2,6,5,8,4, 0 };//{ 6, 4, 8, 3, 1, 9, 7 };
	int len = sizeof(arr) / sizeof(int);

	int* temp = new int(sizeof(int) * len);

	cout << endl << "[정렬 전] : ";
	Print(arr, len);

	cout << endl << endl;

	cout << "선택 정렬" << endl;
	sw.start();
	for (double k = 0; k < n; k++)
	{
		n_swap = 0, n_compare = 0;
		for (int i = 0; i < len; i++)
		{
			temp[i] = arr[i];
		}
		SelectionSort1(len, temp);
	}
	sw.stop();
	cout << endl << "[정렬 후] : ";
	Print(temp, len);

	cout << "비교 횟수 : " << n_compare << " 교환 횟수 : " << n_swap << endl;
	cout << "소요 시간 : " << (double)(sw.getEnd() - sw.getStart()) / CLOCKS_PER_SEC << "s" << endl;
	cout << "소요 시간 : " << sw.getElapsedTime() << "ms" << endl << endl;

	cout << "버블 정렬" << endl;
	sw.start();
	for (double k = 0; k < n; k++)
	{
		n_swap = 0, n_compare = 0;
		for (int i = 0; i < len; i++)
		{
			temp[i] = arr[i];
		}
		BubbleSortVersion(temp, len);
	}
	sw.stop();
	cout << endl << "[정렬 후] : ";
	Print(temp, len);
	cout << "비교 횟수 : " << n_compare << " 교환 횟수 : " << n_swap << endl;
	cout << "소요 시간 : " << (double)(sw.getEnd() - sw.getStart()) / CLOCKS_PER_SEC << "s" << endl;
	cout << "소요 시간 : " << sw.getElapsedTime() << "ms" << endl << endl;

	cout << "퀵 정렬" << endl;
	sw.start();
	for (double k = 0; k < n; k++)
	{
		n_swap = 0, n_compare = 0;
		for (int i = 0; i < len; i++)
		{
			temp[i] = arr[i];
		}
		QuickSort(temp, 0, len - 1);
	}
	sw.stop();
	cout << endl << "[정렬 후] : ";
	Print(temp, len);
	cout << "비교 횟수 : " << n_compare << " 교환 횟수 : " << n_swap << endl;
	cout << "소요 시간 : " << (double)(sw.getEnd() - sw.getStart()) / CLOCKS_PER_SEC << "s" << endl;
	cout << "소요 시간 : " << sw.getElapsedTime() << "ms" << endl << endl;

	cout << "힙 정렬" << endl;
	sw.start();
	for (double k = 0; k < n; k++)
	{
		n_swap = 0, n_compare = 0;
		for (int i = 0; i < len; i++)
		{
			temp[i] = arr[i];
		}
		HeapSort(temp, len);
	}
	sw.stop();
	cout << endl << "[정렬 후] : ";
	Print(temp, len);
	cout << "비교 횟수 : " << n_compare << " 교환 횟수 : " << n_swap << endl;
	cout << "소요 시간 : " << (double)(sw.getEnd() - sw.getStart()) / CLOCKS_PER_SEC << "s" << endl;
	cout << "소요 시간 : " << sw.getElapsedTime() << "ms" << endl << endl;
}

void SelectionSort1(int len, int* arr)
{
	for (int i = 0; i < len; i++)
	{
		int min = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
			n_compare++;
		}
		//Print(i, min, arr, len);
		swap(arr[i], arr[min]);
		n_swap++;
	}
}

void BubbleSortVersion(int* arr, int size)
{
	int loc = -100;
	int range = 0;
	while (1)
	{
		for (int i = size - 1; i > range; i--)
		{
			if (arr[i] < arr[i - 1])
			{
				swap(arr[i], arr[i - 1]);
				n_swap++;
				loc = i;
			}
			n_compare++;
		}

		if (loc > range) range = loc;
		else if (loc == range) break;

	}
}

void QuickSort(int* arr, int left, int right)
{
	if (left >= right) {
		return;
	}

	int pivot = left;
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		n_compare++;
		while (low <= right && arr[low] <= arr[pivot])
		{
			low++;
		}

		n_compare++;
		while (high >= left + 1 && arr[high] >= arr[pivot])
		{
			high--;
		}

		n_compare++;
		if (low <= high)
		{
			swap(arr[low], arr[high]);
			n_swap++;
		}
	}

	swap(arr[pivot], arr[high]);
	n_swap++;

	QuickSort(arr, left, high - 1);
	QuickSort(arr, high + 1, right);
}

void HeapSort(int* arr, int size)
{
	// 부모 : i  왼쪽 i * 2 + 1  오른쪽 i * 2 + 2
	int i = 0;
	size--;

	while (size > 0)
	{
		for (int i = size; i >= 0; i--)
		{
			if (i * 2 + 1 > size) continue;

			int temp = i * 2 + 1;

			n_compare++;
			if (i * 2 + 2 < size) arr[temp] < arr[i * 2 + 2] ? temp = i * 2 + 2 : temp;

			n_compare++;
			if (arr[i] < arr[temp])
			{
				swap(arr[i], arr[temp]);
				n_swap++;
			}
		}

		swap(arr[size], arr[0]);
		n_swap++;
		size--;
	}
	return;
}

void Print(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}