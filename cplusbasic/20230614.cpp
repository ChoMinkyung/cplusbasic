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
		cout << "���� ����� �����Ѵ�." << endl;
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

		cout << "�ϳ��� ��ü�� �ٸ� ��ü�� �ʱ�ȭ : " << endl;
		StringBad sailor = sports;
		cout << "sailor : " << sailor << endl;

		cout << "�ϳ��� ��ü�� �ٸ� ��ü�� ���� : " << endl;
		StringBad knot;
		knot = headline1;
		cout << "knot: " << knot << endl;
		cout << "�� ����� �������´�." << endl;

	}
	cout << "main()�� ��" << endl;
	return 0;
}

void callme1(StringBad& rsb)
{
	cout << "������ ���޵� StringBad :\n";
	cout << "     \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
	cout << "������ ���޵� StringBad :\n";
	cout << "     \"" << sb << "\"\n";
}