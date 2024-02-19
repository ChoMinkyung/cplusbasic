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
	cout << "�л� ���� ���α׷��Դϴ�." << endl;

	while (menu != 0)
	{
		cout << "[MENU] 1:����  2:����  3:���  4:ã��  5:�ʱ�ȭ  0:����" << endl;
		cout << ">> �޴��� �����ϼ��� : ";
		while (1)
		{
			cin >> menu;
			if (menu < 0 || menu > 6) cout << ">> �ٽ� �Է��ϼ��� : ";
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
			hash.Insert(st);
			break;
		case Remove:
			cout << "\t>> ������ ��ȣ�� �Է��ϼ��� : ";
			cin >> no;
			hash.Remove(no);
			break;
		case Print:
			hash.Print();
			break;
		case Find:
			cout << "\t>> ã�� ��ȣ�� �Է��ϼ��� : ";
			cin >> no;
			if (hash.Find(no)>-1)
			{
				cout << "\t�����͸� ã�ҽ��ϴ�." << endl;
			}
			else
			{
				cout << "\t�����͸� ã�� ���߽��ϴ�." << endl;
			}
			break;
		case Clear:
			hash.Clear();
			cout << "\t�ʱ�ȭ�Ǿ����ϴ�." << endl;
			break;

		default:
			break;
		}

		cout << endl;
	}

	cout << "���α׷��� ����Ǿ����ϴ�. �����մϴ�." << endl;
}
