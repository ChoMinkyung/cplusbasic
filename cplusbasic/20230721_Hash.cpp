#include <iostream>
using namespace std;

enum { Insert = 1, Remove, Print, Find, Clear };

#include "Hash.h"

int main()
{
	Hash hash;
	Student st;
	int no;

	int menu = 100;
	cout << "학생 관리 프로그램입니다." << endl;

	while (menu != 0)
	{
		cout << "[MENU] 1:삽입  2:삭제  3:출력  4:찾기  5:초기화  0:종료" << endl;
		cout << ">> 메뉴를 선택하세요 : ";
		while (1)
		{
			cin >> menu;
			if (menu < 0 || menu > 6) cout << ">> 다시 입력하세요 : ";
			else break;
		}
		cout << endl;
		switch (menu)
		{

		case Insert:
			cout << "\t>> 번호를 입력하세요 : ";
			cin >> st.no;
			cout << "\t>> 이름을 입력하세요 : ";
			cin >> st.name;
			hash.Insert(st);
			break;
		case Remove:
			cout << "\t>> 삭제할 번호를 입력하세요 : ";
			cin >> no;
			hash.Remove(no);
			break;
		case Print:
			hash.Print();
			break;
		case Find:
			cout << "\t>> 찾을 번호를 입력하세요 : ";
			cin >> no;
			if (hash.Find(no)>-1)
			{
				cout << "\t데이터를 찾았습니다." << endl;
			}
			else
			{
				cout << "\t데이터를 찾지 못했습니다." << endl;
			}
			break;
		case Clear:
			hash.Clear();
			cout << "\t초기화되었습니다." << endl;
			break;

		default:
			break;
		}

		cout << endl;
	}

	cout << "프로그램이 종료되었습니다. 감사합니다." << endl;
}
