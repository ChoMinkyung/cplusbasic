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