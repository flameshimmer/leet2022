#include "stdafx.h"

//You are given an n x n 2D matrix representing an image, rotate the image by 90
//degrees (clockwise).
//You have to rotate the image in-place, which means you have to modify the input
//2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
// 
//
//Example 1:
//Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [[7,4,1],[8,5,2],[9,6,3]]
//
//Example 2:
//Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
//Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
// 
//Constraints:
//n == matrix.length == matrix[i].length
//1 <= n <= 20
//-1000 <= matrix[i][j] <= 1000

namespace Solution2022
{
	namespace RotateImage
	{
		namespace RingOfFourByRingOfFour {
			void rotate(vector<vector<int>>& m) {
				int a = 0;
				int b = m.size() - 1;
				for (int i = 0; i < b - a; i++) {
					swap(m[a][a + i], m[a + i][b]);
					swap(m[a][a + i], m[b][b - i]);
					swap(m[a][a + i], m[b - i][a]);
				}
				a++;
				b--;			
			}
/*
		Input
		1, 2, 3
		4, 5, 6
		7, 8, 9


		for-loop 1
		swap1               swap2               swap3
		1<->3               3<->9              9<->7

		3, 2, 1            9, 2, 1            7, 2, 1
		4, 5, 6    =>      4, 5, 6    =>      4, 5, 6
		7, 8, 9            7, 8, 3            9, 8, 3



		for-loop 2
		swap1              swap2              swap3
		2<->6              6<->8              8<->4

		7, 6, 1            7, 8, 1            7, 4, 1
		4, 5, 2    =>      4, 5, 2    =>      8, 5, 2
		9, 8, 3            9, 6, 3            9, 6, 3


		output
		7, 4, 1,
		8, 5, 2,
		9, 6, 3,
*/
		}
		namespace TransposeThenReverse {
			void rotate(vector<vector<int>>& matrix) {
				int rowCount = matrix.size();
				if (rowCount == 0) { return; }
				int colCount = matrix[0].size();
				if (colCount == 0) { return; }

				for (int i = 0; i < rowCount; i++) {
					for (int j = i; j < colCount; j++) { // note j starts from i!!!
						swap(matrix[i][j], matrix[j][i]);
					}
				}
				for (auto& row : matrix) {
					reverse(row.begin(), row.end());
				}
			}
		}
	    

		void Main() {
			vector<vector<int>> test = { {1,2,3},{4,5,6},{7,8,9} };
			RingOfFourByRingOfFour::rotate(test);
		}
	}
}
