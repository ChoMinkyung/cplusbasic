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
		puts("큐의 생성에 실패하였습니다.");
		return 1;
	}
	
	while (1)
	{
		int m, x;
		
		cout << "현재 데이터 수 : " << Size(&que) << " / " << Capacity(&que) << endl;
		cout << "(1)인큐  (2)디큐  (3)피크  (4)출력  (5)검색  (6)비우기" << endl;

		cin >> m;

		if (m == 0) break;

		switch (m)
		{
		case 1: // 인큐
			cout << "데이터 : ";
			cin >> x;
			if (Enque(&que, x) == -1) puts("\a오류 : 인큐에 실패하였습니다.");
			break;
		case 2: // 디큐
			if (Deque(&que, &x) == -1) cout << "디큐한 데이터는 " << x << "입니다." << endl;
			break;

		case 3: // 피크
			if (Peek(&que, &x) == -1) puts("\a오류 : 피크에 실패하였습니다.");
			else cout << "피크한 데이터는 " << x << "입니다." << endl;
			break;
		case 4: // 출력
			Print(&que);
			break;
		case 5: //검색
			break;
		case 6: // 비우기
			break;

		default:
			break;
		}

	}
}