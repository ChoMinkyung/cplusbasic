#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <new>
using namespace std;

//#include "20230621_Tv.h"
//#include "20230621_queuetp.h"
#include "20230621_exc_mean.h"

double hmean(double a, double b) throw(bad_hmean);
double gmean(double a, double b) throw(bad_gmean);

struct Big
{
	double stuff[20000];
};

int main()
{
	/* "20230621_Tv.h"
	Tv s42;
	cout << "42\" TV�� �ʱ� ������ : \n";
	s42.settings();
	s42.onoff();
	s42.chanup();

	cout << "\n42\" TV�� ����� ������ : \n";
	s42.settings();

	Remote grey;

	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.volup(s42);
	cout << "\n������ ��� �� 42\" TV�� ������ : \n";
	s42.settings();

	Tv s58(Tv::On);
	s58.set_mode();
	grey.set_chan(s58, 28);
	cout << "\n58\" TV�� ������ : \n";
	s58.settings();


	//"20230621_queuetp.h"
	QueueTP<string> cs(5);
	string temp;

	while (!cs.isfull())
	{
		cout << "�̸��� �Է��Ͻʽÿ�. �����Ͻ� ������� ����ǰ�� �帳�ϴ�." << endl << "�̸� : ";
		getline(cin, temp);
		cs.enqueue(temp);
	}

	cout << "ť�� ���� á���Ƿ�, ���ݺ��� ����ǰ�� ������ �帮�ڽ��ϴ�." << endl;

	while (!cs.isempty())
	{
		cs.dequeue(temp);
		cout << temp << " ��! �����մϴ�. �ȳ��� ���ʽÿ�." << endl;
	}

	// p.1141
	double x, y, z;

	cout << "�� ���� �Է��Ͻʽÿ� : ";
	while (cin >> x >> y)
	{
		try
		{
			z = hmean(x, y);
		}
		catch (const char* s)
		{
			cout << s << endl;
			cout << "�� ���� ���� �Է��Ͻʽÿ� : ";
			continue;
		}
		cout << x << ", " << y << "�� ��ȭ����� " << z << "�Դϴ�.\n";
		cout << "�ٸ� �� ���� �Է��Ͻʽÿ� (�������� q): ";
	}
	cout << "���α׷��� �����մϴ�.\n";

	//"20230621_exc_mean.h"
	double x, y, z;
	cout << "�� ���� �Է��Ͻʽÿ� : ";
	while (cin >> x >> y)
	{
		try
		{
			z = hmean(x, y);
			cout << x << ", " << y << "�� ��ȭ����� " << z << "�Դϴ�.\n";
			cout << x << ", " << y << "�� ��������� " << gmean(x, y) << "�Դϴ�.\n";
			cout << "�ٸ� �� ���� �Է��Ͻʽÿ� (�������� q) : ";
		}
		catch (bad_hmean& bg)
		{
			bg.mesg();
			cout << "�ٽ� �Ͻʽÿ�.\n";
			continue;
		}
		catch (bad_gmean& hg)
		{
			cout << hg.mesg();
			cout << "Values used : " << hg.v1 << ", " << hg.v2 << endl;
			cout << "�˼��մϴ�. �� �̻� ������ �� �����ϴ�.\n";
			break;
		}
	}

	cout << "���α׷��� �����մϴ�.\n";

	// p. 1166

	Big* pb;
	try
	{
		cout << "ū �޸� ���� ������ ��û�ϰ� �ֽ��ϴ�.\n";
		pb = new Big[10000];
		cout << "�޸� ���� ���� ��û�� �źεǾ����ϴ�.\n";
	}
	catch (bad_alloc& ba)
	{
		cout << "���ܰ� �����Ǿ����ϴ�.\n";
		cout << ba.what() << endl;
		exit(EXIT_FAILURE);
	}
	cout << "�޸� ������ ���������� ���ԵǾ����ϴ�.\n";
	pb[0].stuff[0] = 4;
	cout << pb[0].stuff[0] << endl;
	delete[] pb;
	*/


}

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean(a, b);//"�߸��� hmean() �Ű����� : a=-b�� ������ �ʽ��ϴ�.";
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0) throw bad_gmean(a, b);
	return sqrt(a * b);
}