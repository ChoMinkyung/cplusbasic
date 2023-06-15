#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

#include "Stack.h"

/*

	Q2. �ϳ����� ž
	- �� ���� ������ �� �ִ� ������ ��� ���� ���� ���� �ϳ����̴�.
	- � ���� ���� �׺��� �� ū ������ ���� �� ����.

*/

int repeat_count = 0;

void TowerOfHanoi(bool number_1, int loc_1, Stack** st);
void Print(Stack* top);

int main()
{
	int len;
	cout << "���� �ִ� ũ�⸦ �Է��ϼ��� : ";
	cin >> len;

	Stack* top = new Stack[3];
	top[0] = Stack(len);
	top[1] = Stack(len);
	top[2] = Stack(len);

	Stack** pTop = new Stack * [3];
	pTop[0] = &top[0];
	
	if (len % 2 == 0)
	{
		pTop[1] = &top[1];
		pTop[2] = &top[2];
	}
	else
	{
		pTop[1] = &top[2];
		pTop[2] = &top[1];
	}

	// �ʱ�ȭ
	for (int i = len; i > 0; i--)
	{
		top[0].Push(i);
	}

	cout << "����" << endl;
	Print(top);

	TowerOfHanoi(true, 1, pTop);

	cout << endl<< "����" << endl;

}


void TowerOfHanoi(bool number_1, int loc_1, Stack** st)
{
	repeat_count++;
	cout << endl << repeat_count << "��°" << endl;

	double x = 0;
	// 1�� ã�´�.
	if (number_1)
	{
		st[loc_1 > 0 ? loc_1-1 : 2]->Pop(&x);
		st[loc_1]->Push(x);
		loc_1 < 2 ? loc_1++ : loc_1 = 0;
	}
	else
	{
		double min = 100;
		int loc = 0;
		double temp = 0;
		for (int i = 0; i < 3; i++)
		{
			st[i]->Peek(&x);
			if (x != 1 && x < min && !st[i]->IsEmpty())
			{
				loc = i;
				min = x;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			st[i]->Peek(&temp);
			if (temp > min || st[i]->IsEmpty())	st[i]->Push(min);
			
		}
		st[loc]->Pop(&x);
	}

	Print(*st);

	number_1 = number_1 ? false : true;

	if (!st[1]->IsFull() && !st[2]->IsFull()) TowerOfHanoi(number_1, loc_1, st);

}

void Print(Stack* top)
{
	//����Ʈ
	for (int i = top[0].Capacity() - 1; i >= 0; i--)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "[";
			if (!top[j].IsEmpty() && top[j].Size() > i)  cout << top[j].Print(i);
			else  cout << " ";
			cout << "] ";

		}
		cout << endl;
	}
	cout << " A   B   C";
	cout << endl;
}