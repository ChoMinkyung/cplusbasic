#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int ArSize = 8;
int sum_arr(const int* begin, const int* end);

unsigned int c_in_str(const char* str, char ch);

struct polar
{
	double distance;
	double angle;
};

struct rect
{
	double x;
	double y;
};

polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

const int Len = 66;
const int Divs = 6;

void subdivide(char ar[], int low, int high, int level);

const double* f1(const double ar[], int n);
const double* f2(const double[], int);
const double* f3(const double*, int);


int main()
{
	/*
	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };
	int sum = sum_arr(cookies, cookies + ArSize);
	cout << "먹은 과자 수 합계 : " << sum << endl;
	sum = sum_arr(cookies, cookies + 3);
	cout << "처음 세 사람은 과자 " << sum << "개를 먹었습니다." << endl;
	sum = sum_arr(cookies + 4, cookies + 8);
	cout << "마지막 네 사람은 과자 " << sum << "개를 먹었습니다.\n";
	return 0;

	char mmm[15] = "mininmum";
	const char* wail = "ululate";

	unsigned int ms = c_in_str(mmm, 'm');
	unsigned int us = c_in_str(wail, 'u');

	cout << mmm << "에는 m이 " << ms << "개 들어 있습니다.\n";
	cout << wail << "에는 u가 " << us << "개 들어 있습니다.\n";

	rect rplace;
	polar pplace;

	cout << "x값과 y값을 입력하시오 : ";
	while (cin >> rplace.x >> rplace.y)
	{
		pplace = rect_to_polar(rplace);
		show_polar(pplace);
		cout << "x값과 y값을 입력하십시오 (끝내려면 q를 입력) : ";
	}

	cout << "프로그램을 종료합니다.\n";
	return 0;


	char ruler[Len];
	int i;
	for (i = 1; i < Len - 2; i++)
	{
		ruler[i] = ' ';
	}

	ruler[Len - 1] = '\0';
	int max = Len - 2;
	int min = 0;
	ruler[min] = ruler[max] = '|';
	cout << ruler << endl;
	for (i = 1; i <= Divs; i++)
	{
		subdivide(ruler, min, max, i);
		cout << ruler << endl;
		for (int j = 1; j < Len - 2; j++) ruler[j] = ' ';
	}
	return 0;
	*/

	double av[3] = { 1112.3, 1542.6, 2227.9 };

	const double* (*pl)(const double*, int) = f1;
	auto p2 = f2;
	cout << "함수 포인터 : \n";
	cout << "주소값\n";
	cout << (*pl)(av, 3) << ": " << *(*pl)(av, 3) << endl;
	cout << p2(av, 3) << ": " << *p2(av, 3) << endl;

	const double* (*pa[3])(const double*, int) = { f1, f2, f3 };
	auto pb = pa;

	cout << "\n함수 포인터를 원소로 가지는 배열 : \n";
	cout << "주소값\n";
	for (int i = 0; i < 3; i++)
	{
		cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl;
	}
	cout << "\n함수 포인터를 가리키는 포인터 : \n";
	cout << "주소값\n";
	for (int i = 0; i < 3; i++)
	{
		cout << pb[i](av, 3) << ": " << *pb[i](av, 3) << endl;
	}
	cout << "\n포인터를 원소로 가지는 배열을 가르키는 포인터 : \n";
	cout << "주소값\n";
	auto pc = &pa;

	cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl;
	const double* (*(*pd)[3])(const double*, int) = &pa;

	const double* pdb = (*pd)[1](av, 3);
	cout << pdb << ": " << *pdb << endl;

	cout << (*(*pd)[2])(av, 3) << ": " << *(*(*pd)[2])(av, 3) << endl;
	return 0;

}

const double* f1(const double* ar, int n)
{
	return ar;
}

const double* f2(const double ar[], int n)
{
	return ar + 1;
}

const double* f3(const double ar[], int n)
{
	return ar + 2;
}


void subdivide(char ar[], int low, int high, int level)
{
	if (level == 0)return;
	int mid = (high + low) / 2;
	ar[mid] = '|';
	subdivide(ar, low, mid, level - 1);
	subdivide(ar, mid, high, level - 1);

}

polar rect_to_polar(rect xypos)
{
	polar answer;
	answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
	answer.angle = atan2(xypos.y, xypos.x);
	return answer;
}

void show_polar(polar dapos)
{
	const double Rad_to_deg = 57.29577951;
	cout << "거리 = " << dapos.distance;
	cout << ", 각도 = " << dapos.angle * Rad_to_deg;
	cout << "도\n";
}

unsigned int c_in_str(const char* str, char ch)
{
	int count = 0;
	while (*str)
	{
		if (*str == ch)count++;
		str++;
	}
	return count;
}


int sum_arr(const int* begin, const int* end)
{
	const int* pt;
	int total = 0;

	for (pt = begin; pt != end; pt++)
		total = total + *pt;
	return total;
}