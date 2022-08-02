#include "stdafx.h"

//Given an m x n integers matrix, return the length of the longest increasing
//path in matrix.
//From each cell, you can either move in four directions: left, right, up, or
//down. You may not move diagonally or move outside the boundary (i.e.,
//wrap-around is not allowed).
// 
//
//Example 1:
//Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
//Output: 4
//Explanation: The longest increasing path is [1, 2, 6, 9].
//
//Example 2:
//Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
//Output: 4
//Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is
//not allowed.
//
//Example 3:
//Input: matrix = [[1]]
//Output: 1
// 
//Constraints:
//m == matrix.length
//n == matrix[i].length
//1 <= m, n <= 200
//0 <= matrix[i][j] <= 231 - 1

namespace Solution2022
{
	namespace LongestIncreasingPathinaMatrix
	{
		int dfs(vector<vector<int>>& M, int x, int y, int rowCount, int colCount, vector<vector<int>>& dp) {
			if (dp[x][y] != 0) { return dp[x][y]; }

			vector<pair<int, int>> dirs = { {1, 0},{0, 1},{-1, 0},{0, -1} };
			int result = 1;
			for (auto& [a, b] : dirs) {
				int xx = x + a;
				int yy = y + b;

				if (xx < 0 || xx >= rowCount || yy < 0 || yy >= colCount || M[xx][yy] <= M[x][y]) { continue; }
				result = max(result, 1 + dfs(M, xx, yy, rowCount, colCount, dp));
			}
			dp[x][y] = result;
			return result;
		}


		int longestIncreasingPath(vector<vector<int>>& M) {
			int rowCount = M.size();
			if (rowCount == 0) { return 0; }
			int colCount = M[0].size();
			if (colCount == 0) { return 0; }

			vector<vector<int>> dp(rowCount, vector<int>(colCount, 0));
			int result = 1;
			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					result = max(result, dfs(M, i, j, rowCount, colCount, dp));
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
