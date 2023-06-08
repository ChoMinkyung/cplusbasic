#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
using namespace std;


// �� ó�� ��� base, ����� �� nmemb, ũ�� size, key ����Ű�� ��
void* bsearchx(const void* key, const void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*));

int compar(const void*, const void*);

int main()
{
	int arr_size;
	int key;
	int* key_exist;

	cout << "�迭�� ũ�⸦ �Է��ϼ��� : ";
	cin >> arr_size;
	int* arr = new int[arr_size];

	cout << "������������ �迭�� �Է��ϼ���" << endl;
	cout << "index 0 : ";
	cin >> arr[0];
	for (int i = 1; i < arr_size; i++)
	{
		do // ������������ �Է¹ޱ�
		{
			cout << "index " << i << " : ";

			cin >> arr[i];
		} while (arr[i-1] > arr[i]);
	}

	for (int i = 0; i < arr_size; i++)
	{
		cout << arr[i] << " ";
	}
	
	cout << endl << "ã�� ��Ҹ� �Է��ϼ��� : ";
	cin >> key;

	key_exist = (int*)bsearchx(&key, arr, arr_size, sizeof(int), (int(*)(const void*, const void*))compar);

	if (key_exist == NULL) cout << "ã�� ��Ұ� �����ϴ�." << endl;
	else cout << key << "�� arr[" << (int)(key_exist - arr) << "]�� �ֽ��ϴ�." << endl;

	delete[] arr;
}

int compar(const void* a, const void* b)
{
	if (*(int*)a < *(int*)b) return -1;
	else if (*(int*)a > *(int*)b) return 1;
	else return 0;
}

void* bsearchx(const void* key, const void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*))
{
	const int* arr_element = static_cast<const int*>(base);
	const int* key_element = static_cast<const int*>(key);

	while (1)
	{
		if ((*compar)(&arr_element[nmemb / 2], key_element) == 0)
		{
			for (int i = nmemb/2; i >= 0; i--)
			{
				if (arr_element[i] != arr_element[i - 1])return (void*)&arr_element[i];
			}
		}
		else if ((*compar)(&arr_element[nmemb / 2], key_element) > 0) nmemb = nmemb / 2;
		else arr_element = arr_element + (&arr_element[nmemb] - arr_element) / 2;
	}

	return NULL;
}