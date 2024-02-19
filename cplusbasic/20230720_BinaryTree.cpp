#include <iostream>
using namespace std;
#include "BinaryTree.h"

enum { Insert = 1, Remove, Print, Clear };

int main()
{
	BinaryTree binaryTree;
	Student st;

	int menu = 100;

	cout << "�л� ���� ���α׷��Դϴ�." << endl;
	while (menu != 0)
	{
		cout << "[MENU] 1:����  2:����  3:���  4:�ʱ�ȭ  0:����" << endl;
		cout << ">> �޴��� �����ϼ��� : ";
		while (1)
		{
			cin >> menu;
			if (menu < 0 || menu > 5) cout << ">> �ٽ� �Է��ϼ��� : ";
			else break;
		}

		cout << endl;

		switch (menu)
		{

		case Insert:
			cout << "\t>> ��ȣ�� �Է��ϼ��� : ";
			cin >> st.no;
			cout << "\t>> �̸��� �Է��ϼ��� : ";
			cin >> st.name;
			binaryTree.Insert(st);
			break;
		case Remove:
			int no;
			cout << "\t>> ������ ��ȣ�� �Է��ϼ��� : ";
			cin >> no;
			binaryTree.Remove(no);
			break;
		case Print:
			binaryTree.Print(binaryTree.GetRoot());
			break;
		case Clear:
			binaryTree.Clear();
			cout << "\t�ʱ�ȭ�Ǿ����ϴ�." << endl;
			break;

		default:
			break;
		}

		cout << endl;
	}

	cout << "���α׷��� ����Ǿ����ϴ�. �����մϴ�." << endl;
}