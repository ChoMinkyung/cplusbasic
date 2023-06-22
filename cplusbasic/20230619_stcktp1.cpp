#include "20230619_stcktp1.h"

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

const int Num = 10;

int main()
{
	srand(time(0));
	cout << "������ ũ�⸦ �Է��Ͻʽÿ� : ";
	int stacksize;
	cin >> stacksize;

	// �� ���� ����
	StackTp<const char*> st(stacksize);

	const char* in[Num] = {
		" 1: ���ȣ", " 2: �ָ���",
		" 3: �̸���", " 4: ������", 
		" 5: �̼���", "6: �ɼ���",
		" 7: �ڹ���", " 8: ȫ�浿", 
		" 9: �����", "10: �Ͼ߽�"
	};

	const char* out[Num];

	int processed = 0;
	int nextin = 0;
	while (processed < Num)
	{
		if (st.isempty()) st.push(in[nextin++]);
		else if (st.isfull()) st.pop(out[processed++]);
		else if (rand() % 2 && nextin < Num) st.push(in[nextin++]);
		else st.pop(out[processed++]);
	}

	for (int i = 0; i < Num; i++)
	{
		cout << out[i] << endl;
	}

	cout << "���α׷��� �����մϴ�." << endl;

}