#include "stdafx.h"

//Given an m x n binary matrix mat, return the distance of the nearest 0 for each
//cell.
//The distance between two adjacent cells is 1.
// 
//
//Example 1:
//Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
//Output: [[0,0,0],[0,1,0],[0,0,0]]
//
//Example 2:
//Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
//Output: [[0,0,0],[0,1,0],[1,2,1]]
// 
//Constraints:
//m == mat.length
//n == mat[i].length
//1 <= m, n <= 104
//1 <= m * n <= 104
//mat[i][j] is either 0 or 1.
//There is at least one 0 in mat.

namespace Solution2022
{
	namespace ZeroOneMatrix
	{
		vector<vector<int>> updateMatrixBFS(vector<vector<int>>& mat) {
			int rowCount = mat.size();
			if (rowCount == 0) { return mat; }
			int colCount = mat[0].size();
			if (colCount == 0) { return mat; }

			vector<vector<int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
			vector<vector<int>> dist(rowCount, vector<int>(colCount, -1));

			queue<pair<int, int>> q;

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					if (mat[i][j] == 0) { 
						dist[i][j] = 0;
						q.push({i, j});
					}
				}
			}

			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (vector<int> dir : dirs) {
					int newX = x + dir[0];
					int newY = y + dir[1];

					if (newX >=0 && newX < rowCount && newY >=0 && newY < colCount && dist[newX][newY] == -1) {
						dist[newX][newY] = dist[x][y] + 1;
						q.push({ newX, newY });
					}
				}			
			}

			return dist;
		}

		vector<vector<int>> updateMatrixDP(vector<vector<int>>& mat) {
			int rowCount = mat.size();
			if (rowCount == 0) { return mat; }
			int colCount = mat[0].size();
			if (colCount == 0) { return mat; }

			vector<vector<int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
			vector<vector<int>> dist(rowCount, vector<int>(colCount, INT_MAX-10000));

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					if (mat[i][j] == 0) { dist[i][j] = 0; }
					else {
						if (i - 1 >= 0) {
							dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
						}
						if (j - 1 >= 0) {
							dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
						}
					}
				}
			}

			for (int i = rowCount - 1; i >= 0; i--) {
				for (int j = colCount - 1; j >= 0; j--) {
					if (i + 1 < rowCount) {
						dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);						
					}
					if (j + 1 < colCount) {
						dist[i][j] = min(dist[i][j], dist[i][j+1] + 1);
					}
				}
			}
			return dist;
		}

		void Main() {
			vector<vector<int>> test = { {0,0,0},{0,1,0},{1,1,1} };
			print(updateMatrixDP(test));
		}
	}
}
