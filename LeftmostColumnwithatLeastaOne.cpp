#include "stdafx.h"

//A row-sorted binary matrix means that all elements are 0 or 1 and each row of
//the matrix is sorted in non-decreasing order.
//Given a row-sorted binary matrix binaryMatrix, return the index (0-indexed) of
//the leftmost column with a 1 in it. If such an index does not exist, return -1.
//You can't access the Binary Matrix directly. You may only access the matrix
//using a BinaryMatrix interface:
//BinaryMatrix.get(row, col) returns the element of the matrix at index (row,
//col) (0-indexed).
//BinaryMatrix.dimensions() returns the dimensions of the matrix as a list of 2
//elements [rows, cols], which means the matrix is rows x cols.
//Submissions making more than 1000 calls to BinaryMatrix.get will be judged
//Wrong Answer. Also, any solutions that attempt to circumvent the judge will
//result in disqualification.
//For custom testing purposes, the input will be the entire binary matrix mat.
//You will not have access to the binary matrix directly.
// 
//
//Example 1:
//Input: mat = [[0,0],[1,1]]
//Output: 0
//
//Example 2:
//Input: mat = [[0,0],[0,1]]
//Output: 1
//
//Example 3:
//Input: mat = [[0,0],[0,0]]
//Output: -1
// 
//Constraints:
//rows == mat.length
//cols == mat[i].length
//1 <= rows, cols <= 100
//mat[i][j] is either 0 or 1.
//mat[i] is sorted in non-decreasing order.

namespace Solution2022
{
	namespace LeftmostColumnwithatLeastaOne
	{

		// This is the BinaryMatrix's API interface.
		// You should not implement it, or speculate about its implementation
		class BinaryMatrix {
		public:
			int get(int row, int col) { return 0; }
			vector<int> dimensions() { return {}; }
		};


		int leftMostColumnWithOne(BinaryMatrix& matrix) {
			int rowCount = matrix.dimensions()[0];
			int colCount = matrix.dimensions()[1];

			int curCol = colCount - 1;
			for (int row = 0; row < rowCount; row++) {
				while (curCol >= 0 && matrix.get(row, curCol) == 1) { curCol--; }
			}

			return curCol == colCount - 1 ? -1 : curCol + 1;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
