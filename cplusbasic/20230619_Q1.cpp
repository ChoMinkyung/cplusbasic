#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

#include "Stack.h"
#include "20230619_Q1_StopWatch.h"

/*

	Q2. �ϳ����� ž
	- �� ���� ������ �� �ִ� ������ ��� ���� ���� ���� �ϳ����̴�.
	- � ���� ���� �׺��� �� ū ������ ���� �� ����.

*/

int repeat_count = 0;

void TowerOfHanoi(int n, int x, int y, Stack ** pTop);
void Print(Stack* top);

int main()
{
	StopWatch sw;

	int len;
	cout << "���� �ִ� ũ�⸦ �Է��ϼ��� : ";
	cin >> len;

	Stack* top = new Stack[3];
	top[0] = Stack(len);
	top[1] = Stack(len);
	top[2] = Stack(len);

	Stack** pTop = new Stack * [3];
	pTop[0] = &top[0];
	pTop[1] = &top[1];
	pTop[2] = &top[2];

	for (int i = len; i > 0; i--)
	{
		top[0].Push(i);
	}

	Print(top);

	sw.start();

	TowerOfHanoi(len, 1, 3, pTop);

	sw.stop();

	cout << endl << "���� �ִ� ũ�� : " << len << endl;
	cout << "Ƚ�� : " << repeat_count << "��" << endl;
	cout << endl << "�ҿ� �ð� : " << (double)(sw.getEnd() - sw.getStart()) / CLOCKS_PER_SEC << "s" << endl;
	cout << "�ҿ� �ð� : " << sw.getElapsedTime() << "ms" << endl << endl;

	Print(top);

}


void TowerOfHanoi(int n, int x, int y, Stack** pTop)
{

	double move_n;
	if (n > 1)
		TowerOfHanoi(n - 1, x, 6 - x - y, pTop);
		

	pTop[x-1]->Pop(&move_n);
	pTop[y-1]->Push(move_n);
	repeat_count++;

	//cout << repeat_count << "��°" << endl;
	//Print(*pTop);

	if (n > 1)
		TowerOfHanoi(n - 1, 6 - x - y, y, pTop);
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