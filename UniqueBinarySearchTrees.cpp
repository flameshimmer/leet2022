#include "stdafx.h"

//Given an integer n, return the number of structurally unique BST's (binary
//search trees) which has exactly n nodes of unique values from 1 to n.
// 
//
//Example 1:
//Input: n = 3
//Output: 5
//
//Example 2:
//Input: n = 1
//Output: 1
// 
//Constraints:
//1 <= n <= 19

namespace Solution2022
{
	namespace UniqueBinarySearchTrees
	{
		int helper(int n, vector<int>& M) {
			if (n < 2) { return 1; }
			if (M[n] != -1) { return M[n]; }
			int result = 0;
			for (int i = 0; i < n; i++) {
				result += helper(i, M) * helper(n - 1 - i, M);
			}
			M[n] = result;
			return result;
		}

		int numTrees(int n) {
			vector<int> M(n + 1, -1);
			return helper(n, M);
		}

		namespace DP {
			int numTrees(int n) {
				vector<int> M(n + 1, 0);
				M[0] = 1;
				M[1] = 1;
				for (int i = 2; i <= n; i++) { // because 0 and 1 already have answer, start from 2 til n
					for (int j = 0; j < i; j++) { // left child count can be 0 to i-1
						M[i] += M[j] * M[i - 1 - j];
					}
				}
				return M[n];
			}
		}


		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
