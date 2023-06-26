#include <iostream>
using namespace std;

void Print(int* arr, int size, int insert_loc, int loc);
void Move(int* arr, int size, int insert_loc, int loc);

int main()
{
	int arr[] = { 6, 4, 8, 5, 2, 9, 7 };
	//int arr[] = { 1, 4, 6, 7, 3, 9, 8 };

	int size = sizeof(arr) / sizeof(int);

	for (int i = 0; i < size - 1; i++)
	{
		int insert_loc = 0;
		if (arr[i] > arr[i + 1])
		{
			for (int j = i; j >= 0; j--)
			{
				if (arr[j] > arr[i + 1]) insert_loc = j;
				else break;
			}

			Print(arr, size, insert_loc, i + 1);
			Move(arr, size, insert_loc, i + 1);
		}
		else Print(arr, size, -1, i + 1);
	}

	cout << endl << "Á¤·Ä ³¡ ";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Move(int* arr, int size, int insert_loc, int loc)
{
	int temp = arr[loc];
	for (int i = loc; i > insert_loc; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[insert_loc] = temp;
}

void Print(int* arr, int size, int insert_loc, int loc)
{

	for (int i = 0; i < size; i++)
	{
		cout << " " << arr[i] << " ";
	}
	cout << endl;

	if (insert_loc < 0)
	{
		for (int i = 0; i < size; i++)
		{
			if (i == loc)cout << " +";
			else cout << "   ";

		}
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (i < insert_loc) cout << "   ";
			else if (i == insert_loc) cout << "^---";
			else if (i > insert_loc && i < loc) cout << "---";
			else if (i == loc)cout << "+";
			else break;
		}

	}
	cout << endl;
}