#include "stdafx.h"

//Given an integer array nums, find the contiguous subarray (containing at least
//one number) which has the largest sum and return its sum.
//A subarray is a contiguous part of an array.
// 
//
//Example 1:
//Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
//Output: 6
//Explanation: [4,-1,2,1] has the largest sum = 6.
//
//Example 2:
//Input: nums = [1]
//Output: 1
//
//Example 3:
//Input: nums = [5,4,-1,7,8]
//Output: 23
// 
//Constraints:
//1 <= nums.length <= 105
//-104 <= nums[i] <= 104
// 
//Follow up: If you have figured out the O(n) solution, try coding another
//solution using the divide and conquer approach, which is more subtle.

namespace Solution2022
{
	namespace MaximumSubarray
	{
	    int maxSubArray(vector<int>& nums) {
			int len = nums.size();
			if (len == 0) { return 0; }
	        
			int sum = nums[0];
			int result = nums[0];

			for (int i = 1; i < len; i++) {
				sum = max(0, sum) + nums[i];
				result = max(result, sum);
			}
			return result;
	    }


		int helper(vector<int>& nums, int start, int end) {
			if (start == end) { return nums[start]; }

			int mid = start + (end - start) / 2;
			int maxL = helper(nums, start, mid);
			int maxR = helper(nums, mid + 1, end);

			int maxMidL = INT_MIN;
			int curSum = 0;
			for (int i = mid; i >= start; i--) {
				curSum += nums[i];
				maxMidL = max(maxMidL, curSum);
			}

			int maxMidR = INT_MIN;
			curSum = 0;
			for (int i = mid + 1; i <= end; i++) {
				curSum += nums[i];
				maxMidR = max(maxMidR, curSum);
			}
			
			return max(max(maxL, maxR), maxMidL + maxMidR);
		}



		int maxSubArrayDivideAndConquer(vector<int>& nums) {
			int len = nums.size();
			if (len == 0) { return 0; }

			return helper(nums, 0, len - 1);
		}

		void Main() {
			string test = "tst test test";
			print(test);
		}
	}
}
