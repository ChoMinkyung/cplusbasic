#pragma once
class Stack
{
private:
	int max;
	int prt;
	int* stk;
public:
	Stack();
	Stack(int max);
	~Stack();

	int getStk(int idx);
	
	int getPtr();

	void PlusSize(int n);

	/* ���ÿ� ������ Ǫ�� */
	int Push(int x);

	/* ���ÿ� �����͸� �� */
	int Pop(int* x);

	/* ���ÿ��� �����͸� ��ũ */
	int Peek(int* x);

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
	int Search(int x);

	/* ��� ������ ��� */
	void Print();

	/* ���� ���� */
	void Terminate();
};

