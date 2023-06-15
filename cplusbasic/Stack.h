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

	/* 스택에 데이터 푸시 */
	int Push(double x);

	/* 스택에 데이터를 팝 */
	int Pop(double* x);

	/* 스택에서 데이터를 피크 */
	int Peek(double* x);

	/* 스택 비우기 */
	void Clear();

	/* 스택의 최대 용량 */
	int Capacity();

	/* 스택의 데이터 개수 */
	int Size();

	/* 스택이 비어 있나요 ? */
	int IsEmpty();

	/* 스택이 가득 찼나요 ? */
	int IsFull();

	/* 스택에서 검색 */
	int Search(double x);

	/* 모든 데이터 출력 */
	void Print();

	double Print(int i);

	/* 스택 종료 */
	void Terminate();

};

