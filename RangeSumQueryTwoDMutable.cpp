#include "stdafx.h"

//Given a 2D matrix matrix, handle multiple queries of the following types:
//Update the value of a cell in matrix.
//Calculate the sum of the elements of matrix inside the rectangle defined by its
//upper left corner (row1, col1) and lower right corner (row2, col2).
//Implement the NumMatrix class:
//NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
//void update(int row, int col, int val) Updates the value of matrix[row][col] to
//be val.
//int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the
//elements of matrix inside the rectangle defined by its upper left corner (row1,
//col1) and lower right corner (row2, col2).
// 
//
//Example 1:
//Input
//["NumMatrix", "sumRegion", "update", "sumRegion"]
//[[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0,
//3, 0, 5]]], [2, 1, 4, 3], [3, 2, 2], [2, 1, 4, 3]]
//Output
//[null, 8, null, 10]
//Explanation
//NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2,
//0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
//numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e. sum of the left red
//rectangle)
//numMatrix.update(3, 2, 2);       // matrix changes from left image to right
//image
//numMatrix.sumRegion(2, 1, 4, 3); // return 10 (i.e. sum of the right red
//rectangle)
// 
//Constraints:
//m == matrix.length
//n == matrix[i].length
//1 <= m, n <= 200
//-105 <= matrix[i][j] <= 105
//0 <= row < m
//0 <= col < n
//-105 <= val <= 105
//0 <= row1 <= row2 < m
//0 <= col1 <= col2 < n
//At most 104 calls will be made to sumRegion and update.

namespace Solution2022
{
	namespace RangeSumQueryTwoDMutable
	{
		class NumMatrix {
		private:
			class FenwickTree {
			private:
				vector<vector<int>> data;
				int lowBits(int i) { return i & -i; }
			public:
				FenwickTree(int rowCount, int colCount) {
					data.resize(rowCount + 1, vector<int>(colCount + 1, 0));
				}

				void update(int row, int col, int delta) {
					for (int i = row; i < data.size(); i += lowBits(i)) {
						for (int j = col; j < data[0].size(); j += lowBits(j)) {
							data[i][j] += delta;
						}
					}
				}

				int query(int row, int col) {
					int result = 0;
					for (int i = row; i > 0; i -= lowBits(i)) {
						for (int j = col; j > 0; j -= lowBits(j)) {
							result += data[i][j];
						}
					}
					return result;
				}
			};

			FenwickTree tree;
			vector<vector<int>> data;
		public:
			NumMatrix(vector<vector<int>>& matrix) : data(matrix), tree(matrix.size(), matrix[0].size()) {
				for (int i = 0; i < matrix.size(); i++) {
					for (int j = 0; j < matrix[0].size(); j++) {
						tree.update(i + 1, j + 1, matrix[i][j]);
					}
				}
			}

			void update(int row, int col, int val) {
				tree.update(row + 1, col + 1, val - data[row][col]);
				data[row][col] = val;
			}

			int sumRegion(int row1, int col1, int row2, int col2) {
				return tree.query(row2 + 1, col2 + 1) - tree.query(row1, col2 + 1) - tree.query(row2 + 1, col1) + tree.query(row1, col1);
			}
		};


		/**
		 * Your NumMatrix object will be instantiated and called as such:
		 * NumMatrix* obj = new NumMatrix(matrix);
		 * obj->update(row,col,val);
		 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
		 */

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
