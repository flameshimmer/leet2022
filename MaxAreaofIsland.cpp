#include "stdafx.h"
//You are given an m x n binary matrix grid.An island is a group of 1's (representing land)
//connected 4-directionally (horizontal or vertical.) 
//You may assume all four edges of the grid are surrounded by water.
//
//The area of an island is the number of cells with a value 1 in the island.
//
//Return the maximum area of an island in grid.If there is no island, return 0.
//
//
//
//Example 1:
//
//
//Input: grid = 
//	[
//		[0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0], 
//		[0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0], 
//		[0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0], 
//		[0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0], 
//		[0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0],
//		[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0], 
//		[0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0], 
//		[0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0]
//	]
//	Output : 6
//	Explanation : The answer is not 11, because the island must be connected 4 - directionally.
//	Example 2 :
//
//	Input : grid = [[0, 0, 0, 0, 0, 0, 0, 0]]
//	Output : 0
//
//
//	Constraints :
//
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 50
//	grid[i][j] is either 0 or 1.


namespace Solution2022
{
	namespace MaxAreaofIsland
	{
		void helper(vector<vector<int>>& grid, int x, int y, int rowCount, int colCount, int& curArea, int& maxArea) {
			if (x < 0 || x >= rowCount || y < 0 || y >= colCount || grid[x][y] == 0) { return; }
			curArea++;
			maxArea = max(maxArea, curArea);
			grid[x][y] = 0;

			helper(grid, x-1, y, rowCount, colCount, curArea, maxArea);
			helper(grid, x, y-1, rowCount, colCount, curArea, maxArea);
			helper(grid, x+1, y, rowCount, colCount, curArea, maxArea);
			helper(grid, x, y+1, rowCount, colCount, curArea, maxArea);		
		}

		int maxAreaOfIsland(vector<vector<int>>& grid) {
			int rowCount = grid.size();
			if (rowCount == 0) { return 0; }
			int colCount = grid[0].size();
			if (colCount == 0) { return 0; }

			int curArea = 0;
			int maxArea = 0;

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					if (grid[i][j] == 1) {
						curArea = 0;
						helper(grid, i, j, rowCount, colCount, curArea, maxArea);
					}
				}
			}
			return maxArea;
		}

		void Main() {
			vector<vector<int>> test = { {0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0} };
			print(maxAreaOfIsland(test));
		}
	}
}
