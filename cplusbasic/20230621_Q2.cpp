#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <new>
#include <iomanip>

using namespace std;

#include "20230619_Q1_StopWatch.h"


void SelectionSort1(int len, int* arr);
void SelectionSort2(int len, int* arr);
void BubbleSortVersion(int* arr, int size);

void Print(int unsort, int min, int* arr, int len);

int main()
{
	StopWatch sw;

	double n = 10000000;

	cout << fixed << setprecision(0) << n << "번 반복했을 때" << endl;
	cout << fixed << setprecision(6);

	int arr[] = { 6, 4, 8, 3, 1, 9, 7 };
	int len = sizeof(arr) / sizeof(int);

	cout << endl << "[정렬 전] : ";
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl << endl;
	int* temp = new int(sizeof(int) * len);

	cout << "선택 정렬 1" << endl;
	sw.start();
	for (double k = 0; k < n; k++)
	{
		for (int i = 0; i < len; i++)
		{
			temp[i] = arr[i];
		}
		SelectionSort1(len, temp);
	}
	sw.stop();
	cout << "소요 시간 : " << (double)(sw.getEnd() - sw.getStart()) / CLOCKS_PER_SEC << "s" << endl;
	cout << "소요 시간 : " << sw.getElapsedTime() << "ms" << endl << endl;


	cout << "선택 정렬 2" << endl;
	sw.start();
	for (double k = 0; k < n; k++)
	{
		for (int i = 0; i < len; i++)
		{
			temp[i] = arr[i];
		}
		SelectionSort2(len, temp);
	}
	sw.stop();

	cout << "소요 시간 : " << (double)(sw.getEnd() - sw.getStart()) / CLOCKS_PER_SEC << "s" << endl;
	cout << "소요 시간 : " << sw.getElapsedTime() << "ms" << endl << endl;

	cout << "버블 정렬" << endl;


	sw.start();
	for (double k = 0; k < n; k++)
	{
		for (int i = 0; i < len; i++)
		{
			temp[i] = arr[i];
		}
		BubbleSortVersion(temp, len);
	}
	sw.stop();

	cout << "소요 시간 : " << (double)(sw.getEnd() - sw.getStart()) / CLOCKS_PER_SEC << "s" << endl;
	cout << "소요 시간 : " << sw.getElapsedTime() << "ms" << endl << endl;
}

void Print(int unsort, int min, int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (unsort == i) cout << "* ";
		else if (i == min) cout << "+ ";
		else cout << "  ";
	}
	cout << endl;

	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
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
		}
		//Print(i, min, arr, len);
		swap(arr[i], arr[min]);
	}
}

void SelectionSort2(int len, int* arr)
{
	for (int i = 0; i < len; i++)
	{
		int min = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
				swap(arr[i], arr[min]);
				//Print(i, min, arr, len);
			}
		}
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
				loc = i;
			}
		}

		if (loc > range) range = loc;
		else if (loc == range) break;

	}
}