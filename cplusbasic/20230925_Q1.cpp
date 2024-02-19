#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int landSize = 2;
int** createBuilding(int row, int col);
int countBuilding(int** building, int row, int col, int land[landSize][landSize]);

int main()
{

	int answer = 0;

	int land[landSize][landSize] = { {0, 0}, {0, 1} };
	int buildingSize[] = { 1,2 };

	/*int land[landSize][landSize] = { {1, 0, 0, 1}, {0, 0, 0, 1},  {0, 0, 0, 1},  {0, 1, 0, 1} };
	int buildingSize[] = { 1,2 };*/

	/*int land[landSize][landSize] = { {1,0,0,0,1},{1,0,0,1,1},{0,0,0,0,0},{0,0,1,1,1},{0,0,0,0,0} };
	int buildingSize[] = { 1,3 };*/

	/*int land[landSize][landSize] = { {1,0,0,0,1},{1,0,0,1,1},{0,0,0,0,0},{0,0,1,1,1},{0,0,0,0,0} };
	int buildingSize[] = { 1,4 };*/

	int** building = createBuilding(buildingSize[0], buildingSize[1]);
	answer += countBuilding(building, buildingSize[0], buildingSize[1], land);

	if (buildingSize[0] != buildingSize[1])
	{
		building = createBuilding(buildingSize[1], buildingSize[0]);
		answer += countBuilding(building, buildingSize[1], buildingSize[0], land);
	}


	// 정답 출력
	cout << "land" << endl;

	for (int i = 0; i < landSize; i++)
	{
		for (int j = 0; j < landSize; j++)
		{
			cout << land[i][j] << " ";
		}
		cout << endl;
	}

	cout << "building : (" << buildingSize[0] << ", " << buildingSize[1] << ")" << endl;
	cout << "정답 : " << answer << endl;
}

int** createBuilding(int row, int col)
{
	int** building = new int* [row];

	for (int i = 0; i < row; i++) {
		building[i] = new int[col];
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			building[i][j] = 1;
		}
	}

	return building;
}

int countBuilding(int** building, int row, int col, int land[landSize][landSize])
{
	int result = 0;
	for (int i = 0; i <= landSize - row; i++)
	{
		for (int j = 0; j <= landSize - col; j++)
		{
			bool build = true;
			for (int buildingRow = 0; buildingRow < row; buildingRow++)
			{
				for (int buildingCol = 0; buildingCol < col; buildingCol++)
				{
					if (land[i + buildingRow][j + buildingCol] == building[buildingRow][buildingCol])
					{
						build = false;
					}
				}

			}
			if (build) result++;
		}
	}

	return result;
}