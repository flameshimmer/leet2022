#include "stdafx.h"

//You are given an m x n binary matrix grid. An island is a group of 1's
//(representing land) connected 4-directionally (horizontal or vertical.) You may
//assume all four edges of the grid are surrounded by water.
//An island is considered to be the same as another if and only if one island can
//be translated (and not rotated or reflected) to equal the other.
//Return the number of distinct islands.
// 
//
//Example 1:
//Input: grid = [[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]
//Output: 1
//
//Example 2:
//Input: grid = [[1,1,0,1,1],[1,0,0,0,0],[0,0,0,0,1],[1,1,0,1,1]]
//Output: 3
// 
//Constraints:
//m == grid.length
//n == grid[i].length
//1 <= m, n <= 50
//grid[i][j] is either 0 or 1.

namespace Solution2022
{
	namespace NumberofDistinctIslands
	{
		void helper(int i, int j, int r, int c, int rowCount, int colCount, string& key, vector<vector<int>>& grid) {
			if (r < 0 || r >= rowCount || c < 0 || c >= colCount || grid[r][c] == 0) { return; }
			grid[r][c] = 0;
			key += to_string(r - i) + to_string(c - j);
			helper(i, j, r + 1, c, rowCount, colCount, key, grid);
			helper(i, j, r - 1, c, rowCount, colCount, key, grid);
			helper(i, j, r, c + 1, rowCount, colCount, key, grid);
			helper(i, j, r, c - 1, rowCount, colCount, key, grid);
		}


		int numDistinctIslands(vector<vector<int>>& grid) {
			int rowCount = grid.size();
			int colCount = grid[0].size();

			unordered_set<string> set;
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					if (grid[i][j]) {
						string key;
						helper(i, j, i, j, rowCount, colCount, key, grid);
						set.insert(key);
					}
				}
			}
			return set.size();
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
