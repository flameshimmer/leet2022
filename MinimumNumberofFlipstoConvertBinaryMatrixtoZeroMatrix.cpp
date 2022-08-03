#include "stdafx.h"

//Given a m x n binary matrix mat. In one step, you can choose one cell and flip
//it and all the four neighbors of it if they exist (Flip is changing 1 to 0 and
//0 to 1). A pair of cells are called neighbors if they share one edge.
//Return the minimum number of steps required to convert mat to a zero matrix or
//-1 if you cannot.
//A binary matrix is a matrix with all cells equal to 0 or 1 only.
//A zero matrix is a matrix with all cells equal to 0.
// 
//
//Example 1:
//Input: mat = [[0,0],[0,1]]
//Output: 3
//Explanation: One possible solution is to flip (1, 0) then (0, 1) and finally
//(1, 1) as shown.
//
//Example 2:
//Input: mat = [[0]]
//Output: 0
//Explanation: Given matrix is a zero matrix. We do not need to change it.
//
//Example 3:
//Input: mat = [[1,0,0],[1,0,0]]
//Output: -1
//Explanation: Given matrix cannot be a zero matrix.
// 
//Constraints:
//m == mat.length
//n == mat[i].length
//1 <= m, n <= 3
//mat[i][j] is either 0 or 1.

namespace Solution2022
{
	namespace MinimumNumberofFlipstoConvertBinaryMatrixtoZeroMatrix
	{
		int minFlips(vector<vector<int>>& mat) {
			vector<pair<int, int>> dirs = { {0, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
			int rowCount = mat.size();
			int colCount = mat[0].size();
			int start = 0;

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					start |= mat[i][j] << (i * colCount + j); // note this is i * colCount, not i* rowCount;
				}
			}

			queue<int> q;
			q.push(start);
			unordered_set<int> seen;
			int result = 0;

			while (!q.empty()) {
				int sz = q.size();
				while (sz) {
					sz--;
					int top = q.front();
					q.pop();
					if (top == 0) { return result; }

					for (int i = 0; i < rowCount; i++) {
						for (int j = 0; j < colCount; j++) {
							int next = top;
							for (auto& [x, y] : dirs) {
								int ii = i + x;
								int jj = j + y;
								if (ii >= 0 && ii < rowCount && jj >= 0 && jj < colCount) {
									next ^= 1 << ii * colCount + jj;
								}
							}
							if (seen.find(next) == seen.end()) {
								q.push(next);
								seen.insert(next);
							}
						}
					}
				}
				result++;
			}
			return -1;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
