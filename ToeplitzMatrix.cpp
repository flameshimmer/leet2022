#include "stdafx.h"

//Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return
//false.
//A matrix is Toeplitz if every diagonal from top-left to bottom-right has the
//same elements.
// 
//
//Example 1:
//Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
//Output: true
//Explanation:
//In the above grid, the diagonals are:
//"[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
//In each diagonal all elements are the same, so the answer is True.
//
//Example 2:
//Input: matrix = [[1,2],[2,2]]
//Output: false
//Explanation:
//The diagonal "[1, 2]" has different elements.
// 
//Constraints:
//m == matrix.length
//n == matrix[i].length
//1 <= m, n <= 20
//0 <= matrix[i][j] <= 99
// 
//Follow up:
//What if the matrix is stored on disk, and the memory is limited such that you
//can only load at most one row of the matrix into the memory at once?
//What if the matrix is so large that you can only load up a partial row into the
//memory at once?

namespace Solution2022
{
	namespace ToeplitzMatrix
	{
		namespace Hashmap {
			bool isToeplitzMatrix(vector<vector<int>>& matrix) {
				int rowCount = matrix.size();
				if (rowCount == 0) { return true; }
				int colCount = matrix[0].size();
				if (colCount == 0) { return true; }

				unordered_map<int, int> map;
				for (int i = 0; i < rowCount; i++) {
					for (int j = 0; j < colCount; j++) {
						if (map.find(i - j) != map.end() && map[i - j] != matrix[i][j]) { return false; }
						map[i - j] = matrix[i][j];
					}
				}
				return true;
			}
		}

		namespace Calculation {
			bool isToeplitzMatrix(vector<vector<int>>& matrix) {
				int rowCount = matrix.size();
				if (rowCount == 0) { return true; }
				int colCount = matrix[0].size();
				if (colCount == 0) { return true; }

				for (int i = 0; i < rowCount - 1; i++) {
					for (int j = 0; j < colCount - 1; j++) {
						if (matrix[i][j] != matrix[i + 1][j + 1]) { return false; }
					}
				}
				return true;
			}
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
