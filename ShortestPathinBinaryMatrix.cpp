#include "stdafx.h"

//Given an n x n binary matrix grid, return the length of the shortest clear path
//in the matrix. If there is no clear path, return -1.
//A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0))
//to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
//All the visited cells of the path are 0.
//All the adjacent cells of the path are 8-directionally connected (i.e., they
//are different and they share an edge or a corner).
//The length of a clear path is the number of visited cells of this path.
// 
//
//Example 1:
//Input: grid = [[0,1],[1,0]]
//Output: 2
//
//Example 2:
//Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
//Output: 4
//
//Example 3:
//Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
//Output: -1
// 
//Constraints:
//n == grid.length
//n == grid[i].length
//1 <= n <= 100
//grid[i][j] is 0 or 1

namespace Solution2022
{
	namespace ShortestPathinBinaryMatrix
	{

	    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
			int rowCount = grid.size();
			if (rowCount == 0) { return -1; }
			int colCount = grid[0].size();
			if (colCount == 0) { return -1; }
			if (grid[0][0] == 1 || grid[rowCount - 1][colCount - 1] == 1) { return -1; }
			if (rowCount == 1 && colCount == 1) { return 1; }
			
			vector<vector<bool>> visited(rowCount, vector<bool>(colCount, false));
			queue<pair<int, int>> q;
			q.push({ 0, 0 });
			visited[0][0] = true;

			vector<vector<int>> dirs = { {1, 0},{-1, 0},{0, 1},{0, -1},{1, -1},{-1, 1},{1, 1},{-1, -1} };
			int result = 1;

			while (!q.empty()) {
				int sz = q.size();
				
				while (sz) {
					sz--;
					
					auto [x, y] = q.front();
					q.pop();

					if (x == rowCount - 1 && y == colCount - 1) { return result; }

					for (auto& dir : dirs) {
						int a = x + dir[0];
						int b = y + dir[1];
						if (a < 0 || a >= rowCount || b < 0 || b >= colCount || visited[a][b] || grid[x][y]) { continue; }
						visited[a][b] = true;
						q.push({ a, b });
					}
				}
				result++;
			}
			return -1;
	    }

		void Main() {
			vector<vector<int>> test = { {0,1},{1,0} };
			print(shortestPathBinaryMatrix(test));
		}
	}
}
