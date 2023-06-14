#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void reverseDisplay(int value);
void reverseDisplay(const string& s);

int main()
{
	reverseDisplay(12345);
	cout << endl;
	reverseDisplay("abcd");
}

void reverseDisplay(int value)
{
	cout << value % 10;
	if (value / 10 > 0)
	{
		reverseDisplay(value / 10);
	}

	return;
}

void reverseDisplay(const string& s)
{
	string sc = s;

	if (sc[0] != '\0')
	{
		cout << sc[sc.length() - 1];
		sc.resize(sc.length() - 1);
		reverseDisplay(sc);
	}

	return;
}