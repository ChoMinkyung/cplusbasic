#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#include <fstream>
#include "Queue.h"
#include "Stack.h"

int main()
{
	int isNumber[100] = { 0 };
	int index = 0;
	double x;
	Stack OperatorStack(100);
	Queue PostFixQueue(100);

	ifstream calcFile;
	calcFile.open("calc2.txt");
	if (!calcFile.is_open())
	{
		cout << "파일을 열 수 없습니다." << endl;
		cout << "프로그램을 종료합니다." << endl;
		exit(EXIT_FAILURE);
	}

	char ch;
	double number = 0;
	double number_count = 1;
	int while_count = 0;
	int number_double = 0;
	int negative = 0;
	while (calcFile.get(ch))
	{
		cout << ch;
		if (ch == '.')
		{
			number_double = 1;
			continue;
		}
		if (ch >= '0' && ch <= '9')
		{
			number = number + number_count * (int)(ch - '0');
			number_count /= 10;
		}
		else
		{
			if (ch == '-' && number_count == 1)
			{
				negative = 1;
				continue;
			}

			if (number_count < 1)
			{
				if (negative) number = -number;
				if (number_double)PostFixQueue.Enque(number/10.0);
				else PostFixQueue.Enque((double)number / number_count / 10.0);
				isNumber[index++] = 1;

				number = 0;
				number_count = 1;
				number_double = 0;
				negative = 0;
			}


			if (ch == '(')
			{
				OperatorStack.Push((int)ch);
				while_count++;
			}
			else if (ch == ')')
			{
				int i = OperatorStack.getPtr() - 1;
				while (OperatorStack.getStk(i) != (int)'(')
				{
					OperatorStack.Pop(&x);
					PostFixQueue.Enque(x);
					index++;
					i--;
					while_count--;
				}
				OperatorStack.Pop(&x);
				while_count--;
				number_count = 10;
			}
			else if (ch == '+' || ch == '-')
			{

				for (int i = OperatorStack.getPtr() - 1; i >= 0; i--)
				{
					if (OperatorStack.getStk(i) == '(')
					{
						OperatorStack.Push(ch);
						while_count++;

						break;
					}
					else
					{
						OperatorStack.Pop(&x);
						PostFixQueue.Enque(x);
						index++;

						OperatorStack.Push(ch);
						break;
					}
				}
			}
			else if (ch == '*' || ch == '/')
			{
				OperatorStack.Push(ch);
				while_count++;

			}
		}

		/*
		cout << endl << endl;

		cout << "Stack : ";
		for (int i = 0; i < while_count; i++)
		{
			cout << (char)OperatorStack.Print(i) << " ";
		}

		cout << endl;
		cout << "Queue : ";
		for (int i = 0; i < index; i++)
		{
			if (isNumber[i]) cout << PostFixQueue.Print(i) << " ";
			else cout << (char)PostFixQueue.Print(i) << " ";
		}
		cout << endl << endl;
		*/

	}

	cout << endl << endl;

	while (!OperatorStack.IsEmpty())
	{
		OperatorStack.Pop(&x);
		PostFixQueue.Enque(x);
		index++;
	}

	for (int i = 0; i < index; i++)
	{
		if (isNumber[i]) cout << PostFixQueue.Print(i) << " ";
		else cout << (char)PostFixQueue.Print(i) << " ";

	}

	OperatorStack.Clear();

	cout << endl;

	int i = 0;
	double n1, n2;
	int n_operator;
	while (!PostFixQueue.IsEmpty())
	{
		PostFixQueue.Deque(&x);
		if (isNumber[i] == 1) OperatorStack.Push(x);
		else
		{
			n_operator = x;
			OperatorStack.Pop(&x);
			n2 = x;
			OperatorStack.Pop(&x);
			n1 = x;
			if (n_operator == '+') x = n1 + n2;
			else if (n_operator == '-') x = n1 - n2;
			else if (n_operator == '*') x = n1 * n2;
			else if (n_operator == '/') x = n1 / n2;

			cout << endl << "중간계산결과 : " << x << endl;
			OperatorStack.Push(x);
		}
		i++;
	}

	OperatorStack.Pop(&x);

	cout << endl << "Result : " << x << endl;

}

