#include <stdio.h>
#include "IntStack.h"


int Initialize(IntStack* s, int max)
{
	s->prt = 0;
	s->max = max;

	s->stk = (int*)malloc(sizeof(int) * (max + 1));
	if (s->stk == NULL)
	{
		s->max = 0;
		return -1;
	}

	return 0;
}

int Push(IntStack* s, int x)
{
	if (IsFull(&s) == 1) return -1;
	s->stk[s->prt] = x;
	s->prt++;

	return 0;
}

int Pop(IntStack* s, int* x)
{
	if (IsEmpty(&s) == 1) return -1;
	*x = s->stk[s->prt-1];
	s->prt--;
	return 0;
}

int Peek(const IntStack* s, int* x)
{
	if (IsEmpty(&s) == 1) return -1;
	
	*x = s->stk[s->prt - 1];
	return 0;
}

void Clear(IntStack* s)
{
	s->prt = 0;
}

int Capacity(const IntStack* s)
{
	return s->max;
}

int Size(const IntStack* s)
{
	return s->prt;
}

int IsEmpty(const IntStack* s)
{
	// 1이면 비었음
	if (s->prt == 0) return 1;
	return 0;
}

int IsFull(const IntStack* s)
{
	//1이면 가득 참
	if (s->prt == s->max) return 1;
	return 0;
}

int Search(const IntStack* s, int x)
{
	for (int i = 0; i < s->prt; i++)
	{
		if (s->stk[i] == x) return i;
	}
	return -1;
}

void Print(const IntStack* s)
{
	for (int i = 0; i < s->prt; i++)
		printf("%d ", s->stk[i]);
	printf("\n");
}

void Terminate(IntStack* s)
{
	if (s->stk != NULL) free(s->stk);
	s->prt = s->max = 0;
}
