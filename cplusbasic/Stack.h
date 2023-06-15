#pragma once
class Stack
{
private:
	int max;
	int prt;
	double* stk;
public:
	Stack();
	Stack(int max);
	~Stack();

	int getStk(int idx);
	
	int getPtr();

	void PlusSize(int n);

	/* ���ÿ� ������ Ǫ�� */
	int Push(double x);

	/* ���ÿ� �����͸� �� */
	int Pop(double* x);

	/* ���ÿ��� �����͸� ��ũ */
	int Peek(double* x);

	/* ���� ���� */
	void Clear();

	/* ������ �ִ� �뷮 */
	int Capacity();

	/* ������ ������ ���� */
	int Size();

	/* ������ ��� �ֳ��� ? */
	int IsEmpty();

	/* ������ ���� á���� ? */
	int IsFull();

	/* ���ÿ��� �˻� */
	int Search(double x);

	/* ��� ������ ��� */
	void Print();

	double Print(int i);

	/* ���� ���� */
	void Terminate();

};

