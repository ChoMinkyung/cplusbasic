#include <iostream>
using namespace std;

#include "LinkedList.h"

enum {Insert=1, Remove, Print, Clear};

//#include <list>

int main()
{
	/*list<int> intList;
	for (list<int>::iterator it = intList.begin(); it != intList.end(); it++)
	{

	}

	for (list<int>::reverse_iterator rit = intList.rbegin(); rit != intList.rend(); rit--)
	{

	}*/


	LinkedList list;

	Student st;

	int menu=100;
	cout << "�л� ���� ���α׷��Դϴ�." << endl;
	while (menu!=0)
	{
		cout << "[MENU] 1:���� 2:���� 3:��� 4:�ʱ�ȭ 0:����" << endl;
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