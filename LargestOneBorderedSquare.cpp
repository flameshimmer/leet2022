#include "stdafx.h"

//Given a 2D grid of 0s and 1s, return the number of elements in the largest
//square subgrid that has all 1s on its border, or 0 if such a subgrid doesn't
//exist in the grid.
// 
//
//Example 1:
//Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
//Output: 9
//
//Example 2:
//Input: grid = [[1,1,0,0]]
//Output: 1
// 
//Constraints:
//1 <= grid.length <= 100
//1 <= grid[0].length <= 100
//grid[i][j] is 0 or 1

namespace Solution2022
{
	namespace LargestOneBorderedSquare
	{
		int largest1BorderedSquare(vector<vector<int>>& g) {
			int rowCount = g.size();
			int colCount = g[0].size();
			vector<vector<int>> top(rowCount, vector<int>(colCount, 0));
			vector<vector<int>> left(rowCount, vector<int>(colCount, 0));

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					if (g[i][j] != 0) {
						top[i][j] = i > 0 ? top[i - 1][j] + 1 : 1;
						left[i][j] = j > 0 ? left[i][j - 1] + 1 : 1;
					}
				}
			}
			for (int a = min(rowCount, colCount); a > 0; a--) {
				for (int i = rowCount - 1; i - a + 1 >= 0; i--) {
					for (int j = colCount - 1; j - a + 1 >= 0; j--) {
						if (top[i][j] >= a && left[i][j] >= a && left[i - a + 1][j] >= a && top[i][j - a + 1] >= a) { return a * a; }
					}
				}
			}

			return 0;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
