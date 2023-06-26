#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <memory>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <set>
#include <map>
#include <ctime>
using namespace std;

vector<int> Lotto(int range, int n);
void Show(int v);

int main()
{
	vector<int> winners;

	for (int i = 0; i < 5; i++)
	{
		winners = Lotto(45, 6);
		cout << (char)(i + 'A') << ": ";
		for_each(winners.begin(), winners.end(), Show);

		cout << endl;
	}

}

vector<int> Lotto(int range, int n)
{
	vector<int> num;
	for (int i = 1; i <= range; i++)
	{
		num.push_back(i);
	}

	srand(time(NULL)+rand());
	
	random_shuffle(num.begin(), num.end());

	vector<int> slice(num.begin(), num.begin() + n + 1);
	sort(slice.begin(), slice.end());

	return slice;
}

void Show(int v)
{
	cout << v << ' ';
}