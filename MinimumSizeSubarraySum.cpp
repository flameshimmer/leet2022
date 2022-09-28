#include "stdafx.h"

//Given an array of positive integers nums and a positive integer target, return
//the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1,
//numsr] of which the sum is greater than or equal to target. If there is no such
//subarray, return 0 instead.
// 
//
//Example 1:
//Input: target = 7, nums = [2,3,1,2,4,3]
//Output: 2
//Explanation: The subarray [4,3] has the minimal length under the problem
//constraint.
//
//Example 2:
//Input: target = 4, nums = [1,4,4]
//Output: 1
//
//Example 3:
//Input: target = 11, nums = [1,1,1,1,1,1,1,1]
//Output: 0
// 
//Constraints:
//1 <= target <= 109
//1 <= nums.length <= 105
//1 <= nums[i] <= 105
// 
//Follow up: If you have figured out the O(n) solution, try coding another
//solution of which the time complexity is O(n log(n)).

namespace Solution2022
{
	namespace MinimumSizeSubarraySum
	{
		int minSubArrayLen(int target, vector<int>& nums) {
			int len = nums.size();
			int sum = 0;
			int start = 0;
			int result = INT_MAX;
			for (int end = 0; end < len; end++) {
				sum += nums[end];
				while (start <= end && sum >= target) {
					result = min(result, end - start + 1);
					sum -= nums[start];
					start++;
				}
			}
			return result == INT_MAX ? 0 : result;
		}

		void Main() {
			vector<int> test = { 2,3,1,2,4,3 };
			print(minSubArrayLen(7, test));
		}
	}
}
