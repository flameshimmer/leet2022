#include "stdafx.h"

//Given an m x n matrix matrix and an integer k, return the max sum of a
//rectangle in the matrix such that its sum is no larger than k.
//It is guaranteed that there will be a rectangle with a sum no larger than k.
// 
//
//Example 1:
//Input: matrix = [[1,0,1],[0,-2,3]], k = 2
//Output: 2
//Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and
//2 is the max number no larger than k (k = 2).
//
//Example 2:
//Input: matrix = [[2,2,-1]], k = 3
//Output: 3
// 
//Constraints:
//m == matrix.length
//n == matrix[i].length
//1 <= m, n <= 100
//-100 <= matrix[i][j] <= 100
//-105 <= k <= 105
// 
//Follow up: What if the number of rows is much larger than the number of columns?

namespace Solution2022
{
	namespace MaxSumofRectangleNoLargerThanK
	{
		int helper(vector<int>& row, int k) {
			set<int> set({ 0 });
			int sum = 0;
			int result = INT_MIN;
			for (int i = 0; i < row.size(); i++) {
				sum += row[i];
				auto it = set.lower_bound(sum - k);
				if (it != set.end()) {
					result = max(result, sum - *it);
				}
				set.insert(sum);
			}
			return result;
		}

		int maxSumSubmatrix(vector<vector<int>>& m, int k) {
			int rowCount = m.size();
			int colCount = m[0].size();
			int result = INT_MIN;

			for (int i = 0; i < rowCount; i++) {
				vector<int> row(colCount, 0);
				for (int j = i; j < rowCount; j++) {
					for (int k = 0; k < colCount; k++) {
						row[k] += m[j][k];
					}
					result = max(result, helper(row, k));
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
