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
	cout << endl << "예금주 : " << name << endl;
	cout << "계좌번호 : " << acctnum << endl;
	cout << "잔액 : " << balance << "원" << endl << endl;;
}

void BankAccount::deposit(double cash)
{
	balance += cash;
	cout << cash << "원이 입금되었습니다." << endl << endl;
}

void BankAccount::withdraw(double cash)
{
	balance -= cash;
	cout << cash << "원이 출금되었습니다." << endl << endl;
}
