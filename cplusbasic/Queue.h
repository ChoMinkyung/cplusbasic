#pragma once
class Queue
{
private:
	int max;
	int num;
	int front;
	int rear;
	int* que;
public:
	Queue();
	Queue(int max);
	~Queue();

	void PlusNum(int n);

	/* ť�� �����͸� ��ť */
	int Enque(int x);

	/* ť���� �����͸� ��ť */
	int Deque(int* x);

	/* ť���� �����͸� ��ũ */
	int Peek(int* x);

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
	int Search(int x);

	/* ��� ������ ��� */
	void Print();

	int Print(int index);

	/* ť ���� */
	void Terminate();
};

