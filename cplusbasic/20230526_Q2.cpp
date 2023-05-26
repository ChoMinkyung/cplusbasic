#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

int sum(int n);

int main()
{
	int n;

	cin >> n;

	cout << sum(n) << endl;

}

int sum(int n)
{
	return (1 + n) * n / 2;
}