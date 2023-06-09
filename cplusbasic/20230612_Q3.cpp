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
	int x;
	Stack OperatorStack(100);
	Queue PostFixQueue(100);

	ifstream calcFile;
	calcFile.open("calc.txt");
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
	while (calcFile.get(ch))
	{
		cout << "현재 : " << ch;
		if (ch >= '0' && ch <= '9' || ch=='.')
		{
			number = number + number_count * (int)(ch - '0');
			number_count /= 10;
		}
		else
		{
			if (number_count < 1)
			{
				PostFixQueue.Enque((double)number / number_count / 10.0);
				isNumber[index++] = 1;

				number = 0;
				number_count = 1;
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
			}
			else if (ch == '+' || ch == '-')
			{
				for (int i = OperatorStack.getPtr(); i >= 0; i--)
				{
					if (OperatorStack.getStk(i) == '(')
					{
						OperatorStack.Push(ch);
						while_count++;

						break;
					}
					else if (OperatorStack.getStk(i) == '*' || OperatorStack.getStk(i) == '/')
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

	}

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
	cout << endl;

}

