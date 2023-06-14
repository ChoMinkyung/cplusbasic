#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include "20230608_Q3_account.h"
using namespace std;

BankAccount::BankAccount(const char* client, const char* num, double bal)
{
	strcpy(name, client);
	strcpy(acctnum, num);
	balance = bal;
}

void BankAccount::show(void) const
{
	cout << endl << "������ : " << name << endl;
	cout << "���¹�ȣ : " << acctnum << endl;
	cout << "�ܾ� : " << balance << "��" << endl << endl;;
}

void BankAccount::deposit(double cash)
{
	balance += cash;
	cout << cash << "���� �ԱݵǾ����ϴ�." << endl << endl;
}

void BankAccount::withdraw(double cash)
{
	balance -= cash;
	cout << cash << "���� ��ݵǾ����ϴ�." << endl << endl;
}
