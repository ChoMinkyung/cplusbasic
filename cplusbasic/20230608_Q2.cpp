#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void print(char* word, int* correct);

int main()
{
	int len = 5;
	char* word = new char[len + 1];
	int* correct = new int[sizeof(int) * len];

	strcpy(word, "apple");
	int flag = 0;

	int fail = 0, success = 0;
	while (success != len)
	{
		char c;
		cout << "�ܾ� �� �� ���ڸ� �Է��ϼ���. ";
		print(word, correct);
		cin >> c;

		for (int i = 0; i < len; i++)
		{
			if (word[i] == c)
			{
				if (correct[i] == 1)
				{
					flag = 1;
				}
				else
				{
					correct[i] = 1;
					flag = 2;
					break;
				}
			}
		}

		if (flag == 0)
		{
			fail++;
			cout << c << "��/�� �ܾ ���Ե��� �ʽ��ϴ�." << endl;;
		}
		else if (flag == 1)
		{
			fail++;
			cout << c << "�� �̹� �ܾ ���ԵǾ� �ֽ��ϴ�." << endl;
		}
		else
		{
			print(word, correct);
			success++;
			flag = 0;
		}
	}

	cout << "�� " << fail << "�� ����, " << fail + success << "�� ���� ����! " << word << endl;

	delete[] word;
	delete[] correct;
}

void print(char* word, int* correct)
{
for (int i = 0; i < strlen(word); i++)
	{
		if (correct[i] != 1)cout << "*";
		else cout << word[i];
	}
	cout << endl;
}