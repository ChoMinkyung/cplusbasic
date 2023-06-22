#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

int solution(int l, int* v);
bool check(int* road, int len);
void Print(int* road, int len);

int main()
{
	int l = 15;
	int v[7] = {15, 5, 3, 7, 9, 14, 0};

	int d = solution(l, v);

	if (d < 0)cout << "������ d�� �����ϴ�." << endl;
	else cout << "�ּ� d�� " << d << " �Դϴ�." << endl;
}

int solution(int l, int* v)
{
	int d = 1;

	int* road = new int(sizeof(int) * (l + 1));
	memset(road, 0, (l+1) * sizeof(int));

	while (1)
	{
		for (int i = 0; i < l; i++)
		{
			if (v[i] < 0) break;
			for (int j = -d; j <= d; j++)
			{
				cout << v[i] << " ";
				cout << j << endl;
				if (v[i] + j >= 0 && v[i] + j <= l)
				{
					cout << v[i] + j << " ����" << endl;
					road[v[i] + j] += 1;

				}
			}
		}
		Print(road, l);

		if (check(road, l)) return d;
		d++;
	}

	return -1;
}

bool check(int* road, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (road[i] == 0) return false;
		else if (road[i] == 1 && road[i + 1] == 1) return false;
	}

	return true;
}

void Print(int* road, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << road[i] << " ";
	}
	 
	cout << endl;
}