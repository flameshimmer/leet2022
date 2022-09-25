#include "stdafx.h"

//Given a non-empty array nums containing only positive integers, find if the
//array can be partitioned into two subsets such that the sum of elements in both
//subsets is equal.
// 
//
//Example 1:
//Input: nums = [1,5,11,5]
//Output: true
//Explanation: The array can be partitioned as [1, 5, 5] and [11].
//
//Example 2:
//Input: nums = [1,2,3,5]
//Output: false
//Explanation: The array cannot be partitioned into equal sum subsets.
// 
//Constraints:
//1 <= nums.length <= 200
//1 <= nums[i] <= 100

namespace Solution2022
{
	namespace PartitionEqualSubsetSum
	{
		bool canPartition(vector<int>& nums) {
			int sum = accumulate(nums.begin(), nums.end(), 0);
			if (sum % 2 == 1) { return false; }
			sum /= 2;

			vector<bool> dp(sum + 1, false);
			dp[0] = true;
			for (int v : nums) {
				for (int i = sum; i >= v; i--) {
					dp[i] = dp[i] || dp[i - v];
				}
			}
			return dp[sum];
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
