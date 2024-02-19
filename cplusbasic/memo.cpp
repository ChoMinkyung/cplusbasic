#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string s = "-1 -2 -3 -4";
	string answer = "";
	int max = INT_MIN;
	int min = INT_MAX;
	int digit = 1;
	int compare = 0;
	while (!s.empty())
	{
		if (s[s.size() - 1] >= '0' && s[s.size() - 1] <= '9')
		{
			compare = compare + pow((int)(s[s.size() - 1] - '0'),digit);
			digit++;
		}
		else if (s[s.size() - 1] >= '-') compare *= -1;
		else
		{
			if (max < compare) max = compare;
			if (min > compare) min = compare;

			compare = 0;
			digit = 1;
		}
		s.pop_back();

		if (s.empty())
		{
			if (max < compare) max = compare;
			if (min > compare) min = compare;
		}
	}

	answer = to_string(min);
	answer.push_back(' ');
	answer += to_string(max);

	cout << answer << endl;
}

