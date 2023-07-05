#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include "20230619_Q1_StopWatch.h"

using namespace std;
StopWatch sw;

vector <int> Solution(const int(*relation)[2], int N);
int CountFriend(vector<vector<int>> depth, int N, int me, int myFriend);

int main()
{
	const int N = 5;
	//const int relation[10][2] = { {1,2} , {1, 3 }, {2, 4}, {4, 5} };
	int relation[10][2] = { {1,2} , {1, 3 }, {2, 4}, {4, 5} };

	vector <int> friend_array;
	sw.start();
	friend_array = Solution(relation, N);
	sw.stop();

	for (int i = 0; i < N; i++)
	{
		cout << i + 1 << "의 친구 수 : " << friend_array[i] << endl;
	}

	cout << "소요 시간 : " << (double)(sw.getEnd() - sw.getStart()) / CLOCKS_PER_SEC << "s" << endl;
	cout << "소요 시간 : " << sw.getElapsedTime() << "ms" << endl << endl;
}

vector<int> Solution(const int(*relation)[2], const int N)
{
	vector <int> friend_array;

	vector <vector<int>> depth;
	vector <int> temp_friend;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				if (relation[j][k] == i)
				{
					temp_friend.push_back(relation[j][1 - k]);
				}
			}
		}
		depth.push_back(temp_friend);
		temp_friend.clear();
	}

	/*for (int i = 0; i < depth.size(); ++i) {
		const vector<int>& row = depth[i];
		cout << i + 1 << "의 친구 : ";
		for (int j = 0; j < row.size(); ++j) {
			cout << depth[i][j] << " ";
		}
		cout << endl;
	}*/


	for (int i = 0; i < N; i++)
	{
		int n = 0;
		n += depth[i].size();
		for (int j = 0; j < depth[i].size(); j++)
			n += CountFriend(depth, N, depth[i][j], i + 1);
		friend_array.push_back(n);
	}

	return friend_array;
}

int CountFriend(vector<vector<int>> depth, int N, int me, int myFriend)
{
	int n = 0;
	for (int i = 0; i < depth[me-1].size(); i++)
	{
		if (depth[me-1][i] != myFriend) n++;
	}

	return n;
}