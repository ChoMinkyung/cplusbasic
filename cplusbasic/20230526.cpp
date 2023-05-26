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

	cout << "이름을 입력하시오 : \n";
	cin >> name;
	cout << "좋아하는 디저트를 입력하십시오:\n";
	cin >> dessert;
	cout << "맛있는 " << dessert << " 디저트를 준비하겠습니다. " << name << " 님!\n";

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

	cout << "string 객체를 string 객체에 대입할 수 있다 : s2 = s1\n";
	s2 = s1;
	cout << "s1: " << s1 << " s2: " << s2 << endl;
	cout << "string 객체에 c 스타일 문자열을 대입할 수 있다.\n";
	cout << "s2= \"buzzard\"\n";
	s2 = " buzzard";
	cout << "s2: " << s2 << endl;
	cout << "string 객체들을 결합할 수 있다 : s3=s1+s2\n";
	s3 = s1 + s2;
	cout << "s3: " << s3 << endl;
	cout << "string 객체들을 추가할 수 있다.\n";
	s1 += s2;
	cout << "s1 += s2 --> s1 = " << s1 << endl;
	s2 += " for a day";
	cout << "s2 +=\"for a day\" --> s2 = " << s2 << endl;




	double* p3 = new double[3];

	p3[0] = 0.2;
	p3[1] = 0.5;
	p3[2] = 0.8;

	cout << "p3[1]은 " << p3[1] << "입니다.\n";
	p3 = p3 + 1;

	cout << "이제는 p3[0]이 " << p3[0] << "이고, ";
	cout << "p3[1]이 " << p3[1] << "입니다.\n";
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
	cout << "pw 포인터에 1을 더함:\n";
	cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";

	cout << "ps = " << ps << ", *ps = " << *ps << endl;
	ps = ps + 1;
	cout << "ps 포인터에 1을 더함:\n";
	cout << "ps = " << ps << ", *ps = " << *ps << endl;

	cout << "배열 표기로 두 원소에 접근\n";
	cout << "stacks[0] = " << stacks[0] << ", stacks[1] = " << stacks[1] << endl;

	cout << "포인터 표기로 두 원소에 접근\n";
	cout << "*stacks = " << *stacks << ", *(stacks+1) = " << *(stacks + 1) << endl;

	cout << sizeof(wages) << " = wages 배열의 크기\n";
	cout << sizeof(pw) << " = pw 포인터의 크기\n";

	*/

	char animal[20] = "bear";
	const char* bird = "wren";
	char* ps;

	cout << animal << " and ";
	cout << bird << "\n";
	//cout << ps << "\n"; // 쓰레기 출력 혹은 먹통

	cout << "동물의 종류를 입력하십시오 : ";
	cin >> animal;
	///cin >> ps; //절대로 해서는 안되는 엄청난 실수다

	ps = animal;
	cout << ps << "s!\n";
	cout << "strcpy() 사용 전:\n";
	cout << (int*)animal << ": " << animal << endl;
	cout << (int*)ps << ": " << ps << endl;

	ps = new char[strlen(animal) + 1];
	strcpy(ps, animal);
	cout << "strcpy() 사용 후:\n";
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