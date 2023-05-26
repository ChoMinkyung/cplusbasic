/*
Q2. p.129 연습문제 3,5,7

*/
#include <iostream>
using namespace std;

int main()
{
	/* 
	// 3번 문제
	int dau, bun, cho;

	cout << "먼저, 도각을 입력하시오 : ";
	cin >> dau;
	cout << "다음에, 분각을 입력하시오 : ";
	cin >> bun;
	cout << "끝으로, 초각 입력하시오 : ";
	cin >> cho;

	double wee = dau + (double)bun / 60 + (double)cho / (60 * 60);

	cout << dau << "도, " << bun << "분, " << cho << "초 = " << wee << "도" << endl;

	// 7번 문제
	long long world;
	long long Iceland;

	cout << "세계 인구 수를 입력하시오 : ";
	cin >> world;
	cout << "아이슬란드의 인구수를 입력하시오 : ";
	cin >> Iceland;
	double per =  (double)Iceland / world * 100 ;

	cout << "세계 인구수중에서 아이슬란드가 차지하는 비중은 " << per << "%이다." << endl;
	*/

	// 9번 문제
	double europe;
	double america;

	cout << "휘발유 소비량을 입력하세요(100킬로미터당 리터 수) : ____ 마일\b\b\b\b\b\b\b\b\b";
	cin >> europe;

	double gallon = europe/ 3.875;

	america = 62.14 / gallon;

	cout << "유럽스타일(연료/거리) = " << europe << "liters/100km 미국스타일(거리/연료) = " << america << "mpg" <<endl;
}