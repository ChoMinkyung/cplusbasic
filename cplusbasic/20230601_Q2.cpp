#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	char password[30];
	bool password_invalid = false;
	while (!password_invalid)
	{
		int n_count = 0;
		password_invalid = true;
		
		cout << "비밀번호를 입력하세요 : ";

		cin.getline(password, 30);

		if (strlen(password) < 8)
		{
			password_invalid = false;
		}

		for (int i = 0; i < strlen(password); i++)
		{
			if (!isalnum(password[i]))
			{
				password_invalid = false;
				break;
			}

			if (password[i] <= 57 || password[i] <= 48)
			{
				n_count++;
			}
		}


		if (n_count < 2)
		{
			password_invalid = false;
		}

		if(!password_invalid) cout << "Invalid password" << endl;

	}

	cout << "valid password" << endl;
}
