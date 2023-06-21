#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iomanip>
using namespace std;

#include "20230619_Q1_StopWatch.h"


void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
int compare = 0, change = 0;

void BubbleSortVersion1(int* arr, int size);
void BubbleSortVersion2(int* arr, int size);
void BubbleSortVersion3(int* arr, int size);

void Print(int* arr, int size);

int main()
{
	StopWatch sw;

	//int arr[] = { 4, 3, 1, 7, 5, 9, 2, 8, 6 };
	int arr[] = { 1,3,9,4,7,8,6 };

	int size = sizeof(arr) / sizeof(int);

	int* temp = new int[sizeof(int) * size];

	double n = 10000000;

	cout << fixed << setprecision(0) << n << "번 반복했을 때" << endl;
	cout << fixed << setprecision(6);


	cout << endl << "[정렬 전] : ";
	Print(arr, size);
	cout << endl;

	//버전 1 
	sw.start();

	for (double k = 0; k < n; k++)
	{
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		BubbleSortVersion1(temp, size);

	}

	sw.stop();

	cout << "버전 1" << endl;
	cout << "[정렬 후] : ";
	Print(temp, size);
	cout << "비교 횟수 : " << compare << endl;
	cout << "교환 횟수 : " << change << endl;
	cout << "소요 시간 : " << (double)(sw.getEnd() - sw.getStart()) / CLOCKS_PER_SEC << "s" << endl;
	cout << "소요 시간 : " << sw.getElapsedTime() << "ms" << endl << endl;


	//버전 2 : 교환 횟수
	sw.start();

	for (double k = 0; k < n; k++)
	{
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		BubbleSortVersion2(temp, size);

	}

	sw.stop();

	cout << "버전 2" << endl;
	cout << "[정렬 후] : ";
	Print(temp, size);
	cout << "비교 횟수 : " << compare << endl;
	cout << "교환 횟수 : " << change << endl;
	cout << "소요 시간 : " << (double)(sw.getEnd() - sw.getStart()) / CLOCKS_PER_SEC << "s" << endl;
	cout << "소요 시간 : " << sw.getElapsedTime() << "ms" << endl << endl;

	//Print(temp, size);

	// 버전 3 : 스캔 범위 제한

	sw.start();

	for (double k = 0; k < n; k++)
	{
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		BubbleSortVersion3(temp, size);

	}

	sw.stop();

	cout << "버전 3" << endl;
	cout << "[정렬 후] : ";
	Print(temp, size);
	cout << "비교 횟수 : " << compare << endl;
	cout << "교환 횟수 : " << change << endl;
	cout << "소요 시간 : " << (double)(sw.getEnd() - sw.getStart()) / CLOCKS_PER_SEC << "s" << endl;
	cout << "소요 시간 : " << sw.getElapsedTime() << "ms" << endl << endl;

	//Print(temp, size);

}

void BubbleSortVersion1(int* arr, int size)
{
	compare = 0, change = 0;

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			compare++;
			if (arr[j] < arr[j - 1])
			{
				swap(&arr[j], &arr[j - 1]);

				change++;
			}
		}

	}


}

void BubbleSortVersion2(int* arr, int size)
{
	compare = 0, change = 0;



	for (int i = 0; i < size - 1; i++)
	{
		int n_swap = 0;
		for (int j = size - 1; j > i; j--)
		{
			compare++;
			if (arr[j] < arr[j - 1])
			{
				swap(&arr[j], &arr[j - 1]);
				change++;
				n_swap++;
			}
		}
		if (n_swap == 0) break;
	}

}

void BubbleSortVersion3(int* arr, int size)
{
	compare = 0, change = 0;

	int loc = -100;
	int range = 0;
	while (1)
	{
		for (int i = size - 1; i > range; i--)
		{
			compare++;
			if (arr[i] < arr[i - 1])
			{
				swap(&arr[i], &arr[i - 1]);
				loc = i;
				change++;
			}
		}

		if (loc > range) range = loc;
		else if (loc == range) break;

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