#include "stdafx.h"

//Given a collection of candidate numbers (candidates) and a target number
//(target), find all unique combinations in candidates where the candidate
//numbers sum to target.
//Each number in candidates may only be used once in the combination.
//
//Note: The solution set must not contain duplicate combinations.
// 
//
//Example 1:
//Input: candidates = [10,1,2,7,6,1,5], target = 8
//Output: 
//[
//[1,1,6],
//[1,2,5],
//[1,7],
//[2,6]
//]
//
//Example 2:
//Input: candidates = [2,5,2,1,2], target = 5
//Output: 
//[
//[1,2,2],
//[5]
//]
// 
//Constraints:
//1 <= candidates.length <= 100
//1 <= candidates[i] <= 50
//1 <= target <= 30

namespace Solution2022
{
	namespace CombinationSumII
	{
		void comboHelper(vector<int>& can, int start, int len, int sum, int target, vector<int>& result, vector<vector<int>>& results) {
			if (sum == target) { results.push_back(result); }
			if (sum >= target) { return; }

			for (int i = start; i < len; i++) {
				result.push_back(can[i]);
				comboHelper(can, i + 1, len, sum + can[i], target, result, results);
				result.pop_back();
				while (i + 1 < len && can[i] == can[i + 1]) { i++; }
			}
		}

		vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
			sort(candidates.begin(), candidates.end());
			vector<vector<int>> results;
			vector<int> result;
			int len = candidates.size();
			int sum = 0;
			comboHelper(candidates, 0, len, sum, target, result, results);
			return results;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
