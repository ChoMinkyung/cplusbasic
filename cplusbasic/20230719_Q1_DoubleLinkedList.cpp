#include <iostream>
using namespace std;

#include "DoubleLinkedList.h"

enum { Insert = 1, Remove, Print, ReversePrint, Clear };

int main()
{

	DoubleLinkedList list;
	Student st;

	int menu = 100;

	cout << "�л� ���� ���α׷��Դϴ�." << endl;
	while (menu != 0)
	{
		cout << "[MENU] 1:����  2:����  3:���  4:�Ųٷ� ���  5:�ʱ�ȭ  0:����" << endl;
		cout << ">> �޴��� �����ϼ��� : ";
		cin >> menu;
		cout << endl;

		switch (menu)
		{

		case Insert:
			cout << "\t>> ��ȣ�� �Է��ϼ��� : ";
			cin >> st.no;
			cout << "\t>> �̸��� �Է��ϼ��� : ";
			cin >> st.name;
			list.Insert(st);
			break;
		case Remove:
			int no;
			cout << "\t>> ������ ��ȣ�� �Է��ϼ��� : ";
			cin >> no;
			list.Remove(no);
			break;
		case Print:
			list.Print();
			break;
		case ReversePrint:
			list.ReversePrint();
			break;
		case Clear:
			list.Clear();
			cout << "\t�ʱ�ȭ�Ǿ����ϴ�." << endl;
			break;

		default:
			break;
		}

		cout << endl;
	}

	cout << "���α׷��� ����Ǿ����ϴ�. �����մϴ�." << endl;
}