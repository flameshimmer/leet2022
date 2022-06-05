#include "stdafx.h"

//You are given an m x n grid where each cell can have one of three values:
//0 representing an empty cell,
//1 representing a fresh orange, or
//2 representing a rotten orange.
//Every minute, any fresh orange that is 4-directionally adjacent to a rotten
//orange becomes rotten.
//Return the minimum number of minutes that must elapse until no cell has a fresh
//orange. If this is impossible, return -1.
// 
//
//Example 1:
//Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
//Output: 4
//
//Example 2:
//Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
//Output: -1
//Explanation: The orange in the bottom left corner (row 2, column 0) is never
//rotten, because rotting only happens 4-directionally.
//
//Example 3:
//Input: grid = [[0,2]]
//Output: 0
//Explanation: Since there are already no fresh oranges at minute 0, the answer
//is just 0.
// 
//Constraints:
//m == grid.length
//n == grid[i].length
//1 <= m, n <= 10
//grid[i][j] is 0, 1, or 2. 
namespace Solution2022
{
	namespace RottingOranges
	{
		int orangesRotting(vector<vector<int>>& grid) {
			int rowCount = grid.size();
			if (rowCount == 0) { return 0; }
			int colCount = grid[0].size();
			if (colCount == 0) { return 0; }

			queue<pair<int, int>> q;
			int totalOrange = 0;
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					if (grid[i][j] > 0) { totalOrange++; }
					if (grid[i][j] == 2) { 
						q.push({ i,j });
					}
				}
			}

			int result = -1;
			int totalRotten = 0;
			vector<vector<int>> dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
			while (!q.empty()) {
				int sz = q.size();
				totalRotten += sz;
				while (sz) {
					sz--;
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (vector<int> dir : dirs) {
						int newX = x + dir[0];
						int newY = y + dir[1];
						if (newX >= 0 && newX < rowCount && newY >= 0 && newY < colCount && grid[newX][newY] == 1) {
							q.push({ newX, newY });
							grid[newX][newY] = 2;
						}
					}
				}
				result++;
			}
			if (totalOrange == 0) { return 0; }
			return totalRotten == totalOrange ? result: -1;
		}

		void Main() {
			vector<vector<int>> test = { {2,1,1},{1,1,0},{0,1,1} };
			print(orangesRotting(test));
		}
	}
}
