#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	/*
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "�̸��� �Է��Ͻÿ� : \n";
	cin >> name;
	cout << "�����ϴ� ����Ʈ�� �Է��Ͻʽÿ�:\n";
	cin >> dessert;
	cout << "���ִ� " << dessert << " ����Ʈ�� �غ��ϰڽ��ϴ�. " << name << " ��!\n";

	char name[40];

	cin.get(name, 5);
	cout << name << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get(name, 5);
	cout << name << endl;


	const int len = 10;
	int* name = (int *)malloc(sizeof(int) * len);

	const int len2 = 10;
	int name2[len2];

	string s1 = "penguin";
	string s2, s3;

	cout << "string ��ü�� string ��ü�� ������ �� �ִ� : s2 = s1\n";
	s2 = s1;
	cout << "s1: " << s1 << " s2: " << s2 << endl;
	cout << "string ��ü�� c ��Ÿ�� ���ڿ��� ������ �� �ִ�.\n";
	cout << "s2= \"buzzard\"\n";
	s2 = " buzzard";
	cout << "s2: " << s2 << endl;
	cout << "string ��ü���� ������ �� �ִ� : s3=s1+s2\n";
	s3 = s1 + s2;
	cout << "s3: " << s3 << endl;
	cout << "string ��ü���� �߰��� �� �ִ�.\n";
	s1 += s2;
	cout << "s1 += s2 --> s1 = " << s1 << endl;
	s2 += " for a day";
	cout << "s2 +=\"for a day\" --> s2 = " << s2 << endl;




	double* p3 = new double[3];

	p3[0] = 0.2;
	p3[1] = 0.5;
	p3[2] = 0.8;

	cout << "p3[1]�� " << p3[1] << "�Դϴ�.\n";
	p3 = p3 + 1;

	cout << "������ p3[0]�� " << p3[0] << "�̰�, ";
	cout << "p3[1]�� " << p3[1] << "�Դϴ�.\n";
	p3 = p3 - 1;

	delete[] p3;


	const int len = 10;
	int* name = (int*)malloc(sizeof(int) * len);
	free(name);

	const int len2 = 10;
	int name2[len2];

	int len4;
	cin >> len4;
	int* name = new int[len4];
	delete[] name;

	int len3 = 10;
	//cin >> len3;
	int name3[len3];

	double wages[3] = { 10000.0, 20000.0, 30000.0 };
	short stacks[3] = { 3,2,1 };

	double* pw = wages;
	short* ps = &stacks[0];

	cout << "pw = " << pw << ", *pw = " << *pw << endl;
	pw = pw + 1;
	cout << "pw �����Ϳ� 1�� ����:\n";
	cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";

	cout << "ps = " << ps << ", *ps = " << *ps << endl;
	ps = ps + 1;
	cout << "ps �����Ϳ� 1�� ����:\n";
	cout << "ps = " << ps << ", *ps = " << *ps << endl;

	cout << "�迭 ǥ��� �� ���ҿ� ����\n";
	cout << "stacks[0] = " << stacks[0] << ", stacks[1] = " << stacks[1] << endl;

	cout << "������ ǥ��� �� ���ҿ� ����\n";
	cout << "*stacks = " << *stacks << ", *(stacks+1) = " << *(stacks + 1) << endl;

	cout << sizeof(wages) << " = wages �迭�� ũ��\n";
	cout << sizeof(pw) << " = pw �������� ũ��\n";

	*/

	char animal[20] = "bear";
	const char* bird = "wren";
	char* ps;

	cout << animal << " and ";
	cout << bird << "\n";
	//cout << ps << "\n"; // ������ ��� Ȥ�� ����

	cout << "������ ������ �Է��Ͻʽÿ� : ";
	cin >> animal;
	///cin >> ps; //����� �ؼ��� �ȵǴ� ��û�� �Ǽ���

	ps = animal;
	cout << ps << "s!\n";
	cout << "strcpy() ��� ��:\n";
	cout << (int*)animal << ": " << animal << endl;
	cout << (int*)ps << ": " << ps << endl;

	ps = new char[strlen(animal) + 1];
	strcpy(ps, animal);
	cout << "strcpy() ��� ��:\n";
	cout << (int*)animal << ": " << animal << endl;
	cout << (int*)ps << ": " << ps << endl;
	delete[] ps;




	return 0;
}

/*

#include <stdlib.h>
#include <crtdbg.h>
int main()
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF );
	_CrtSetBreakAlloc(154);
	int* arr = NULL;
	arr = (int*)malloc(sizeof(int) * 4);
	_CrtDumpMemoryLeaks();
	return 0;
}
*/