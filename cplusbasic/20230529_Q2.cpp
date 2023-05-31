#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	char word[30];
	cin >> word;
	
	bool circular = true;

	int len = strlen(word);

	for (int i = 0; i < len/2; i++)
	{
		if (word[i] != word[len - i-1])
		{
			circular = false;
			break;
		}
	}
	cout << word << "은/는 회문";
	if (circular) cout << "입니다." << endl;
	else cout << "이 아닙니다." << endl;
}