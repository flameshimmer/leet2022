#include "stdafx.h"

//Given a positive integer n, generate an n x n matrix filled with elements from
//1 to n2 in spiral order.
// 
//
//Example 1:
//Input: n = 3
//Output: [[1,2,3],[8,9,4],[7,6,5]]
//
//Example 2:
//Input: n = 1
//Output: [[1]]
// 
//Constraints:
//1 <= n <= 20

namespace Solution2022
{
	namespace SpiralMatrixII
	{
		vector<vector<int>> generateMatrix(int n) {
			vector<vector<int>> result(n, vector<int>(n));
			if (n == 0) { return result; }

			vector<pair<int, int>> dirs = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
			vector<int> length = { n, n - 1 }; // colCount, rowCount -1
			int dirIndex = 0;
			int i = 0;
			int j = -1;

			int v = 1;
			while (length[dirIndex % 2]) {
				for (int k = 0; k < length[dirIndex % 2]; k++) {
					i += dirs[dirIndex].first;
					j += dirs[dirIndex].second;
					result[i][j] = v;
					v++;
				}
				length[dirIndex % 2]--;
				dirIndex = (dirIndex + 1) % 4;
			}
			return result;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
