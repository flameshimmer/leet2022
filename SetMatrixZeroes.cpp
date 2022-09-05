#include "stdafx.h"

//Given an m x n integer matrix matrix, if an element is 0, set its entire row
//and column to 0's.
//You must do it in place.
// 
//
//Example 1:
//Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
//Output: [[1,0,1],[0,0,0],[1,0,1]]
//
//Example 2:
//Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
//Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
// 
//Constraints:
//m == matrix.length
//n == matrix[0].length
//1 <= m, n <= 200
//-231 <= matrix[i][j] <= 231 - 1
// 
//Follow up:
//A straightforward solution using O(mn) space is probably a bad idea.
//A simple improvement uses O(m + n) space, but still not the best solution.
//Could you devise a constant space solution?

namespace Solution2022
{
	namespace SetMatrixZeroes
	{
		// Record whether the row/col should be 0 in the first row/col, 
		// use two bool to record whether the first row/col should be 0 separately. 

	    void setZeroes(vector<vector<int>>& matrix) {
			int rowCount = matrix.size();
			int colCount = matrix[0].size();

			bool firstRowZero = false;
			for (int i = 0; i < colCount; i++) {
				if (matrix[0][i] == 0) { firstRowZero = true; break; }
			}

			bool firstColZero = false;
			for (int i = 0; i < rowCount; i++) {
				if (matrix[i][0] == 0) { firstColZero = true; break; }
			}

			for (int i = 1; i < rowCount; i++) {
				for (int j = 1; j < colCount; j++) {
					if (matrix[i][j] == 0) {
						matrix[0][j] = 0;
						matrix[i][0] = 0;
					}
				}
			}

			for (int i = 1; i < rowCount; i++) {
				for (int j = 1; j < colCount; j++) {
					if (matrix[0][j] == 0 || matrix[i][0] == 0) {
						matrix[i][j] = 0;
					}
				}
			}

			if (firstRowZero) {
				fill(matrix[0].begin(), matrix[0].end(), 0);
			}

			if (firstColZero) {
				for (int i = 0; i < rowCount; i++) { matrix[i][0] = 0; }
			}
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
