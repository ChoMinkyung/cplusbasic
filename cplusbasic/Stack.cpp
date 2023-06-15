#include <iostream>
using namespace std;

#include "Stack.h"

Stack::Stack()
{
    prt = max = 0;
}

Stack::Stack(int max)
{
    prt = 0;
    this->max = max;

    stk = new double[sizeof(double) * max+1];
    if (stk == NULL)
    {
        this->max = 0;
    }
}


Stack::~Stack()
{
}

int Stack::getStk(int idx)
{
    return stk[idx];
}

int Stack::getPtr()
{
    return prt;
}

void Stack::PlusSize(int n)
{
    prt += n;
}

int Stack::Push(double x)
{
    if (IsFull()) return -1;
    stk[prt] = x;
    prt++;

    return 0;
}

int Stack::Pop(double* x)
{
    if (IsEmpty()) return -1;
    *x = stk[prt - 1];
    prt--;

    return 0;
}

int Stack::Peek(double* x)
{
    if (IsEmpty()) return -1;

    *x = stk[prt - 1];
    
    return 0;
}

void Stack::Clear()
{
    prt = 0;
}

int Stack::Capacity()
{
    return max;
}

int Stack::Size()
{
    return prt;
}

int Stack::IsEmpty()
{
    if (!prt) return 1;
    return 0;
}

int Stack::IsFull()
{
    if (prt == max) return 1;
    return 0;
}

int Stack::Search(double x)
{
    for (int i = 0; i < prt; i++)
    {
        if (stk[i] == x) return i;
    }
    return -1;
}

void Stack::Print()
{
    for(int i=0; i<prt; i++)
        cout << stk[i] << " ";
    cout << endl;
}

double Stack::Print(int i)
{
    return stk[i];
}

void Stack::Terminate()
{
    if (stk != NULL) delete[] stk;
    prt = max = 0;
}


