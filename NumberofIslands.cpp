#include "stdafx.h"

//Given an m x n 2D binary grid grid which represents a map of '1's (land) and
//'0's (water), return the number of islands.
//An island is surrounded by water and is formed by connecting adjacent lands
//horizontally or vertically. You may assume all four edges of the grid are all
//surrounded by water.
// 
//
//Example 1:
//Input: grid = [
//  ["1","1","1","1","0"],
//  ["1","1","0","1","0"],
//  ["1","1","0","0","0"],
//  ["0","0","0","0","0"]
//]
//Output: 1
//
//Example 2:
//Input: grid = [
//  ["1","1","0","0","0"],
//  ["1","1","0","0","0"],
//  ["0","0","1","0","0"],
//  ["0","0","0","1","1"]
//]
//Output: 3
// 
//Constraints:
//m == grid.length
//n == grid[i].length
//1 <= m, n <= 300
//grid[i][j] is '0' or '1'.

namespace Solution2022
{
	namespace NumberofIslands
	{
		void helper(int i, int j, int rowCount, int colCount, vector<vector<char>>& grid) {
			if (i < 0 || i >= rowCount || j < 0 || j >= colCount || grid[i][j] == '0' ) { return; }
			grid[i][j] = '0';

			vector<vector<int>> dirs = { {1, 0}, {-1, 0},{0, 1}, {0, -1} };			
			for (vector<int>& dir : dirs) {
				helper(i + dir[0], j + dir[1], rowCount, colCount, grid);
			}
		}


	    int numIslands(vector<vector<char>>& grid) {
			int rowCount = grid.size();
			if (rowCount == 0) { return 0; }
			int colCount = grid[0].size();
			if (colCount == 0) { return 0; }

			int result = 0;
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					if (grid[i][j] == '1') {
						result++;
						helper(i, j, rowCount, colCount, grid);
					}
				}
			}
			return result;
	    }

		void Main() {
			vector<vector<char>> test =
			{ {'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'} };
			print(numIslands(test));
		}
	}
}
