#include "stdafx.h"

//Given an m x n matrix, return all elements of the matrix in spiral order.
// 
//
//Example 1:
//Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [1,2,3,6,9,8,7,4,5]
//
//Example 2:
//Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
//Output: [1,2,3,4,8,12,11,10,9,5,6,7]
// 
//Constraints:
//m == matrix.length
//n == matrix[i].length
//1 <= m, n <= 10
//-100 <= matrix[i][j] <= 100

namespace Solution2022
{
	namespace SpiralMatrix
	{

		vector<int> spiralOrder(vector<vector<int>>& M) {
			int rowCount = M.size();
			if (rowCount == 0) { return {}; }
			int colCount = M[0].size();
			if (colCount == 0) { return {}; }

			vector<int> result;
			vector<vector<int>> dirs = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
			vector<int> lens = { colCount, rowCount - 1 };
			int i = 0;
			int j = -1; // Note!!! Starting j at -1 position is going to save a bunch of code!!!
			int dirIndex = 0;
			while (lens[dirIndex % 2]) {
				for (int k = 0; k < lens[dirIndex % 2]; k++) {
					i += dirs[dirIndex][0];
					j += dirs[dirIndex][1];
					result.push_back(M[i][j]);
				}
				lens[dirIndex % 2]--;
				dirIndex = (dirIndex + 1) % 4;
			}
			return result;
		}

		namespace RemeberPrintedArea {
			bool isLegal(int x, int y, int rowCount, int colCount, vector<vector<bool>>& visited) {
				if (x < 0 || x >= rowCount || y < 0 || y >= colCount || visited[x][y]) { return false; }
				return true;
			}

			vector<int> spiralOrder(vector<vector<int>>& M) {
				int rowCount = M.size();
				if (rowCount == 0) { return {}; }
				int colCount = M[0].size();
				if (colCount == 0) { return {}; }

				vector<vector<bool>> visited(rowCount, vector<bool>(colCount, false));
				vector<vector<int>> dirs = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

				vector<int> result;
				int i = 0;
				int j = -1;
				int total = 0;
				int dirIndex = 0;
				while (total < rowCount * colCount) {
					int x = dirs[dirIndex][0];
					int y = dirs[dirIndex][1];
					if (isLegal(i + x, j + y, rowCount, colCount, visited)) {
						i += x; j += y;
						total++;
						result.push_back(M[i][j]);
						visited[i][j] = true;
					}
					else {
						dirIndex = (dirIndex + 1) % 4;
					}
				}
				return result;
			}
		}



		void Main() {
			//vector<vector<int>> test = { {1,2,3},{4,5,6},{7,8,9} };
			vector<vector<int>> test = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
			print(spiralOrder(test));
		}
	}
}
