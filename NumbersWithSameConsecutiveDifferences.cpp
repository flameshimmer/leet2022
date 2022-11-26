#include "stdafx.h"

//Return all non-negative integers of length n such that the absolute difference
//between every two consecutive digits is k.
//
//Note that every number in the answer must not have leading zeros. For example,
//01 has one leading zero and is invalid.
//You may return the answer in any order.
// 
//
//Example 1:
//Input: n = 3, k = 7
//Output: [181,292,707,818,929]
//Explanation: 
//Note that 070 is not a valid number, because it has leading zeroes.
//
//Example 2:
//Input: n = 2, k = 1
//Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
// 
//Constraints:
//2 <= n <= 9
//0 <= k <= 9

namespace Solution2022
{
	namespace NumbersWithSameConsecutiveDifferences
	{
		void helper(int level, int n, int k, int result, vector<int>& results) {
			if (level == n) { results.push_back(result); return; }


			vector<int> candidates;
			if (level == 0) { candidates = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; }
			else {
				if (result % 10 + k <= 9) { candidates.push_back((result % 10 + k)); }
				if (k != 0 && result % 10 - k >= 0) { candidates.push_back((result % 10 - k)); } // NOTE: k == 0, might cause duplicate. So need to check k!=0 here!!!
			}

			for (int c : candidates) {
				helper(level + 1, n, k, result * 10 + c, results);
			}
		}


		vector<int> numsSameConsecDiff(int n, int k) {
			vector<int> results;
			helper(0, n, k, 0, results);
			return results;
		}

		void Main() {
			print(numsSameConsecDiff(3, 7));
		}
	}
}
