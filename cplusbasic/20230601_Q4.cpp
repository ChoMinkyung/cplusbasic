#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

void Q4_1()
{
	int* data = new int[30];
	int search;
	bool find = false;
	cout << "데이터 입력 : ";
	int i = 0;
	while (cin.peek() != '\n')
	{
		cin >> data[i];
		i++;
	}
	cout << "검색 데이터 : ";
	cin >> search;

	for (int k = -1; k < i; k++)
	{
		if (k < 0) cout << "   | ";
		else cout << k << "  ";
	}
	cout << endl;

	for (int k = -1; k < i; k++)
	{
		cout << "---";

	}
	cout << endl;

	for (int j = 0; j < i; j++)
	{
		cout << "   | ";
		for (int k = 0; k < i; k++)
		{
			if (j == k) cout << "* ";
			else cout << "   ";
		}
		cout << endl;
		cout << j << "  | ";
		for (int k = 0; k < i; k++)
		{
			cout << data[k] << "  ";
		}
		if (data[j] == search)
		{
			find = true;
			break;
		}
		cout << endl;
	}

	cout << endl << endl << "자료중에 " << search;
	if (find) cout << "이/가 있습니다." << endl;
	else cout << "이/가 없습니다." << endl;

	delete[] data;
}

void Q4_2()
{

	int* data = new int[30];
	int search;
	bool find = false;
	cout << "데이터 입력 : ";
	int i = 0;
	while (cin.peek() != '\n')
	{
		cin >> data[i];
		i++;
	}
	cout << "검색 데이터 : ";
	cin >> search;
	data[i] = search;
	i++;
	for (int k = -1; k < i; k++)
	{
		if (k < 0) cout << "   | ";
		else cout << k << "  ";
	}
	cout << endl;
	for (int k = -1; k < i; k++)
	{
		cout << "---";

	}
	cout << endl;

	int j = 0;
	while (1)
	{
		cout << "   | ";
		for (int k = 0; k < i; k++)
		{
			if (j == k) cout << "* ";
			else cout << "   ";
		}
		cout << endl;
		cout << j << "  | ";
		for (int k = 0; k < i; k++)
		{
			cout << data[k] << "  ";
		}
		if (data[j] == search)
		{
			find = true;
			break;
		}
		cout << endl;
		j++;
	}

	cout << endl << endl << "자료중에 " << search;
	if (find && j!=i-1) cout << "이/가 있습니다." << endl;
	else cout << "이/가 없습니다." << endl;

	delete[] data;
}


int main()
{
	Q4_1();
	cout << endl;
	cin.ignore();
	Q4_2();

}