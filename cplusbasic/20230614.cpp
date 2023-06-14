#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#include "20230614_strngbad.h"

void callme1(StringBad&);
void callme2(StringBad);

int main()
{
	cout << endl;
	{
		cout << "내부 블록을 시작한다." << endl;
		StringBad headline1("Celery Stalks at Midnight");
		StringBad headline2("Lettuce Prey");
		StringBad sports("Spinach Leaves Bowl for Dollars");

		cout << "headline1: " << headline1 << endl;
		cout << "headline2: " << headline2 << endl;
		cout << "sprots: " << sports << endl;
	
		callme1(headline1);
		cout << "headline1: " << headline1 << endl;
		callme2(headline2);
		cout << "headline2: " << headline2 << endl;

		cout << "하나의 객체를 다른 객체로 초기화 : " << endl;
		StringBad sailor = sports;
		cout << "sailor : " << sailor << endl;

		cout << "하나의 객체를 다른 객체에 대입 : " << endl;
		StringBad knot;
		knot = headline1;
		cout << "knot: " << knot << endl;
		cout << "이 블록을 빠져나온다." << endl;

	}
	cout << "main()의 끝" << endl;
	return 0;
}

void callme1(StringBad& rsb)
{
	cout << "참조로 전달된 StringBad :\n";
	cout << "     \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
	cout << "값으로 전달된 StringBad :\n";
	cout << "     \"" << sb << "\"\n";
}