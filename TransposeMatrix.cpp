#include "stdafx.h"

//Given a 2D integer array matrix, return the transpose of matrix.
//The transpose of a matrix is the matrix flipped over its main diagonal,
//switching the matrix's row and column indices.
// 
//
//Example 1:
//Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [[1,4,7],[2,5,8],[3,6,9]]
//
//Example 2:
//Input: matrix = [[1,2,3],[4,5,6]]
//Output: [[1,4],[2,5],[3,6]]
// 
//Constraints:
//m == matrix.length
//n == matrix[i].length
//1 <= m, n <= 1000
//1 <= m * n <= 105
//-109 <= matrix[i][j] <= 109

namespace Solution2022
{
	namespace TransposeMatrix
	{
	    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
			int rowCount = matrix.size();
			if (rowCount == 0) { return matrix; }
			int colCount = matrix[0].size();
			if (colCount == 0) { return matrix; }
			
			vector<vector<int>> newMatirx(colCount, vector<int>(rowCount, 0));

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					newMatirx[j][i] = matrix[i][j];
				}
			}
			return newMatirx;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
