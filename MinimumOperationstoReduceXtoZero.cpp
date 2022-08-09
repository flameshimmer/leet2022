#include "stdafx.h"

//You are given an integer array nums and an integer x. In one operation, you can
//either remove the leftmost or the rightmost element from the array nums and
//subtract its value from x. 
//Note that this modifies the array for future
//operations.
//Return the minimum number of operations to reduce x to exactly 0 if it is
//possible, otherwise, return -1.
// 
//
//Example 1:
//Input: nums = [1,1,4,2,3], x = 5
//Output: 2
//Explanation: The optimal solution is to remove the last two elements to reduce
//x to zero.
//
//Example 2:
//Input: nums = [5,6,7,8,9], x = 4
//Output: -1
//
//Example 3:
//Input: nums = [3,2,20,1,1,3], x = 10
//Output: 5
//Explanation: The optimal solution is to remove the last three elements and the
//first two elements (5 operations in total) to reduce x to zero.
// 
//Constraints:
//1 <= nums.length <= 105
//1 <= nums[i] <= 104
//1 <= x <= 109

namespace Solution2022
{
	namespace MinimumOperationstoReduceXtoZero
	{
	    int minOperations(vector<int>& nums, int x) {
			int len = nums.size();
			if (len == 0) { return -1; }
			int target = accumulate(nums.begin(), nums.end(), 0) - x;

			if (target == x) { return len; } // don't forget this special case handling!
			if (target < 0) { return -1; } // don't forget this special case handling!

			int start = 0;
			int result = INT_MIN;
			int sum = 0;

			for (int end = 0; end < len; end++) {
				sum += nums[end];
				while (sum > target && start <= end) {
					sum -= nums[start];
					start++;
				}
				if (sum == target) { result = max(result, end - start + 1); }
			}
			return result == INT_MIN ? -1 : len - result;
	    }

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
