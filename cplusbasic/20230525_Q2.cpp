/*
Q2. p.129 �������� 3,5,7

*/
#include <iostream>
using namespace std;

int main()
{
	/* 
	// 3�� ����
	int dau, bun, cho;

	cout << "����, ������ �Է��Ͻÿ� : ";
	cin >> dau;
	cout << "������, �а��� �Է��Ͻÿ� : ";
	cin >> bun;
	cout << "������, �ʰ� �Է��Ͻÿ� : ";
	cin >> cho;

	double wee = dau + (double)bun / 60 + (double)cho / (60 * 60);

	cout << dau << "��, " << bun << "��, " << cho << "�� = " << wee << "��" << endl;

	// 7�� ����
	long long world;
	long long Iceland;

	cout << "���� �α� ���� �Է��Ͻÿ� : ";
	cin >> world;
	cout << "���̽������� �α����� �Է��Ͻÿ� : ";
	cin >> Iceland;
	double per =  (double)Iceland / world * 100 ;

	cout << "���� �α����߿��� ���̽����尡 �����ϴ� ������ " << per << "%�̴�." << endl;
	*/

	// 9�� ����
	double europe;
	double america;

	cout << "�ֹ��� �Һ��� �Է��ϼ���(100ų�ι��ʹ� ���� ��) : ____ ����\b\b\b\b\b\b\b\b\b";
	cin >> europe;

	double gallon = europe/ 3.875;

	america = 62.14 / gallon;

	cout << "������Ÿ��(����/�Ÿ�) = " << europe << "liters/100km �̱���Ÿ��(�Ÿ�/����) = " << america << "mpg" <<endl;
}