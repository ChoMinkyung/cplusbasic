#include <iostream>
using namespace std;
#include "BinaryTree.h"

enum { Insert = 1, Remove, Print, Clear };

int main()
{
	BinaryTree binaryTree;
	Student st;

	int menu = 100;

	cout << "학생 관리 프로그램입니다." << endl;
	while (menu != 0)
	{
		cout << "[MENU] 1:삽입  2:삭제  3:출력  4:초기화  0:종료" << endl;
		cout << ">> 메뉴를 선택하세요 : ";
		while (1)
		{
			cin >> menu;
			if (menu < 0 || menu > 5) cout << ">> 다시 입력하세요 : ";
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
			binaryTree.Insert(st);
			break;
		case Remove:
			int no;
			cout << "\t>> 삭제할 번호를 입력하세요 : ";
			cin >> no;
			binaryTree.Remove(no);
			break;
		case Print:
			binaryTree.Print(binaryTree.GetRoot());
			break;
		case Clear:
			binaryTree.Clear();
			cout << "\t초기화되었습니다." << endl;
			break;

		default:
			break;
		}

		cout << endl;
	}

	cout << "프로그램이 종료되었습니다. 감사합니다." << endl;
}