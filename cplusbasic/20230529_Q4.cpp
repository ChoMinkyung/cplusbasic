#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

struct car
{
	char name[30];
	int yesr;
};

void Q7()
{
	int n;
	cout << "몇 대의 차를 목록으로 관리하시겠습니까? ";
	cin >> n;
	cin.ignore();
	car* CAR = new car[n];

	for (int i = 0; i < n; i++)
	{
		cout << "자동차 #" << i + 1 << endl;

		cout << "제작업체 : ";
		cin.getline(CAR[i].name, 30);

		cout << "제작년도 : ";
		cin >> CAR[i].yesr;
		cin.ignore();
	}

	cout << "현재 귀하가 보유하고 있는 자동차 목록은 다음과 같습니다." << endl;

	for (int i = 0; i < n; i++)
	{
		cout << CAR[i].yesr << "년형 " << CAR[i].name << endl;
	}
}

void Q8()
{
	char words[30];
	int count = 0;
	while (strcmp(words, "done") != 0)
	{
		count++;
		cin >> words;
	}

	cout << "총 " << --count << "단어가 입력되었습니다." << endl;
}

int main()
{
	Q7();

	cout << endl;

	Q8();
}