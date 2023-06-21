#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

#include "Stack.h"
#include "20230619_Q1_StopWatch.h"

/*

	Q2. 하노이의 탑
	- 한 번에 움직일 수 있는 원반은 기둥 위에 놓인 원반 하나뿐이다.
	- 어떤 원반 위에 그보다 더 큰 원반을 쌓을 수 없다.

*/

int repeat_count = 0;

void TowerOfHanoi(int n, int x, int y, Stack ** pTop);
void Print(Stack* top);

int main()
{
	StopWatch sw;

	int len;
	cout << "원반 최대 크기를 입력하세요 : ";
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

	cout << endl << "원반 최대 크기 : " << len << endl;
	cout << "횟수 : " << repeat_count << "번" << endl;
	cout << endl << "소요 시간 : " << (double)(sw.getEnd() - sw.getStart()) / CLOCKS_PER_SEC << "s" << endl;
	cout << "소요 시간 : " << sw.getElapsedTime() << "ms" << endl << endl;

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

	//cout << repeat_count << "번째" << endl;
	//Print(*pTop);

	if (n > 1)
		TowerOfHanoi(n - 1, 6 - x - y, y, pTop);
}

void Print(Stack* top)
{
	//프린트
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