#pragma once
class Queue
{
private:
	int max;
	int num;
	int front;
	int rear;
	double* que;
public:
	Queue();
	Queue(int max);
	~Queue();

	void PlusNum(int n);

	/* ť�� �����͸� ��ť */
	int Enque(double x);

	/* ť���� �����͸� ��ť */
	int Deque(double* x);

	/* ť���� �����͸� ��ũ */
	double Peek(double* x);

	/* ��� ������ ���� */
	void Clear();

	/* ť�� �ִ� �뷮 */
	int Capacity();

	/* ť�� ����� ������ ���� */
	int Size();

	/* ť�� ����ִ°� ? */
	int IsEmpty();

	/* ť�� ���� á�°� ? */
	int IsFull();

	/* ť���� �˻� */
	int Search(double x);

	/* ��� ������ ��� */
	void Print();

	double Print(int index);

	/* ť ���� */
	void Terminate();
};

