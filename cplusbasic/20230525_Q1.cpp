/*

Q1. p.129 �������� 1.

*/
#include <iostream>
using namespace std;

int main()
{
	int height;
	cout << "Ű�� �Է��ϼ��� :  ___ cm\b\b\b\b\b\b";
	cin >> height;

	if (height > 99)
	{
		const double m_height = height / 100;
		const double c_height = height % 100;

		if (c_height > 0) cout << "Ű�� " << height << "cm, " << m_height << "m " << c_height << "cm �Դϴ�.";
		else  cout << "Ű�� " << height << "cm, " << m_height << "m �Դϴ�.";

	}
	else  cout << "Ű�� " << height << "cm �Դϴ�.";

	cout << endl;

}