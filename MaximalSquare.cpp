#include "stdafx.h"

//Given an m x n binary matrix filled with 0's and 1's, find the largest square
//containing only 1's and return its area.
// 
//
//Example 1:
//[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
//Output: 4
//
//Example 2:
//Input: matrix = [["0","1"],["1","0"]]
//Output: 1
//
//Example 3:
//Input: matrix = [["0"]]
//Output: 0
// 
//Constraints:
//m == matrix.length
//n == matrix[i].length
//1 <= m, n <= 300
//matrix[i][j] is '0' or '1'.

namespace Solution2022
{
	namespace MaximalSquare
	{
		int maximalSquare(vector<vector<char>>& matrix) {
			int rowCount = matrix.size();
			int colCount = matrix[0].size();

			vector<vector<int>> M(rowCount, vector<int>(colCount, 0));
			int result = 0;

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					M[i][j] = matrix[i][j] - '0';
					if (M[i][j] == 0) { continue; }
					if (i - 1 >= 0 && j - 1 >= 0) {
						M[i][j] = min(min(M[i - 1][j], M[i][j - 1]), M[i - 1][j - 1]) + 1;
					}
					result = max(result, M[i][j] * M[i][j]);
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
