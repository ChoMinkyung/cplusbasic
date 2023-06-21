#include "20230619_stcktp1.h"

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

const int Num = 10;

int main()
{
	srand(time(0));
	cout << "스택의 크기를 입력하십시오 : ";
	int stacksize;
	cin >> stacksize;

	// 빈 스택 생성
	StackTp<const char*> st(stacksize);

	const char* in[Num] = {
		" 1: 노미호", " 2: 주리혜",
		" 3: 이몽룡", " 4: 성춘향", 
		" 5: 이수일", "6: 심순애",
		" 7: 박문수", " 8: 홍길동", 
		" 9: 김두한", "10: 하야시"
	};

	const char* out[Num];

	int processed = 0;
	int nextin = 0;
	while (processed < Num)
	{
		if (st.isempty()) st.push(in[nextin++]);
		else if (st.isfull()) st.pop(out[processed++]);
		else if (rand() % 2 && nextin < Num) st.push(in[nextin++]);
		else st.pop(out[processed++]);
	}

	for (int i = 0; i < Num; i++)
	{
		cout << out[i] << endl;
	}

	cout << "프로그램을 종료합니다." << endl;

}