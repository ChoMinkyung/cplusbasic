#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	// 0:´ÝÈû, 1:¿­¸²
	int locker[100] = { 0 };

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if ((j + 1) % (i + 1) == 0)
			{
				if (locker[j] == 0)locker[j] = 1;
				else locker[j] = 0;
			}
		}
	}

	for (int i = 0; i < 100; i++)
	{
		if (locker[i] == 1) cout << i+1 << " ";
	}
	cout << endl;
}