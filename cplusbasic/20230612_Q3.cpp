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

	Stack OperatorStack;
	Queue PostFixQueue;

	ifstream calcFile;
	calcFile.open("calc.txt");
	if (!calcFile.is_open())
	{
		cout << "파일을 열 수 없습니다." << endl;
		cout << "프로그램을 종료합니다." << endl;
		exit(EXIT_FAILURE);
	}

	char ch;
	int number = 0;
	int number_count = 1;
	while (calcFile.get(ch))
	{
		cout << ch;
		if (ch >= '0' && ch <= '9')
		{
			number += number_count * (ch - '0');
			number_count *= 10;

		}
		else
		{
			if (number_count > 1)
			{
				PostFixQueue.PlusNum(1);
				PostFixQueue.Enque(number);
				isNumber[index++] = 1;

				number = 0;
				number_count = 1;
			}


			if (ch == '(')
			{
				OperatorStack.PlusSize(1);
				OperatorStack.Push((int)ch);
			}
			else if (ch == ')')
			{
				int i = OperatorStack.getPtr();
				while (OperatorStack.getStk(i) != (int)ch)
				{
					PostFixQueue.PlusNum(1);
					PostFixQueue.Enque(OperatorStack.getStk(i));
					index++;
				}
				OperatorStack.PlusSize(-1);
			}
			else if (ch == '+' || ch == '-')
			{
				for (int i = OperatorStack.getPtr(); i >= 0; i--)
				{
					if (OperatorStack.getStk(i) == '*' || OperatorStack.getStk(i) == '/')
					{
						PostFixQueue.Enque(OperatorStack.getStk(i));
						PostFixQueue.PlusNum(1);
						index++;

						OperatorStack.PlusSize(-1);
						OperatorStack.Push(ch);
						OperatorStack.PlusSize(1);
					}
				}
			}
			else if (ch == '*' || ch == '/')
			{
				OperatorStack.Push(ch);
				OperatorStack.PlusSize(1);
			}
		}
	}

	for (int i = 0; i < index; i++)
	{
		if (isNumber[i]) cout << PostFixQueue.Print(i) << " ";
		else cout << (char)PostFixQueue.Print(i) << " ";

	}
	cout << endl;
}