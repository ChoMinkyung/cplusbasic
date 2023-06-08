#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "IntStack.h"

int main()
{
	IntStack s;
	if (Initialize(&s, 64) == -1)
	{
		puts("���� ������ �����߽��ϴ�.");
		return 1;
	}

	while (1)
	{
		int menu, x;
		printf("���� ������ �� : %d / %d\n\n", Size(&s), Capacity(&s));
		printf("(1)Ǫ�� (2)�� (3)��ũ (4)��� (5)�ʱ�ȭ (6)����\n(7)Capacity (8)Size (9)IsEmpty (10)IsFull (11)Search (0)����\n");
		printf("\n�޴��� �Է��ϼ��� : ");
		scanf("%d", &menu);

		if (menu == 0) break;
		switch (menu)
		{
		case 1: // Ǫ��
			printf("������: ");
			scanf("%d", &x);
			if (Push(&s, x) == -1) puts("\a���� : Ǫ�ÿ� �����߽��ϴ�.");
			break;
		case 2: // ��
			if (Pop(&s, &x) == -1) puts("\a���� : �˿� �����߽��ϴ�.");
			else printf("�� �����ʹ� %d�Դϴ�.\n", x);
			break;
		case 3: //��ũ
			if(Peek(&s, &x)==-1) puts("\a���� : ��ũ�� �����߽��ϴ�.");
			else printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
			break;
		case 4: // ���
			Print(&s);
			break;
		case 5: // �ʱ�ȭ
			printf("���� �뷮�� �Է����ּ��� : ");
			int max;
			scanf("%d", &max);
			if (Initialize(&s, max) == -1)
			{
				puts("���� ������ �����߽��ϴ�.\n");
				return 1;
			}
			else puts("������ �����߽��ϴ�.\n");
			break;
		case 6: // ����
			Clear(&s);
			break;
		case 7:// Capacity
			printf("������ �뷮�� %d �Դϴ�.\n", Capacity(&s));
			break;
		case 8: // Size
			printf("���ÿ� �����Ͱ� %d�� �ֽ��ϴ�.\n", Size(&s));
			break;
		case 9: // IsEmpty
			if (IsEmpty(&s) == 1) printf("������ ����ֽ��ϴ�.\n");
			else printf("������ ������� �ʽ��ϴ�.\n");
			break;
		case 10: // IsFull(11)Search
			if (IsFull(&s) == 1) printf("������ ���� �� �ֽ��ϴ�.\n");
			else printf("������ ���� �� ���� �ʽ��ϴ�.\n");
			break;
		case 11:
			printf("ã�� �����͸� �Է��ϼ��� : ");
			int x;
			scanf("%d", &x);
			if (Search(&s, x) == -1)printf("ã�� �����Ͱ� �����ϴ�.\n");
			else printf("������ %d�� %d��°�� �ֽ��ϴ�.\n", x, Search(&s, x));
			break;
		default:
			break;
		}
	}
	Terminate(&s);
	return 0;
}