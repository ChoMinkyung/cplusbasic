#include <iostream>
#include "Queue.h"
using namespace std;

Queue::Queue()
{
	front = rear = num = max = 0;
}

Queue::Queue(int max)
{
	front = rear = num = 0;

	que = new int[sizeof(int) * max];
	if (que == NULL)
	{
		max = 0;
	}

	this->max = max;
}

Queue::~Queue()
{
}

void Queue::PlusNum(int n)
{
	num += n;
}

int Queue::Enque(int x)
{
	if (num >= max) return -1;
	else
	{
		num++;
		que[rear++] = x;
		if (rear == max) rear = 0;

		return 0;
	}
}

int Queue::Deque(int* x)
{
	if (num <= 0) return -1;
	else
	{
		num--;
		*x = que[front++];
		if (front == max) front = 0;
		return 0;
	}
}

int Queue::Peek(int* x)
{
	if (num <= 0) return -1;

	*x = que[front];
	return 0;
}

void Queue::Clear()
{
	front = rear = num = 0;
}

int Queue::Capacity()
{
	return max;
}

int Queue::Size()
{
	return num;
}

int Queue::IsEmpty()
{
	return num<=0;
}

int Queue::IsFull()
{
	return num >= max;
}

int Queue::Search(int x)
{
	for (int i = 0; i < num; i++)
	{
		int idx;
		if (que[idx = (i +front) % max] == x) return idx;
	}
	return -1;
}

void Queue::Print()
{
	for (int i = 0; i < num; i++) 
		cout << que[(i + front) % max] << " ";
	cout << endl;
}

int Queue::Print(int index)
{
	return que[(index + front) % max];
}

void Queue::Terminate()
{
	if (que = NULL) delete[] que;
	max = num = front = rear = 0;
}
