#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;



int main()
{
	int size;
	cout << "퀸의 개수를 입력하세요 : ";
	cin >> size;

	int* queen_loc = new int[sizeof(int) * size];

	for (int i = 0; i < size; i++)
	{
		queen_loc[i] = -1;
	}





}

void Queen(int* queen)
{
	int size = sizeof(queen) / sizeof(int);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{

			queen[i] = j;

		}
	}
}

bool IsSameLine(int* queen, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		if (queen[i] == col) return true; //같은 라인일때
	}

	return false; // 좌우 겹치지 않음
}

bool IsSameDiagonal(int* queen, int row, int col)
{
	int size = sizeof(queen) / sizeof(int);

	int copy_row = row;
	int copy_col = col;

	while (1)
	{
		if (copy_row < 3) copy_row++;
		else if (copy_row > 0) copy_row--;

		if (copy_col < 3) copy_col++;
		else if (copy_col > 0) copy_col--;
	}


}