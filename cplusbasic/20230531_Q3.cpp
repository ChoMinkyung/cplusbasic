#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int strsize = 60;

void printMenu();
void memberRegister();
int readMember();
void read(int pre);


struct bop
{
	char fullname[strsize];
	char title[strsize];
	char bopname[strsize];
	int prefernece;
};

bop BOP_member[30];

int main()
{
	printMenu();

	char menu;
	int pre;
	bool start = true;

	while (start)
	{
		cout << "���ϴ� �޴��� �����ϼ��� : ";
		cin >> menu;

		switch (menu)
		{
		case 'a':
			memberRegister();
			break;
		case 'b':
			read(0);
			break;
		case 'c':
			read(1);
			break;
		case 'd':
			read(2);
			break;
		case 'e':
			read(100);
			break;
		case 'q':
			start = false;
			break;
			
		}

	}

	cout << "���α׷��� ����Ǿ����ϴ�.";


}

void printMenu()
{
	cout << "Benevolent Order of Programmers" << endl;

	cout.width(30);
	cout << left << "a. ȸ�� ���";

	cout.width(30);
	cout << "b. �Ǹ����� ����" << endl;

	cout.width(30);
	cout << left << "c. �������� ����";

	cout.width(30);
	cout << "d. BOP ���̵�� ����" << endl;

	cout.width(30);
	cout << left << "e. ȸ���� ������ ������ ����";

	cout.width(30);
	cout << "q. ����" << endl;
}

void memberRegister()
{
	bop BOP;

	ofstream bop_member;

	bop_member.open("bop_member.txt", ios::app);

	cin.ignore();
	cout << "�̸��� �Է��ϼ��� : ";
	cin.getline(BOP.fullname, strsize);
	cout << "������ �Է��ϼ��� : ";
	cin.getline(BOP.title, strsize);
	cout << "BOP ���̵� �Է��ϼ��� : ";
	cin.getline(BOP.bopname, strsize);
	cout << "preference�� �Է��ϼ��� : ";
	cin >> BOP.prefernece;

	bop_member << BOP.fullname << " ";
	bop_member << BOP.title << " ";
	bop_member << BOP.bopname << " ";
	bop_member << BOP.prefernece << endl;

	bop_member.close();
	
}

int readMember()
{
	ifstream inFile;
	inFile.open("bop_member.txt");
	if (!inFile.is_open())
	{
		cout << "������ �� �� �����ϴ�." << endl;
		cout << "���α׷��� �����մϴ�.\n";
		exit(EXIT_FAILURE);
	}

	int count = 0;

	while (inFile.good())
	{
		inFile >> BOP_member[count].fullname;
		inFile >> BOP_member[count].title;
		inFile >> BOP_member[count].bopname;
		inFile >> BOP_member[count].prefernece;

		count++;
	}

	return --count;
}

void read(int pre)
{
	ifstream inFile;

	int count = readMember();

	if (pre == 0)
	{
		for (int i = 0; i < count; i++)
		{
			cout << BOP_member[i].fullname << endl;
		}
	}
	else if(pre==1)
	{
		for (int i = 0; i < count; i++)
		{
			cout << BOP_member[i].title << endl;
		}
	}
	else if (pre == 2)
	{
		for (int i = 0; i < count; i++)
		{
			cout << BOP_member[i].bopname << endl;
		}
	}
	else
	{
		for (int i = 0; i < count; i++)
		{
			if(BOP_member[i].prefernece==0) cout << BOP_member[i].fullname << endl;
			else if(BOP_member[i].prefernece==1) cout << BOP_member[i].title << endl;
			else if(BOP_member[i].prefernece==2) cout << BOP_member[i].bopname << endl;
		}
	}

	cout << "�� " << count << "�� �����Ǿ����ϴ�." << endl;
}