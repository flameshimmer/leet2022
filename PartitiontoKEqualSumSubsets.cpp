#include "stdafx.h"

//Given an integer array nums and an integer k, return true if it is possible to
//divide this array into k non-empty subsets whose sums are all equal.
// 
//
//Example 1:
//Input: nums = [4,3,2,3,5,2,1], k = 4
//Output: true
//Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3),
//(2,3) with equal sums.
//
//Example 2:
//Input: nums = [1,2,3,4], k = 3
//Output: false
// 
//Constraints:
//1 <= k <= nums.length <= 16
//1 <= nums[i] <= 104
//The frequency of each element is in the range [1, 4].

namespace Solution2022
{
	namespace PartitiontoKEqualSumSubsets
	{
		bool helper(int curSum, int targetSum, int k, int startPos, vector<int>& nums, vector<bool>& visited) {
			if (k == 0) { return true; }
			if (curSum == targetSum) { return helper(0, targetSum, k - 1, 0, nums, visited); } // NOTE: start pos reset to 0!!!

			int len = nums.size();
			for (int i = startPos; i < len; i++) {
				if (visited[i] || nums[i] + curSum > targetSum) { continue; }
				visited[i] = true;
				if (helper(curSum + nums[i], targetSum, k, startPos + 1, nums, visited)) { return true; }
				visited[i] = false;
				while (i + 1 < len && nums[i] == nums[i + 1]) { i++; }
			}
			return false;
		}

		bool canPartitionKSubsets(vector<int>& nums, int k) {
			int len = nums.size();
			if (len < k) { return false; }
			int sum = accumulate(nums.begin(), nums.end(), 0);
			if (sum % k != 0) { return false; }

			sort(nums.begin(), nums.end());
			vector<bool> visited(len, false);
			return helper(0, sum / k, k, 0, nums, visited);
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}


	}
}
