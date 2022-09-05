#include "stdafx.h"

//Write an efficient algorithm that searches for a value target in an m x n
//integer matrix matrix. This matrix has the following properties:
//Integers in each row are sorted from left to right.
//The first integer of each row is greater than the last integer of the previous
//row.
// 
//
//Example 1:
//Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
//Output: true
//
//Example 2:
//Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
//Output: false
// 
//Constraints:
//m == matrix.length
//n == matrix[i].length
//1 <= m, n <= 100
//-104 <= matrix[i][j], target <= 104

namespace Solution2022
{
	namespace SearchaTwoDMatrix
	{
		// Directly binary the whole matrix as if it is a 1D array. 
		bool searchMatrix(vector<vector<int>>& matrix, int target) {
			int rowCount = matrix.size();
			int colCount = matrix[0].size();

			int start = 0;
			int end = rowCount * colCount - 1;

			while (start <= end) {
				int mid = start + (end - start) / 2;
				int r = mid / colCount; // Note: this is divide by colCount, instead of divide by rowCount!!!
				int c = mid % colCount;
				int midV = matrix[r][c];
				if (midV == target) { return true; }
				else if (midV < target) { start = mid + 1; }
				else { end = mid - 1; }
			}
			return false;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
