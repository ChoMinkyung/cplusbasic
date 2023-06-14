#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#include "_20230608_Q4_IntQueue.h"

int main()
{
	IntQueue que;

	if (Initialize(&que, 64) == -1)
	{
		puts("ť�� ������ �����Ͽ����ϴ�.");
		return 1;
	}
	
	while (1)
	{
		int m, x;
		
		cout << "���� ������ �� : " << Size(&que) << " / " << Capacity(&que) << endl;
		cout << "(1)��ť  (2)��ť  (3)��ũ  (4)���  (5)�˻�  (6)����" << endl;

		cin >> m;

		if (m == 0) break;

		switch (m)
		{
		case 1: // ��ť
			cout << "������ : ";
			cin >> x;
			if (Enque(&que, x) == -1) puts("\a���� : ��ť�� �����Ͽ����ϴ�.");
			break;
		case 2: // ��ť
			if (Deque(&que, &x) == -1) cout << "��ť�� �����ʹ� " << x << "�Դϴ�." << endl;
			break;

		case 3: // ��ũ
			if (Peek(&que, &x) == -1) puts("\a���� : ��ũ�� �����Ͽ����ϴ�.");
			else cout << "��ũ�� �����ʹ� " << x << "�Դϴ�." << endl;
			break;
		case 4: // ���
			Print(&que);
			break;
		case 5: //�˻�
			break;
		case 6: // ����
			break;

		default:
			break;
		}

	}
}