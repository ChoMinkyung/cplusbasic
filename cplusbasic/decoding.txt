#include <iostream>
using namespace std;

int max4(int a, int b, int c, int d);

int main()
{
	int max = max4(9, 3, 5, 2);
	cout << "max = " << max << endl;
}

int max4(int a, int b, int c, int d)
{
	int max = a;
	
	if (max < b) max = b;
	if (max < c) max = c;
	if (max < d) max = d;
	
	return max;
}