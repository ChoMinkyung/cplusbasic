#define _crt_secure_no_warnings

#include <iostream>
#include <string>
#include <cmath>

#include <new>

const int buf = 512;
const int n = 5;
char buffer[buf];

using namespace std;

namespace pers
{
	struct person
	{
		std::string fname;
		std::string lname;
	};
	void getperson(person&);
	void showperson(const person&);
}

namespace debts
{

}

int main()
{
	/*
	double* pd1, * pd2;
	int i;
	cout << "new�� ��ġ���� new�� ù���� ȣ�� : " << endl;

	pd1 = new double[n];
	pd2 = new (buffer) double[n];

	for (i = 0; i < n; i++)
	{
		pd2[i] = pd1[i] = 1000 + 20.0 * i;
	}

	cout << "�޸� �ּ� :\n" << pd1 << " : ��;     " << (void*)buffer << " : ����" << endl;
	cout << "�޸� ���� :\n";

	for (i = 0; i < n; i++)
	{
		cout << &pd1[i] << "�� " << pd1[i] << ";  ";
		cout << &pd2[i] << "�� " << pd2[i] << endl;
	}

	cout << "\nnew�� ��ġ���� new�� �ι�° ȣ�� : \n";
	double* pd3, * pd4;
	pd3 = new double[n];
	pd4 = new (buffer) double[n];
	for (i = 0; i < n; i++)
	{
		pd4[i] = pd3[i] = 1000 + 40.0 * i;
	}
	cout << "�޸� ���� :\n";

	for (i = 0; i < n; i++)
	{
		cout << &pd3[i] << "�� " << pd3[i] << ";  ";
		cout << &pd4[i] << "�� " << pd4[i] << endl;
	}

	cout << "\nnew�� ��ġ���� new�� ����° ȣ��:\n";
	delete[] pd1;
	pd1 = new double[n];
	pd2 = new (buffer + n * sizeof(double)) double[n];

	for (i = 0; i < n; i++)
	{
		pd2[i] = pd1[i] = 1000 + 60.0 * i;
	}
	cout << "�޸� ���� :\n";

	for (i = 0; i < n;i++)
	{
		cout << &pd1[i] << "�� " << pd1[i] << ";  ";
		cout << &pd2[i] << "�� " << pd2[i] << endl;
	}
	delete pd1;
	delete pd3;
	return 0;
	*/




}