#include "stdafx.h"

//Given an array nums of distinct integers, return all the possible permutations.
//You can return the answer in any order.
// 
//
//Example 1:
//Input: nums = [1,2,3]
//Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//
//Example 2:
//Input: nums = [0,1]
//Output: [[0,1],[1,0]]
//
//Example 3:
//Input: nums = [1]
//Output: [[1]]
// 
//Constraints:
//1 <= nums.length <= 6
//-10 <= nums[i] <= 10
//All the integers of nums are unique.

namespace Solution2022
{
	namespace Permutations
	{
		void helper(int level, int len, vector<int>& nums, vector<bool>& candidate, vector<int>& result, vector<vector<int>>& results) {
			if (level == len) {
				results.push_back(result);
				return;
			}

			for (int i = 0; i < len; i++) {
				if (candidate[i]) {
					result.push_back(nums[i]);
					candidate[i] = false;
					helper(level + 1, len, nums, candidate, result, results);
					candidate[i] = true;
					result.pop_back();
				}
			}
		}


		vector<vector<int>> permute(vector<int>& nums) {
			vector<vector<int>> results;
			int len = nums.size();
			if (len == 0) { return results; }

			vector<int> result;
			vector<bool> candidate(len, true);
			helper(0, len, nums, candidate, result, results);
			return results;
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
