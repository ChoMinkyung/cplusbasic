#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

void Print(char* str);
void PrintSpace(int range);

int main()
{
	//char str[] = "ABABCDEFGHA";
	//char pattern[] = "ABC";
	char str[256];
	char pattern[256];
	int n_pattern = 0;

	cout << "�˻��� ���ڿ��� �Է��ϼ��� : " << endl;
	cin >> str;
	cout << "������ �Է��ϼ��� : ";
	cin >> pattern;

	for (int i = 0; i < strlen(str); i++)
	{
		if (i + strlen(pattern) > strlen(str)) break;

		for (int j = 0; j < strlen(pattern); j++)
		{
			Print(str);

			PrintSpace(i);
			PrintSpace(j);

			if (str[i + j] == pattern[j])
			{
				cout << "+";
				if (j == strlen(pattern) - 1) n_pattern++;
			}
			else
			{
				cout << "|";
				j = strlen(pattern);
			}

			cout << endl;
			PrintSpace(i);
			Print(pattern);
			cout << endl;
		}
	}
	cout << "\"" << str << "\"�ȿ� \"" << pattern << "\"�� " << n_pattern << "�� �ֽ��ϴ�." << endl;

	n_pattern = 0;

	for (int i = 0; i < strlen(str); i++)
	{
		if (i + strlen(pattern) > strlen(str)) break;

		for (int j = 0; j < strlen(pattern); j++)
		{

			if (str[i + j] == pattern[j])
			{
				if (j == strlen(pattern) - 1) n_pattern++;
			}
			else
			{
				j = strlen(pattern);
			}
		}
	}

	cout << "\""<< str << "\"�ȿ� \"" << pattern << "\"�� " << n_pattern << "�� �ֽ��ϴ�." << endl;
}

void Print(char* str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;
}

void PrintSpace(int range)
{
	for (int i = 0; i < range; i++) cout << "  ";
}