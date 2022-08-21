#include "stdafx.h"

//Given an m x n matrix grid where each cell is either a wall 'W', an enemy 'E'
//or empty '0', return the maximum enemies you can kill using one bomb. You can
//only place the bomb in an empty cell.
//The bomb kills all the enemies in the same row and column from the planted
//point until it hits the wall since it is too strong to be destroyed.
// 
//
//Example 1:
//Input: grid = [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
//Output: 3
//
//Example 2:
//Input: grid = [["W","W","W"],["0","0","0"],["E","E","E"]]
//Output: 1
// 
//Constraints:
//m == grid.length
//n == grid[i].length
//1 <= m, n <= 500
//grid[i][j] is either 'W', 'E', or '0'.

namespace Solution2022
{
	namespace BombEnemy
	{
	    int maxKilledEnemies(vector<vector<char>>& grid) {
			int rowCount = grid.size();
			int colCount = grid[0].size();

			int result = 0;
			int rowHit = 0;
			vector<int> colHit(colCount, 0);

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					if (j == 0 || grid[i][j - 1] == 'W') {
						rowHit = 0;
						for (int k = j; k < colCount && grid[i][k] != 'W'; k++) { 
							rowHit += (grid[i][k] == 'E'); 
						}
					}
					if (i == 0 || grid[i - 1][j] == 'W') {
						colHit[j] = 0;
						for (int k = i; k < rowCount && grid[k][j] != 'W'; k++) { 
							colHit[j] += (grid[k][j] == 'E'); 
						}
					}
					if (grid[i][j] == '0') {
						result = max(result, rowHit + colHit[j]);
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
