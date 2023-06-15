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

	/* 큐에 데이터를 인큐 */
	int Enque(double x);

	/* 큐에서 데이터를 디큐 */
	int Deque(double* x);

	/* 큐에서 데이터를 피크 */
	double Peek(double* x);

	/* 모든 데이터 삭제 */
	void Clear();

	/* 큐의 최대 용량 */
	int Capacity();

	/* 큐에 저장된 데이터 개수 */
	int Size();

	/* 큐가 비어있는가 ? */
	int IsEmpty();

	/* 큐가 가득 찼는가 ? */
	int IsFull();

	/* 큐에서 검색 */
	int Search(double x);

	/* 모든 데이터 출력 */
	void Print();

	double Print(int index);

	/* 큐 종료 */
	void Terminate();
};

