#include "stdafx.h"

//Given an integer array nums that may contain duplicates, return all possible
//subsets (the power set).
//The solution set must not contain duplicate subsets. Return the solution in any
//order.
// 
//
//Example 1:
//Input: nums = [1,2,2]
//Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
//
//Example 2:
//Input: nums = [0]
//Output: [[],[0]]
// 
//Constraints:
//1 <= nums.length <= 10
//-10 <= nums[i] <= 10

namespace Solution2022
{
	namespace SubsetsII
	{
		void helper(int start, int len, vector<int>& nums, vector<int>& result, vector<vector<int>>& results) {
			results.push_back(result);
			if (start == len) { return; }

			for (int i = start; i < len; i++) {
				result.push_back(nums[i]);
				helper(i + 1, len, nums, result, results);
				result.pop_back();
				while (i + 1 < len && nums[i] == nums[i + 1]) { i++; }
			}
		}

		vector<vector<int>> subsetsWithDup(vector<int>& nums) {
			vector<vector<int>> results;
			vector<int> result;
			int len = nums.size();
			sort(nums.begin(), nums.end());
			helper(0, len, nums, result, results);
			return results;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
