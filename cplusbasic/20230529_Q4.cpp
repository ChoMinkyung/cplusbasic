#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

struct car
{
	char name[30];
	int yesr;
};

void Q7()
{
	int n;
	cout << "�� ���� ���� ������� �����Ͻðڽ��ϱ�? ";
	cin >> n;
	cin.ignore();
	car* CAR = new car[n];

	for (int i = 0; i < n; i++)
	{
		cout << "�ڵ��� #" << i + 1 << endl;

		cout << "���۾�ü : ";
		cin.getline(CAR[i].name, 30);

		cout << "���۳⵵ : ";
		cin >> CAR[i].yesr;
		cin.ignore();
	}

	cout << "���� ���ϰ� �����ϰ� �ִ� �ڵ��� ����� ������ �����ϴ�." << endl;

	for (int i = 0; i < n; i++)
	{
		cout << CAR[i].yesr << "���� " << CAR[i].name << endl;
	}
}

void Q8()
{
	char words[30];
	int count = 0;
	while (strcmp(words, "done") != 0)
	{
		count++;
		cin >> words;
	}

	cout << "�� " << --count << "�ܾ �ԷµǾ����ϴ�." << endl;
}

int main()
{
	Q7();

	cout << endl;

	Q8();
}