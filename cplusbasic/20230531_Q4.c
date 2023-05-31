#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t=x; x=y; y=t;}while(0)

void ary_reverse(int a[], int n)
{
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", a[j]);
		}
		printf("\na[%d]�� a[%d]�� ��ȯ�մϴ�.", i, n - i - 1);
		swap(int, a[i], a[n - i - 1]);
		printf("\n");
	}
}

int main()
{
	int nx;
	printf("��� ���� : ");
	scanf("%d", &nx);
	int* x = malloc(sizeof(int) * nx);

	for (int i = 0; i < nx; i++)
	{
		printf("x[%d]: ", i);
		scanf("%d", &x[i]);
	}

	ary_reverse(x, nx);

	for (int i = 0; i < nx; i++)
	{
		printf("%d ",x[i]);
	}
	printf("\n���� ������ �����մϴ�.\n");
	free(x);

	return 0;
}