
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

struct CandyBar
{
	char name[50];
	double weight;
	int calorie;
};

int main()
{
	int number = 3;

	CandyBar* snack = new CandyBar[number];

	snack[0] = { "Mocha Munch", 2.3, 350 };
	snack[1] = { "��ĵ���", 4.9, 200 };
	snack[2] = { "ToyStroy Rex",9.1, 490 };

	for (int i = 0; i < number; i++)
	{
		cout << i + 1 << endl;
		cout << "ĵ����� ��ǥ�� : " << snack[i].name << endl;
		cout << "ĵ����� �߷� : " << snack[i].weight << endl;
		cout << "ĵ��ٿ� ������ Į�θ� : " << snack[i].calorie << endl;
	}

}