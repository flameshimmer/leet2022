#include "stdafx.h"

//Given two integers n and k, return all possible combinations of k numbers out
//of the range [1, n].
//You may return the answer in any order.
// 
//
//Example 1:
//Input: n = 4, k = 2
//Output:
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//]
//
//Example 2:
//Input: n = 1, k = 1
//Output: [[1]]
// 
//Constraints:
//1 <= n <= 20
//1 <= k <= n

namespace Solution2022
{
	namespace Combinations
	{
		void helper(int start, int level, int n, int k, vector<int>& result, vector<vector<int>>& results) {
			if (level >= k) {
				results.push_back(result);
				return;
			}
			
			for (int i = start; i <= n; i++) {
				result.push_back(i);
				helper(i + 1, level + 1, n, k, result, results);
				result.pop_back();			
			}
		}


		vector<vector<int>> combine(int n, int k) {
			vector<vector<int>> results;
			if (k == 0) { return results; }

			vector<int> result;
			helper(1, 0, n, k, result, results);
			return results;
		}


		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
