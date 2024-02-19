#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void InsertInput(string testCaseStr, vector<vector<int>>& testcase, int L, int index);
int CountOne(int num);
int Compare(vector<vector<int>>& testcase, int L);

int main()
{
    int T; // test case line
    int L; // number of bytes
    vector<int> result;

   
    cin >> T;
    

    for (int i = 0; i < T; i++)
    {
        cin >> L;
        vector<vector<int>> testCase(3);

        for (int j = 0; j < 3; j++)
        {
            string testCaseStr;
            cin >> testCaseStr;
            InsertInput(testCaseStr, testCase, L, j);
        }

        result.push_back(Compare(testCase, L));
    }

    for (int i = 0; i < T; i++)
    {
        cout << result[i] << endl;
    }

}

void InsertInput(string testCaseStr, vector<vector<int>>& testcase, int L, int index)
{
    int num = 0;
    for (int i = 0; i < testCaseStr.length(); i++)
    {
        if (testCaseStr[i] != '-')
        {
            num *= 10;
            num += testCaseStr[i] - '0';
        }
        else
        {
            testcase[index].push_back(num);
            num = 0;
        }
    }

    testcase[index].push_back(num);
}

int CountOne(int num)
{
    int binary = 0;
    int digits = 0;
    while (num != 0)
    {
        if (num % 2 == 1)
        {
            binary++;
        }

        num /= 2;
    }


    return binary;
}

int Compare(vector<vector<int>>& testcase, int L)
{
    int compare;
    int count = 0;

    for (int i = 0; i < L; i++)
    {
        compare = (testcase[0][i] ^ testcase[1][i]) | (testcase[1][i] ^ testcase[2][i]);
        count += CountOne(compare);
    }

    return count;
}