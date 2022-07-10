#include "stdafx.h"

//Given an integer array nums, return an array answer such that answer[i] is
//equal to the product of all the elements of nums except nums[i].
//The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
//integer.
//You must write an algorithm that runs in O(n) time and without using the
//division operation.
// 
//
//Example 1:
//Input: nums = [1,2,3,4]
//Output: [24,12,8,6]
//
//Example 2:
//Input: nums = [-1,1,0,-3,3]
//Output: [0,0,9,0,0]
// 
//Constraints:
//2 <= nums.length <= 105
//-30 <= nums[i] <= 30
//The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
//integer.
// 
//Follow up: Can you solve the problem in O(1) extra space complexity? (The
//output array does not count as extra space for space complexity analysis.)

namespace Solution2022
{
	namespace ProductofArrayExceptSelf
	{
	    vector<int> productExceptSelf(vector<int>& nums) {
			int len = nums.size();
			if (len == 0) { return {}; }

			vector<int> result(len, 1);

			int cur = nums[0];
			for (int i = 1; i < len; i++) {
				result[i] = cur;
				cur *= nums[i];
			}

			cur = nums[len - 1];
			for (int i = len - 2; i >= 0; i--) {
				result[i] *= cur;
				cur *= nums[i];
			}
			return result;
	    }

		void Main() {
			vector<int> test = {1, 2, 3, 4};
			print(productExceptSelf(test));
		}
	}
}
