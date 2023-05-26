
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

struct CandyBar
{
	char name[50];
	double weight;
	int calorie;
};

int main()
{
	int number = 3;

	CandyBar* snack = new CandyBar[number];

	snack[0] = { "Mocha Munch", 2.3, 350 };
	snack[1] = { "Èñ¿µÄµµð¹Ù", 4.9, 200 };
	snack[2] = { "ToyStroy Rex",9.1, 490 };

	for (int i = 0; i < number; i++)
	{
		cout << i + 1 << endl;
		cout << "Äµµð¹ÙÀÇ »óÇ¥¸í : " << snack[i].name << endl;
		cout << "Äµµð¹ÙÀÇ Áß·® : " << snack[i].weight << endl;
		cout << "Äµµð¹Ù¿¡ ÇÔÀ¯µÈ Ä®·Î¸® : " << snack[i].calorie << endl;
	}

}