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
	cout << "피자 회사의 이름 : ";
	cin.getline(pizza.name, 30);
	cout << "피자의 지름 : ";
	cin >> pizza.diameter;
	cout << "피자의 중량 : ";
	cin >> pizza.weight;

	cout << endl << "피자 회사 : " << pizza.name << endl;
	cout << "피자의 지름 : " << pizza.diameter << endl << "피자의 중량 : " << pizza.weight << endl;
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
	cout << "피자의 지름 : ";
	cin >> pizza.diameter;
	cin.ignore();
	cout << "피자 회사의 이름 : ";
	cin.getline(pizza.name, 30);
	cout << "피자의 중량 : ";
	cin >> pizza.weight;

	cout << endl << "피자 회사 : " << pizza.name << endl;
	cout << "피자의 지름 : " << pizza.diameter << endl << "피자의 중량 : " << pizza.weight << endl;

	delete[] pizza.name;
}
