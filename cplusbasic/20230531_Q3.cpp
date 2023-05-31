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
		cout << "원하는 메뉴를 선택하세요 : ";
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

	cout << "프로그램이 종료되었습니다.";


}

void printMenu()
{
	cout << "Benevolent Order of Programmers" << endl;

	cout.width(30);
	cout << left << "a. 회원 등록";

	cout.width(30);
	cout << "b. 실명으로 열람" << endl;

	cout.width(30);
	cout << left << "c. 직함으로 열람";

	cout.width(30);
	cout << "d. BOP 아이디로 열람" << endl;

	cout.width(30);
	cout << left << "e. 회원이 지정한 것으로 열람";

	cout.width(30);
	cout << "q. 종료" << endl;
}

void memberRegister()
{
	bop BOP;

	ofstream bop_member;

	bop_member.open("bop_member.txt", ios::app);

	cin.ignore();
	cout << "이름을 입력하세요 : ";
	cin.getline(BOP.fullname, strsize);
	cout << "직함을 입력하세요 : ";
	cin.getline(BOP.title, strsize);
	cout << "BOP 아이디를 입력하세요 : ";
	cin.getline(BOP.bopname, strsize);
	cout << "preference를 입력하세요 : ";
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
		cout << "파일을 열 수 없습니다." << endl;
		cout << "프로그램을 종료합니다.\n";
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

	cout << "총 " << count << "개 열람되었습니다." << endl;
}