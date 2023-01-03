#include "stdafx.h"

//Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal
//4-directionally connected group of 0s and a closed island is an island totally
//(all left, top, right, bottom) surrounded by 1s.
//Return the number of closed islands.
// 
//
//Example 1:
//[[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
//Output: 2
//Explanation: 
//Islands in gray are closed because they are completely surrounded by water
//(group of 1s).
//
//Example 2:
//Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
//Output: 1
//
//Example 3:
//Input: grid = [[1,1,1,1,1,1,1],
//               [1,0,0,0,0,0,1],
//               [1,0,1,1,1,0,1],
//               [1,0,1,0,1,0,1],
//               [1,0,1,1,1,0,1],
//               [1,0,0,0,0,0,1],
//               [1,1,1,1,1,1,1]]
//Output: 2
// 
//Constraints:
//1 <= grid.length, grid[0].length <= 100
//0 <= grid[i][j] <=1

namespace Solution2022
{
	namespace NumberofClosedIslands
	{
		void helper(int i, int j, int rowCount, int colCount, vector<vector<int>>& grid) {
			if (i < 0 || i >= rowCount || j < 0 || j >= colCount || grid[i][j] == 1) { return; }
			grid[i][j] = 1;
			helper(i - 1, j, rowCount, colCount, grid);
			helper(i + 1, j, rowCount, colCount, grid);
			helper(i, j - 1, rowCount, colCount, grid);
			helper(i, j + 1, rowCount, colCount, grid);
		}

		int closedIsland(vector<vector<int>>& grid) {
			int rowCount = grid.size();
			int colCount = grid[0].size();

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					if (grid[i][j] == 0 && (i == 0 || j == 0 || i == rowCount - 1 || j == colCount - 1)) {
						helper(i, j, rowCount, colCount, grid);
					}
				}
			}

			int result = 0;
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					if (grid[i][j] == 0) {
						result++;
						helper(i, j, rowCount, colCount, grid);
					}
				}
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
