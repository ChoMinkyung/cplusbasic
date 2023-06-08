#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
using namespace std;


// 맨 처음 요소 base, 요소의 수 nmemb, 크기 size, key 가르키는 값
void* bsearchx(const void* key, const void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*));

int compar(const void*, const void*);

int main()
{
	int arr_size;
	int key;
	int* key_exist;

	cout << "배열의 크기를 입력하세요 : ";
	cin >> arr_size;
	int* arr = new int[arr_size];

	cout << "오름차순으로 배열을 입력하세요" << endl;
	cout << "index 0 : ";
	cin >> arr[0];
	for (int i = 1; i < arr_size; i++)
	{
		do // 오름차순으로 입력받기
		{
			cout << "index " << i << " : ";

			cin >> arr[i];
		} while (arr[i-1] > arr[i]);
	}

	for (int i = 0; i < arr_size; i++)
	{
		cout << arr[i] << " ";
	}
	
	cout << endl << "찾을 요소를 입력하세요 : ";
	cin >> key;

	key_exist = (int*)bsearchx(&key, arr, arr_size, sizeof(int), (int(*)(const void*, const void*))compar);

	if (key_exist == NULL) cout << "찾는 요소가 없습니다." << endl;
	else cout << key << "는 arr[" << (int)(key_exist - arr) << "]에 있습니다." << endl;

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