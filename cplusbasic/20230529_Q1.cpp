#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

struct TCL
{
	char name[30];
	double diameter;
	double weight;
};

int main()
{
	TCL pizza;
	cout << "���� ȸ���� �̸� : ";
	cin.getline(pizza.name, 30);
	cout << "������ ���� : ";
	cin >> pizza.diameter;
	cout << "������ �߷� : ";
	cin >> pizza.weight;

	cout << endl << "���� ȸ�� : " << pizza.name << endl;
	cout << "������ ���� : " << pizza.diameter << endl << "������ �߷� : " << pizza.weight << endl;
}

struct TCL
{
	char *name = new char[30];
	double diameter;
	double weight;
};

int main()
{
	TCL pizza;
	cout << "������ ���� : ";
	cin >> pizza.diameter;
	cin.ignore();
	cout << "���� ȸ���� �̸� : ";
	cin.getline(pizza.name, 30);
	cout << "������ �߷� : ";
	cin >> pizza.weight;

	cout << endl << "���� ȸ�� : " << pizza.name << endl;
	cout << "������ ���� : " << pizza.diameter << endl << "������ �߷� : " << pizza.weight << endl;

	delete[] pizza.name;
}
