#include <iostream>
#include "stock10.h"

Stock::Stock(const string& co, long n, double pr)
{
	cout << "����Ʈ �����ڰ� ȣ��Ǿ����ϴ�." << endl;
	company = "no name";

	if (n < 0)
	{
		cout << "�ֽ� ���� ������ �� �� �����Ƿ�, " << company << " shares�� 0���� �����մϴ�.\n";
		shares = 0;
	}
	else shares = n;

	share_val = pr;
	set_tot();
}

void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		cout << "���� �ֽ� ���� ������ �� �� �����Ƿ�, " << "�ŷ��� ��ҵǾ����ϴ�.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();

	}
}

void Stock::sell(long num, double price)
{
	if (num < 0)
	{
		cout << "�ŵ� �ֽ� ���� ������ �� �� �����Ƿ�, " << "�ŷ��� ��ҵǾ����ϴ�.\n";
	}
	else if (num > shares)
	{
		cout << "���� �ֽĺ��� ���� �ֽ��� �ŵ��� �� �����Ƿ�, " << "�ŷ��� ��ҵǾ����ϴ�.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

void Stock::show()
{
	cout << "ȸ��� : " << company
		<< " �ֽ� �� :" << shares << endl
		<< " �ְ� : $" << share_val << " �ֽ� �� ��ġ : $" << total_val << endl;
}
