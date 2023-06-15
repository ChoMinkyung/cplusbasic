#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


// players_len은 배열 players의 길이입니다.
// callings_len은 배열 callings의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* players[], size_t players_len, const char* callings[], size_t callings_len) {
	// return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
	char** answer = (char**)malloc(players_len + 1);
	answer = players;
	
	for (int i = 0; i < callings_len; i++)
	{
		char *temp[10];
		for (int j = 1; j < players_len; j++)
		{
			if (strcmp(callings[i],answer[j])==0)
			{
				*temp = answer[j];
				answer[j] = answer[j - 1];
				answer[j - 1]= *temp;
				break;
			}
		}
		
	}
	return answer;
}

int main()
{
	const char* players[] = { "mumu", "soe", "poe", "kai", "mine" };
	const char* callings[] = { "kai", "kai", "mine", "mine" };

	char** answer = solution(players, 5, callings, 4);

	for (int k = 0; k < 5; k++)
	{
		printf("%s ", answer[k]);

	}
	printf("\n");
}

void TowerOfHanoi(bool number_1, int loc_1, Stack* st)
{
	repeat_count++;
	cout << endl << repeat_count << "번째" << endl;
	double x = 0;
	// 1을 찾는다.
	if (number_1)
	{
		if (loc_1 == 0)
		{
			st[2].Pop(&x);
			st[loc_1].Push(x);
			loc_1++;
		}
		else if (loc_1 == 1)
		{
			st[0].Pop(&x);
			st[loc_1].Push(x);
			loc_1++;
		}
		else if (loc_1 == 2)
		{
			st[1].Pop(&x);
			st[loc_1].Push(x);
			loc_1 = 0;
		}

		/*
		for (int i = 0; i < 3; i++)
		{
			st[i].Peek(&x);
			if (!st[i].IsEmpty() && x == 1)
			{
				st[i].Pop(&x);
				st[loc_1].Push(x);
				break;
			}
		}
		if (loc_1 == 2) loc_1 = 0;
		else loc_1++;
		*/
	}
	else
	{
		double min = 100;
		int loc = 0;
		double temp = 0;
		for (int i = 0; i < 3; i++)
		{
			st[i].Peek(&x);
			if (x != 1 && x < min && !st[i].IsEmpty())
			{
				loc = i;
				min = x;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			st[i].Peek(&temp);
			if (temp > min || st[i].IsEmpty()) st[i].Push(min);
		}
		st[loc].Pop(&x);
	}

	Print(&st);

	number_1 = number_1 ? false : true;

	cout << "가득참 ? " << !st[1].IsFull() << " " << !st[2].IsFull() << endl;

	if (!st[1].IsFull() && !st[2].IsFull()) TowerOfHanoi(number_1, loc_1, st);

}