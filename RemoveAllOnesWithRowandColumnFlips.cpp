#include "stdafx.h"

//You are given an m x n binary matrix grid.
//In one operation, you can choose any row or column and flip each value in that
//row or column (i.e., changing all 0's to 1's, and all 1's to 0's).
//Return true if it is possible to remove all 1's from grid using any number of
//operations or false otherwise.
// 
//
//Example 1:
//Input: grid = [[0,1,0],[1,0,1],[0,1,0]]
//Output: true
//Explanation: One possible way to remove all 1's from grid is to:
//- Flip the middle row
//- Flip the middle column
//
//Example 2:
//Input: grid = [[1,1,0],[0,0,0],[0,0,0]]
//Output: false
//Explanation: It is impossible to remove all 1's from grid.
//
//Example 3:
//Input: grid = [[0]]
//Output: true
//Explanation: There are no 1's in grid.
// 
//Constraints:
//m == grid.length
//n == grid[i].length
//1 <= m, n <= 300
//grid[i][j] is either 0 or 1.

namespace Solution2022
{
	namespace RemoveAllOnesWithRowandColumnFlips
	{
		//The main fact to understand is - whenever you changed the first row for the first time, 
		//you don't need to change that row again. If you need to change that, that's an impossible case. 
		//So, we fix all the first row dependency at first.whenever there's a 1 at the first row,
		//we change the corresponding column.
		//
		//Then we know, if any time we had to change any other column again, that means it's not
		//possible because we have to make the change on the first row again. So, all we need to check 
		//is if we need to flip a row. So, we either see all the 0's on all rows, or we see all the 1's 
		//on that row.
	    bool removeOnes(vector<vector<int>>& grid) {
			int rowCount = grid.size();
			if (rowCount == 0) { return true; }
			int colCount = grid[0].size();
			if (colCount == 0) { return true; }

			// If any cell on the first row has 1, flipping that column. 
			for (int j = 0; j < colCount; j++) {
				if (grid[0][j] == 1) {
					for (int i = 0; i < rowCount; i++) {
						grid[i][j] = !grid[i][j];
					}
				}
			}
			// Now, all other rows should be either all 0's or all 1's. If not, than that's impossible to find a solution 
			for (int i = 0; i < rowCount; i++) {
				int sum = accumulate(grid[i].begin(), grid[i].end(), 0);
				if (sum != 0 && sum != colCount) { return false; }
			}
			return true;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
