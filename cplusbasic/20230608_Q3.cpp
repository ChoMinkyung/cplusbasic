#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#include "_20230608_Q3_account.h"
#include "_20230608_Q3_move.h"

void Q3_account();
void Q3_move();

int main()
{
	Q3_account();

	cout << endl;

	Q3_move();
}

void Q3_account()
{
	BankAccount bank = BankAccount("min", "110-448-125496", 10000);
	double cash;
	int menu;

	while (1)
	{
		cout << "(1) 잔액 확인  (2) 입금  (3) 출금  (0) 종료\n메뉴를 선택하세요 : ";
		cin >> menu;

		if (menu == 0)break;

		switch (menu)
		{
		case 1:
			bank.show();
			break;
		case 2:
			cout << endl << "입금할 금액 : ";
			cin >> cash;
			bank.deposit(cash);
			break;
		case 3:
			cout << endl << "출금할 금액 : ";
			cin >> cash;
			bank.withdraw(cash);
		default:
			break;
		}
	}

	cout << "프로그램이 종료되었습니다." << endl;
}

void Q3_move()
{
	Move move_1 = Move(10, 9.5);
	Move move_2 = Move(8, 100.1);

	cout << "move 1 : ";
	move_1.showmove();
	cout << "move 2 : ";
	move_2.showmove();

	cout << endl << "move 3 : move 1 에 move 2 더함" << endl;
	Move move_3 = move_1.add(move_2);

	cout << "move 1 : ";
	move_1.showmove();
	cout << "move 2 : ";
	move_2.showmove();
	cout << "move 3 : ";
	move_3.showmove();

	move_1.reset();

	cout << endl << "move 1 reset" << endl;
	cout << "move 1 : ";
	move_1.showmove();
	cout << "move 2 : ";
	move_2.showmove();
	cout << "move 3 : ";
	move_3.showmove();
}