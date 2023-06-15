#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


// players_len�� �迭 players�� �����Դϴ�.
// callings_len�� �迭 callings�� �����Դϴ�.
// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
char** solution(const char* players[], size_t players_len, const char* callings[], size_t callings_len) {
	// return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
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
	cout << endl << repeat_count << "��°" << endl;
	double x = 0;
	// 1�� ã�´�.
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

	cout << "������ ? " << !st[1].IsFull() << " " << !st[2].IsFull() << endl;

	if (!st[1].IsFull() && !st[2].IsFull()) TowerOfHanoi(number_1, loc_1, st);

}