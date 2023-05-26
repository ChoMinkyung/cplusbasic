/*

Q1. p.129 연습문제 1.

*/
#include <iostream>
using namespace std;

int main()
{
	int height;
	cout << "키를 입력하세요 :  ___ cm\b\b\b\b\b\b";
	cin >> height;

	if (height > 99)
	{
		const double m_height = height / 100;
		const double c_height = height % 100;

		if (c_height > 0) cout << "키는 " << height << "cm, " << m_height << "m " << c_height << "cm 입니다.";
		else  cout << "키는 " << height << "cm, " << m_height << "m 입니다.";

	}
	else  cout << "키는 " << height << "cm 입니다.";

	cout << endl;

}