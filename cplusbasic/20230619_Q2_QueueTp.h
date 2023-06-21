#pragma once
#include <iostream>
using namespace std;

template <class Type>

class Queue
{
private:
	enum { SIZE = 10 };
	int queuesize;
	Type* items;
	int front, rear;
public:
	explicit Queue(int qq=SIZE);
	Queue(const Queue& q);
	~Queue() { delete[] items; }
	bool isempty() { return front == rear; }
	bool isfull() { return front == rear + 1; }
	bool enqueue(const Type& item);
	bool dequeue(Type& item);
	Queue& operator=(const Queue& q);
};

template<class Type>
inline Queue<Type>::Queue(int qq)
{
	queuesize = SIZE;
	this->front = this->rear = 0;
	items = new Type[queuesize];
}

template<class Type>
inline Queue<Type>::Queue(const Queue& q)
{
	queuesize = q.queuesize;
	front = 0;

	if (q.front > q.rear) rear = queuesize - (q.front - q.rear) + 1;
	else rear = q.rear - q.front + 1;

	items = new Type[queuesize];

	for (int i = 0; i < rear; i++)
	{
		items[i] = q.items[q.front + i];
	}
}

template<class Type>
inline bool Queue<Type>::enqueue(const Type& item)
{
	if(isfull()) return false;
	else
	{
		items[rear++] = item;
		return true;
	}
}

template<class Type>
inline bool Queue<Type>::dequeue(Type& item)
{
	if(isempty()) return false;
	else
	{
		item = items[front++];
		return true;
	}
}

template<class Type>
inline Queue<Type>& Queue<Type>::operator=(const Queue& q)
{
	if (this == &q) return *this;
	delete[] items;

	queuesize = q.queuesize;
	front = 0;

	if (q.front > q.rear) rear = queuesize - (q.front - q.rear) + 1;
	else rear = q.rear - q.front + 1;

	items = new Type[queuesize];

	for (int i = 0; i < rear; i++)
	{
		items[i] = q.items[q.front + i];
	}

	return &this;
}
