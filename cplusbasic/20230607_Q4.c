#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "IntStack.h"

int main()
{
	IntStack s;
	if (Initialize(&s, 64) == -1)
	{
		puts("스택 생성에 실패했습니다.");
		return 1;
	}

	while (1)
	{
		int menu, x;
		printf("현재 데이터 수 : %d / %d\n\n", Size(&s), Capacity(&s));
		printf("(1)푸시 (2)팝 (3)피크 (4)출력 (5)초기화 (6)비우기\n(7)Capacity (8)Size (9)IsEmpty (10)IsFull (11)Search (0)종료\n");
		printf("\n메뉴를 입력하세요 : ");
		scanf("%d", &menu);

		if (menu == 0) break;
		switch (menu)
		{
		case 1: // 푸시
			printf("데이터: ");
			scanf("%d", &x);
			if (Push(&s, x) == -1) puts("\a오류 : 푸시에 실패했습니다.");
			break;
		case 2: // 팝
			if (Pop(&s, &x) == -1) puts("\a오류 : 팝에 실패했습니다.");
			else printf("팝 데이터는 %d입니다.\n", x);
			break;
		case 3: //피크
			if(Peek(&s, &x)==-1) puts("\a오류 : 피크에 실패했습니다.");
			else printf("피크 데이터는 %d입니다.\n", x);
			break;
		case 4: // 출력
			Print(&s);
			break;
		case 5: // 초기화
			printf("스택 용량을 입력해주세요 : ");
			int max;
			scanf("%d", &max);
			if (Initialize(&s, max) == -1)
			{
				puts("스택 생성에 실패했습니다.\n");
				return 1;
			}
			else puts("스택을 생성했습니다.\n");
			break;
		case 6: // 비우기
			Clear(&s);
			break;
		case 7:// Capacity
			printf("스택의 용량은 %d 입니다.\n", Capacity(&s));
			break;
		case 8: // Size
			printf("스택에 데이터가 %d개 있습니다.\n", Size(&s));
			break;
		case 9: // IsEmpty
			if (IsEmpty(&s) == 1) printf("스택이 비어있습니다.\n");
			else printf("스택이 비어있지 않습니다.\n");
			break;
		case 10: // IsFull(11)Search
			if (IsFull(&s) == 1) printf("스택이 가득 차 있습니다.\n");
			else printf("스택이 가득 차 있지 않습니다.\n");
			break;
		case 11:
			printf("찾을 데이터를 입력하세요 : ");
			int x;
			scanf("%d", &x);
			if (Search(&s, x) == -1)printf("찾는 데이터가 없습니다.\n");
			else printf("데이터 %d는 %d번째에 있습니다.\n", x, Search(&s, x));
			break;
		default:
			break;
		}
	}
	Terminate(&s);
	return 0;
}