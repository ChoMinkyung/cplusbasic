#include <iostream>
#include <string>
#include <vector>

using namespace std;

string calculator(string input);
bool result(vector<string>& numberList, vector<bool>& sign, char op);

int main()
{
	string input = "3+5*7-6/2+1";
	string output = calculator(input);

	while (stoi(input) != 0)
	{
		cout << "계산 식을 입력하세요. (0입력시 종료)" << endl;
		cout << ": ";
		cin >> input;
		output = calculator(input);
		cout << input << " = " << output << endl;
	}
	cout << "종료되었습니다." << endl;
}

string calculator(string input)
{
	vector<string> numberList;
	vector<char> operatorList;
	vector<bool> sign;
	int midResult;
	string number;
	// 우선순위 '*' =  '/' >  '+', '-'

	while (true)
	{
		//숫자일때
		if (input[0] >= 48 && input[0] <= 57)
		{
			number.push_back(input[0]);
			if (input[0] >= 0) sign.push_back(true);
			else sign.push_back(false);
		}
		else // 문자일때
		{
			numberList.push_back(number);
			number.clear();
			for (int i = operatorList.size() - 1; i >= 0; i--)
			{
				if (input[0] == '*' || input[0] == '/')
				{
					if (operatorList[i] == '*' || operatorList[i] == '/')
					{
						midResult = result(numberList, sign, operatorList[i]);
						if (!midResult) return "Impossible";
						else operatorList.pop_back();
					}

				}

				if (input[0] == '+' || input[0] == '-')
				{
					midResult = result(numberList, sign, operatorList[i]);
					if (!midResult) return "Impossible";
					else operatorList.pop_back();

				}

			}

			operatorList.push_back(input[0]);
		}

		input.erase(input.begin());

		if (input.empty())
		{
			numberList.push_back(number);
			number.clear();
			while (!operatorList.empty())
			{
				midResult = result(numberList, sign, operatorList[operatorList.size() - 1]);
				if (!midResult) return "Impossible";
				else operatorList.pop_back();

			}
			break;
		}

	}

	int outputNumber = stoi(numberList[0]);
	if (!sign[0]) outputNumber *= -1;

	string output;
	output = to_string(outputNumber);

	return output;
}

bool result(vector<string>& numberList, vector<bool>& sign, char op)
{

	int midResult = 0;

	int a = stoi(numberList[numberList.size() - 2]);
	int b = stoi(numberList[numberList.size() - 1]);

	if (!sign[sign.size() - 2]) a *= -1;
	if (!sign[sign.size() - 1]) b *= -1;

	if (op == '*') midResult = a * b;
	if (op == '/')
	{
		if (b == 0) return false;
		midResult = a / b;
	}
	if (op == '+') midResult = a + b;
	if (op == '-') midResult = a - b;


	numberList.pop_back();
	numberList.pop_back();
	sign.pop_back();
	sign.pop_back();

	if (midResult < 0)
	{
		midResult *= -1;
		sign.push_back(false);
	}
	else sign.push_back(true);

	numberList.push_back(to_string(midResult));

	return true;
}